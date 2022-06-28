// ReportCreator.cpp: implementation of the CReportCreator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ReportCreator.h"
#include "cpuinformations.h"
#include "memoryinfo.h"
#include "deviceinformations.h"
#include "osinformations.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReportCreator::CReportCreator()
{

	m_DaysOfWeek=new CString[7];

	m_DaysOfWeek[0]="Sunday";
	m_DaysOfWeek[1]="Monday";
	m_DaysOfWeek[2]="Tuesday";
	m_DaysOfWeek[3]="Wednesday";
	m_DaysOfWeek[4]="Thursday";
	m_DaysOfWeek[5]="Friday";
	m_DaysOfWeek[6]="Saturday";
	
	m_testerInfo=m_osInfo=m_featuresInfo=m_cacheInfo=m_mbInfo=m_devListInfo=true;

}

CReportCreator::~CReportCreator()
{

	delete [] m_DaysOfWeek;

}

void CReportCreator::CreateReport(){



	   CCPUInformations cpuInfo;
	   CMemoryInfo memInfo;
	   COSInformations osInfo;
	   CDeviceInformations devInfo;

	   char tmp[300];
	   GetCurrentDirectory(300,tmp); //mi salvo la directory corrente in quanto viene cambiata successivamente dalla FileDialog	
	   
	   CFileDialog dialog(FALSE,".htm","report.htm",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		                  "HTML Files (*.HTM,*.HTML)|*.htm;*.html||");

	   if(dialog.DoModal() == IDCANCEL) return;


	   CString data;
	   
	   CTime t=CTime::GetCurrentTime();

	   CStdioFile file;
	   
	   

	   if(!file.Open((LPCTSTR)dialog.GetPathName(),CFile::modeWrite | CFile::modeCreate)) {
			
		   MessageBox(NULL,"Error: Cannot create report file","CPUBench2004 Error",MB_OK | MB_ICONWARNING);
	
			return;
	   
	   }
			
	   data.Format("Data reported on %02d:%02d:%02d, %s %02d/%02d/%04d",t.GetHour(),t.GetMinute(),t.GetSecond(),m_DaysOfWeek[t.GetDayOfWeek()-1],t.GetDay(),t.GetMonth(),t.GetYear());
	   

	   file.WriteString("<html><head><title>CPUBench2004 System informations report</title></head><body bgcolor=FFFFFF>\n");
	   file.WriteString("<font face=Tahoma color=FFFFFF><table border=0 width=100% cellspacing=0 cellpadding=5>\n");
	   file.WriteString("<tr align=left><td><p><big><b><font size=\"5\" face=\"Arial\" color=000000>CPUBench2004 report</FONT></b></big></p><hr width=100%></td></tr>\n");
	   file.WriteString("<tr align=left><td><p><big><b><font size=\"3\" face=\"Arial\" color=000000>"+data+"</FONT></big></p></td></b></tr></table>");
       
	   if(m_testerInfo) {

         file.WriteString("<br><br>"); 
         file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" width=\"80%\" cellspacing=\"0\"><tr><td height=\"40\" width=\"654\" colspan=\"2\" bgcolor=\"#000080\">"); 
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">Tester informations</font></td></tr></p>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">Tester Name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+m_testerName+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">System Name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+m_systemName+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">System Details:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+m_systemDetails+"</font></font></td></tr></table></div>");
		 file.WriteString("<br><br>");
	   }
	   if(m_cpuInfo) {
	
	     file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">CPU Informations</font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCPUName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Codename:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCodeName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Brand string:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetBrandString()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">Vendor ID:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetVendorString()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Frequency Range:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetFrequencyRange()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">Current Frequency:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCPUFrequency()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">Family, model, stepping:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCPUFeatures()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Platform:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetSocketName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">Bus type:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetBusType()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">L1 data cache:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1DCache()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">L1 Instruction cache:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1ICache()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">L2 cache:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2Cache()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"300\"><b><font size=\"3\" face=\"Arial\">CPU Frequency ratio:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"400\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetMultiplier()+"</font></font></td></tr></table></div>");
	     file.WriteString("<br><br>");
	   
	   }

	   if(m_featuresInfo) {
	
	     file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">CPU features informations</font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Built-in native x87 unit:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetFPUSupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Virtual mode extensions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetVirtualModeSupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Debugging extensions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetDebugExtSupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Page size extensions (4 MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetPageSizeExt()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Timestamp counter (with RDTSC):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetTimestamp()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">PAE (Page Address Extensions):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetPAEExt()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Machine check extensions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetMachineCheck()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">CMPXCHG8B instruction:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCMPXCHG8B()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Built-in APIC hardware:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetAPIC()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">SYSENTER/SYSEXIT functions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetSysEnterExit()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">MTRR (Memory Type Range Registers):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetMTRR()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Global paging extensions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetGlobalPaging()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Machine check architecture:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetMachineCheck()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Conditional move (CMOV) instruction:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCMOV()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">PSE-36:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetPSE36Support()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">MMX instructions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetMMXSupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Streaming SIMD extensions (SSE):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetSSESupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Streaming SIMD extensions 2 (SSE2):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetSSE2Support()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Streaming SIMD extensions 3 (SSE3):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetSSE3Support()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">AMD 3DNow! instruction set:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.Get3DNow()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">AMD 3DNow! instruction set:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.Get3DNow()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">AMD MMX instruction set extensions:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetXtendedMMX()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">HyperThreading technology:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetHTSupport()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">FXSAVE/FXRESTOR:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetFXSAVERESTOR()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">CLFLUSH instruction:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetCLFLUSH()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Long mode (AKA AMD64 extensions to x86):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetAMD64Support()+"</font></font></td></tr></table></div>");
		 file.WriteString("<br><br>");
	   
	   }


	   if(m_cacheInfo) {
	
	     file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">Cache informations</font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data cache size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1DCache()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data cache associativity:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data cache line size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_LineSize()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data cache lines per tag:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_LinesPerTag()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction cache size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1ICache()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction cache associativity:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_Associativity()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction cache line size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_LineSize()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction cache lines per tag:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_LinesPerTag()+"</font></font></td></tr>");
         file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data TLB associativity (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_TLB4M_Associativity()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data TLB entries (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_TLB4M_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction TLB associativity (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_TLB4M_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction TLB entries (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_TLB4M_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data TLB associativity (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_TLB4K_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Data TLB entries (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1D_TLB4K_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction TLB associativity(4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_TLB4K_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L1 Instruction TLB entries (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL1I_TLB4K_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Cache size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2Cache()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Cache associativity::</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2_Associativity()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Cache line size:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2_LineSize()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Cache lines per tag:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2_LinesPerTag()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Data TLB associativity (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2D_TLB4M_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Data TLB entries (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2D_TLB4M_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Instruction TLB associativity (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2I_TLB4M_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Instruction TLB entries (4MByte pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2I_TLB4M_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Data TLB associativity (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2D_TLB4K_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Data TLB entries (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2D_TLB4K_Entries()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Instruction TLB associativity (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2I_TLB4K_Associativity()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">L2 Instruction TLB entries (4K pages):</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetL2I_TLB4K_Entries()+"</font></font></td></tr></table></div>");
		 file.WriteString("<br><br>");
	   
	   }


	   if(m_osInfo) {
	
	     file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">Operating System informations</font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">OS name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetOSName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">OS revision:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetOSName()+"("+osInfo.GetOSRevision()+")"+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Service pack:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetServicePack()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">OS directory:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetMainDirectory()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Computer name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetComputerName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">User name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetUserName()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Boot mode:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetBootMode()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Standby mode:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetStandByMode()+"</font></font></td></tr>");
         file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Current resolution:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+osInfo.GetScreenRes()+"</font></font></td></tr></table></div>");
		 file.WriteString("<br><br>");
	   
	   }

	   if(m_mbInfo) {
	
	     file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
		 file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">Motherboard informations</font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Chipset name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetChipsetName()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Front Side Bus type:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetBusType()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Front Side Bus speed:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+cpuInfo.GetFSBSpeed()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Chipset vendor ID:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetChipsetVendorID()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Chipset vendor name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetChipsetVendor()+"</font></font></td></tr>");
	     file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">Chipset device ID:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetChipsetID()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">BIOS name:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetBIOSName()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">BIOS version:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetBIOSVersion()+"</font></font></td></tr>");
         file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">BIOS date:</font></b></td>");
         file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetBIOSDate()+"</font></font></td></tr>");
		 file.WriteString("<tr><td height=\"25\" width=\"375\"><b><font size=\"3\" face=\"Arial\">PCI bus latency:</font></b></td>");
		 file.WriteString("<td height=\"25\" width=\"325\"><font size=\"3\" face=\"Arial\">"+devInfo.GetChipsetPCILatency()+"</font></font></td></tr></table></div>");
		 file.WriteString("<br><br>");
	   
	   }

	   if(m_devListInfo) {
	
			file.WriteString("<div align=\"left\"><table border=\"1\" align=\"center\" height=\"100\" width=\"80%\" cellspacing=\"1\"><tr><td height=\"40\" width=\"654\" colspan=\"3\" bgcolor=\"#000080\">");
			file.WriteString("<p align=\"center\"><font size=\"4\" face=\"Arial\" color=\"#FFFFFF\">PCI Devices list</font></td></tr>");

			 
			for(int i=0; i<devInfo.GetNumOfDevices()*6; i+=6){

				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">Device name:</font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">"+devInfo.GetDeviceName(i/6)+"</font></font></td></tr>");
				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">Device Vendor name:</font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">"+devInfo.GetDeviceVendor(i/6)+"</font></font></td></tr>");
				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">Device ID:</font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">"+devInfo.GetDeviceID(i/6)+"</font></font></td></tr>");
				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">Device vendor ID:</font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">"+devInfo.GetDeviceVendorID(i/6)+"</font></font></td></tr>");
				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">Device PCI latency:</font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">"+devInfo.GetDevicePCILatency(i/6)+"</font></font></td></tr>");
				 file.WriteString("<tr><td height=\"25\" width=\"200\"><b><font size=\"3\" face=\"Arial\">   </font></b></td>");
				 file.WriteString("<td height=\"25\" width=\"500\"><font size=\"3\" face=\"Arial\">   </font></font></td></tr>");

			}
			file.WriteString("</table></div><br><br>");
   
	   }






	file.WriteString("</body></html>");

	file.Close();

	SetCurrentDirectory(tmp); //ripristino la directory corrente
	

}




