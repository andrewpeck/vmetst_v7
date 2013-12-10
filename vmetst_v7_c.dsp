# Microsoft Developer Studio Project File - Name="vmetst_v7_c" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=vmetst_v7_c - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vmetst_v7_c.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vmetst_v7_c.mak" CFG="vmetst_v7_c - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vmetst_v7_c - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "vmetst_v7_c - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "vmetst_v7_c - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE F90 /compile_only /include:"Release/" /nologo /warn:nofileopt
# ADD F90 /compile_only /include:"Release/" /nologo /warn:nofileopt
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "vmetst_v7_c - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE F90 /check:bounds /compile_only /debug:full /include:"Debug/" /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD F90 /browser /check:bounds /compile_only /debug:full /include:"Debug/" /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "vmetst_v7_c - Win32 Release"
# Name "vmetst_v7_c - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=.\adc_read.cpp
# End Source File
# Begin Source File

SOURCE=.\cfebbx_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\crc22.cpp
# End Source File
# Begin Source File

SOURCE=.\ddd_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\ddd_wr.cpp
# End Source File
# Begin Source File

SOURCE=.\dddstr_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\decode_readout.cpp
# End Source File
# Begin Source File

SOURCE=.\dow_crc.cpp
# End Source File
# Begin Source File

SOURCE=.\dsn_io.cpp
# End Source File
# Begin Source File

SOURCE=.\dsn_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\lct_quality.cpp
# End Source File
# Begin Source File

SOURCE=..\vmetst_v7_1214208_vs2008partialc\vmetst_v7_c\lenval.cpp
# End Source File
# Begin Source File

SOURCE=.\micro.cpp
# End Source File
# Begin Source File

SOURCE=.\miniscope16.cpp
# End Source File
# Begin Source File

SOURCE=.\pattern_finder.cpp
# End Source File
# Begin Source File

SOURCE=.\pattern_unit.cpp
# End Source File
# Begin Source File

SOURCE=.\pause.cpp
# End Source File
# Begin Source File

SOURCE=.\phaser_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\phaser_wr.cpp
# End Source File
# Begin Source File

SOURCE=.\ports_vme.cpp
# End Source File
# Begin Source File

SOURCE=.\posneg_rd.cpp
# End Source File
# Begin Source File

SOURCE=.\posneg_wr.cpp
# End Source File
# Begin Source File

SOURCE=.\scope160c.cpp
# End Source File
# Begin Source File

SOURCE=.\smb_read.cpp
# End Source File
# Begin Source File

SOURCE=.\smb_write.cpp
# End Source File
# Begin Source File

SOURCE=.\stop.cpp
# End Source File
# Begin Source File

SOURCE=.\vme_io_wxp.cpp
# End Source File
# Begin Source File

SOURCE=.\vme_jtag_io_byte.cpp
# End Source File
# Begin Source File

SOURCE=.\vme_jtag_io_ops.cpp
# End Source File
# Begin Source File

SOURCE=.\vmetst_v7.cpp
# End Source File
# Begin Source File

SOURCE=.\xsvf_writer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\btapi.h
# End Source File
# Begin Source File

SOURCE=.\btdef.h
# End Source File
# Begin Source File

SOURCE=.\btngpci.h
# End Source File
# Begin Source File

SOURCE=.\btwapi.h
# End Source File
# Begin Source File

SOURCE=.\btwdef.h
# End Source File
# Begin Source File

SOURCE=.\btwio.h
# End Source File
# Begin Source File

SOURCE=.\lenval.h
# End Source File
# Begin Source File

SOURCE=.\micro.h
# End Source File
# Begin Source File

SOURCE=.\ports.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\clct_injector_ram_image.txt
# End Source File
# Begin Source File

SOURCE=.\loopback_doc.txt
# End Source File
# Begin Source File

SOURCE=.\userprom0_readback.txt
# End Source File
# Begin Source File

SOURCE=.\vmeprom256.txt
# End Source File
# Begin Source File

SOURCE=.\vmetst_log.txt
# End Source File
# Begin Source File

SOURCE=.\vmetst_scn.txt
# End Source File
# Begin Source File

SOURCE=.\vmetst_sum.txt
# End Source File
# Begin Source File

SOURCE=.\bit3_984.lib
# End Source File
# End Target
# End Project
