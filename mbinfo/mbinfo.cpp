// mbinfo.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "mbinfo.h"
#include <afxtempl.h>
#include "drvload.h"
#include "searchdlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CMbinfoApp

BEGIN_MESSAGE_MAP(CMbinfoApp, CWinApp)
	//{{AFX_MSG_MAP(CMbinfoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMbinfoApp construction

CMbinfoApp::CMbinfoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMbinfoApp object

CMbinfoApp theApp;


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


#define PCI_TYPE0_ADDRESSES             6
#define PCI_DEVICES_DETECTION			10


static struct _PCI_COMMON_CONFIG {
    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

    union {
        struct _PCI_HEADER_TYPE_0 {
            ULONG   BaseAddresses[PCI_TYPE0_ADDRESSES];
            ULONG   CIS;
            USHORT  SubVendorID;
            USHORT  SubSystemID;
            ULONG   ROMBaseAddress;
            ULONG   Reserved2[2];

            UCHAR   InterruptLine;      //
            UCHAR   InterruptPin;       // (ro)
            UCHAR   MinimumGrant;       // (ro)
            UCHAR   MaximumLatency;     // (ro)
        } type0;


    } u;

    UCHAR   DeviceSpecific[192];

} pcidata;




extern "C" DWORD PASCAL EXPORT GetPCIDevicesInformations(DeviceInfo** devices) {


	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	
	CArray<DeviceInfo*,DeviceInfo*> devs;


	DWORD rlen;
	unsigned long data[3];

	unsigned char bus;
	unsigned short fun;

	if(!(GetVersion()&0x80000000)) {

		LoadDriverNT Loader;

		Loader.Init("pciinfo","PCIINFO");

		Loader.CreateReg();
				
		Loader.Start();
			
		HANDLE pciinfo=CreateFile("\\\\.\\pciinfo",GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    
		if(pciinfo==INVALID_HANDLE_VALUE) {
			MessageBox(NULL,"Unable to access to the device driver: Motherboard informations unavailable. If this is the first time that you run CPUBench2002, please try to restart your PC.","CPUBench2002 Error",MB_OK | MB_ICONERROR);
			return 0;
		}

			
		data[0]=PCI_DEVICES_DETECTION; 

		for(bus=0;bus<2;bus++)
		{
			for(fun=0;fun<256;fun++)
			{
				data[1]=bus; //bus
				data[2]=fun; //slot
				if(DeviceIoControl(pciinfo,0,data,sizeof(data),&pcidata,sizeof(pcidata),&rlen,NULL))
				{
					if(rlen==256)
					{

						DeviceInfo *currDevice=new DeviceInfo;

						currDevice->VendorID=pcidata.VendorID;
						currDevice->DeviceID=pcidata.DeviceID;
						currDevice->LatencyTimer=pcidata.LatencyTimer;
						currDevice->RevID=pcidata.RevisionID;


						//cerco il produttore della periferica

						CDataSource dataSource;

						HRESULT	hr;

						USES_CONVERSION;

						hr = dataSource.OpenFromInitializationString(OLESTR("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=.\\definitions\\definitionsdata.mdb;"));

						if (FAILED(hr)){
							AfxMessageBox("Cannot open database connection.",MB_ICONERROR);
							strcpy(currDevice->Vendor,"unknow");
							return hr;
						}


						CSession session;

						hr=session.Open(dataSource);

						if(FAILED(hr)){
							AfxMessageBox("Session initialization failed.",MB_ICONERROR);
							strcpy(currDevice->Vendor,"unknow");
							return hr;
						}


						CCommand<CDynamicAccessor> cmd;

					
						CString query;
						query.Format("SELECT * FROM Device_vendors WHERE VendorID='%04Xh'",pcidata.VendorID);
	
						if(FAILED(cmd.Create(session,query))){
							AfxMessageBox("Error while init the Accessor.");
							strcpy(currDevice->Vendor,"unknow");
							return FALSE;
						}

						CDBPropSet	propset(DBPROPSET_ROWSET);
						propset.AddProperty(DBPROP_IRowsetChange, true);
						propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);


						if(FAILED(cmd.Open(&propset))){
							AfxMessageBox("Error while opening the Accessor.");
						strcpy(currDevice->Vendor,"unknow");
							return FALSE;
						}
						
						if(cmd.MoveLast() == S_OK)
							strcpy(currDevice->Vendor,CString((wchar_t*)cmd.GetValue("Vendor_name")));
						else strcpy(currDevice->Vendor,"unknow");

						cmd.Close();

						//cerco le info sulla periferica

						query.Format("SELECT * FROM Device_descriptors WHERE DeviceID='%04Xh'",pcidata.DeviceID);
	
						if(FAILED(cmd.Create(session,query))){
							AfxMessageBox("Error while init the Accessor.");
							strcpy(currDevice->Name,"unknow");
							return FALSE;
						}


						if(FAILED(cmd.Open(&propset))){
							AfxMessageBox("Error while opening the Accessor.");
						strcpy(currDevice->Name,"unknow");
							return FALSE;
						}
						
						if(cmd.MoveLast() == S_OK)
							strcpy(currDevice->Name,CString((wchar_t*)cmd.GetValue("DeviceName")));
						else strcpy(currDevice->Name,"unknow");

						cmd.Close();
						session.Close();
						dataSource.Close();
					
						devs.Add(currDevice);

				}
		}
	}
			
		}
	
		CloseHandle(pciinfo);
		Loader.Stop();

	}


	int size=devs.GetSize();

	for(int i=0; i<size && i< 20; i++){


		devices[i]=new DeviceInfo;

		devices[i]->VendorID=devs[i]->VendorID;
		devices[i]->DeviceID=devs[i]->DeviceID;
		devices[i]->LatencyTimer=devs[i]->LatencyTimer;
		devices[i]->RevID=devs[i]->RevID;

		strcpy(devices[i]->Vendor,devs[i]->Vendor);
		strcpy(devices[i]->Name,devs[i]->Name);

		delete devs[i];
	}

	return (size < 20) ? size : 20;


}

BOOL CMbinfoApp::InitInstance() 
{
	HRESULT hr=CoInitialize(NULL);

	if(FAILED(hr)){
		AfxMessageBox("Failed to initialize COM",MB_OK | MB_ICONERROR);
		return FALSE;
	}
	return CWinApp::InitInstance();
}

int CMbinfoApp::ExitInstance() 
{
	CoUninitialize();
	
	return CWinApp::ExitInstance();
}
