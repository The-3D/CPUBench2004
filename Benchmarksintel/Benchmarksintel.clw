; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=4
Class1=CBenchmarksintelApp
LastClass=CBenchmarkDlg
NewFileInclude2=#include "Benchmarksintel.h"
ResourceCount=3
NewFileInclude1=#include "stdafx.h"
Class2=CBenchmarkDlg
LastTemplate=CDialog
Resource1=IDD_FORM (English (U.S.))
Class3=CProvaDlg
Resource2=IDD_BENCHMARKSTATUSDLG_DIALOG
Class4=CBenchmarkStatusDlg
Resource3=IDD_PROVADLG_DIALOG

[CLS:CBenchmarksintelApp]
Type=0
HeaderFile=Benchmarksintel.h
ImplementationFile=Benchmarksintel.cpp
Filter=N

[DLG:IDD_FORM (English (U.S.))]
Type=1
Class=CBenchmarkDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

[CLS:CBenchmarkDlg]
Type=0
HeaderFile=BenchmarkDlg.h
ImplementationFile=BenchmarkDlg.cpp
BaseClass=CWnd
Filter=W
LastObject=CBenchmarkDlg
VirtualFilter=WC

[DLG:IDD_PROVADLG_DIALOG]
Type=1
Class=CProvaDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[CLS:CProvaDlg]
Type=0
HeaderFile=ProvaDlg.h
ImplementationFile=ProvaDlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_BENCHMARKSTATUSDLG_DIALOG]
Type=1
Class=CBenchmarkStatusDlg
ControlCount=3
Control1=IDC_PROGRESS1,msctls_progress32,1350565888
Control2=IDC_PROGRESS2,msctls_progress32,1350565888
Control3=IDC_STATIC,static,1342308352

[CLS:CBenchmarkStatusDlg]
Type=0
HeaderFile=BenchmarkStatusDlg.h
ImplementationFile=BenchmarkStatusDlg.cpp
BaseClass=CDialog
Filter=D

