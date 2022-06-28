// DeviceInformations.cpp: implementation of the CDeviceInformations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "DeviceInformations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDeviceInformations::CDeviceInformations()
{

	
	typedef DWORD (CALLBACK* Get_PCIDevicesInformations)(DeviceInfo**);


	DeviceInfo **devices=new DeviceInfo*[20]; //l'array viene creato dalla DLL
	int size;

	HINSTANCE hLib=AfxLoadLibrary("mbinfo.dll");

	if(hLib==NULL){
		MessageBox(NULL,"Error loading CPU informations DLL. CPU informations are unavailable","Error",MB_OK | MB_ICONERROR);
		return;
	}


	Get_PCIDevicesInformations GetPCIDevicesInformations=(Get_PCIDevicesInformations)GetProcAddress(hLib,"GetPCIDevicesInformations");

	if(GetPCIDevicesInformations != NULL)
		size=GetPCIDevicesInformations(devices);
	else MessageBox(NULL,"Cannot detect CPU Vendor string","Error",MB_ICONWARNING);

	for(int i=0; i<size; i++){

		DeviceInfo d;

		d.DeviceID=devices[i]->DeviceID;
		strcpy(d.Name,devices[i]->Name);
		strcpy(d.Vendor,devices[i]->Vendor);
		d.VendorID=devices[i]->VendorID;
		d.RevID=devices[i]->RevID;
		d.LatencyTimer=devices[i]->LatencyTimer;

		m_devices.Add(d);

		//delete devices[i];
	}


	delete [] devices;


	AfxFreeLibrary(hLib);


	//prelevo i dati sul BIOS

	HKEY hKey;
	CString strDate,str,str2="";
	

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,"HARDWARE\\description\\system",0,KEY_QUERY_VALUE,&hKey) != ERROR_SUCCESS) return;
	
	unsigned long type=REG_MULTI_SZ;
	int d=MAX_PATH;
	if(RegQueryValueEx(hKey,"SystemBiosVersion",NULL,&type,(unsigned char*)str.GetBuffer(MAX_PATH),(unsigned long*)&d) != ERROR_SUCCESS) return;

	
	str.ReleaseBuffer(d);

	for(i=str.Find('\0'); i<str.GetLength()-1; i++)
		str2+=str.GetAt(i+1);




	m_BIOSName=str;
	m_BIOSVersion=str2;

	type=REG_SZ;
	if(RegQueryValueEx(hKey,"SystemBiosDate",NULL,&type,(unsigned char*)strDate.GetBuffer(MAX_PATH),(unsigned long*)&d) != ERROR_SUCCESS) return;
	
	
	m_BIOSDate=strDate;

	RegCloseKey(hKey);



}

CDeviceInformations::~CDeviceInformations()
{

}
