// CacheInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CacheInfoDlg.h"
#include "itembkdrawer.h"
#include "cpuinformations.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCacheInfoDlg dialog


CCacheInfoDlg::CCacheInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCacheInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCacheInfoDlg)
	m_title = _T("");
	m_L1ITLB4M_entries = _T("");
	m_L1ITLB4M_ass = _T("");
	m_L1DTLB4M_entries = _T("");
	m_L1DTLB4M_ass = _T("");
	m_L1D_Ass = _T("");
	m_L1D_CacheSize = _T("");
	m_L1D_LineSize = _T("");
	m_L1D_LinesPerTag = _T("");
	m_L1I_CacheSize = _T("");
	m_L1I_LineSize = _T("");
	m_L1I_Ass = _T("");
	m_L1I_LinesPerTag = _T("");
	m_L1I_TLB4K_Ass = _T("");
	m_L1D_TLB4K_Ass = _T("");
	m_L1D_TLB4K_Entries = _T("");
	m_L1I_TLB4K_Entries = _T("");
	m_L2_Ass = _T("");
	m_L2_CacheSize = _T("");
	m_L2_LineSize = _T("");
	m_L2_LinesPerTag = _T("");
	m_L2D_TLB4K_Ass = _T("");
	m_L2D_TLB4K_Entries = _T("");
	m_L2D_TLB4M_Ass = _T("");
	m_L2D_TLB4M_Entries = _T("");
	m_L2I_TLB4K_Ass = _T("");
	m_L2I_TLB4K_Entries = _T("");
	m_L2I_TLB4M_Ass = _T("");
	m_L2I_TLB4M_Entries = _T("");
	//}}AFX_DATA_INIT

	m_fntLbl.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

	m_fntTitle.CreateFont(-17,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");


}


void CCacheInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCacheInfoDlg)
	DDX_Control(pDX, IDC_CACHELATENCY, m_cacheLatency);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Text(pDX, IDC_MAINTITLE, m_title);
	DDX_Text(pDX, IDC_L1ITLB4M_ENTRIES, m_L1ITLB4M_entries);
	DDX_Text(pDX, IDC_L1ITLB4M_ASS, m_L1ITLB4M_ass);
	DDX_Text(pDX, IDC_L1DTLB4M_ENTRIES, m_L1DTLB4M_entries);
	DDX_Text(pDX, IDC_L1DTLB4M_ASS, m_L1DTLB4M_ass);
	DDX_Text(pDX, IDC_L1D_ASSOCIATIVITY, m_L1D_Ass);
	DDX_Text(pDX, IDC_L1D_CACHESIZE, m_L1D_CacheSize);
	DDX_Text(pDX, IDC_L1D_LINESIZE, m_L1D_LineSize);
	DDX_Text(pDX, IDC_L1D_LINESPERTAG, m_L1D_LinesPerTag);
	DDX_Text(pDX, IDC_L1I_CACHESIZE, m_L1I_CacheSize);
	DDX_Text(pDX, IDC_L1I_LINESIZE, m_L1I_LineSize);
	DDX_Text(pDX, IDC_L1I_ASSOCIATIVITY, m_L1I_Ass);
	DDX_Text(pDX, IDC_L1I_LINESPERTAG, m_L1I_LinesPerTag);
	DDX_Text(pDX, IDC_L1I_TLB4K_ASSOCIATIVITY, m_L1I_TLB4K_Ass);
	DDX_Text(pDX, IDC_L1D_TLB4K_ASSOCIATIVITY, m_L1D_TLB4K_Ass);
	DDX_Text(pDX, IDC_L1D_TLB4K_ENTRIES, m_L1D_TLB4K_Entries);
	DDX_Text(pDX, IDC_L1I_TLB4K_ENTRIES, m_L1I_TLB4K_Entries);
	DDX_Text(pDX, IDC_L2_ASSOCIATIVITY, m_L2_Ass);
	DDX_Text(pDX, IDC_L2_CACHESIZE, m_L2_CacheSize);
	DDX_Text(pDX, IDC_L2_LINESIZE, m_L2_LineSize);
	DDX_Text(pDX, IDC_L2_LINESPERTAG, m_L2_LinesPerTag);
	DDX_Text(pDX, IDC_L2D_TLB4K_ASSOCIATIVITY, m_L2D_TLB4K_Ass);
	DDX_Text(pDX, IDC_L2D_TLB4K_ENTRIES, m_L2D_TLB4K_Entries);
	DDX_Text(pDX, IDC_L2D_TLB4M_ASSOCIATIVITY, m_L2D_TLB4M_Ass);
	DDX_Text(pDX, IDC_L2D_TLB4M_ENTRIES, m_L2D_TLB4M_Entries);
	DDX_Text(pDX, IDC_L2I_TLB4K_ASSOCIATIVITY, m_L2I_TLB4K_Ass);
	DDX_Text(pDX, IDC_L2I_TLB4K_ENTRIES, m_L2I_TLB4K_Entries);
	DDX_Text(pDX, IDC_L2I_TLB4M_ASSOCIATIVITY, m_L2I_TLB4M_Ass);
	DDX_Text(pDX, IDC_L2I_TLB4M_ENTRIES, m_L2I_TLB4M_Entries);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCacheInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CCacheInfoDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CACHELATENCY, OnCachelatency)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCacheInfoDlg message handlers

