// ReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ReportDlg.h"
#include "itembkdrawer.h"
#include "reportcreator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog


CReportDlg::CReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReportDlg)
	m_cpuInfo = FALSE;
	m_cpuFeatures = FALSE;
	m_cacheInfo = FALSE;
	m_testerInfo = FALSE;
	m_mbInfo = FALSE;
	m_osInfo = FALSE;
	m_pciDevs = FALSE;
	m_sysDetails = _T("");
	m_sysName = _T("");
	m_testerName = _T("");
	m_benchResults = FALSE;
	//}}AFX_DATA_INIT
}


void CReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReportDlg)
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Check(pDX, IDC_CPUINFO, m_cpuInfo);
	DDX_Check(pDX, IDC_CPUFEATURES, m_cpuFeatures);
	DDX_Check(pDX, IDC_CACHEINFO, m_cacheInfo);
	DDX_Check(pDX, IDC_INCLUDETESTERINFO, m_testerInfo);
	DDX_Check(pDX, IDC_MBINFO, m_mbInfo);
	DDX_Check(pDX, IDC_OSINFO, m_osInfo);
	DDX_Check(pDX, IDC_PCIDEVS, m_pciDevs);
	DDX_Text(pDX, IDC_SYSTEMDETAILS, m_sysDetails);
	DDX_Text(pDX, IDC_SYSTEMNAME, m_sysName);
	DDX_Text(pDX, IDC_TESTERNAME, m_testerName);
	DDX_Check(pDX, IDC_BENCHRESULTS, m_benchResults);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReportDlg, CDialog)
	//{{AFX_MSG_MAP(CReportDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_INCLUDETESTERINFO, OnIncludetesterinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportDlg message handlers


BOOL CReportDlg::OnEraseBkgnd(CDC* pDC) 
{

	CRect r;

	GetClientRect(&r);


	CItemBkDrawer::DrawBk(pDC,&r);


	return TRUE;
}

HBRUSH CReportDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CReportDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_cpuInfo=TRUE;
	m_cpuFeatures=TRUE;
	m_cacheInfo=TRUE;
	m_benchResults=TRUE;
	m_testerInfo=TRUE;
	m_mbInfo=TRUE;
	m_osInfo=TRUE;
	m_pciDevs=TRUE;

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReportDlg::OnOK() 
{


	CReportCreator r;
	

	UpdateData();

	r.IncludeTesterInfo(m_testerInfo);
	r.IncludeCPUFeaturesInfo(m_cpuFeatures);
	r.IncludeCPUInfo(m_cpuInfo);
	r.IncludeCacheInfo(m_cacheInfo);
	r.IncludeOSInfo(m_osInfo);


	r.SetSystemDetails(m_sysDetails);
	r.SetSystemName(m_sysName);
	r.SetTesterName(m_testerName);


	r.CreateReport();
	
	CDialog::OnOK();
}

void CReportDlg::OnIncludetesterinfo() 
{


	UpdateData();

	if(!m_testerInfo){

		GetDlgItem(IDC_SYSTEMNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_SYSTEMDETAILS)->EnableWindow(FALSE);
		GetDlgItem(IDC_TESTERNAME)->EnableWindow(FALSE);
		return;
	}

	GetDlgItem(IDC_SYSTEMNAME)->EnableWindow();
	GetDlgItem(IDC_SYSTEMDETAILS)->EnableWindow();
	GetDlgItem(IDC_TESTERNAME)->EnableWindow();
}
