// cpuinfo.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "cpuinfo.h"
#include "drvload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PCI_DEVICES_DETECTION 10
#define CPU_CLOCK_MULTIPLIER_AMD_K7 11
#define CPU_CLOCK_MULTIPLIER_AMD_K8 12
#define CPU_CLOCK_MULTIPLIER_INTEL_WILLAMETTE 13
#define CPU_CLOCK_MULTIPLIER_INTEL_NORTHWOOD 14
#define CPU_CLOCK_MULTIPLIER_INTEL_PRESCOTT 15
#define CPU_CLOCK_MULTIPLIER_INTEL_BANIAS 16



/////////////////////////////////////////////////////////////////////////////
// CCpuinfoApp

BEGIN_MESSAGE_MAP(CCpuinfoApp, CWinApp)
	//{{AFX_MSG_MAP(CCpuinfoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCpuinfoApp construction

CCpuinfoApp::CCpuinfoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCpuinfoApp object

CCpuinfoApp theApp;


struct CacheInfo{

	int L1DCache,L1ICache,L2Cache;

	int L1D_ass,L1D_linesPerTag,L1D_lineSize;
	int L1I_ass,L1I_linesPerTag,L1I_lineSize;
	int L2_ass,L2_linesPerTag,L2_lineSize;
		
	int L1D_TLB4M_ass,L1D_TLB4M_entries;
	int L1D_TLB4K_ass,L1D_TLB4K_entries;
	int L1I_TLB4M_ass,L1I_TLB4M_entries;
	int L1I_TLB4K_ass,L1I_TLB4K_entries;

	int L2D_TLB4M_ass,L2D_TLB4M_entries;
	int L2D_TLB4K_ass,L2D_TLB4K_entries;
	int L2I_TLB4M_ass,L2I_TLB4M_entries;
	int L2I_TLB4K_ass,L2I_TLB4K_entries;


	int traceSize;

};


/********************************************

  Name: GetVendorString

  Description: retrive the CPU vendor name.

*********************************************/


extern "C" DWORD PASCAL EXPORT GetVendorString(char* Vendor){


	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString VendorString;

	BOOL isAMD=FALSE,isIntel=FALSE,isCyrix=FALSE,isIDT=FALSE,isRise=FALSE;
	__asm {
		mov eax,0; //standard eax=1
		cpuid;
		cmp ebx,'htuA';
		jne no_amd;
		cmp edx,'itne';
		jne no_amd;
		cmp ecx,'DMAc';
		jne no_amd;
		
		mov isAMD,TRUE;
no_amd:
	}
	if(isAMD) {
		VendorString="AuthenticAMD";
		strcpy(Vendor,VendorString);
		return 0;
	}
    	__asm {
		mov eax,0; //standard eax=1;
		cpuid;
		cmp ebx,'uneG';
		jne no_intel;
		cmp edx,'Ieni';
		jne no_intel;
		cmp ecx,'letn';
		jne no_intel;
		mov isIntel,TRUE;
no_intel:
	}
    if(isIntel) {
	  VendorString="GenuineIntel";
      strcpy(Vendor,VendorString);
	  return 0;

	}

	  	__asm {
		mov eax,0; //standard eax=1;
		cpuid;
		cmp ebx,'iryC';
		jne no_Cyrix;
		cmp edx,'snIx';
		jne no_Cyrix;
		cmp ecx,'daet';
		jne no_Cyrix;
		mov isCyrix,TRUE;
        no_Cyrix:
	}
    if(isCyrix) {
	  VendorString="CyrixInstead";
      strcpy(Vendor,VendorString);

	  return 0;
	}

	  	__asm {
		mov eax,0; //standard eax=1;
		cpuid;
		cmp ebx,'esiR';
		jne no_Rise;
		cmp edx,'esiR';
		jne no_Rise;
		cmp ecx,'esiR';
		jne no_Rise;
		mov isRise,TRUE;
no_Rise:
	}
    if(isRise) {
	  VendorString="RiseRiseRise";
      strcpy(Vendor,VendorString);
	  return 0;

	}

	//controllo se la CPU è IDT
	__asm {
		mov eax,0; //standard eax=1;
		cpuid;
		cmp ebx,'tneC';
		jne no_Rise;
		cmp edx,'Hrua';
		jne no_Rise;
		cmp ecx,'slua';
		jne no_Centaur;
		mov isRise,TRUE;
no_Centaur:
	}
    if(isIDT) {
	  VendorString="CentaurHauls";
  	  strcpy(Vendor,VendorString);
	  return 0;

	}
	
	VendorString="Unknown";
	strcpy(Vendor,VendorString);

	 return 0;
}


/***************************************************************

  Funzione: GetCPUFeatures

  Riconosce le principali features della CPU

****************************************************************/


extern "C" DWORD PASCAL EXPORT GetCPUFeatures(char* f) {

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString features;

	int family=0,model=0,step=0;


	__asm {

		mov eax,1; //standard eax=1
		cpuid;
		mov edx,eax; //conservo eax in edx ed ecx
		mov ecx,eax;
		and eax,0x0f; //ricavo lo stepping
		mov step,eax;
		mov eax,edx;
		shr edx,4;
		and edx,0x0f; //ricavo il model
		mov model,edx;
		shr ecx,8;
		and ecx,0x0f;
		mov family,ecx; //ricavo il family
		shr eax,12;
		and eax,0x0f;
	
		
	}


	features.Format("Family %X model %X step %X",family,model,step);

	strcpy(f,features);


	return 0;
	
}

