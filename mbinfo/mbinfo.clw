; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=6
Class1=CMbinfoApp
LastClass=CMbinfoApp
NewFileInclude2=#include "mbinfo.h"
ResourceCount=1
NewFileInclude1=#include "stdafx.h"
Class2=CDeviceVendorsSet
LastTemplate=CDialog
Class3=CDeviceDescriptorsSet
Class4=CDeviceDescriptorsTableSet
Class5=CDeviceVendorsTableSet
Class6=CSearchDlg
Resource1=IDD_SEARCHDLG_DIALOG

[CLS:CMbinfoApp]
Type=0
HeaderFile=mbinfo.h
ImplementationFile=mbinfo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMbinfoApp

[CLS:CDeviceVendorsSet]
Type=0
HeaderFile=DeviceVendorsSet.h
ImplementationFile=DeviceVendorsSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CDeviceVendorsSet]
DB=1
DBType=DAO
ColumnCount=3
Column1=[VendorID], 12, 50
Column2=[Vendor_name], 12, 255
Column3=[Vendor_logo], 12, 50

[CLS:CDeviceDescriptorsSet]
Type=0
HeaderFile=DeviceDescriptorsSet.h
ImplementationFile=DeviceDescriptorsSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CDeviceDescriptorsSet]
DB=1
DBType=DAO
ColumnCount=3
Column1=[DeviceID], 12, 50
Column2=[DeviceName], 12, 255
Column3=[DeviceLogo], 12, 50

[CLS:CDeviceDescriptorsTableSet]
Type=0
HeaderFile=DeviceDescriptorsTableSet.h
ImplementationFile=DeviceDescriptorsTableSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CDeviceDescriptorsTableSet]
DB=1
DBType=DAO
ColumnCount=3
Column1=[DeviceID], 12, 20
Column2=[DeviceName], 12, 200
Column3=[DeviceLogo], 12, 20

[CLS:CDeviceVendorsTableSet]
Type=0
HeaderFile=DeviceVendorsTableSet.h
ImplementationFile=DeviceVendorsTableSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CDeviceVendorsTableSet]
DB=1
DBType=DAO
ColumnCount=3
Column1=[VendorID], 12, 20
Column2=[Vendor_name], 12, 200
Column3=[Vendor_logo], 12, 20

[DLG:IDD_SEARCHDLG_DIALOG]
Type=1
Class=CSearchDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CURRDEV,static,1342308352

[CLS:CSearchDlg]
Type=0
HeaderFile=SearchDlg.h
ImplementationFile=SearchDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CURRDEV

