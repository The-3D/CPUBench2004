// BenchmarkEnvironment.cpp: implementation of the CBenchmarkEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarks.h"
#include "BenchmarkEnvironment.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEvent environmentCreated;



DWORD WINAPI InitEnvironment(LPVOID arg){




	CBenchmarkDlg **wnd=(CBenchmarkDlg**)arg;
	

	CString str=AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS,NULL,(HBRUSH)GetStockObject(WHITE_BRUSH),NULL);


	(*wnd)->CreateEx(WS_EX_TOPMOST,str,"CPUBench CBE (CPUBench Benchmarking Environment)",WS_POPUP | WS_VISIBLE,0,0,1024,768,NULL,NULL);
	

	(*wnd)->ShowWindow(SW_SHOW);

	(*wnd)->RedrawWindow();

	(*wnd)->SetFocus();



	environmentCreated.SetEvent();

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
//		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
//		}
	}
	return 1;
}



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


	//prendo le vecchie impostazioni

	EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&m_oldMode);

	//imposto la risoluzione a 1024x768x60 Hz

	ChangeVideoResolution(1024,768,32,m_oldMode.dmDisplayFrequency);
	
	CWinThread *t=AfxBeginThread((AFX_THREADPROC)InitEnvironment,&m_wndEnv,THREAD_PRIORITY_NORMAL);

//		::WaitForSingleObject(t->m_hThread,INFINITE);

	m_msgThreadID=t->m_nThreadID;
	CSingleLock sl(&environmentCreated);

	sl.Lock();
	sl.Unlock();

}


void CBenchmarkEnvironment::ShowBenchDescriptionImage(CString testName){

	CBitmap bmpBackground;

	bmpBackground.LoadBitmap("benchdescription");

	CDC* dc=m_wndEnv->GetOutTarget(0)->GetDC();

	CDC memDC;

	memDC.CreateCompatibleDC(NULL);


	memDC.SelectObject(bmpBackground);

	dc->BitBlt(0,0,800,600,&memDC,0,0,SRCCOPY);
	
	CFont testNameFont;
	
	testNameFont.CreateFont(-30,0,0,0,600,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");


	dc->SelectObject(&testNameFont);


	dc->SetTextColor(RGB(255,255,255));
	dc->SetBkMode(TRANSPARENT);
	dc->TextOut(285,8,testName);

	dc->DeleteDC();

	memDC.DeleteDC();

}

void CBenchmarkEnvironment::CloseBenchmarkingEnvironment(){


	m_wndEnv->SendMessage(WM_CLOSE);

	m_wndEnv->DestroyWindow();

	PostThreadMessage(m_msgThreadID,WM_QUIT,0,0);

	ChangeVideoResolution(m_oldMode.dmPelsWidth,m_oldMode.dmPelsHeight,m_oldMode.dmBitsPerPel,m_oldMode.dmDisplayFrequency);


}