/***************************************************************

  Funzione: GetCPUFeatures

  Riconosce le principali features della CPU - non esportabile
  - per uso interno 

****************************************************************/


void GetCPUFeaturesSpecific(int& f,int& m,int& s) {

	int family=0,model=0,step=0;


	__asm {

		mov eax,1; //standard eax=1
		cpuid;
		mov edx,eax; //conservo eax in edx ed ecx
		mov ecx,eax;
		and eax,0x0f; //ricavo lo stepping
		mov step,eax;
		mov eax,edx;
		shr edx,4;
		and edx,0x0f; //ricavo il model
		mov model,edx;
		shr ecx,8;
		and ecx,0x0f;
		mov family,ecx; //ricavo il family
		shr eax,12;
		and eax,0x0f;
	
		
	}

	f=family;
	m=model;
	s=step;
	
}

/**********************************************************
  
  Funzione:TimeStamp

  Rileva i ticks generati dal timestamp counter
  funzione di supporto a GetCPUFrequency() x calcolo della
  frequenza della CPU - per uso interno

***********************************************************/

inline ULONG TimeStamp()
{

	ULONG Tick;
	__asm {

		rdtsc;
		mov Tick,eax;
	}
	return (ULONG) Tick;
}


/****************************************************

  Funzione: GetMultiplier

  riconosce il moltiplicatore di frequenza della CPU



******************************************************/


