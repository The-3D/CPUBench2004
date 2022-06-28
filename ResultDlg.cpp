// ResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ResultDlg.h"
#include "itembkdrawer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultDlg dialog


CResultDlg::CResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResultDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResultDlg)
	//}}AFX_DATA_INIT
}


void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultDlg)
	DDX_Control(pDX, IDC_BENCHDETAILS, m_benchDetails);
	DDX_Control(pDX, IDC_CPUINFO, m_cpuInfo);
	DDX_Control(pDX, IDC_GRAPHOFRESULT, m_graphResult);
	DDX_Control(pDX, IDC_SAVE_PROJECT, m_saveProject);
	DDX_Control(pDX, IDOK, m_ok);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialog)
	//{{AFX_MSG_MAP(CResultDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_GRAPHOFRESULT, OnGraphofresult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultDlg message handlers

BOOL CResultDlg::OnEraseBkgnd(CDC* pDC) 
{

	CRect r;

	GetWindowRect(&r);

	ScreenToClient(&r);

	CItemBkDrawer::DrawBk(pDC,&r);
	
	return TRUE;
}

HBRUSH CResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	
	if(nCtlColor == CTLCOLOR_STATIC){

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	return hbr;
}

BOOL CResultDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_fntResult.CreateFont(-24,0,0,0,800,TRUE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


	m_fntTime.CreateFont(-18,0,0,0,590,TRUE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	
	m_fnt.CreateFont(-12,0,0,0,700,TRUE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


	GetDlgItem(IDC_RESULT)->SetFont(&m_fntResult);
	GetDlgItem(IDC_RESULT2)->SetFont(&m_fntResult);
	GetDlgItem(IDC_RAMSCORE)->SetFont(&m_fntTime);
	GetDlgItem(IDC_LBLRAMSCORE)->SetFont(&m_fntTime);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CResultDlg::OnGraphofresult() 
{

	
}
