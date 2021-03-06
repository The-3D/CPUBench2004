; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSplashDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CPUBench2004.h"

ClassCount=20
Class1=CCPUBench2004App
Class2=CCPUBench2004Dlg
Class3=CAboutDlg

ResourceCount=17
Resource1=IDD_OSINFOITEMDLG_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DEVICESLISTDLG_DIALOG
Class4=CBenchmarkSettingsDlg
Class5=CFlexGUIButton
Resource4=IDD_RESULTDLG_DIALOG
Class6=CCPUInfoItemDlg
Resource5=IDD_SYSINFODLG_DIALOG
Class7=COSInfoItemDlg
Class8=CExtProgressCtrl
Resource6=IDD_EXTOSINFODLG_DIALOG
Class9=CSysInfoDlg
Resource7=IDD_EXTCPUINFOITEMDLG_DIALOG
Class10=CExtCPUInfoItemDlg
Resource8=IDD_CPUINFOITEMDLG_DIALOG
Class11=CExtOSInfoDlg
Resource9=IDD_ABOUTBOX
Class12=CExtMemoryInfoDlg
Resource10=IDD_EXTMBINFODLG_DIALOG
Class13=CExtMBInfoDlg
Resource11=IDD_REPORTDLG_DIALOG
Class14=CCacheInfoDlg
Resource12=IDD_CPUFEATURESDLG_DIALOG
Class15=CCPUFeaturesDlg
Resource13=IDD_CACHEINFODLG_DIALOG
Class16=CDevicesListDlg
Resource14=IDD_EXTMEMORYINFODLG_DIALOG
Class17=CReportDlg
Class18=CImageCtrl
Resource15=IDD_CPUBENCH2004_DIALOG
Class19=CResultDlg
Resource16=IDD_BENCHMARKSETTINGSDLG_DIALOG
Class20=CSplashDlg
Resource17=IDD_SPLASHDLG_DIALOG

[CLS:CCPUBench2004App]
Type=0
HeaderFile=CPUBench2004.h
ImplementationFile=CPUBench2004.cpp
Filter=N

[CLS:CCPUBench2004Dlg]
Type=0
HeaderFile=CPUBench2004Dlg.h
ImplementationFile=CPUBench2004Dlg.cpp
Filter=W
LastObject=CCPUBench2004Dlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CPUBench2004Dlg.h
ImplementationFile=CPUBench2004Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CPUBENCH2004_DIALOG]
Type=1
Class=CCPUBench2004Dlg
ControlCount=4
Control1=IDC_RUNBENCHMARK,button,1342242827
Control2=IDC_BUTTON2,button,1342242827
Control3=IDC_EXIT,button,1342242827
Control4=IDC_LOGO,static,1342308352

[DLG:IDD_BENCHMARKSETTINGSDLG_DIALOG]
Type=1
Class=CBenchmarkSettingsDlg
ControlCount=13
Control1=IDC_TITLE1,static,1342308352
Control2=IDC_WINDOWSMEDIA,static,1342308352
Control3=IDC_TITLE3,static,1342308352
Control4=IDC_CAD,static,1342308352
Control5=IDC_DB,static,1342308352
Control6=IDC_DIRECT3D,static,1342308352
Control7=IDC_TITLE4,static,1342308352
Control8=IDC_RAM,static,1342308352
Control9=IDC_CONFIGURE,button,1342242827
Control10=IDC_RT1,static,1342308352
Control11=IDC_RAM2,static,1342308352
Control12=IDC_RAM3,static,1342308352
Control13=IDC_RT2,static,1342308352

[CLS:CBenchmarkSettingsDlg]
Type=0
HeaderFile=BenchmarkSettingsDlg.h
ImplementationFile=BenchmarkSettingsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBenchmarkSettingsDlg

[CLS:CFlexGUIButton]
Type=0
HeaderFile=FlexGUIButton.h
ImplementationFile=FlexGUIButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CFlexGUIButton

[DLG:IDD_CPUINFOITEMDLG_DIALOG]
Type=1
Class=CCPUInfoItemDlg
ControlCount=32
Control1=IDC_TITLE1,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CPUNAME,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CPUVENDOR,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BRANDNAME,static,1342308352
Control8=IDC_ADVINFO,button,1342242827
Control9=IDC_CACHEINFO,button,1342242827
Control10=IDC_TITLE2,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_SIGNATURE,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CODENAME,static,1342308352
Control15=IDC_TITLE3,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_L1INSTRCACHE,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_L1DATACACHE,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_L2CACHE,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_FREQUENCY,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_TRACECACHE,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_BUSTYPE,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_SOCKETNAME,static,1342308352
Control30=IDC_CPULOGO,static,1342179342
Control31=IDC_STATIC,static,1342308352
Control32=IDC_BUSSPEED,static,1342308352

