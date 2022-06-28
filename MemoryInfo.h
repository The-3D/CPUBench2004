// MemoryInfo.h: interface for the CMemoryInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMORYINFO_H__4FBEB746_3902_4A6F_86AD_577F1518A8F5__INCLUDED_)
#define AFX_MEMORYINFO_H__4FBEB746_3902_4A6F_86AD_577F1518A8F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMemoryInfo  
{
public:
	CMemoryInfo();
	CRAMInfo();
	CString GetRAMSize();
	CString GetRAMAvailable();
	CString GetVirtualSize();
	CString GetVirtualAvailable();
	CString GetPageFileSize();
	CString GetPageFileAvailable();
	CString GetRAMLoadPercent();
	CString GetMinAppAddress();
	CString GetMaxAppAddress();
	CString GetAllocationGranularity();
	int GetRAMAvailablePercent();
	int GetPageFileAvailablePercent();
	int GetVirtualAvailablePercent();
	int GetMemLoadPercent();
	virtual ~CMemoryInfo();

private:
    MEMORYSTATUS m_MemStatus;
	SYSTEM_INFO m_SysInfo;


};

#endif // !defined(AFX_MEMORYINFO_H__4FBEB746_3902_4A6F_86AD_577F1518A8F5__INCLUDED_)
