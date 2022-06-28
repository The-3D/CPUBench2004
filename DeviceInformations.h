// DeviceInformations.h: interface for the CDeviceInformations class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEVICEINFORMATIONS_H__A2B1D943_02AE_4DD5_A01A_687982B2BD48__INCLUDED_)
#define AFX_DEVICEINFORMATIONS_H__A2B1D943_02AE_4DD5_A01A_687982B2BD48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>

typedef struct PCI_INFO {

	char Name[200];
	char Vendor[100];
	char MemRange[100];
	char Definition[200];
	int VendorID;
	int DeviceID;
	int RevID;
	int LatencyTimer;

} DeviceInfo;


class CDeviceInformations  
{
public:
	CDeviceInformations();

	CString GetChipsetName(){
		return (m_devices.GetSize() >0) ? m_devices[0].Name : "Unknow";
	}
	CString GetChipsetVendor(){
		return (m_devices.GetSize() >0) ? m_devices[0].Vendor : "Unknow";
	}
	CString GetChipsetID(){

		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("0x%04X",m_devices[0].DeviceID);
		else str="Not detected";
		return str;
	}

	CString GetChipsetVendorID(){
	
		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("0x%04X",m_devices[0].VendorID);
		else str="Not detected";
		return str;
	}

	CString GetChipsetPCILatency(){
	
		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("%d clocks",m_devices[0].LatencyTimer);
		else str="Not detected";

		return str;
	}


	int GetNumOfDevices(){ return m_devices.GetSize(); }


	CString GetDeviceName(int dev){

		ASSERT(m_devices.GetSize() > dev );

		return (m_devices.GetSize() >0) ? m_devices[dev].Name : "Unknow";
	}

	CString GetDeviceVendor(int dev){

		ASSERT(m_devices.GetSize() > dev );

		return (m_devices.GetSize() >0) ? m_devices[dev].Vendor : "Unknow";
	}

	CString GetDeviceID(int dev){

		ASSERT(m_devices.GetSize() > dev );

		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("0x%04X",m_devices[dev].DeviceID);
		else str="Not detected";
		return str;
	}

	CString GetDeviceVendorID(int dev){
		
		ASSERT(m_devices.GetSize() > dev );

		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("0x%04X",m_devices[dev].VendorID);
		else str="Not detected";
		return str;
	}

	CString GetDevicePCILatency(int dev){
	
		ASSERT(m_devices.GetSize() > dev );
		CString str;

		if(m_devices.GetSize() != 0)			
			str.Format("%d clocks",m_devices[dev].LatencyTimer);

		else str="Not detected";

		return str;
	}


	CString GetBIOSName(){ return m_BIOSName;}
	CString GetBIOSDate(){ return m_BIOSDate;}
	CString GetBIOSVersion(){ return m_BIOSVersion;}
	
	virtual ~CDeviceInformations();
	CArray<DeviceInfo,DeviceInfo&> m_devices;
	CString m_BIOSName,m_BIOSDate,m_BIOSVersion;


};

#endif // !defined(AFX_DEVICEINFORMATIONS_H__A2B1D943_02AE_4DD5_A01A_687982B2BD48__INCLUDED_)
