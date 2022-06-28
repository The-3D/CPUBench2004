// CPUFeaturesItem.cpp: implementation of the CCPUFeaturesItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUFeaturesItem.h"
#include "cpuinformations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCPUFeaturesItem::CCPUFeaturesItem()
{

	CCPUInformations info;

	title=info.GetCPUName()+" supported features";


	genericFeatures=new CString[32];
	featureValues=new CString[32];


	genericFeatures[0]="Built in native x87 FP unit:";
	genericFeatures[1]="Virtual mode extensions:";
	genericFeatures[2]="Debugging extensions:";
	genericFeatures[3]="Page size extensions(4 MByte pages):";
	genericFeatures[4]="Time Stamp Counter(with RDTSC):";
	genericFeatures[5]="PAE (Page Address Extensions):";
	genericFeatures[6]="Machine check extensions:";
	genericFeatures[7]="CMPXCHG8B Instruction:";
	genericFeatures[8]="Built-in APIC hardware:";
	genericFeatures[9]="SYSENTER/SYSEXIT Instructions:";
	genericFeatures[10]="MTRR (Memory Type Range Registers):";
	genericFeatures[11]="Global Paging Extension:";
	genericFeatures[12]="Machine Check Architecture:";
	genericFeatures[13]="Conditional move (CMOV) instruction:";
	genericFeatures[14]="PSE-36 (Page Size Extensions):";
	genericFeatures[15]="MMX™ Instructions extension:";
	genericFeatures[16]="Streaming SIMD Extensions (SSE):";
	genericFeatures[17]="Streaming SIMD Extensions 2(SSE2):";
	genericFeatures[18]="Streaming SIMD Extensions 3(SSE3):";
	genericFeatures[19]="AMD 3DNow! instruction support:";
	genericFeatures[20]="AMD MMX™ instruction set extensions:";
	genericFeatures[21]="Hyperthreading tecnology:";
	genericFeatures[22]="FXSAVE/FXRESTOR:";
	genericFeatures[23]="CLFLUSH instruction:";
	genericFeatures[24]="Long mode(AKA AMD64 extensions to x86):";


	for(int i=0; i< 32; i++)
		featureValues[i]="not supported";




	featureValues[0]=info.GetFPUSupport();
	featureValues[1]=info.GetVirtualModeSupport();
	featureValues[2]=info.GetDebugExtSupport();
	featureValues[3]=info.GetPageSizeExt();
	featureValues[4]=info.GetTimestamp();
	featureValues[5]=info.GetTimestamp();
	featureValues[5]=info.GetPAEExt();
	featureValues[6]=info.GetMachineCheck();
	featureValues[7]=info.GetCMPXCHG8B();
	featureValues[8]=info.GetAPIC();
	featureValues[9]=info.GetSysEnterExit();
	featureValues[10]=info.GetMTRR();
	featureValues[11]=info.GetGlobalPaging();
	featureValues[12]=info.GetMachineCheck();
	featureValues[13]=info.GetCMOV();
	featureValues[14]=info.GetPSE36Support();
	featureValues[15]=info.GetMMXSupport();
	featureValues[16]=info.GetSSESupport();
	featureValues[17]=info.GetSSE2Support();
	featureValues[18]=info.GetSSE3Support();
	featureValues[19]=info.Get3DNow();
	featureValues[20]=info.GetXtendedMMX();
	featureValues[21]=info.GetHTSupport();
	featureValues[22]=info.GetCLFLUSH();
	featureValues[23]=info.GetFXSAVERESTOR();
	featureValues[24]=info.GetAMD64Support();




}

CCPUFeaturesItem::~CCPUFeaturesItem()
{

	delete [] genericFeatures;

}


void CCPUFeaturesItem::DrawContent(CDC *dc){

	CFont fLbl;
	CFont fTitle;

	CCPUInformations info;

	fLbl.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


	fTitle.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


	dc->SetTextColor(0);


	CGdiObject *pOldObj=dc->SelectObject(&fTitle);


	dc->TextOut(itemRect.left+25,itemRect.top+15,title);


	dc->SelectObject(&fLbl);




	int maxLenght=0;



	for(int i=0; i<25; i++){
		CSize s;

		GetTextExtentPoint32(*dc,genericFeatures[i],genericFeatures[i].GetLength(),&s);

		if(s.cx > maxLenght) maxLenght=s.cx;

		dc->TextOut(itemRect.left+70,itemRect.top+40+i*15,genericFeatures[i]);

	}

	for(i=0; i<25; i++){

		dc->TextOut(itemRect.left+74+maxLenght,itemRect.top+40+i*15,featureValues[i]);

	}


	dc->SelectObject(pOldObj);



}
