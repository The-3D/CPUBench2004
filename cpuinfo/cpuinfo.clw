; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=2
Class1=CCpuinfoApp
LastClass=CCpuinfoApp
NewFileInclude2=#include "cpuinfo.h"
ResourceCount=0
NewFileInclude1=#include "stdafx.h"
Class2=CCPUInfoSet
LastTemplate=CDaoRecordset

[CLS:CCpuinfoApp]
Type=0
HeaderFile=cpuinfo.h
ImplementationFile=cpuinfo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CCpuinfoApp

[CLS:CCPUInfoSet]
Type=0
HeaderFile=CPUInfoSet.h
ImplementationFile=CPUInfoSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CCPUInfoSet]
DB=1
DBType=DAO
ColumnCount=11
Column1=[vendorID], 12, 50
Column2=[signature], 12, 50
Column3=[name], 12, 50
Column4=[codename], 12, 50
Column5=[frequencyRange], 12, 50
Column6=[defaultVoltage], 12, 50
Column7=[socketName], 12, 50
Column8=[busType], 12, 50
Column9=[fullVendorName], 12, 50
Column10=[l2Cache], 4, 4
Column11=[logoName], 12, 50

