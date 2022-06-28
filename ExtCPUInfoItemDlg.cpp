// ExtCPUInfoItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ExtCPUInfoItemDlg.h"
#include "gradient.h"
#include "cpuinformations.h"
#include "itembkdrawer.h"
#include "cacheinfodlg.h"
#include "cpufeaturesdlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CExtCPUInfoItemDlg dialog


CExtCPUInfoItemDlg::CExtCPUInfoItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtCPUInfoItemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtCPUInfoItemDlg)
	m_vendorName = _T("");
	m_cpuName = _T("");
	m_codeName = _T("");
	m_platform = _T("");
	m_brandName = _T("");
	m_frequency = _T("");
	m_frequencyRange = _T("");
	m_multiplier = _T("");
	m_L1ICache = _T("");
	m_L1DCache = _T("");
	m_traceCache = _T("");
	m_signature = _T("");
	m_L2Cache = _T("");
	m_defaultVCore = _T("");
	m_HTsupport = _T("");
	m_MMX = _T("");
	m_PSE36 = _T("");
	m_SSE = _T("");
	m_SSE2 = _T("");
	m_SSE3 = _T("");
	m_AMD64 = _T("");
	//}}AFX_DATA_INIT

	fntLbl.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


}


void CExtCPUInfoItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtCPUInfoItemDlg)
	DDX_Control(pDX, IDC_CACHEDETAILS, m_cacheDetails);
	DDX_Control(pDX, IDC_FEATURES, m_cpuFeatures);
	DDX_Text(pDX, IDC_VENDORNAME, m_vendorName);
	DDX_Text(pDX, IDC_CPUNAME, m_cpuName);
	DDX_Text(pDX, IDC_CODENAME, m_codeName);
	DDX_Text(pDX, IDC_PLATFORM, m_platform);
	DDX_Text(pDX, IDC_BRANDNAME, m_brandName);
	DDX_Text(pDX, IDC_CPUFREQUENCY, m_frequency);
	DDX_Text(pDX, IDC_FREQUENCYRANGE, m_frequencyRange);
	DDX_Text(pDX, IDC_FREQUENCYRATIO, m_multiplier);
	DDX_Text(pDX, IDC_L1ICACHE, m_L1ICache);
	DDX_Text(pDX, IDC_L1DCACHE, m_L1DCache);
	DDX_Text(pDX, IDC_TRACECACHE, m_traceCache);
	DDX_Text(pDX, IDC_SIGNATURE, m_signature);
	DDX_Text(pDX, IDC_L2CACHE, m_L2Cache);
	DDX_Text(pDX, IDC_DEFVCORE, m_defaultVCore);
	DDX_Text(pDX, IDC_HTSUPPORT, m_HTsupport);
	DDX_Text(pDX, IDC_MMX, m_MMX);
	DDX_Text(pDX, IDC_PSE36, m_PSE36);
	DDX_Text(pDX, IDC_SSE, m_SSE);
	DDX_Text(pDX, IDC_SSE2, m_SSE2);
	DDX_Text(pDX, IDC_SSE3, m_SSE3);
	DDX_Text(pDX, IDC_AMD64, m_AMD64);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtCPUInfoItemDlg, CDialog)
	//{{AFX_MSG_MAP(CExtCPUInfoItemDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CACHEDETAILS, OnCachedetails)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_FEATURES, OnFeatures)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtCPUInfoItemDlg message handlers

BOOL CExtCPUInfoItemDlg::OnEraseBkgnd(CDC* pDC) 
{


	return TRUE;
}

BOOL CExtCPUInfoItemDlg::OnInitDialog() 
{

	CCPUInformations i;


	m_vendorName=i.GetVendorString();
	m_cpuName=i.GetCPUName();
	m_codeName=i.GetCodeName();
	m_platform=i.GetSocketName();
	m_brandName=i.GetBrandString();
	m_frequency=i.GetCPUFrequency();
	m_multiplier=i.GetMultiplier();
	m_signature=i.GetCPUFeatures();
	m_L1ICache=i.GetL1ICache();
	m_L1DCache=i.GetL1DCache();
	m_L2Cache=i.GetL2Cache();
	m_traceCache=i.GetTraceCache();
	m_frequencyRange=i.GetFrequencyRange();
	m_defaultVCore=i.GetDefaultVCore();
	m_HTsupport=i.GetHTSupport();
	m_MMX=i.GetMMXSupport();
	m_SSE=i.GetSSESupport();
	m_SSE2=i.GetSSE2Support();
	m_SSE3=i.GetSSE3Support();
	m_AMD64=i.GetAMD64Support();
	m_PSE36=i.GetPSE36Support();

	

	
	((CStatic*)GetDlgItem(IDC_CPULOGO))->SetBitmap(::LoadBitmap(AfxGetInstanceHandle(),i.GetLogoName()+"large"));

	
	GetDlgItem(IDC_LBL1)->SetFont(&fntLbl);
	GetDlgItem(IDC_LBL2)->SetFont(&fntLbl);
	GetDlgItem(IDC_LBL3)->SetFont(&fntLbl);
	GetDlgItem(IDC_LBL4)->SetFont(&fntLbl);
	GetDlgItem(IDC_LBL5)->SetFont(&fntLbl);

	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CExtCPUInfoItemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	return hbr;
}


void CExtCPUInfoItemDlg::OnCachedetails() 
{

	CCacheInfoDlg dlg;

	dlg.DoModal();
	
}

void CExtCPUInfoItemDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	 	
	// Do not call CDialog::OnPaint() for painting messages
}

void CExtCPUInfoItemDlg::OnFeatures() 
{
	CCPUFeaturesDlg dlg;
	
	dlg.DoModal();
}


void CExtCPUInfoItemDlg::Update(){

	CCPUInformations i;

	m_frequency="";
	m_multiplier="";

	UpdateData(FALSE);

	m_frequency=i.GetCPUFrequency();
	m_multiplier=i.GetMultiplier();

	UpdateData(FALSE);


	Invalidate();

}



BOOL CExtCPUInfoItemDlg::DestroyWindow() 
{

	fntLbl.DeleteObject();
	//((CStatic*)GetDlgItem(IDC_CPULOGO))->GetBitmap()->ReleaseObject();
	return CDialog::DestroyWindow();
}