[CLS:CCPUInfoItemDlg]
Type=0
HeaderFile=CPUInfoItemDlg.h
ImplementationFile=CPUInfoItemDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=IDC_ADVINFO
VirtualFilter=dWC

[DLG:IDD_OSINFOITEMDLG_DIALOG]
Type=1
Class=COSInfoItemDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_OSNAME,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MEMFREE,msctls_progress32,1342177280
Control5=IDC_MORE,button,1342242827
Control6=IDC_MEMFREEVAL,static,1342308352

[CLS:COSInfoItemDlg]
Type=0
HeaderFile=OSInfoItemDlg.h
ImplementationFile=OSInfoItemDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_OSNAME

[CLS:CExtProgressCtrl]
Type=0
HeaderFile=ExtProgressCtrl.h
ImplementationFile=ExtProgressCtrl.cpp
BaseClass=CProgressCtrl
Filter=W

[DLG:IDD_SYSINFODLG_DIALOG]
Type=1
Class=CSysInfoDlg
ControlCount=3
Control1=IDOK,button,1342242827
Control2=IDC_UPDATE,button,1342242827
Control3=IDC_CREATEREPORT,button,1342242827

[CLS:CSysInfoDlg]
Type=0
HeaderFile=SysInfoDlg.h
ImplementationFile=SysInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_UPDATE

[DLG:IDD_EXTCPUINFOITEMDLG_DIALOG]
Type=1
Class=CExtCPUInfoItemDlg
ControlCount=45
Control1=IDC_LBL1,static,1342308352
Control2=IDC_LBL2,static,1342308352
Control3=IDC_LBL4,static,1342308352
Control4=IDC_CPUNAME,static,1342308352
Control5=IDC_VENDORNAME,static,1342308352
Control6=IDC_CODENAME,static,1342308352
Control7=IDC_LBL5,static,1342308352
Control8=IDC_PLATFORM,static,1342308352
Control9=IDC_CPULOGO,static,1342177294
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_LBL3,static,1342308352
Control15=IDC_BRANDNAME,static,1342308352
Control16=IDC_FEATURES,button,1342242827
Control17=IDC_CACHEDETAILS,button,1342242827
Control18=IDC_STATIC,static,1342308352
Control19=IDC_CPUFREQUENCY,static,1342308352
Control20=IDC_L1ICACHE,static,1342308352
Control21=IDC_FREQUENCYRATIO,static,1342308352
Control22=IDC_L1DCACHE,static,1342308352
Control23=IDC_L2CACHE,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_MMX,static,1342308352
Control30=IDC_SSE3,static,1342308352
Control31=IDC_SSE2,static,1342308352
Control32=IDC_AMD64,static,1342308352
Control33=IDC_HTSUPPORT,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_TRACECACHE,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_PSE36,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_FREQUENCYRANGE,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_SSE,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_SIGNATURE,static,1342308352
Control44=IDC_STATIC,static,1342308352
Control45=IDC_DEFVCORE,static,1342308352

[CLS:CExtCPUInfoItemDlg]
Type=0
HeaderFile=ExtCPUInfoItemDlg.h
ImplementationFile=ExtCPUInfoItemDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CExtCPUInfoItemDlg

[DLG:IDD_EXTOSINFODLG_DIALOG]
Type=1
Class=CExtOSInfoDlg
ControlCount=18
Control1=IDC_LBL,static,1342308352
Control2=IDC_OSNAME,static,1342308352
Control3=IDC_LBL9,static,1342308352
Control4=IDC_REVISION,static,1342308352
Control5=IDC_LBL10,static,1342308352
Control6=IDC_USERNAME,static,1342308352
Control7=IDC_LBL11,static,1342308352
Control8=IDC_COMPUTERNAME,static,1342308352
Control9=IDC_SERVICEPACK,static,1342308352
Control10=IDC_LBL13,static,1342308352
Control11=IDC_STANDBY,static,1342308352
Control12=IDC_LBL15,static,1342308352
Control13=IDC_MAINDIRECTORY,static,1342308352
Control14=IDC_LBL17,static,1342308352
Control15=IDC_BOOTMODE,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_LBL18,static,1342308352
Control18=IDC_RESOLUTION,static,1342308352