BOOL CCacheInfoDlg::OnEraseBkgnd(CDC* pDC) 
{

	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(pDC,&r);
	
	return TRUE;
}

HBRUSH CCacheInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

		if(*pWnd == *GetDlgItem(IDC_MAINTITLE)){

			pDC->SetBkColor(0);
			CRect r;

			GetDlgItem(IDC_MAINTITLE)->GetClientRect(&r);

			pDC->FillSolidRect(0,0,r.Width(),r.Height(),RGB(161,161,175));
			pDC->SetTextColor(0x00FFFFFF);
		}

	
		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	// TODO: Return a different brush if the default is not desired

	return hbr;
}

BOOL CCacheInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	GetDlgItem(IDC_LBL1)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL2)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL3)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL4)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL5)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL6)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL7)->SetFont(&m_fntLbl);
	GetDlgItem(IDC_LBL8)->SetFont(&m_fntLbl);

	CCPUInformations i;

	m_title="Cache informations for "+i.GetCPUName()+" processor";
	GetDlgItem(IDC_MAINTITLE)->SetFont(&m_fntTitle);

	m_L1ITLB4M_entries=i.GetL1I_TLB4M_Entries();
	m_L1ITLB4M_ass=i.GetL1I_TLB4M_Associativity();

	m_L1DTLB4M_entries=i.GetL1D_TLB4M_Entries();
	m_L1DTLB4M_ass=i.GetL1D_TLB4M_Associativity();

	m_L1D_CacheSize=i.GetL1DCache();
	m_L1D_LineSize=i.GetL1D_LineSize();
	m_L1D_LinesPerTag=i.GetL1D_LinesPerTag();
	m_L1D_Ass=i.GetL1D_Associativity();


	m_L1I_CacheSize=i.GetL1ICache();
	m_L1I_LineSize=i.GetL1I_LineSize();
	m_L1I_LinesPerTag=i.GetL1I_LinesPerTag();
	m_L1I_Ass=i.GetL1I_Associativity();

	m_L1I_TLB4K_Entries=i.GetL1I_TLB4K_Entries();
	m_L1I_TLB4K_Ass=i.GetL1I_TLB4K_Associativity();

	m_L1D_TLB4K_Entries=i.GetL1D_TLB4K_Entries();
	m_L1D_TLB4K_Ass=i.GetL1D_TLB4K_Associativity();


	m_L2_CacheSize=i.GetL2Cache();
	m_L2_LineSize=i.GetL2_LineSize();
	m_L2_LinesPerTag=i.GetL2_LinesPerTag();
	m_L2_Ass=i.GetL2_Associativity();


	m_L2I_TLB4K_Entries=i.GetL2I_TLB4K_Entries();
	m_L2I_TLB4K_Ass=i.GetL2I_TLB4K_Associativity();

	m_L2D_TLB4K_Entries=i.GetL2D_TLB4K_Entries();
	m_L2D_TLB4K_Ass=i.GetL2D_TLB4K_Associativity();

	m_L2I_TLB4M_Entries=i.GetL2I_TLB4M_Entries();
	m_L2I_TLB4M_Ass=i.GetL2I_TLB4M_Associativity();

	m_L2D_TLB4M_Entries=i.GetL2D_TLB4M_Entries();
	m_L2D_TLB4M_Ass=i.GetL2D_TLB4M_Associativity();


	UpdateData(FALSE);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CCacheInfoDlg::OnCachelatency() 
{
	MessageBox("This functionality is available only in the PRO version of CPUBench2004.","Warning",MB_ICONWARNING);
	
}
