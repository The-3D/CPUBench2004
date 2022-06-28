# Microsoft Developer Studio Project File - Name="Benchmarksintel" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Benchmarksintel - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Benchmarksintel.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Benchmarksintel.mak" CFG="Benchmarksintel - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Benchmarksintel - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Benchmarksintel - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Benchmarksintel - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "Benchmarksintel - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D _WIN32_WINNT=0x400 /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 C:\DXSDK\Samples\C++\DirectShow\BaseClasses\debug\strmbasd.lib winmm.lib ddraw.lib dxguid.lib d3dx9dt.lib d3d9.lib d3dxof.lib comctl32.lib winmm.lib /nologo /stack:0x200000,0x200000 /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /out:"..\Benchmarksintel.dll" /pdbtype:sept /ignore:4089 /ignore:4078
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Benchmarksintel - Win32 Release"
# Name "Benchmarksintel - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "common D3D"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\d3dfont.cpp"

!IF  "$(CFG)" == "Benchmarksintel - Win32 Release"

!ELSEIF  "$(CFG)" == "Benchmarksintel - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\d3dutil.cpp"

!IF  "$(CFG)" == "Benchmarksintel - Win32 Release"

!ELSEIF  "$(CFG)" == "Benchmarksintel - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\dxutil.cpp"

!IF  "$(CFG)" == "Benchmarksintel - Win32 Release"

!ELSEIF  "$(CFG)" == "Benchmarksintel - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\Benchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\BenchmarkDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BenchmarkEnvironment.cpp
# End Source File
# Begin Source File

SOURCE=.\Benchmarksintel.cpp
# End Source File
# Begin Source File

SOURCE=.\Benchmarksintel.def
# End Source File
# Begin Source File

SOURCE=.\Benchmarksintel.rc
# End Source File
# Begin Source File

SOURCE=.\BenchmarkStatusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CompressionBenchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\Direct3DBenchmark.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\DirectShow\Common\dshowutil.cpp"
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\Gradient.cpp
# End Source File
# Begin Source File

SOURCE=..\ItemBkDrawer.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\VideoCompressionBenchmark.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Benchmark.h
# End Source File
# Begin Source File

SOURCE=.\BenchmarkDlg.h
# End Source File
# Begin Source File

SOURCE=.\BenchmarkEnvironment.h
# End Source File
# Begin Source File

SOURCE=.\Benchmarksintel.h
# End Source File
# Begin Source File

SOURCE=.\BenchmarkStatusDlg.h
# End Source File
# Begin Source File

SOURCE=.\CompressionBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\Direct3DBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.h
# End Source File
# Begin Source File

SOURCE=..\Gradient.h
# End Source File
# Begin Source File

SOURCE=..\ItemBkDrawer.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VideoCompressionBenchmark.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Benchmarksintel.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
