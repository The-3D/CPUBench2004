# Microsoft Developer Studio Project File - Name="CPUBench2004" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=CPUBench2004 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CPUBench2004.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CPUBench2004.mak" CFG="CPUBench2004 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CPUBench2004 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CPUBench2004 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=xicl6.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CPUBench2004 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 msimg32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "CPUBench2004 - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 msimg32.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CPUBench2004 - Win32 Release"
# Name "CPUBench2004 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BenchmarkResultItem.cpp
# End Source File
# Begin Source File

SOURCE=.\BenchmarkSettingsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CacheInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUBench2004.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUBench2004.rc
# End Source File
# Begin Source File

SOURCE=.\CPUBench2004Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesItem.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUInfoItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CPUInformations.cpp
# End Source File
# Begin Source File

SOURCE=.\DeviceInformations.cpp
# End Source File
# Begin Source File

SOURCE=.\DevicesListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogBasedItem.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtCPUInfoItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtMBInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtMemoryInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtOSInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\FlexGUIButton.cpp
# End Source File
# Begin Source File

SOURCE=.\FlexGUIWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\Gradient.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ItemBkDrawer.cpp
# End Source File
# Begin Source File

SOURCE=.\MainWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\MemoryInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\OSInfoItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OSInformations.cpp
# End Source File
# Begin Source File

SOURCE=.\ReportCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\ReportDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ResultDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SplashDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SysInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SysInfoWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkspaceBkDrawer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BenchmarkResultItem.h
# End Source File
# Begin Source File

SOURCE=.\BenchmarkSettingsDlg.h
# End Source File
# Begin Source File

SOURCE=.\BenchResult.h
# End Source File
# Begin Source File

SOURCE=.\CacheInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\CPUBench2004.h
# End Source File
# Begin Source File

SOURCE=.\CPUBench2004Dlg.h
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesDlg.h
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesItem.h
# End Source File
# Begin Source File

SOURCE=.\CPUFeaturesWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\CPUInfoItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\CPUInformations.h
# End Source File
# Begin Source File

SOURCE=.\DeviceInformations.h
# End Source File
# Begin Source File

SOURCE=.\DevicesListDlg.h
# End Source File
# Begin Source File

SOURCE=.\DialogBasedItem.h
# End Source File
# Begin Source File

SOURCE=.\ExtCPUInfoItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\ExtMBInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ExtMemoryInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ExtOSInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.h
# End Source File
# Begin Source File

SOURCE=.\FlexGUIButton.h
# End Source File
# Begin Source File

SOURCE=.\FlexGUIItem.h
# End Source File
# Begin Source File

SOURCE=.\FlexGUIWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\Gradient.h
# End Source File
# Begin Source File

SOURCE=.\ImageCtrl.h
# End Source File
# Begin Source File

SOURCE=.\ItemBkDrawer.h
# End Source File
# Begin Source File

SOURCE=.\MainWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\MemoryInfo.h
# End Source File
# Begin Source File

SOURCE=.\OSInfoItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\OSInformations.h
# End Source File
# Begin Source File

SOURCE=.\ReportCreator.h
# End Source File
# Begin Source File

SOURCE=.\ReportDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ResultDlg.h
# End Source File
# Begin Source File

SOURCE=.\SplashDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SysInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\SysInfoWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\WorkspaceBkDrawer.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\AMD_Athlon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_64.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_6448.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_64_FX.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_64_FX48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_XP.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Athlon_XP48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_K648.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AMD_Opteron_6448.bmp
# End Source File
# Begin Source File

SOURCE=.\res\athlon48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bk.bmp
# End Source File
# Begin Source File

SOURCE=.\res\celeron48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CPUBench2004.ico
# End Source File
# Begin Source File

SOURCE=.\res\CPUBench2004.rc2
# End Source File
# Begin Source File

SOURCE=.\res\duron48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_P4_HT.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_P4_HT48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_P4_Xeon48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_Pentium_M.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_Pentium_M48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_Pentium_M_48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Intel_PIII_Xeon48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ipIII48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\k6248.bmp
# End Source File
# Begin Source File

SOURCE=.\res\logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\splash.bmp
# End Source File
# Begin Source File

SOURCE=.\res\title2.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
