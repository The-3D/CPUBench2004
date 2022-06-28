// CPUInfoItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUInfoItemDlg.h"
#include "itembkdrawer.h"
#include "cpuinformations.h"
#include "sysinfodlg.h"
#include "cacheinfodlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoItemDlg dialog


CCPUInfoItemDlg::CCPUInfoItemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUInfoItemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUInfoItemDlg)
	m_brandName = _T("");
	m_codeName = _T("");
	m_cpuName = _T("");
	m_cpuVendor = _T("");
	m_frequency = _T("");
	m_L1DCache = _T("");
	m_L1ICache = _T("");
	m_L2Cache = _T("");
	m_signature = _T("");
	m_socket = _T("");
	m_traceCache = _T("");
	m_busType = _T("");
	m_fsbSpeed = _T("");
	//}}AFX_DATA_INIT

}


void CCPUInfoItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUInfoItemDlg)
	DDX_Control(pDX, IDC_CACHEINFO, m_cacheinfo);
	DDX_Control(pDX, IDC_ADVINFO, m_advinfo);
	DDX_Text(pDX, IDC_BRANDNAME, m_brandName);
	DDX_Text(pDX, IDC_CODENAME, m_codeName);
	DDX_Text(pDX, IDC_CPUNAME, m_cpuName);
	DDX_Text(pDX, IDC_CPUVENDOR, m_cpuVendor);
	DDX_Text(pDX, IDC_FREQUENCY, m_frequency);
	DDX_Text(pDX, IDC_L1DATACACHE, m_L1DCache);
	DDX_Text(pDX, IDC_L1INSTRCACHE, m_L1ICache);
	DDX_Text(pDX, IDC_L2CACHE, m_L2Cache);
	DDX_Text(pDX, IDC_SIGNATURE, m_signature);
	DDX_Text(pDX, IDC_SOCKETNAME, m_socket);
	DDX_Text(pDX, IDC_TRACECACHE, m_traceCache);
	DDX_Text(pDX, IDC_BUSTYPE, m_busType);
	DDX_Text(pDX, IDC_BUSSPEED, m_fsbSpeed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCPUInfoItemDlg, CDialog)
	//{{AFX_MSG_MAP(CCPUInfoItemDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_ADVINFO, OnAdvinfo)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CACHEINFO, OnCacheinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoItemDlg message handlers

BOOL CCPUInfoItemDlg::OnEraseBkgnd(CDC* pDC) 
{




/*

  //abilitare se si vuole utilizzare l'alphablend

		CDC memDC;

		memDC.CreateCompatibleDC(pDC);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(pDC,r.Width(),r.Height());

		memDC.SelectObject(&bmp);

		BLENDFUNCTION bf;

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha =210;
		bf.AlphaFormat = 0;
	


		CGradient g;

		g.SetGradientColors(RGB(0xE3,0xE3,0xEC),RGB(255,255,255));

		g.SetDirection(g.BTT);

		g.DrawLinearGradient(&memDC,CRect(0,0,r.Width(),r.Height()));

//		memDC.FillSolidRect(0,0,itemRect.Width(),itemRect.Height(),RGB(255,255,255));

		AlphaBlend(*pDC,r.left,r.top,r.Width(),r.Height(),memDC,0,0,r.Width(),r.Height(),bf);


		CGdiObject *pOb=pDC->SelectObject(new CPen(PS_SOLID,1,RGB(0x70,0x6F,0x91)));


		pDC->MoveTo(r.left,r.top);
		pDC->LineTo(r.left,r.top+r.Height());
		pDC->LineTo(r.right,r.top+r.Height());
		pDC->LineTo(r.right,r.top-1);


  */

	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(pDC,&r);


    return TRUE;

}

HBRUSH CCPUInfoItemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CCPUInfoItemDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFont *tempFont=new CFont;

		
	CFont *pFont=GetFont();

	LOGFONT lf;

	pFont->GetLogFont(&lf);

	lf.lfWeight=FW_BOLD;


	tempFont->CreateFontIndirect(&lf);

	GetDlgItem(IDC_TITLE1)->SetFont(tempFont);
	GetDlgItem(IDC_TITLE2)->SetFont(tempFont);
	GetDlgItem(IDC_TITLE3)->SetFont(tempFont);


	//init cpu data


	CCPUInformations i;

	m_cpuVendor=i.GetVendorString();
	m_signature=i.GetCPUFeatures();
	m_frequency=i.GetCPUFrequency();
	m_L1ICache=i.GetL1ICache();
	m_L1DCache=i.GetL1DCache();
	m_L2Cache=i.GetL2Cache();
	m_traceCache=i.GetTraceCache();
	m_brandName=i.GetBrandString();
	m_brandName.TrimLeft();

	m_socket=i.GetSocketName();
	m_busType=i.GetBusType();
	m_codeName=i.GetCodeName();
	m_cpuName=i.GetCPUName();
	m_fsbSpeed=i.GetFSBSpeed();

	((CStatic*)GetDlgItem(IDC_CPULOGO))->SetBitmap(::LoadBitmap(AfxGetInstanceHandle(),i.GetLogoName()));



	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCPUInfoItemDlg::OnAdvinfo() 
{

	CSysInfoDlg dlg;

	dlg.DoModal();
}

void CCPUInfoItemDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Do not call CDialog::OnPaint() for painting messages
}

void CCPUInfoItemDlg::OnCacheinfo() 
{
	CCacheInfoDlg dlg;
	
	dlg.DoModal();
}