void GetMultiplier(float& multiplier,float& fsbRatio){

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	multiplier=fsbRatio=0;

	CString Vendor;

	char v[100];

	GetVendorString(v);

	Vendor=v;

	int fam,mod,step;

	GetCPUFeaturesSpecific(fam,mod,step);

	if((GetVersion()&0x80000000))
		return;

		
	LoadDriverNT Loader;

	Loader.Init("pciinfo","PCIINFO");

	Loader.CreateReg();
			
	Loader.Start();

	HANDLE pciinfo=CreateFile("\\\\.\\pciinfo",GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	if(pciinfo==INVALID_HANDLE_VALUE){
		MessageBox(NULL,"Cannot detect CPU frequency ratio. This means that the CPU access device driver is not installed correctly (1).","Error",MB_ICONWARNING);
		return;
	}


	int data=0;
	ULONG msrval=0;
	ULONG rlen=0;
	int mapBit =0;
	int val;


	if(Vendor == "AuthenticAMD"){

		switch(fam){

		case 0x6:	//K7 generation MSRs
			data=CPU_CLOCK_MULTIPLIER_AMD_K7;
			if(!DeviceIoControl(pciinfo,0,&data,sizeof(data),&msrval,sizeof(msrval),&rlen,NULL)){
				MessageBox(NULL,"Cannot detect CPU frequency ratio. This means that the CPU access device driver is not installed correctly (2).","Error",MB_ICONWARNING);
				return;
			}


			//controllo se la cpu supporta i p-states

			//devo verificare se è abilitato il controllo del FID
			__asm {


				mov eax,0x80000007;
				cpuid;
				mov val, edx;
			}


			if(((val >> 1) & 1)){

				mapBit=0;
				msrval=msrval & 0xF;
			}
			else{
				
				mapBit=(msrval >> 19) & 1;
				msrval=(msrval >> 24 ) & 0xF;

			}
						
			switch(msrval) {

			case 0:
				multiplier=(mapBit) ? 25.0f : 11.0f;
				break;
			case 1:
				multiplier=(mapBit) ? 19.0f : 11.5f;
				break;
			case 2:
				multiplier=(mapBit) ? 26.0f : 12.0f;
				break;
			case 3:
				multiplier=(mapBit) ? 20.0f : 12.5f;
				break;
			case 4:
				multiplier=(mapBit) ? 13.0f : 5.0f;
				break;
			case 5:
				multiplier=(mapBit) ? 13.5f : 5.5f;
				break;
			case 6:
				multiplier=(mapBit) ? 14.0f : 6.0f;
				break;
			case 7:
				multiplier=(mapBit) ? 21.0f : 6.5f;
				break;
			case 8:
				multiplier=(mapBit) ? 15.0f : 7.0f;
				break;
			case 9:
				multiplier=(mapBit) ? 22.0f : 7.5f;
				break;
			case 10:
				multiplier=(mapBit) ? 16.0f : 8.0f;
				break;
			case 11:
				multiplier=(mapBit) ? 16.5f : 8.5f;
				break;
			case 12:
				multiplier=(mapBit) ? 17.0f : 9.0f;
				break;
			case 13:
				multiplier=(mapBit) ? 18.0f : 9.5f;
				break;
			case 14:
				multiplier=(mapBit) ? 23.0f : 10.0f;
				break;
			case 15:
				multiplier=(mapBit) ? 24.0f : 10.5f;
				break;
			}

			fsbRatio=2.0; //2xFSB speed

			break;

		

		case 0xF: // K8 generation MSRs
			fsbRatio=4;
			data=CPU_CLOCK_MULTIPLIER_AMD_K8;
			if(!DeviceIoControl(pciinfo,0,&data,sizeof(data),&msrval,sizeof(msrval),&rlen,NULL)){
				MessageBox(NULL,"Cannot detect CPU frequency ratio. This means that the CPU access device driver is not installed correctly (2).","Error",MB_ICONWARNING);
				return;
			}

			//devo verificare se è abilitato il controllo del FID
			__asm {


				mov eax,0x80000007;
				cpuid;
				mov val, edx;
			}


			if(((val >> 1) & 1))

				msrval=msrval & 0x3F; //00000000000000000000000000111111
			else
				msrval=msrval >>24 & 0x3F;
										
			switch(msrval) {

				case 0:
					multiplier=4;
					break;
				case 2:
					multiplier=5;
					break;
				case 4:
					multiplier=6;
					break;
				case 6:
					multiplier=7;
					break;
				case 8:
					multiplier=8;
					break;
				case 10:
					multiplier=9;
					break;
				case 12:
					multiplier=10;
					break;
				case 14:
					multiplier=11;
					break;
				case 16:
					multiplier=12;
					break;
				case 18:
					multiplier=13;
					break;
				case 20:
					multiplier=14;
					break;
				case 22:
					multiplier=15;
					break;
				case 24:
					multiplier=16;
					break;
				case 26:
					multiplier=17;
					break;
				case 28:
					multiplier=18;
					break;
				case 30:
					multiplier=19;
					break;
				case 32:
					multiplier=20;
					break;
				case 34:
					multiplier=21;
					break;
				case 36:
					multiplier=22;
					break;
				case 38:
					multiplier=23;
					break;
				case 40:
					multiplier=24;
					break;
				case 42:
					multiplier=25;
					break;

				}


			break;

			}

		}
		else if(Vendor == "GenuineIntel"){


			switch(fam){

			case 0x6: //detects only pentium M multiplier - checking for coerency

				if(mod >= 9){

					fsbRatio=4;
					data=CPU_CLOCK_MULTIPLIER_INTEL_BANIAS;

					if(!DeviceIoControl(pciinfo,0,&data,sizeof(data),&msrval,sizeof(msrval),&rlen,NULL)){
						MessageBox(NULL,"Cannot detect CPU frequency ratio. This means that the CPU access device driver is not installed correctly (2).","Error",MB_ICONWARNING);
						return;
					}
	
					multiplier = (msrval >> 22) & 0xF;
	
				}
				break;

			case 0xF:


				fsbRatio = 4;
				data=(mod >= 2) ? CPU_CLOCK_MULTIPLIER_INTEL_NORTHWOOD : CPU_CLOCK_MULTIPLIER_INTEL_WILLAMETTE;

				if(!DeviceIoControl(pciinfo,0,&data,sizeof(data),&msrval,sizeof(msrval),&rlen,NULL)){
					MessageBox(NULL,"Cannot detect CPU frequency ratio. This means that the CPU access device driver is not installed correctly (2).","Error",MB_ICONWARNING);
					return;
				}
				msrval = (mod >= 2) ? (msrval >> 24 ) & 0xFF : (msrval >> 8 ) & 0xF; 
				
				switch(msrval){
				
				case 0:
					multiplier=16.0f;
					break;
				case 1:
					multiplier=17.0f;
					break;
				case 2:
					multiplier=18.0f;
					break;
				case 3:
					multiplier=19.0f;
					break;
				case 4:
					multiplier=20.0f;
					break;
				case 5:
					multiplier=21.0f;
					break;
				case 6:
					multiplier=22.0f;
					break;
				case 7:
					multiplier=(mod >= 2 ) ? 23.0f : 24.0f;
					break;
				case 8:
					multiplier=8.0;
					break;
				case 9:
					multiplier=(mod >= 2 ) ? 9.0f : 23.0f;
					break;
				case 10:
					multiplier=10.0f;
					break;
				case 11:
					multiplier=11.0f;
					break;
				case 12:
					multiplier=12.0f;
					break;
				case 13:
					multiplier=13.0f;
					break;
				case 14:
					multiplier=14.0f;
					break;
				case 15:
					multiplier=15.0f;
					break;
				}


				break;
			}

		}


		CloseHandle(pciinfo);
		Loader.Stop();
	}

/**************************************************************
  
	Funzione: GetCPUFrequency()

    rileva la frequenza operativa x la CPU

***************************************************************/


DWORD PASCAL EXPORT GetCPUFrequency(char* cpuF,char* mult,char* fsb)
{

		AFX_MANAGE_STATE(AfxGetStaticModuleState());


		float mul,ratio;
		
		GetMultiplier(mul,ratio);

		if(mul == 0){
			strcpy(mult,"not detected");
			strcpy(fsb,"not detected");
		}

		CString cpuFreq;

		_LARGE_INTEGER pf,li0,li1;

		int ticks0,ticks1,dlt,dli;

		float pff,freq;



		 QueryPerformanceFrequency(&pf);
		 pff = (float)(pf.LowPart) / 1000000.0f;

		 QueryPerformanceCounter(&li0);

		 //rdtsc
		 _asm{
		  xor eax,eax
		  rdtsc
		  mov ticks0,eax
		 }

		 Sleep(10);

		 QueryPerformanceCounter(&li1);

		 // rdtsc
		 _asm{
		  xor eax,eax
		  rdtsc
		  mov ticks1,eax
		 }

		 dlt = ticks1-ticks0;
		 dli = li1.LowPart - li0.LowPart;


		freq = (float)dlt*pff / dli;


		cpuFreq.Format("%1.2f MHz (%1.2f GHz)",freq,freq/1000);

		strcpy(cpuF,cpuFreq);

		if(mul != 0){

			float fsbFreq=freq/mul;

			sprintf(fsb,"%1.2f MHz (%dx%1.2f MHz)",fsbFreq*ratio,(int)ratio,fsbFreq);
			sprintf(mult,"%1.1fx",mul);
		}


		return 0;			
}


/***********************************************************++

  Funzione: ControlIntelCacheDescriptors

  Analizza i descrittori della cache su CPU intel


  ***********************************************************/



void ControlIntelCacheDescriptors(int val,CacheInfo *ci){

	switch(val) {

	//controllo L1 Instruction Cache

		case 0x06:
			ci->L1ICache=8;
			ci->L1I_ass=4;
			ci->L1I_lineSize=32;
			ci->L1I_linesPerTag=0;
			break;

		case 0x08:
			ci->L1ICache=16;
			ci->L1I_ass=4;
			ci->L1I_lineSize=32;
			ci->L1I_linesPerTag=0;
			break;

		case 0x30:
			ci->L1ICache=32;
			ci->L1I_ass=8;
			ci->L1I_lineSize=64;
			ci->L1I_linesPerTag=0;
			break;
			
		//controllo L1 Data Cache
		case 10:
			ci->L1DCache=8;
			ci->L1D_ass=2;
			ci->L1D_lineSize=32;
			ci->L1D_linesPerTag=0;
			break;

		case 0x66:
			ci->L1DCache=8;
			ci->L1D_ass=4; 
			ci->L1D_lineSize=64;
			ci->L1D_linesPerTag=0;
			break;

		case 12:
			ci->L1DCache=16;
			ci->L1D_ass=4;
			ci->L1D_lineSize=32;
			ci->L1D_linesPerTag=0;
			break;

		case 0x67:
			ci->L1DCache=16;
			ci->L1D_ass=4;
			ci->L1D_lineSize=64;
			ci->L1D_linesPerTag=0;
			break;

		case 0x68:
			ci->L1DCache=32;
			ci->L1D_ass=4;
			ci->L1D_lineSize=64;
			ci->L1D_linesPerTag=0;
			break;

		case 0x2C:
			ci->L1DCache=32;
			ci->L1D_ass=8;
			ci->L1D_lineSize=64;
			ci->L1D_linesPerTag=0;
			break;

		//Controllo L2 Cache
		case 0x40:
			ci->L2Cache=0;
			ci->L2_ass=0;
			ci->L2_lineSize=0;
			ci->L2_linesPerTag=0;
			break;
		
		case 0x79:
			ci->L2Cache=128;
			ci->L2_ass=8;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;

		case 0x41:
			ci->L2Cache=128;
			ci->L2_ass=4;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x39:
			ci->L2Cache=128;
			ci->L2_ass=4;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;

		case 0x3B:
			ci->L2Cache=128;
			ci->L2_ass=2;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;
		
		case 0x7A:
			ci->L2Cache=256;
			ci->L2_ass=8;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;
		case 0x42:
			ci->L2Cache=256;
			ci->L2_ass=4;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x82:
			ci->L2Cache=256;
			ci->L2_ass=8;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;
	
		case 0x43:
			ci->L2Cache=512;
			ci->L2_ass=4;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x7B:
			ci->L2Cache=512;
			ci->L2_ass=8;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;

		case 0x83:
			ci->L2Cache=512;
			ci->L2_ass=8;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x86:
			ci->L2Cache=512;
			ci->L2_ass=4;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;
		
		case 0x44:
			ci->L2Cache=1024;
			ci->L2_ass=4;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x7C:
			ci->L2Cache=1024;
			ci->L2_ass=8;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;

		case 0x84:
			ci->L2Cache=1024;
			ci->L2_ass=8;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x87:
			ci->L2Cache=1024;
			ci->L2_ass=8;
			ci->L2_lineSize=64;
			ci->L2_linesPerTag=0;
			break;

		case 0x45:
			ci->L2Cache=2048;
			ci->L2_ass=4;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		case 0x85:
			ci->L2Cache=2048;
			ci->L2_ass=8;
			ci->L2_lineSize=32;
			ci->L2_linesPerTag=0;
			break;

		//controllo L1 instruction TLB

		case 0x01:
			ci->L1I_TLB4K_ass=4;
			ci->L1I_TLB4K_entries=32;
			break;
		case 0x02:
			ci->L1I_TLB4M_ass=0x00FFFFFF; //fully associative
			ci->L1I_TLB4M_entries=32;
			break;

		case 0x50:
			ci->L1I_TLB4K_ass=0x00FFFFFF;
			ci->L1I_TLB4K_entries=64;
			ci->L1I_TLB4M_ass=0x00FFFFFF;
			ci->L1I_TLB4M_entries=64;
			break;

		case 0x51:
			ci->L1I_TLB4K_ass=0x00FFFFFF;
			ci->L1I_TLB4K_entries=128;
			ci->L1I_TLB4M_ass=0x00FFFFFF;
			ci->L1I_TLB4M_entries=128;
			break;

		case 0x52:
			ci->L1I_TLB4K_ass=0x00FFFFFF;
			ci->L1I_TLB4K_entries=256;
			ci->L1I_TLB4M_ass=0x00FFFFFF;
			ci->L1I_TLB4M_entries=256;
			break;

		case 0xB0:
			ci->L1I_TLB4K_ass=4;
			ci->L1I_TLB4K_entries=128;
			break;

		//controllo L1 data TLB

		case 0x03:
			ci->L1D_TLB4K_ass=4;
			ci->L1D_TLB4K_entries=64;
			break;
		case 0x04:
			ci->L1D_TLB4M_ass=4; //fully associative
			ci->L1D_TLB4M_entries=8;
			break;

		case 0x5B:
			ci->L1D_TLB4K_ass=0x00FFFFFF;
			ci->L1D_TLB4K_entries=64;
			ci->L1D_TLB4M_ass=0x00FFFFFF;
			ci->L1D_TLB4M_entries=64;
			break;

		case 0x5C:
			ci->L1D_TLB4K_ass=0x00FFFFFF;
			ci->L1D_TLB4K_entries=128;
			ci->L1D_TLB4M_ass=0x00FFFFFF;
			ci->L1D_TLB4M_entries=128;
			break;

		case 0x5D:
			ci->L1D_TLB4K_ass=0x00FFFFFF;
			ci->L1D_TLB4K_entries=256;
			ci->L1D_TLB4M_ass=0x00FFFFFF;
			ci->L1D_TLB4M_entries=256;
			break;

		case 0xB3:
			ci->L1D_TLB4K_ass=4;
			ci->L1D_TLB4K_entries=128;
			break;
	}

}



/***************************************************************

  Funzione: GetCacheInfo()

  Rileva le varie cache della CPU

****************************************************************/


extern "C" DWORD PASCAL EXPORT GetCacheInfo(CacheInfo *ci) {


	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int largest=0; //indica la + grande funzione che la CPU supporta
	int desc1,desc2;

	ZeroMemory(ci,sizeof(CacheInfo));
	
	int family,model,step;
	int temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

	GetCPUFeaturesSpecific(family,model,step);

	CString VendorString;

	char str[100];

	GetVendorString(str);

	VendorString=str;

	if(VendorString == "AuthenticAMD") {


		ci->traceSize=0;

		__asm{
			mov		eax,0x80000000			// special to amd
			mov		ebx,0
			mov		ecx,0
			mov		edx,0

			_emit	0x0f
			_emit	0xa2

			mov		largest,eax	

			mov		eax,0x80000005				// L1 CACHE
			mov		ebx,0
			mov		ecx,0
			mov		edx,0

			//CPUID
			_emit	0x0f
			_emit	0xa2
        
			mov     temp1,eax
			mov     temp2,ebx
			mov     temp3,ecx
			mov     temp4,edx  
		}

		if(largest >= 0x80000006)				
		{
			__asm
			{
				mov		eax,0x80000006			// L2 CACHE
				mov		ebx,0
				mov		ecx,0
				mov		edx,0

				_emit	0x0f
				_emit	0xa2

				mov temp5,eax;
				mov temp6,ebx;
				mov temp7,ecx;
				mov temp8,edx;
			}
		}
			else 
			{
				temp5=0;
				temp6=0;
				temp7=0;
				temp8=0;

		}
			
			

			//2 MByte - 4 MByte pages (L1 TLB)
			if(temp1 >> 24 & 0xFF == 0xFF) ci->L1D_TLB4M_ass=0x00FFFFFF;
			else
				ci->L1D_TLB4M_ass=(temp1>>24) & 0xFF;
			ci->L1D_TLB4M_entries=temp1 >> 16 & 0xFF;

			if(temp1 >>8 & 0xFF == 0xFF) ci->L1I_TLB4M_ass=0x00FFFFFF;
			else
			ci->L1I_TLB4M_ass=temp1 >>8 & 0xFF;
			ci->L1I_TLB4M_entries=temp1 & 0xFF;

			//4 KByte pages (L1 TLB)
			if(temp2 >> 24 & 0xFF == 0xFF) ci->L1D_TLB4K_ass=0x00FFFFFF;
			else 	ci->L1D_TLB4K_ass=temp2>>24 & 0xFF;
			ci->L1D_TLB4M_entries=temp2 >> 16 & 0xFF;

			if(temp2 >>8 & 0xFF == 0xFF) ci->L1I_TLB4K_ass=0x00FFFFFF;
			else
			ci->L1I_TLB4K_ass=temp2 >>8 & 0xFF ;

			ci->L1I_TLB4M_entries=temp2 & 0xFF;

			//L1 Data cache
			ci->L1DCache=temp3 >>24 & 0xFF;
			ci->L1D_ass=temp3 >> 16 & 0xFF;
			ci->L1D_linesPerTag=temp3 >> 8 & 0xFF;
			ci->L1D_lineSize=temp3 >> 0 & 0xFF;

			//L1 Instruction cache

			ci->L1ICache=temp4 >>24 & 0xFF;
			ci->L1I_ass=temp4 >> 16 & 0xFF;
			ci->L1I_linesPerTag=temp4 >> 8 & 0xFF;
			ci->L1I_lineSize=temp4 >> 0 & 0xFF;



			//L2 Cache/Instruction TLB 2 MByte/4 MByte pages
			switch(temp5 >>28 & 0xF ) {
			case 0:
				ci->L2D_TLB4M_ass=0;
				break;
			case 1:
				ci->L2D_TLB4M_ass=1;
				break;
			case 2:
				ci->L2D_TLB4M_ass=2;
				break;
			case 4:
				ci->L2D_TLB4M_ass=4;
				break;
			case 6:
				ci->L2D_TLB4M_ass=8;
				break;
			case 8:
				ci->L2D_TLB4M_ass=16;
				break;
			case 15:
				ci->L2D_TLB4M_ass=0x00FFFFFF;
				break;
			default:
				ci->L2D_TLB4M_ass=-1;
			}

			ci->L2D_TLB4M_entries=temp5 >> 16 & 0xFFF;

			switch(temp5 >>12 & 0xF ) {
			case 0:
				ci->L2I_TLB4M_ass=0;
				break;
			case 1:
				ci->L2I_TLB4M_ass=1;
				break;
			case 2:
				ci->L2I_TLB4M_ass=2;
				break;
			case 4:
				ci->L2I_TLB4M_ass=4;
				break;
			case 6:
				ci->L2I_TLB4M_ass=8;
				break;
			case 8:
				ci->L2I_TLB4M_ass=16;
				break;
			case 15:
				ci->L2I_TLB4M_ass=0x00FFFFFF;
				break;
			default:
				ci->L2I_TLB4M_ass=-1;
			}

			ci->L2I_TLB4M_entries=temp5 >> 0 & 0xFFF;
	
			//L2 Cache/Instruction TLB 4K pages
  			switch(temp6 >>28 & 0xF ) {
			case 0:
				ci->L2D_TLB4K_ass=0;
				break;
			case 1:
				ci->L2D_TLB4K_ass=1;
				break;
			case 2:
				ci->L2D_TLB4K_ass=2;
				break;
			case 4:
				ci->L2D_TLB4K_ass=4;
				break;
			case 6:
				ci->L2D_TLB4K_ass=8;
				break;
			case 8:
				ci->L2D_TLB4K_ass=16;
				break;
			case 15:
				ci->L2D_TLB4K_ass=0x00FFFFFF;
				break;
			default:
				ci->L2D_TLB4M_ass=-1;
			}	
			
				
			ci->L2D_TLB4K_entries=temp6 >> 16 & 0xFFF;


			//verifico l'associatività del TLB
			switch(temp6 >>12 & 0xF ) {
			case 0:
				ci->L2I_TLB4K_ass=0;
				break;
			case 1:
				ci->L2I_TLB4K_ass=1;
				break;
			case 2:
				ci->L2I_TLB4K_ass=2;
				break;
			case 4:
				ci->L2I_TLB4K_ass=4;
				break;
			case 6:
				ci->L2I_TLB4K_ass=8;
				break;
			case 8:
				ci->L2I_TLB4K_ass=16;
				break;
			case 15:
				ci->L2I_TLB4K_ass=0x00FFFFFF;
				break;
			default:
				ci->L2I_TLB4K_ass=-1;
			}

			ci->L2I_TLB4K_entries=temp6 >> 0 & 0xFFF;


			//cache l2
			//L2 Cache associativity


       		switch(temp7 >>12 & 0xF ) {
			case 0:
				ci->L2_ass=0;
				break;
			case 1:
				ci->L2_ass=1;
				break;
			case 2:
				ci->L2_ass=2;
				break;
			case 4:
				ci->L2_ass=4;
				break;
			case 6:
				ci->L2_ass=8;
				break;
			case 8:
				ci->L2_ass=16;
				break;
			case 15:
				ci->L2_ass=0x00FFFFFF;
				break;
			default:
				ci->L2_ass=-1;
			}
			
			ci->L2Cache=temp7 >> 16;
			ci->L2_linesPerTag=temp7 >> 8 & 0xF;
			ci->L2_lineSize=temp7 >> 0 & 0xFF;
	}
	else if(VendorString=="GenuineIntel") {
	    
		   if(family==15) ci->traceSize=12;  //se è un P4
		   else ci->traceSize=0;
		  
		__asm {
					mov eax,2; //funzione standard eax=2
					cpuid;
					mov desc1,eax;
					mov desc2,edx;
		}

		//analizzo i cache descriptor

		for(int i=0; i<=24; i+=8){

			int val=(desc1 >> i) & 0xFF;

			ControlIntelCacheDescriptors(val,ci);
		}

		for(i=0; i<=24; i+=8){

			int val=(desc2 >> i) & 0xFF;

			ControlIntelCacheDescriptors(val,ci);
		}


		return 0;


	}


 //errore! CPU sconosciuta

	return 0;
}  



DWORD PASCAL EXPORT GetBrandString(char* brandString){



	char data[49];

	strcpy(data,"not supported");

	__asm{


		mov eax,80000000h;
		cpuid;
		cmp eax,80000004h;
		jl not_supported;


		mov eax,80000002h;
		cpuid;
	
		mov DWORD PTR[data],eax;
		mov DWORD PTR[data+4],ebx;
		mov DWORD PTR[data+8],ecx;
		mov DWORD PTR[data+12],edx;
		mov eax,80000003h;
		cpuid;

		mov DWORD PTR[data+16],eax;
		mov DWORD PTR[data+20],ebx;
		mov DWORD PTR[data+24],ecx;
		mov DWORD PTR[data+28],edx;
		mov eax,80000004h;
		cpuid;

		mov DWORD PTR[data+32],eax;
		mov DWORD PTR[data+36],ebx;
		mov DWORD PTR[data+40],ecx;
		mov DWORD PTR[data+44],edx;

not_supported:

	}


	strcpy(brandString,data);


	return 0;

}

extern "C" DWORD PASCAL EXPORT GetCPUModelDetails(char* sName,char* busType,char* codeName,char* cpuName,char* cpuLogo,char* defVcore,char* freqRange){

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CDataSource dataSource;

	HRESULT	hr;

	USES_CONVERSION;

	hr = dataSource.OpenFromInitializationString(OLESTR("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=.\\definitions\\definitionsdata.mdb;"));

	if (FAILED(hr)){
		AfxMessageBox("Cannot open database connection.",MB_ICONERROR);
		strcpy(cpuName,"unknow");
		strcpy(sName,"unknow");
		strcpy(busType,"unknow");
		strcpy(codeName,"unknow");
		strcpy(cpuLogo,"unknow");
		strcpy(defVcore,"unknow");
		strcpy(freqRange,"unknow");

		return hr;
	}


	CSession session;

	hr=session.Open(dataSource);

	if(FAILED(hr)){

		AfxMessageBox("Session initialization failed.",MB_ICONERROR);
		strcpy(cpuName,"unknow");
		strcpy(sName,"unknow");
		strcpy(busType,"unknow");
		strcpy(codeName,"unknow");
		strcpy(cpuLogo,"unknow");
		strcpy(defVcore,"unknow");
		strcpy(freqRange,"unknow");

		return hr;
	}


	CCommand<CDynamicAccessor> cmd;

	char vendor[100];

	GetVendorString(vendor);

	CString VendorString=vendor;

	int fam,mod,step;

	GetCPUFeaturesSpecific(fam,mod,step);

	CString query;

	query.Format("SELECT * FROM CPUData WHERE signature = '0x%X%X'",fam,mod);

	query+=" AND vendorid = '"+VendorString+"'";


	if(FAILED(cmd.Create(session,query))){
		AfxMessageBox("Error while init the Accessor.");
		strcpy(cpuName,"unknow");
		strcpy(sName,"unknow");
		strcpy(busType,"unknow");
		strcpy(codeName,"unknow");
		strcpy(cpuLogo,"unknow");
		strcpy(defVcore,"unknow");
		strcpy(freqRange,"unknow");

		return FALSE;
	}

	CDBPropSet	propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);


	if(FAILED(cmd.Open(&propset))){
		AfxMessageBox("Error while opening the Accessor.");
		strcpy(cpuName,"unknow");
		strcpy(sName,"unknow");
		strcpy(busType,"unknow");
		strcpy(codeName,"unknow");
		strcpy(cpuLogo,"unknow");
		strcpy(defVcore,"unknow");
		strcpy(freqRange,"unknow");

		return FALSE;
	}
	
	if(cmd.MoveLast() == S_OK){

		strcpy(cpuName,CString((wchar_t*)cmd.GetValue("name")));
		strcpy(sName,CString((wchar_t*)cmd.GetValue("socketName")));
		strcpy(busType,CString((wchar_t*)cmd.GetValue("busType")));
		strcpy(codeName,CString((wchar_t*)cmd.GetValue("codename")));
		strcpy(cpuLogo,CString((wchar_t*)cmd.GetValue("logoName")));
		strcpy(defVcore,CString((wchar_t*)cmd.GetValue("defaultVoltage")));
		strcpy(freqRange,CString((wchar_t*)cmd.GetValue("frequencyRange")));
	}
	else{

		strcpy(cpuName,"unknow");
		strcpy(sName,"unknow");
		strcpy(busType,"unknow");
		strcpy(codeName,"unknow");
		strcpy(cpuLogo,"unknow");
		strcpy(defVcore,"unknow");
		strcpy(freqRange,"unknow");

	}

	cmd.Close();
	session.Close();
	dataSource.Close();

	return 0;

}



