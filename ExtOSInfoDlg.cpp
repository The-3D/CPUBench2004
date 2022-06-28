// ExtOSInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ExtOSInfoDlg.h"
#include "itembkdrawer.h"
#include "osinformations.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtOSInfoDlg dialog


CExtOSInfoDlg::CExtOSInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtOSInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtOSInfoDlg)
	m_Revision = _T("");
	m_userName = _T("");
	m_OSName = _T("");
	m_computerName = _T("");
	m_servicePack = _T("");
	m_standBy = _T("");
	m_mainDirectory = _T("");
	m_bootMode = _T("");
	m_resolution = _T("");
	//}}AFX_DATA_INIT

	m_fntLbl.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


}


void CExtOSInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtOSInfoDlg)
	DDX_Text(pDX, IDC_REVISION, m_Revision);
	DDX_Text(pDX, IDC_USERNAME, m_userName);
	DDX_Text(pDX, IDC_OSNAME, m_OSName);
	DDX_Text(pDX, IDC_COMPUTERNAME, m_computerName);
	DDX_Text(pDX, IDC_SERVICEPACK, m_servicePack);
	DDX_Text(pDX, IDC_STANDBY, m_standBy);
	DDX_Text(pDX, IDC_MAINDIRECTORY, m_mainDirectory);
	DDX_Text(pDX, IDC_BOOTMODE, m_bootMode);
	DDX_Text(pDX, IDC_RESOLUTION, m_resolution);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtOSInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CExtOSInfoDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtOSInfoDlg message handlers

BOOL CExtOSInfoDlg::OnEraseBkgnd(CDC* pDC) 
{

	return TRUE;
}

HBRUSH CExtOSInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC){

			pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	return hbr;
}

BOOL CExtOSInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	COSInformations osInfo;

	m_OSName=osInfo.GetOSName();
	m_computerName=osInfo.GetComputerName();
	m_userName=osInfo.GetUserName();
	m_Revision=osInfo.GetOSRevision();
	m_bootMode=osInfo.GetBootMode();
	m_mainDirectory=osInfo.GetMainDirectory();
	m_standBy=osInfo.GetStandByMode();
	m_servicePack=osInfo.GetServicePack();
	m_resolution=osInfo.GetScreenRes();

	GetDlgItem(IDC_LBL)->SetFont(&m_fntLbl);

	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExtOSInfoDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	
	// Do not call CDialog::OnPaint() for painting messages
}
