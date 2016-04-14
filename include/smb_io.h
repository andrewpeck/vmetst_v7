    subroutine smb_io(adc_adr,smb_adr,smb_cmd,smb_data)
c
c   Generates SMB serial clock and data streams to TMB LM84 chip
c
c   SMB requires that serial data is stable while clock is high,
c   so data transitions occur while clock is low,
c   midway between clock falling edge and rising edge
c
c 12/10/01 Initial

    !DEC$ ATTRIBUTES C, ALIAS:'_vme_read'  :: vme_read
    !DEC$ ATTRIBUTES C, ALIAS:'_vme_write' :: vme_write
c
    implicit    none
    integer*4   smb_adr
    integer*4   smb_cmd
    integer*4   smb_data
    integer*4   adc_adr

    character*5 annotate(0:28)/
    1 'START',
    1 'A6   ','A5   ','A4   ','A3   ','A2   ', 'A1   ','A0   ',
    1 '0    ','ACK  ',
    1 'C7   ','C6   ','C5   ','C4   ','C3   ','C2   ','C1   ','C0   ',
    1 'NACK ',
    1 'D7   ','D6   ','D5   ','D4   ','D3   ','D2   ','D1   ','D0   ',
    1 'NACK ',
    1 'STOP '/
c
    integer*4   status
    integer*4   vme_read
    integer*4   vme_write
    integer*4   adr
c
    integer*4   i2c_clock
    integer*4   sda_clock
    integer*4   scl_clock
    integer*4   sda_bit(0:28)
    integer*4   sda
    integer*4   scl
    integer*4   d(0:28)
    integer*4   wr_data/0/
    integer*4   rd_data
    integer*4   adc_status
    integer*4   nclks
    integer*4   i
c
c   Get current ADC register state
c
    adr=adc_adr
    status = vme_read(%ref(adr),%ref(rd_data))
    adc_status=rd_data
c
c   Intialize SMB data stream
c
    sda_bit( 0)=0                               !Start
    sda_bit( 1)=ishft(smb_adr,-6).and.1         !A6
    sda_bit( 2)=ishft(smb_adr,-5).and.1         !A5
    sda_bit( 3)=ishft(smb_adr,-4).and.1         !A4
    sda_bit( 4)=ishft(smb_adr,-3).and.1         !A3
    sda_bit( 5)=ishft(smb_adr,-2).and.1         !A2
    sda_bit( 6)=ishft(smb_adr,-1).and.1         !A1
    sda_bit( 7)=ishft(smb_adr, 0).and.1         !A0
    sda_bit( 8)=0                               !0=write command register
    sda_bit( 9)=1                               !ACK
    sda_bit(10)=ishft(smb_cmd,-7).and.1         !C7
    sda_bit(11)=ishft(smb_cmd,-6).and.1         !C6
    sda_bit(12)=ishft(smb_cmd,-5).and.1         !C5
    sda_bit(13)=ishft(smb_cmd,-4).and.1         !C4
    sda_bit(14)=ishft(smb_cmd,-3).and.1         !C3
    sda_bit(15)=ishft(smb_cmd,-2).and.1         !C2
    sda_bit(16)=ishft(smb_cmd,-1).and.1         !C1
    sda_bit(17)=ishft(smb_cmd, 0).and.1         !C0
    sda_bit(18)=1                               !ACK
    sda_bit(19)=1                               !D7 read from LM84,1=z output from fpga
    sda_bit(20)=1                               !D6
    sda_bit(21)=1                               !D5
    sda_bit(22)=1                               !D4
    sda_bit(23)=1                               !D3
    sda_bit(24)=1                               !D2
    sda_bit(25)=1                               !D1
    sda_bit(26)=1                               !D0
    sda_bit(27)=1                               !ACK
    sda_bit(28)=0                               !Stop
c
c   Construct SMBclk and SMBdata
c
    nclks=115
c
    do 10 i2c_clock=0,nclks         !200KHz
    sda_clock=(i2c_clock+0)/4       ! 50KHz
    scl_clock=(i2c_clock+1)/2       ! 50KHz shifted 1/2 of a 100KHz cycle
c
    scl=scl_clock.and.1             ! 0/1
    sda=sda_bit(sda_clock)          !
c
    if(i2c_clock.lt. 3)scl=1        !START scl stays high
    if(i2c_clock.lt. 2)sda=1        !START sda transitions low
c
    if(i2c_clock.gt.nclks-3)scl=1   !STOP scl stays high
    if(i2c_clock.gt.nclks-2)sda=1   !STOP sda transitions high
c
d   write(2,'(i3,i3,i3,1x,a)')
d   1 i2c_clock,scl,sda,annotate(sda_clock)
c
c   Write Serial clock and data to TMB VME interface
c
    wr_data=adc_status.and.'F9FF'x  !Clear bits 9 and 10
    wr_data=wr_data.or.ishft(scl, 9)
    wr_data=wr_data.or.ishft(sda,10)

    status = vme_write(%ref(adr),%ref(wr_data))
    call wait(0.00002)      !Adjust wait time so scl is 50KHz or slower
c
c   Read Serial data from TMB VME interface, read on every cycle to keep clock symmetric
c
    status = vme_read(%ref(adr),%ref(rd_data))
d   write(*,'(1x,z4.4,2x,z4.4)') scl,rd_data
    if(scl.eq.1)d(sda_clock)=rd_data
    call wait(0.00002)      !Adjust wait time so scl is 50KHz or slower

c Clock i2c_clock
10  continue
c
c   Pack read data into an integer, sign extend if bit 7 indicates negative value
c
    smb_data=0
    do i=0,31                           !32 bit integer
    if(i.le.7) then
     sda=ishft(d(26-i),-10).and.'1'x    !data bit from LM84
     smb_data=smb_data.or.ishft(sda,i)  !d[7:0]
    else if(i.gt.7) then
     smb_data=smb_data.or.ishft(sda,i)  !sign extend
    end if
    end do
c
    return
    end