extern "C" DWORD PASCAL EXPORT GetHTSupport(char* HTsupp){



	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}

	if(!((features >> 28) & 1)){
		
		strcpy(HTsupp,"not detected");
		return 0;
	}

	strcpy(HTsupp,"detected");

	//verifico se è abilitata


	SYSTEM_INFO si;

	GetSystemInfo(&si);

	if(si.dwNumberOfProcessors > 1){

		strcat(HTsupp," and enabled");
		return 0;
	}

	strcat(HTsupp,", but disabled");
	return 0;

}


		
extern "C" BOOL PASCAL EXPORT HasMMX() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return (features >> 23) & 1;

}

/*************************************************

   Nome Funzione: HasSSE

   Se ritorna true, la CPU supporta le streaming
   SIMD extension

***************************************************/


extern "C" BOOL PASCAL EXPORT HasSSE() {
		int features=0;
		__asm {
			mov eax,1;
			cpuid;
			mov features,edx; //copio il feature flag in features
		}
		int res = (features >>25) & 1;
		return  res; 

}


/*************************************************

   Nome Funzione: HasSSE2

   Se ritorna true, la CPU supporta le streaming
   SIMD extension 2

***************************************************/

extern "C" BOOL PASCAL EXPORT HasSSE2() {
	   int features=0;
		__asm {
			mov eax,1;
			cpuid;
			mov features,edx; //copio il feature flag in features
		}
		int res = (features >>26) & 1;
		return  res; 

}




