// MemoryInfo.cpp: implementation of the CMemoryInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "MemoryInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMemoryInfo::CMemoryInfo()
{
	GlobalMemoryStatus(&m_MemStatus);
	GetSystemInfo(&m_SysInfo);


}

CString CMemoryInfo::GetRAMSize() {

	CString str;

	str.Format("%d MByte",m_MemStatus.dwTotalPhys/(1024*1024)+1);

	return str;
}

CString CMemoryInfo::GetRAMAvailable() {

	CString str;

	str.Format("%d MB",m_MemStatus.dwAvailPhys/(1024*1024));

	return str;
}

int CMemoryInfo::GetRAMAvailablePercent() {

	return (int)(((float)m_MemStatus.dwAvailPhys/(float)m_MemStatus.dwTotalPhys)*100);
}

int CMemoryInfo::GetMemLoadPercent() {

	return m_MemStatus.dwMemoryLoad;
}

CString CMemoryInfo::GetVirtualSize() {

	CString str;

	str.Format("%d MByte",m_MemStatus.dwTotalVirtual/(1024*1024));

	return str;

}

CString CMemoryInfo::GetVirtualAvailable() {

	CString str;

	str.Format("%d MByte",m_MemStatus.dwAvailVirtual/(1024*1024));

	return str;
}


int CMemoryInfo::GetVirtualAvailablePercent(){

	return (int)(((float)m_MemStatus.dwAvailVirtual/(float)m_MemStatus.dwTotalVirtual)*100);
}



CString CMemoryInfo::GetPageFileAvailable() {

	CString str;

	str.Format("%d MByte",m_MemStatus.dwAvailPageFile/(1024*1024));

	return str;
}

CString CMemoryInfo::GetPageFileSize() {

	CString str;

	str.Format("%d MByte",m_MemStatus.dwTotalPageFile/(1024*1024));

	return str;

}

int CMemoryInfo::GetPageFileAvailablePercent() {



	return (int)(((float)m_MemStatus.dwAvailPageFile/(float)m_MemStatus.dwTotalPageFile)*100);
}



CString CMemoryInfo::GetMinAppAddress() {
	return (int)m_SysInfo.lpMinimumApplicationAddress;
}


CString CMemoryInfo::GetMaxAppAddress() {
	return (int)m_SysInfo.lpMaximumApplicationAddress;
}

CString CMemoryInfo::GetAllocationGranularity() {

	return m_SysInfo.dwAllocationGranularity;

}


CMemoryInfo::~CMemoryInfo()
{

}