[CLS:CExtOSInfoDlg]
Type=0
HeaderFile=ExtOSInfoDlg.h
ImplementationFile=ExtOSInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_REVISION

[DLG:IDD_EXTMEMORYINFODLG_DIALOG]
Type=1
Class=CExtMemoryInfoDlg
ControlCount=18
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PHYSMEM,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PAGESIZE,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_VIRTUALSIZE,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_TOTALLOAD,msctls_progress32,1342177280
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PAGEFILEFREE,msctls_progress32,1342177280
Control11=IDC_STATIC,static,1342308352
Control12=IDC_RAMFREE,msctls_progress32,1342177280
Control13=IDC_STATIC,static,1342308352
Control14=IDC_USERFREE,msctls_progress32,1342177280
Control15=IDC_MEMLOAD,static,1342308353
Control16=IDC_PAGEFREE,static,1342308353
Control17=IDC_RAMFREEPERCENT,static,1342308353
Control18=IDC_USERFREEPERCENT,static,1342308353

[CLS:CExtMemoryInfoDlg]
Type=0
HeaderFile=ExtMemoryInfoDlg.h
ImplementationFile=ExtMemoryInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CExtMemoryInfoDlg
VirtualFilter=dWC

[DLG:IDD_EXTMBINFODLG_DIALOG]
Type=1
Class=CExtMBInfoDlg
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CHIPSETID,static,1342308352
Control3=IDC_OTHERPCI,button,1342242827
Control4=IDC_STATIC,static,1342308352
Control5=IDC_FSBSPEED,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PCILATENCY,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CHIPSETVENDOR,static,1342308352
Control10=IDC_LBL,static,1342308352
Control11=IDC_NAME,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_BIOSNAME,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_BIOSVERSION,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_BIOSDATE,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_BUSTYPE,static,1342308352

[CLS:CExtMBInfoDlg]
Type=0
HeaderFile=ExtMBInfoDlg.h
ImplementationFile=ExtMBInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_VENDORID

[DLG:IDD_CACHEINFODLG_DIALOG]
Type=1
Class=CCacheInfoDlg
ControlCount=77
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_L1DTLB4M_ASS,static,1342308864
Control4=IDC_L1ITLB4M_ASS,static,1342308864
Control5=IDC_STATIC,static,1342308352
Control6=IDC_L1DTLB4M_ENTRIES,static,1342308864
Control7=IDC_STATIC,static,1342308352
Control8=IDC_L1ITLB4M_ENTRIES,static,1342308864
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_L1D_TLB4K_ASSOCIATIVITY,static,1342308864
Control12=IDC_L1I_TLB4K_ASSOCIATIVITY,static,1342308864
Control13=IDC_STATIC,static,1342308352
Control14=IDC_L1D_TLB4K_ENTRIES,static,1342308864
Control15=IDC_STATIC,static,1342308352
Control16=IDC_L1I_TLB4K_ENTRIES,static,1342308864
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_L1D_ASSOCIATIVITY,static,1342308352
Control20=IDC_L1D_LINESIZE,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_L1D_LINESPERTAG,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_L1D_CACHESIZE,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_L1I_ASSOCIATIVITY,static,1342308352
Control28=IDC_L1I_LINESIZE,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_L1I_LINESPERTAG,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_L1I_CACHESIZE,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_L2D_TLB4M_ASSOCIATIVITY,static,1342308352
Control36=IDC_L2I_TLB4M_ASSOCIATIVITY,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_L2D_TLB4M_ENTRIES,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_L2I_TLB4M_ENTRIES,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_L2D_TLB4K_ASSOCIATIVITY,static,1342308352
Control44=IDC_L2I_TLB4K_ASSOCIATIVITY,static,1342308352
Control45=IDC_STATIC,static,1342308352
Control46=IDC_L2D_TLB4K_ENTRIES,static,1342308352
Control47=IDC_STATIC,static,1342308352
Control48=IDC_L2I_TLB4K_ENTRIES,static,1342308352
Control49=IDC_STATIC,static,1342308352
Control50=IDC_STATIC,static,1342308352
Control51=IDC_L2_ASSOCIATIVITY,static,1342308352
Control52=IDC_L2_LINESIZE,static,1342308352
Control53=IDC_STATIC,static,1342308352
Control54=IDC_L2_LINESPERTAG,static,1342308352
Control55=IDC_STATIC,static,1342308352
Control56=IDC_L2_CACHESIZE,static,1342308352
Control57=IDC_STATIC,static,1476526080
Control58=IDC_STATIC,static,1476526080
Control59=IDC_L2CACHE_ASSOCIATIVITY2,static,1476526080
Control60=IDC_L2CACHE_LINESIZE2,static,1476526080
Control61=IDC_STATIC,static,1476526080
Control62=IDC_L2CACHE_LINESPERTAG2,static,1476526080
Control63=IDC_L1_DATA_CACHE_SIZE4,static,1476526080
Control64=IDC_L2CACHE_SIZE2,static,1476526080
Control65=IDC_LBL4,static,1342308352
Control66=IDC_LBL3,static,1342308352
Control67=IDC_LBL5,static,1342308352
Control68=IDC_LBL6,static,1342308352
Control69=IDOK,button,1342242827
Control70=IDC_LBL7,static,1342308352
Control71=IDC_LBL8,static,1342308352
Control72=IDC_LBL1,static,1342308352
Control73=IDC_LBL2,static,1342308352
Control74=IDC_CACHELATENCY,button,1342242827
Control75=IDC_MAINTITLE,static,1342308865
Control76=IDC_STATIC,static,1342177287
Control77=IDC_STATIC,static,1342177287

