// BenchmarkEnvironment.cpp: implementation of the CBenchmarkEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "BenchmarkEnvironment.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBenchmarkEnvironment::CBenchmarkEnvironment()
{
	m_wndEnv=new CBenchmarkDlg();

}

CBenchmarkEnvironment::~CBenchmarkEnvironment()
{

	delete m_wndEnv;

	m_wndEnv=NULL;

}


void CBenchmarkEnvironment::InitBenchmarkingEnvironment(){



	int xRes=GetSystemMetrics(SM_CXSCREEN);
	int yRes=GetSystemMetrics(SM_CYSCREEN);

	

	CString str=AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,NULL,(HBRUSH)GetStockObject(WHITE_BRUSH),NULL);


	m_wndEnv->CreateEx(WS_EX_APPWINDOW | WS_EX_TOPMOST ,str,"CPUBench CBE (CPUBench Benchmarking Environment)",WS_POPUP| WS_VISIBLE,0,0,xRes,yRes,NULL,NULL);
	

	m_wndEnv->ShowWindow(SW_SHOWNORMAL);


}

void CBenchmarkEnvironment::CloseBenchmarkingEnvironment(){

	m_wndEnv->DestroyWindow();

}