/*************************************************

   Nome Funzione: HasSSE3

   Se ritorna true, la CPU supporta le streaming
   SIMD extension 2

***************************************************/

extern "C" BOOL PASCAL EXPORT HasSSE3() {
	   int features=0;
		__asm {
			mov eax,1;
			cpuid;
			mov features,ecx; //copio il feature flag in features
		}
		int res = (features) & 1;
		return  res; 

}


/*************************************************

   Nome Funzione: HasAMD64

   Se ritorna true, la CPU supporta le streaming
   SIMD extension 2

***************************************************/

extern "C" BOOL PASCAL EXPORT HasAMD64() {

	int features;

	__asm {
		mov eax,80000001h;
		CPUID;
		mov features,edx;
	}
	
	return (features >> 29) & 1;

}


/*************************************************

   Nome Funzione: HasPSE36

   Se ritorna true, la CPU supporta il PSE - 36

***************************************************/

extern "C" BOOL PASCAL EXPORT HasPSE36() {

	int features;

	__asm {
		mov eax,80000001h;
		CPUID;
		mov features,edx;
	}
	
	return (features >> 17) & 1;

}


/*************************************************

   Nome Funzione: HasFPU

   Se ritorna true, la CPU ha una FPU integrata

***************************************************/

extern "C" BOOL PASCAL EXPORT HasFPU() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features & 1;

}


