// BenchmarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Benchmarks.h"
#include "BenchmarkDlg.h"
#include "..\itembkdrawer.h"
#include "environmentskindrawer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDlg

CBenchmarkDlg::CBenchmarkDlg() :
	m_stopExecutionRequested(false)
{

	m_fntTitle.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	m_fntText.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	m_fntConsole.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "LUCIDA CONSOLE");

	bFinished=false;

	m_outMode = SINGLE_WINDOW;
}

CBenchmarkDlg::~CBenchmarkDlg()
{
	m_fntText.DeleteObject();
	m_fntTitle.DeleteObject();
	m_fntConsole.DeleteObject();

	m_infoTitle.DestroyWindow();
	this->m_testName.DestroyWindow();
	this->m_testDesc.DestroyWindow();
}

BEGIN_MESSAGE_MAP(CBenchmarkDlg, CWnd)
	//{{AFX_MSG_MAP(CBenchmarkDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_SYSKEYDOWN()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(125,OnBnClickedStopExecution)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDlg message handlers


void CBenchmarkDlg::ExcludeBkRepaint(CDC* pDC,CWnd* pWnd){

 	CRect rc;
 
	// Get the bounding rectangle for the movie screen
	pWnd->GetWindowRect(&rc);
	ScreenToClient(&rc);

	// Exclude the clipping region occupied by our movie screen
	pDC->ExcludeClipRect(&rc);

}


void CBenchmarkDlg::BuildInterface(){


	CString s="Description: This test measures CPU performance";

	m_infoTitle.Create("Test informations",WS_CHILD | WS_VISIBLE , CRect(TITLE_X_POS,INFORMATIONS_AREA_START,TITLE_X_POS+100,INFORMATIONS_AREA_START+15), this,101);
	m_testName.Create("Test name: Scientific benchmark",WS_CHILD | WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+20,TEXT_X_POS+170,INFORMATIONS_AREA_START+35), this,102);
	m_testDesc.Create(s,WS_CHILD | WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+45,TEXT_X_POS+170,INFORMATIONS_AREA_START+145), this,102);
	m_techDetails.Create("1\n\n2\n\n3",WS_VISIBLE , CRect(TEXT_X_POS,TECHDETAILS_AREA_START+20,TEXT_X_POS+190,TECHDETAILS_AREA_START+90), this,102);

	
	m_outTargetMain.Create("",WS_CHILD | WS_VISIBLE , CRect(0,117,OUT_TARGET_MAIN_X_SIZE_SINGLE,717), this,105);
	m_outTargetLeftWnd1.Create("",WS_CHILD | WS_VISIBLE , CRect(0,117,OUT_TARGET_SUBWINDOW_X_SIZE,417), this,120);
	m_outTargetLeftWnd2.Create("",WS_CHILD | WS_VISIBLE , CRect(0,417,OUT_TARGET_SUBWINDOW_X_SIZE,717), this,121);
	

	m_currStatus.Create("status:",WS_CHILD | WS_VISIBLE , CRect(TEXT_X_POS,BENCHSTATUS_AREA_START+30,TITLE_X_POS+190,BENCHSTATUS_AREA_START+50), this,109);
	m_statusTitle.Create("Test status",WS_CHILD | WS_VISIBLE , CRect(TITLE_X_POS,BENCHSTATUS_AREA_START,TITLE_X_POS+100,BENCHSTATUS_AREA_START+15), this,110);
	m_techDetailsTitle.Create("Techinical details",WS_VISIBLE , CRect(TITLE_X_POS,TECHDETAILS_AREA_START,TITLE_X_POS+100,TECHDETAILS_AREA_START+15), this,113);

	m_currProgress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH,CRect(TEXT_X_POS,BENCHSTATUS_AREA_START+50,TEXT_X_POS+175,BENCHSTATUS_AREA_START+70),this,100);

	m_currProgress.SetRange(0,100);

	m_totalStatus.Create("Overall process:",WS_CHILD | WS_VISIBLE , CRect(TEXT_X_POS,BENCHSTATUS_AREA_START+85,TITLE_X_POS+170,BENCHSTATUS_AREA_START+105), this,111);
	m_totalProgress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH,CRect(TEXT_X_POS,BENCHSTATUS_AREA_START+105,TEXT_X_POS+175,BENCHSTATUS_AREA_START+125),this,112);

	m_btnCancel.Create("Cancel",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_OWNERDRAW,CRect(TEXT_X_POS+20,BENCHSTATUS_AREA_START+135,TEXT_X_POS+155,BENCHSTATUS_AREA_START+165),this,125);

	m_totalProgress.SetRange(0,100);

	m_infoTitle.SetFont(&m_fntTitle);

	m_statusTitle.SetFont(&m_fntTitle);
	
	m_techDetailsTitle.SetFont(&m_fntTitle);
	
	m_testName.SetFont(&m_fntText);
	
	m_testDesc.SetFont(&m_fntText);
	
	m_techDetails.SetFont(&m_fntText);

	m_outTargetMain.SetFont(&m_fntConsole);
	
	m_outTargetLeftWnd1.SetFont(&m_fntConsole);
	
	m_outTargetLeftWnd2.SetFont(&m_fntConsole);

	m_currStatus.SetFont(&m_fntText);
	
	m_totalStatus.SetFont(&m_fntText);

	m_outTargetLeftWnd1.ShowWindow(SW_HIDE);
	
	m_outTargetLeftWnd2.ShowWindow(SW_HIDE);

	ASSERT_VALID(&m_outTargetLeftWnd1);
	ASSERT_VALID(&m_outTargetLeftWnd2);
	ASSERT_VALID(&m_outTargetMain);


}




BOOL CBenchmarkDlg::OnEraseBkgnd(CDC* pDC) 
{
 	
	CRect rc;
 
	if(!bFinished)
		ExcludeBkRepaint(pDC,&m_outTargetMain);



	GetClientRect(&rc);


	pDC->FillSolidRect(&rc,0);


	CEnvironmentSkinDrawer d(1024,768,OUT_TARGET_MAIN_X_SIZE_SINGLE,600,117);

	d.DrawSkin(pDC);

	return TRUE;

}

int CBenchmarkDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	BuildInterface();

	return 0;
}


void CBenchmarkDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CWnd::OnShowWindow(bShow, nStatus);
	
	
}

HBRUSH CBenchmarkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC){

		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	
	return hbr;
}


void CBenchmarkDlg::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){

}

void CBenchmarkDlg::OnBnClickedStopExecution(){

	UpdateStatus("Benchmark canceled. Please wait...");

	m_stopExecutionRequested = true;

}