CXX = g++
SOURCES = VMEController_jtag.cc VMEController.cc adc_read_alct.cpp adc_read.cpp adc_read_mez.cpp cfebbx_rd.cpp ck.cpp common.cpp crc22.cpp ddd_rd.cpp dddstr_rd.cpp ddd_wr.cpp decode_raw_hits.cpp decode_readout.cpp dow_crc.cpp dsn_io_alct.cpp dsn_io.cpp dsn_rd_alct.cpp dsn_rd.cpp idcode_decode.cpp jtag_io.cpp lct_quality.cpp lenval.cpp lfsr_rng.cpp micro.cpp miniscope16.cpp pattern_finder.cpp pattern_unit.cpp pause.cpp phaser_rd.cpp phaser_wr.cpp ports_vme.cpp posneg_rd.cpp posneg_wr.cpp scope160c.cpp stop.cpp  vme_io.cpp vme_jtag_io_byte.cpp vme_jtag_io_ops.cpp  vmetst_v7.cpp xsvf_writer.cpp wxp_compat.cpp smb_write.cpp smb_read.cpp 

OBJECTS = $(addprefix obj/,$(subst .cpp,.o,$(subst .cc,.o,$(SOURCES)) ))

INCLUDE= -I./include
LIBDIR = -L./bin

CXXFLAGS = -g -O3 $(INCLUDE) -Wall

TARGET = vmetst_v7


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIBDIR) -o $@ $^
	#$(CXXFLAGS) -c $< -o $@ $(LIBDIR) $(LDFLAGS)



obj/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#$(OBJECTS): src/%.cpp
#	$(CXX) $(CXXFLAGS) -c $< 

.PHONY: clean tar

clean:
	$(RM) obj/*.o

install: 
	cp $(TARGET) /usr/lib/$(TARGET)
	chmod 755 /usr/lib/$(TARGET)
	cp cbc.hpp  /usr/include/cbc.hpp
	chmod 644 /usr/include/cbc.hpp

tar: 
	tar czvf libcbc.tar.gz ../libcbc/*.cpp ../libcbc/*.hpp ../libcbc/Makefile
