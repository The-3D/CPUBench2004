// ReportCreator.h: interface for the CReportCreator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REPORTCREATOR_H__888CB4F3_78C4_48F2_825F_DE984D778665__INCLUDED_)
#define AFX_REPORTCREATOR_H__888CB4F3_78C4_48F2_825F_DE984D778665__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CReportCreator  
{
public:
	CReportCreator();
	void CreateReport();
	void SetTesterName(CString testerName){

		m_testerName=testerName;
	}

	void SetSystemName(CString sysName){

		m_systemName=sysName;
	}

	void SetSystemDetails(CString sysDetails){

		m_systemDetails=sysDetails;

	}

	void IncludeTesterInfo(bool tInfo){

		m_testerInfo=tInfo;

	}

	void IncludeCPUInfo(bool cpuInfo){

		m_cpuInfo=cpuInfo;

	}

	void IncludeCacheInfo(bool cacheInfo){

		m_cacheInfo=cacheInfo;

	}

	void IncludeCPUFeaturesInfo(bool features){

		m_featuresInfo=features;

	}

	void IncludeOSInfo(bool bOS){

		m_osInfo=bOS;
	}

	virtual ~CReportCreator();


private:
	 CString *m_DaysOfWeek;
	 bool m_testerInfo;
	 bool m_cpuInfo;
	 bool m_osInfo;
	 bool m_featuresInfo;
	 bool m_cacheInfo;
	 bool m_mbInfo;
	 bool m_devListInfo;
	 CString m_testerName,m_systemName,m_systemDetails;


};

#endif // !defined(AFX_REPORTCREATOR_H__888CB4F3_78C4_48F2_825F_DE984D778665__INCLUDED_)
