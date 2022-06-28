// OSInformations.cpp: implementation of the COSInformations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "OSInformations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define CMONITORS 80

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COSInformations::COSInformations()
{
	OSVERSIONINFO OSver;
	OSVERSIONINFO OSverEx;
	OSver.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
	OSverEx.dwOSVersionInfoSize=sizeof(OSVERSIONINFOEX);
	
	GetVersionEx(&OSver); //informazioni sull'OS
		//rilevo la versione dell'OS

    switch(OSver.dwMajorVersion) {
	case 3:
		m_OSName="Microsoft Windows 95";
		break;
	case 4:
		switch(OSver.dwMinorVersion) {
		case 00:
			m_OSName="Microsoft Windows NT 4.0";
			break;
		case 10:
			m_OSName="Microsoft Windows 98";
			break;
		case 90:
			m_OSName="Microsoft Windows ME";
			break;
		default:
			m_OSName="MS Windows 4.0";
		}
		break;
	case 5:
		GetVersionEx(&OSverEx);
		
		BuildNumber=OSverEx.dwBuildNumber;
		OSServicePack=OSverEx.szCSDVersion;
		if(OSServicePack == "") OSServicePack="none installed";

		switch(OSver.dwMinorVersion) {

        case 0:
			m_OSName="Microsoft Windows 2000";
		break;
		case 1:
			m_OSName="Microsoft Windows XP";
		break;

		default:
			m_OSName="Next generation windows";
		break;

		}
		break;
	default:
        m_OSName="Next Generation Windows";
	}

	m_MajorVer=OSverEx.dwMajorVersion;
	m_MinorVer=OSverEx.dwMinorVersion;

    
	char* str=new char[128];
	DWORD size=128;
	::GetComputerName(str,&size);
	PCName=str;

	size=128;
	::GetUserName(str,&size);
	UserName=str;

	
	::GetSystemDirectory(str,128);

	OSDirectory=str;

	::GetWindowsDirectory(str,128);

	WindowsDirectory=str;

	switch(GetSystemMetrics(SM_CLEANBOOT)) {
	
	case 0:
		SysBootStatus="Normal Boot";
		break;
	case 1:
		SysBootStatus="Fail Safe boot";
		break;
	case 2:
		SysBootStatus="Fail Safe with Network";
		break;

	}


	NumOfMonitors=GetSystemMetrics(CMONITORS);

	NetworkStatus=GetSystemMetrics(SM_NETWORK) & 1 ? "Detected" : "Not Detected";
	
	bool bMode;

	SystemParametersInfo(SPI_GETLOWPOWERACTIVE,0,&bMode,0);

	StandByMode= bMode ? "Enabled" : "Disabled";

	if(bMode){
		SystemParametersInfo(SPI_GETLOWPOWERTIMEOUT,0,&StandByTimeout,0);
		CString strTO;

		strTO.Format(" (at %d minute(s))",StandByTimeout/60);
		StandByMode+=strTO;

	}
	else StandByTimeout=0;

	ScreenWidth=GetSystemMetrics(SM_CXSCREEN);
	ScreenHeigth=GetSystemMetrics(SM_CYSCREEN);

	CDC dc;
	dc.CreateCompatibleDC(NULL); //dev dc

	ScreenColors=GetDeviceCaps(dc,BITSPIXEL);


}

COSInformations::~COSInformations()
{

}