/*************************************************

   Nome Funzione: HasVirtualMode

   Se ritorna true, la CPU supporta virtual mode

***************************************************/

extern "C" BOOL PASCAL EXPORT HasVirtualMode() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 1 & 1;

}

/*************************************************

   Nome Funzione: HasDebugExt
   Se ritorna true, la CPU supporta debugging extensions

***************************************************/

extern "C" BOOL PASCAL EXPORT HasDebugExt() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 2 & 1;

}


/*************************************************

   Nome Funzione: HasPageSizeExt
   Se ritorna true, la CPU supporta PS ext

***************************************************/

extern "C" BOOL PASCAL EXPORT HasPageSizeExt() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 3 & 1;

}

extern "C" BOOL PASCAL EXPORT HasTimestamp() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 4 & 1;

}

extern "C" BOOL PASCAL EXPORT HasPAE() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 6 & 1;

}


extern "C" BOOL PASCAL EXPORT HasMachineCheck() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 7 & 1;

}


extern "C" BOOL PASCAL EXPORT HasCMPXCHG8B() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 8 & 1;

}

extern "C" BOOL PASCAL EXPORT HasAPIC() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 9 & 1;

}

extern "C" BOOL PASCAL EXPORT HasSysEnterExit() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 11 & 1;

}

extern "C" BOOL PASCAL EXPORT HasMTRR() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 12 & 1;

}