[CLS:CCacheInfoDlg]
Type=0
HeaderFile=CacheInfoDlg.h
ImplementationFile=CacheInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_L2D_TLB4K_ASSOCIATIVITY
VirtualFilter=dWC

[DLG:IDD_CPUFEATURESDLG_DIALOG]
Type=1
Class=CCPUFeaturesDlg
ControlCount=1
Control1=IDOK,button,1342242827

[CLS:CCPUFeaturesDlg]
Type=0
HeaderFile=CPUFeaturesDlg.h
ImplementationFile=CPUFeaturesDlg.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC
LastObject=CCPUFeaturesDlg

[DLG:IDD_DEVICESLISTDLG_DIALOG]
Type=1
Class=CDevicesListDlg
ControlCount=3
Control1=IDOK,button,1342242827
Control2=IDC_DEVLIST,SysListView32,1342291973
Control3=IDC_TITLE,static,1342308352

[CLS:CDevicesListDlg]
Type=0
HeaderFile=DevicesListDlg.h
ImplementationFile=DevicesListDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDevicesListDlg

[DLG:IDD_REPORTDLG_DIALOG]
Type=1
Class=CReportDlg
ControlCount=16
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_CPUINFO,button,1342242819
Control4=IDC_SYSTEMDETAILS,edit,1344344260
Control5=IDC_TESTERNAME,edit,1342242944
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SYSTEMNAME,edit,1342242944
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_INCLUDETESTERINFO,button,1342242819
Control11=IDC_BENCHRESULTS,button,1476460547
Control12=IDC_OSINFO,button,1342242819
Control13=IDC_MBINFO,button,1342242819
Control14=IDC_CACHEINFO,button,1342242819
Control15=IDC_CPUFEATURES,button,1342242819
Control16=IDC_PCIDEVS,button,1342242819

[CLS:CReportDlg]
Type=0
HeaderFile=ReportDlg.h
ImplementationFile=ReportDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CReportDlg

[CLS:CImageCtrl]
Type=0
HeaderFile=ImageCtrl.h
ImplementationFile=ImageCtrl.cpp
BaseClass=CStatic
Filter=W

[DLG:IDD_RESULTDLG_DIALOG]
Type=1
Class=CResultDlg
ControlCount=17
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_RESULT2,static,1342308352
Control4=IDC_RESULT,static,1342308354
Control5=IDOK,button,1342242827
Control6=IDC_BENCHDETAILS,button,1342242827
Control7=IDC_CPUINFO,button,1342242827
Control8=IDC_SAVE_PROJECT,button,1342242827
Control9=IDC_GRAPHOFRESULT,button,1342242827
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LBLRAMSCORE,static,1342308352
Control12=IDC_RAMSCORE,static,1342308352
Control13=IDC_BANNER,static,1342308352
Control14=IDC_RESULTCTRL,static,1342308352
Control15=IDC_STATIC,static,1342177287
Control16=IDC_BANNER2,static,1342308352
Control17=IDC_BANNER3,static,1342308352

[CLS:CResultDlg]
Type=0
HeaderFile=ResultDlg.h
ImplementationFile=ResultDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CResultDlg
VirtualFilter=dWC

[DLG:IDD_SPLASHDLG_DIALOG]
Type=1
Class=CSplashDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[CLS:CSplashDlg]
Type=0
HeaderFile=SplashDlg.h
ImplementationFile=SplashDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSplashDlg

