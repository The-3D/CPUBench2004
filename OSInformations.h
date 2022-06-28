// OSInformations.h: interface for the COSInformations class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OSINFORMATIONS_H__8F7A0E31_355B_4FD2_B81C_8F1706888E02__INCLUDED_)
#define AFX_OSINFORMATIONS_H__8F7A0E31_355B_4FD2_B81C_8F1706888E02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COSInformations  
{
public:
	COSInformations();
	virtual ~COSInformations();

	CString GetOSName(){ return m_OSName;}

	CString GetOSRevision(){

		CString str;

		str.Format("%d.%d.%d",m_MajorVer,m_MinorVer,BuildNumber);

		return str;
	}

	CString GetComputerName() { return PCName; }
	CString GetUserName() { return UserName; }
	CString GetMainDirectory() { return WindowsDirectory; }
	CString GetServicePack() { return OSServicePack; }
	CString GetStandByMode() { return StandByMode;	}
	CString GetBootMode() { return SysBootStatus; }
	CString GetScreenRes(){

		CString str;

		str.Format("%dx%dx%d",ScreenWidth,ScreenHeigth,ScreenColors);

		return str;
	}





private:
	short m_DOSMajorVer,m_DOSMinorVer;
	DWORD m_MajorVer,m_MinorVer,BuildNumber;
	int NumOfMonitors,ScreenWidth,ScreenHeigth,ScreenColors,StandByTimeout;
	CString m_OSName,OSServicePack,PCName,UserName,OSDirectory;
	CString SysBootStatus;
	CString WindowsDirectory,NetworkStatus;
	CString StandByMode;
	CString VideoCardName,VideoDriver;
	int VendorID,DeviceID,SubSysID;

};

#endif // !defined(AFX_OSINFORMATIONS_H__8F7A0E31_355B_4FD2_B81C_8F1706888E02__INCLUDED_)
