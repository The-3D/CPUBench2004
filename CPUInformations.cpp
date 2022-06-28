// CPUInformations.cpp: implementation of the CCPUInformations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUInformations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCPUInformations::CCPUInformations()
{

	typedef DWORD (CALLBACK* Get_VendorString)(char*);
	typedef DWORD (CALLBACK* Get_CPUFeatures)(char*);
	typedef DWORD (CALLBACK* Get_CPUFrequency)(char*,char*,char*);
	typedef DWORD (CALLBACK* Get_CacheInfo)(CacheInfo*);
	typedef DWORD (CALLBACK* Get_BrandString)(char*);
	typedef DWORD (CALLBACK* Get_CPUModelDetails)(char*,char*,char*,char*,char*,char*,char*);
	typedef DWORD (CALLBACK* Get_HTSupport)(char*);
	typedef BOOL (CALLBACK* Has_MMX)();
	typedef BOOL (CALLBACK* Has_SSE)();
	typedef BOOL (CALLBACK* Has_SSE2)();
	typedef BOOL (CALLBACK* Has_SSE3)();
	typedef BOOL (CALLBACK* Has_AMD64)();
	typedef BOOL (CALLBACK* Has_PSE36)();


	HINSTANCE hLib=AfxLoadLibrary("cpuinfo.dll");

	if(hLib==NULL){
		MessageBox(NULL,"Error loading CPU informations DLL. CPU informations are unavailable","Error",MB_OK | MB_ICONERROR);
		return;
	}

	char* str=new char[100],*str2=new char[100],*str3=new char[100],*str4=new char[100],*str5=new char[100],*str6=new char[100],*str7=new char[100];


	Get_VendorString GetVendor=(Get_VendorString)GetProcAddress(hLib,"GetVendorString");

	if(GetVendor != NULL)
		GetVendor(str);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	
	m_Vendor=str;


	Get_CPUFeatures GetFeatures=(Get_CPUFeatures)GetProcAddress(hLib,"GetCPUFeatures");

	if(GetFeatures != NULL)
		GetFeatures(str);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	m_Features=str;

	Get_CPUFrequency GetFrequency=(Get_CPUFrequency)GetProcAddress(hLib,"GetCPUFrequency");

	if(GetFrequency != NULL)
		GetFrequency(str,str2,str3);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	m_CPUFreq=str;
	m_multiplier=str2;
	m_fsbFreq=str3;



	Get_CacheInfo GetCacheInfo=(Get_CacheInfo)GetProcAddress(hLib,"GetCacheInfo");

	if(GetCacheInfo != NULL)
		GetCacheInfo(&ci);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	FormatCacheValues();


	Get_BrandString GetBrandString=(Get_BrandString)GetProcAddress(hLib,"GetBrandString");

	if(GetBrandString != NULL)
		GetBrandString(str);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	m_BrandName=str;

	m_BrandName.TrimLeft();

	Get_CPUModelDetails GetCPUModelDetails=(Get_CPUModelDetails)GetProcAddress(hLib,"GetCPUModelDetails");

	if(GetCPUModelDetails != NULL)
		GetCPUModelDetails(str,str2,str3,str4,str5,str6,str7);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	m_socketName=str;
	m_busType=str2;
	m_codeName=str3;
	m_cpuName=str4;
	m_logoName=str5;
	m_defVcore=str6;
	m_freqRange=str7;



	Get_HTSupport GetHTSupport=(Get_HTSupport)GetProcAddress(hLib,"GetHTSupport");

	if(GetHTSupport != NULL)
		GetHTSupport(str);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	
	m_HTSupport=str;


	Has_MMX HasMMX=(Has_MMX)GetProcAddress(hLib,"HasMMX");

	if(HasMMX != NULL){
		if(HasMMX())
			m_MMX="detected";
		else m_MMX="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	
	
	Has_SSE HasSSE=(Has_SSE)GetProcAddress(hLib,"HasSSE");

	if(HasSSE != NULL){
		if(HasSSE())
			m_SSE="detected";
		else m_SSE="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	
	
	Has_SSE2 HasSSE2=(Has_SSE2)GetProcAddress(hLib,"HasSSE2");

	if(HasSSE2 != NULL){
		if(HasSSE2())
			m_SSE2="detected";
		else m_SSE2="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	Has_SSE3 HasSSE3=(Has_SSE3)GetProcAddress(hLib,"HasSSE3");

	if(HasSSE3 != NULL){
		if(HasSSE3())
			m_SSE3="detected";
		else m_SSE3="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	
	Has_AMD64 HasAMD64=(Has_AMD64)GetProcAddress(hLib,"HasAMD64");

	if(HasAMD64 != NULL){
		if(HasAMD64())
			m_AMD64="detected";
		else m_AMD64="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	
	Has_PSE36 HasPSE36=(Has_PSE36)GetProcAddress(hLib,"HasPSE36");

	if(HasPSE36 != NULL){
		if(HasPSE36())
			m_PSE36="detected";
		else m_PSE36="not detected";
	}
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);
	

	InitCPUFeatures(hLib);

	delete [] str;
	delete [] str2;
	delete [] str3;
	delete [] str4;
	delete [] str5;
	
	AfxFreeLibrary(hLib);


}


void CCPUInformations::FormatCacheValues(){

	if(ci.L1DCache != 0) m_L1D.Format("%d Kbyte",ci.L1DCache);
		else m_L1D="Absent";

	if(ci.L1ICache != 0) m_L1I.Format("%d Kbyte",ci.L1ICache);
		else m_L1I="Absent";

	if(ci.L2Cache != 0) m_L2.Format("%d Kbyte",ci.L2Cache);
		else m_L2="Absent";

	if(ci.traceSize != 0) m_TraceCache.Format("%d microOPS",ci.traceSize);
		else m_TraceCache="Absent";



	switch(ci.L1D_ass){

	case 0:
		m_L1D_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1D_ass="full";
		break;
	default:			
		m_L1D_ass.Format("%d way",ci.L1D_ass);

	}


	if(ci.L1D_lineSize != 0) m_L1D_lineSize.Format("%d byte",ci.L1D_lineSize);
		else m_L1D_lineSize="Unknow";

	if(ci.L1D_linesPerTag != 0) m_L1D_linesPerTag.Format("%d lines",ci.L1D_linesPerTag);
		else m_L1D_linesPerTag="Unknow";


	switch(ci.L1I_ass){

	case 0:
		m_L1I_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1I_ass="full";
		break;
	default:			
		m_L1I_ass.Format("%d way",ci.L1I_ass);

	}


	if(ci.L1I_lineSize != 0) m_L1I_lineSize.Format("%d byte",ci.L1I_lineSize);
		else m_L1D_lineSize="Unknow";

	if(ci.L1I_linesPerTag != 0) m_L1I_linesPerTag.Format("%d lines",ci.L1I_linesPerTag);
		else m_L1I_linesPerTag="Unknow";


	switch(ci.L2_ass){

	case 0:
		m_L2_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L2_ass="full";
		break;
	default:			
		m_L2_ass.Format("%d way",ci.L2_ass);

	}


	if(ci.L2_lineSize != 0) m_L2_lineSize.Format("%d byte",ci.L2_lineSize);
		else m_L2_lineSize="Unknow";

	if(ci.L2_linesPerTag != 0) m_L2_linesPerTag.Format("%d lines",ci.L2_linesPerTag);
		else m_L2_linesPerTag="Unknow";


	switch(ci.L1I_TLB4M_ass){

	case 0:
		m_L1I_TLB4M_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1I_TLB4M_ass="full";
		break;
	default:			
		this->m_L1I_TLB4M_ass.Format("%d way",ci.L1I_TLB4M_ass);

	}
		 

	if(ci.L1I_TLB4M_entries != 0) this->m_L1I_TLB4M_entries.Format("%d entries",ci.L1I_TLB4M_entries);
		else m_L1I_TLB4M_entries="Unknow";


	switch(ci.L1D_TLB4M_ass){

	case 0:
		m_L1D_TLB4M_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1D_TLB4M_ass="full";
		break;
	default:			
		m_L1D_TLB4M_ass.Format("%d way",ci.L1D_TLB4M_ass);

	}

	if(ci.L1D_TLB4M_entries != 0) this->m_L1D_TLB4M_entries.Format("%d entries",ci.L1D_TLB4M_entries);
		else m_L1D_TLB4M_entries="Unknow";



	switch(ci.L1I_TLB4K_ass){

	case 0:
		m_L1I_TLB4K_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1I_TLB4K_ass="full";
		break;
	default:			
		this->m_L1I_TLB4K_ass.Format("%d way",ci.L1I_TLB4K_ass);

	}
		 

	if(ci.L1I_TLB4K_entries != 0) this->m_L1I_TLB4K_entries.Format("%d entries",ci.L1I_TLB4K_entries);
		else m_L1I_TLB4K_entries="Unknow";


	switch(ci.L1D_TLB4K_ass){

	case 0:
		m_L1D_TLB4K_ass="Unknow";
		break;
	case 0x00FFFFFF:
		m_L1D_TLB4K_ass="full";
		break;
	default:			
		m_L1D_TLB4K_ass.Format("%d way",ci.L1D_TLB4K_ass);

	}

	if(ci.L1D_TLB4K_entries != 0) this->m_L1D_TLB4K_entries.Format("%d entries",ci.L1D_TLB4K_entries);
		else m_L1D_TLB4K_entries="Unknow";





	switch(ci.L2I_TLB4M_ass){

	case -1:
		m_L2I_TLB4M_ass="unknow";
	case 0:
		m_L2I_TLB4M_ass="off";
		break;
	case 1:
		m_L2I_TLB4M_ass="direct mapped";
	case 0x00FFFFFF:
		m_L2I_TLB4M_ass="full";
		break;
		m_L2I_TLB4M_ass.Format("%d way",ci.L2I_TLB4M_ass);

	}
		 

	if(ci.L2I_TLB4M_entries != 0) this->m_L2I_TLB4M_entries.Format("%d entries",ci.L2I_TLB4M_entries);
		else m_L2I_TLB4M_entries="Unknow";


	switch(ci.L2D_TLB4M_ass){

	case -1:
		m_L2D_TLB4M_ass="unknow";
	case 0:
		m_L2D_TLB4M_ass="off";
		break;
	case 1:
		m_L2D_TLB4M_ass="direct mapped";
	case 0x00FFFFFF:
		m_L2D_TLB4M_ass="full";
		break;
	default:			
		m_L2D_TLB4M_ass.Format("%d way",ci.L2D_TLB4M_ass);

	}

	if(ci.L2D_TLB4M_entries != 0) this->m_L2D_TLB4M_entries.Format("%d entries",ci.L2D_TLB4M_entries);
		else m_L2D_TLB4M_entries="Unknow";



	switch(ci.L2I_TLB4K_ass){

	case -1:
		m_L2I_TLB4K_ass="unknow";
	case 0:
		m_L2I_TLB4K_ass="off";
		break;
	case 1:
		m_L2I_TLB4K_ass="direct mapped";
	case 0x00FFFFFF:
		m_L2I_TLB4K_ass="full";
		break;
	default:			
		this->m_L2I_TLB4K_ass.Format("%d way",ci.L2I_TLB4K_ass);

	}
		 

	if(ci.L2I_TLB4K_entries != 0) this->m_L2I_TLB4K_entries.Format("%d entries",ci.L2I_TLB4K_entries);
		else m_L2I_TLB4K_entries="Unknow";


	switch(ci.L2D_TLB4K_ass){

	case -1:
		m_L2D_TLB4K_ass="unknow";
	case 0:
		m_L2D_TLB4K_ass="off";
		break;
	case 1:
		m_L2D_TLB4K_ass="direct mapped";
	case 0x00FFFFFF:
		m_L2D_TLB4K_ass="full";
		break;
	default:			
		m_L2D_TLB4K_ass.Format("%d way",ci.L2D_TLB4K_ass);

	}

	if(ci.L2D_TLB4K_entries != 0) this->m_L2D_TLB4K_entries.Format("%d entries",ci.L2D_TLB4K_entries);
		else m_L2D_TLB4K_entries="Unknow";



}


void CCPUInformations::InitCPUFeatures(HINSTANCE hLib){


	typedef BOOL (CALLBACK* Has_Feature)();
	
	Has_Feature HasFPU=(Has_Feature)GetProcAddress(hLib,"HasFPU");

	if(HasFPU != NULL){
		if(HasFPU())
			m_HasFPU="detected";
		else m_HasFPU="not detected";
	}

	Has_Feature HasVirtualMode=(Has_Feature)GetProcAddress(hLib,"HasVirtualMode");

	if(HasVirtualMode != NULL){
		if(HasVirtualMode())
			m_HasVirtualMode="detected";
		else m_HasVirtualMode="not detected";
	}

	Has_Feature HasDebugExt=(Has_Feature)GetProcAddress(hLib,"HasDebugExt");

	if(HasDebugExt != NULL){
		if(HasDebugExt())
			m_HasDebugExt="detected";
		else m_HasDebugExt="not detected";
	}

	Has_Feature HasPageSizeExt=(Has_Feature)GetProcAddress(hLib,"HasPageSizeExt");

	if(HasPageSizeExt != NULL){
		if(HasPageSizeExt())
			m_HasPageSizeExt="detected";
		else m_HasPageSizeExt="not detected";
	}
	Has_Feature HasTimestamp=(Has_Feature)GetProcAddress(hLib,"HasTimestamp");

	if(HasTimestamp != NULL){
		if(HasTimestamp())
			m_HasTimestamp="detected";
		else m_HasTimestamp="not detected";
	}


	Has_Feature HasPAE=(Has_Feature)GetProcAddress(hLib,"HasPAE");

	if(HasPAE != NULL){
		if(HasPAE())
			m_HasPAE="detected";
		else m_HasPAE="not detected";
	}


	Has_Feature HasMachineCheck=(Has_Feature)GetProcAddress(hLib,"HasMachineCheck");

	if(HasMachineCheck != NULL){
		if(HasMachineCheck())
			m_HasMachineCheck="detected";
		else m_HasMachineCheck="not detected";
	}

	Has_Feature HasCMPXCHG8B=(Has_Feature)GetProcAddress(hLib,"HasCMPXCHG8B");

	if(HasCMPXCHG8B != NULL){
		if(HasCMPXCHG8B())
			m_HasCMPXCHG8B="detected";
		else m_HasCMPXCHG8B="not detected";
	}

	Has_Feature HasAPIC=(Has_Feature)GetProcAddress(hLib,"HasAPIC");

	if(HasAPIC != NULL){
		if(HasAPIC())
			m_HasAPIC="detected";
		else m_HasAPIC="not detected";
	}

	Has_Feature HasSysEnterExit=(Has_Feature)GetProcAddress(hLib,"HasSysEnterExit");

	if(HasSysEnterExit != NULL){
		if(HasSysEnterExit())
			m_HasSysEnterExit="detected";
		else m_HasSysEnterExit="not detected";
	}


	Has_Feature HasMTRR=(Has_Feature)GetProcAddress(hLib,"HasMTRR");

	if(HasMTRR != NULL){
		if(HasMTRR())
			m_HasMTRR="detected";
		else m_HasMTRR="not detected";
	}


	Has_Feature HasGlobalPagingExt=(Has_Feature)GetProcAddress(hLib,"HasGlobalPagingExt");

	if(HasGlobalPagingExt != NULL){
		if(HasGlobalPagingExt())
			m_HasGlobalPagingExt="detected";
		else m_HasGlobalPagingExt="not detected";
	}

	Has_Feature HasCMOV=(Has_Feature)GetProcAddress(hLib,"HasCMOV");

	if(HasCMOV != NULL){
		if(HasCMOV())
			m_HasCMOV="detected";
		else m_HasCMOV="not detected";
	}

	Has_Feature HasCLFLUSH=(Has_Feature)GetProcAddress(hLib,"HasCLFLUSH");

	if(HasCLFLUSH != NULL){
		if(HasCLFLUSH())
			m_HasCLFLUSH="detected";
		else m_HasCLFLUSH="not detected";
	}

	Has_Feature HasFXSAVERESTOR=(Has_Feature)GetProcAddress(hLib,"HasFXSAVERESTOR");

	if(HasFXSAVERESTOR != NULL){
		if(HasFXSAVERESTOR())
			m_HasFXSAVERESTOR="detected";
		else m_HasFXSAVERESTOR="not detected";
	}

	Has_Feature Has3DNow=(Has_Feature)GetProcAddress(hLib,"Has3DNow");

	if(Has3DNow != NULL){
		if(Has3DNow())
			m_Has3DNow="detected";
		else m_Has3DNow="not detected";
	}

	Has_Feature HasXtended3DNow=(Has_Feature)GetProcAddress(hLib,"HasXtended3DNow");

	if(HasXtended3DNow != NULL){
		if(HasXtended3DNow())
			m_HasXtended3DNow="detected";
		else m_HasXtended3DNow="not detected";
	}

	Has_Feature HasXtendedMMX=(Has_Feature)GetProcAddress(hLib,"HasXtendedMMX");

	if(HasXtendedMMX != NULL){
		if(HasXtendedMMX())
			m_HasXtendedMMX="detected";
		else m_HasXtendedMMX="not detected";
	}

}

CCPUInformations::~CCPUInformations()
{

}
