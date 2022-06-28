// BenchmarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "BenchmarkDlg.h"
#include "..\itembkdrawer.h"

#define TITLE_X_POS 820
#define TEXT_X_POS 830

#define INFORMATIONS_AREA_START 140
#define BENCHSTATUS_AREA_START 400

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDlg

CBenchmarkDlg::CBenchmarkDlg()
{

	m_fntTitle.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	m_fntText.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	bFinished=false;

}

CBenchmarkDlg::~CBenchmarkDlg()
{
}


BEGIN_MESSAGE_MAP(CBenchmarkDlg, CWnd)
	//{{AFX_MSG_MAP(CBenchmarkDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_CTLCOLOR()
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

	m_infoTitle.Create("CPU informations",WS_VISIBLE , CRect(TITLE_X_POS,INFORMATIONS_AREA_START,TITLE_X_POS+100,INFORMATIONS_AREA_START+15), this,101);
	m_cpuName.Create("CPU Name: Intel pentium M",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+20,TEXT_X_POS+170,INFORMATIONS_AREA_START+35), this,102);
	m_cpuFreq.Create("CPU Frequency: 1400 MHz",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+35,TEXT_X_POS+170,INFORMATIONS_AREA_START+50), this,103);
	m_busSpeed.Create("CPU Bus speed: 399.98 MHz",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+50,TEXT_X_POS+170,INFORMATIONS_AREA_START+65), this,104);

	m_L1DCache.Create("L1 Data cache: 32 KByte",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+65,TEXT_X_POS+170,INFORMATIONS_AREA_START+80), this,105);
	m_L1ICache.Create("L1 Instruction cache: 32 KByte",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+80,TEXT_X_POS+170,INFORMATIONS_AREA_START+95), this,106);
	m_L2Cache.Create("L2 Cache: 1024 KByte",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+95,TEXT_X_POS+170,INFORMATIONS_AREA_START+110), this,107);
	m_traceCache.Create("Trace cache: absent",WS_VISIBLE , CRect(TEXT_X_POS,INFORMATIONS_AREA_START+110,TEXT_X_POS+170,INFORMATIONS_AREA_START+125), this,108);



	m_consoleOutput.Create("prova",WS_VISIBLE , CRect(10,140,810,740), this,105);
	m_currStatus.Create("status:",WS_VISIBLE , CRect(TITLE_X_POS,BENCHSTATUS_AREA_START+40,TITLE_X_POS+150,BENCHSTATUS_AREA_START+60), this,109);
	m_statusTitle.Create("Test status",WS_VISIBLE , CRect(TITLE_X_POS,BENCHSTATUS_AREA_START,TITLE_X_POS+100,BENCHSTATUS_AREA_START+15), this,110);
	m_currProgress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH,CRect(TEXT_X_POS,BENCHSTATUS_AREA_START+60,TEXT_X_POS+180,BENCHSTATUS_AREA_START+80),this,100);

	m_currProgress.SetRange(0,100);


	m_infoTitle.SetFont(&m_fntTitle);
	m_statusTitle.SetFont(&m_fntTitle);
	m_cpuName.SetFont(&m_fntText);
	m_cpuFreq.SetFont(&m_fntText);
	m_busSpeed.SetFont(&m_fntText);
	m_L1DCache.SetFont(&m_fntText);
	m_L1ICache.SetFont(&m_fntText);
	m_L2Cache.SetFont(&m_fntText);
	m_traceCache.SetFont(&m_fntText);



	m_consoleOutput.SetFont(&m_fntText);
	m_currStatus.SetFont(&m_fntText);

}






BOOL CBenchmarkDlg::OnEraseBkgnd(CDC* pDC) 
{

 	CRect rc;
 
	if(!bFinished){

		ExcludeBkRepaint(pDC,&m_consoleOutput);

	}

	GetClientRect(&rc);

		
	CItemBkDrawer::DrawBk(pDC,&rc);

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
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	
	return hbr;
}