extern "C" BOOL PASCAL EXPORT HasGlobalPagingExt() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 13 & 1;

}


extern "C" BOOL PASCAL EXPORT HasCMOV() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 15 & 1;

}

extern "C" BOOL PASCAL EXPORT HasCLFLUSH() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 19 & 1;

}


extern "C" BOOL PASCAL EXPORT HasFXSAVERESTOR() {

	int features;

	__asm {
		mov eax,1;
		CPUID;
		mov features,edx;
	}
	
	return features >> 24 & 1;

}


extern "C" BOOL PASCAL EXPORT Has3DNow() {


	int features;

	__asm {
		mov eax,80000001h;
		CPUID;
		mov features,edx;
	}
	
	return (features >> 31) & 1;

}


extern "C" BOOL PASCAL EXPORT HasXtended3DNow() {
		int features;
		__asm {
			mov eax,80000001h; //funzione estesa
			cpuid;
			mov features,edx; //copio il feature flag in features
		}
        int res=(features >>30) & 1;
		return  res; //and su bit tra features shiftato di 30 bit (il trentesimo bit indica la presenza delle SSE) e 1
	}


extern "C" BOOL PASCAL EXPORT HasXtendedMMX() {

	int features;
	__asm {
		mov eax,80000001h;
		CPUID;
		mov features,edx;
	}
	int res=(features>>22) & 1;
	return res;

}

BOOL CCpuinfoApp::InitInstance() 
{

	HRESULT hRes=CoInitialize(NULL);

	if(FAILED(hRes)){
		AfxMessageBox("COM initalization error",MB_OK | MB_ICONERROR);
		return FALSE;
	}
	
	return CWinApp::InitInstance();
}

int CCpuinfoApp::ExitInstance() 
{

	CoUninitialize();
	
	return CWinApp::ExitInstance();
}
