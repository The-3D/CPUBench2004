// CPUFeaturesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUFeaturesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCPUFeaturesDlg dialog


CCPUFeaturesDlg::CCPUFeaturesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUFeaturesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUFeaturesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCPUFeaturesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUFeaturesDlg)
	DDX_Control(pDX, IDOK, m_ok);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCPUFeaturesDlg, CDialog)
	//{{AFX_MSG_MAP(CCPUFeaturesDlg)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUFeaturesDlg message handlers

BOOL CCPUFeaturesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();



	CRect r;


	GetClientRect(&r);


	w.SetCtrlRect(&r);

	w.BuildInterface();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCPUFeaturesDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	

	w.Draw(&dc);


	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CCPUFeaturesDlg::OnEraseBkgnd(CDC* pDC) 
{
	
	return TRUE;//CDialog::OnEraseBkgnd(pDC);
}
