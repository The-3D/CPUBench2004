// CPUBench2004.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUBench2004Dlg.h"
#include "splashdlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



#define WS_EX_LAYERED 0x80000
#define LWA_COLORKEY 1
#define LWA_ALPHA 2


DWORD SplashThread(LPVOID arg) {

	CSplashDlg* dlg=new CSplashDlg; 
	
	dlg->Create(IDD_SPLASHDLG_DIALOG,NULL);

	dlg->ModifyStyleEx(0,WS_EX_TOPMOST);

	SetWindowLong (dlg->m_hWnd , GWL_EXSTYLE , 
			GetWindowLong (dlg->m_hWnd , GWL_EXSTYLE ) | WS_EX_LAYERED ) ;	

	dlg->ShowWindow(SW_SHOWNORMAL);

	
//	dlg->SetWindowPos(wndTop,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	
	HWND hWnd=dlg->m_hWnd; 
	typedef DWORD (WINAPI *PSLWA)(HWND, DWORD, BYTE, DWORD);
	PSLWA pSetLayeredWindowAttributes;
	HMODULE hDLL = LoadLibrary ("user32");
	pSetLayeredWindowAttributes = 
	(PSLWA) GetProcAddress(hDLL,"SetLayeredWindowAttributes");
	if (pSetLayeredWindowAttributes != NULL) {
		for(int i=0; i<255; i++) {
		
			pSetLayeredWindowAttributes (hWnd, 
			0, i, LWA_ALPHA);
			dlg->UpdateWindow();
			Sleep(1);
		

		}

	}

	FreeLibrary(hDLL);


	Sleep(1000);


	dlg->DestroyWindow();

	return 0;

}


/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004App


BEGIN_MESSAGE_MAP(CCPUBench2004App, CWinApp)
	//{{AFX_MSG_MAP(CCPUBench2004App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004App construction

CCPUBench2004App::CCPUBench2004App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCPUBench2004App object

CCPUBench2004App theApp;




/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004App initialization

BOOL CCPUBench2004App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


	CCPUBench2004Dlg dlg;

	m_pMainWnd = &dlg;

	CWinThread* t=AfxBeginThread((AFX_THREADPROC)SplashThread,NULL,THREAD_PRIORITY_ABOVE_NORMAL);

	WaitForSingleObject(t->m_hThread,INFINITE);



	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
