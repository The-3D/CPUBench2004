# Microsoft Developer Studio Project File - Name="benchmarks" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=benchmarks - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "benchmarks.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "benchmarks.mak" CFG="benchmarks - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "benchmarks - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "benchmarks - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=xicl6.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "benchmarks - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D _WIN32_WINNT=0x400 /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 C:\DXSDK\Samples\C++\DirectShow\BaseClasses\release\strmbase.lib winmm.lib ddraw.lib dxguid.lib d3dx9dt.lib d3d9.lib d3dxof.lib winmm.lib opengl32.lib glu32.lib msimg32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\benchmarks.dll"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D _WIN32_WINNT=0x400 /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x410 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 C:\DXSDK\Samples\C++\DirectShow\BaseClasses\debug\strmbasd.lib winmm.lib ddraw.lib dxguid.lib d3dx9dt.lib d3d9.lib d3dxof.lib winmm.lib glu32.lib opengl32.lib /nologo /stack:0x200000,0x200000 /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"LIBCMTD.lib" /def:".\benchmarks.def" /out:"..\benchmarks.dll" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ENDIF 

# Begin Target

# Name "benchmarks - Win32 Release"
# Name "benchmarks - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "common D3D"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\d3dfile.cpp"

!IF  "$(CFG)" == "benchmarks - Win32 Release"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\d3dfont.cpp"

!IF  "$(CFG)" == "benchmarks - Win32 Release"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\d3dutil.cpp"

!IF  "$(CFG)" == "benchmarks - Win32 Release"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\Common\Src\dxutil.cpp"

!IF  "$(CFG)" == "benchmarks - Win32 Release"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "common DShow"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\DXSDK\Samples\C++\DirectShow\Common\dshowutil.cpp"
# End Source File
# End Group
# Begin Group "DB data sets"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BooksSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PublishersSet.cpp
# End Source File
# End Group
# Begin Group "scientific test"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Atom.cpp
# End Source File
# Begin Source File

SOURCE=.\Molecule.cpp
# End Source File
# Begin Source File

SOURCE=.\MoleculeBuilder.cpp
# End Source File
# Begin Source File

SOURCE=.\MoleculeRenderer.cpp
# End Source File
# End Group
# Begin Group "cad renderers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\HeadRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\StaircaseRenderer.cpp
# End Source File
# End Group
# Begin Group "L3DS"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\l3ds.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Source File

SOURCE=.\AllocationHierarchy.cpp
# End Source File
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

SOURCE=.\benchmarks.cpp
# End Source File
# Begin Source File

SOURCE=.\benchmarks.def

!IF  "$(CFG)" == "benchmarks - Win32 Release"

!ELSEIF  "$(CFG)" == "benchmarks - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\benchmarks.rc
# End Source File
# Begin Source File

SOURCE=.\CadBenchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\D3DAnimatedMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\DatabaseBenchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\Direct3DBenchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\EnvironmentSkinDrawer.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\FlexGUIButton.cpp
# End Source File
# Begin Source File

SOURCE=..\Gradient.cpp
# End Source File
# Begin Source File

SOURCE=..\ItemBkDrawer.cpp
# End Source File
# Begin Source File

SOURCE=.\RayTracingBenchmark.cpp
# End Source File
# Begin Source File

SOURCE=.\RayTracingEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\ScientificBenchmark.cpp
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
# Begin Group "DB Data sets H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BooksSet.h
# End Source File
# Begin Source File

SOURCE=.\PublishersSet.h
# End Source File
# End Group
# Begin Group "scientific test header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Atom.h
# End Source File
# Begin Source File

SOURCE=.\Molecule.h
# End Source File
# Begin Source File

SOURCE=.\MoleculeBuilder.h
# End Source File
# Begin Source File

SOURCE=.\MoleculeRenderer.h
# End Source File
# End Group
# Begin Group "cad renderers H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\HeadRenderer.h
# End Source File
# Begin Source File

SOURCE=.\ModelRenderer.h
# End Source File
# Begin Source File

SOURCE=.\StaircaseRenderer.h
# End Source File
# End Group
# Begin Group "l3ds h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\l3ds.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\AllocationHierarchy.h
# End Source File
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

SOURCE=.\benchmarks.h
# End Source File
# Begin Source File

SOURCE=.\CadBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\D3DAnimatedMesh.h
# End Source File
# Begin Source File

SOURCE=.\DatabaseBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\Direct3DBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\EnvironmentSkinDrawer.h
# End Source File
# Begin Source File

SOURCE=.\ExtProgressCtrl.h
# End Source File
# Begin Source File

SOURCE=.\RayTracingBenchmark.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ScientificBenchmark.h
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

SOURCE=.\res\benchmarks.rc2
# End Source File
# Begin Source File

SOURCE=.\description.bmp
# End Source File
# Begin Source File

SOURCE=.\down.bmp
# End Source File
# Begin Source File

SOURCE=.\dx9performance.bmp
# End Source File
# Begin Source File

SOURCE=.\header_environment.bmp
# End Source File
# Begin Source File

SOURCE=.\moleculeviewer.bmp
# End Source File
# Begin Source File

SOURCE=.\molviewer.bmp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\right.bmp
# End Source File
# Begin Source File

SOURCE=.\right1.bmp
# End Source File
# Begin Source File

SOURCE=.\right2.bmp
# End Source File
# Begin Source File

SOURCE=.\videoencoding.bmp
# End Source File
# End Group
# End Target
# End Project
