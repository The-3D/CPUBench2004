// ExtMBInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "ExtMBInfoDlg.h"
#include "itembkdrawer.h"
#include "deviceinformations.h"
#include "cpuinformations.h"
#include "deviceslistdlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtMBInfoDlg dialog


CExtMBInfoDlg::CExtMBInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtMBInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtMBInfoDlg)
	m_biosDate = _T("");
	m_biosName = _T("");
	m_biosVersion = _T("");
	m_chipsetID = _T("");
	m_chipsetVendor = _T("");
	m_chipsetName = _T("");
	m_fsbSpeed = _T("");
	m_pciLatency = _T("");
	m_busType = _T("");
	//}}AFX_DATA_INIT

	fntLbl.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

}


void CExtMBInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtMBInfoDlg)
	DDX_Control(pDX, IDC_OTHERPCI, m_OtherPCI);
	DDX_Text(pDX, IDC_BIOSDATE, m_biosDate);
	DDX_Text(pDX, IDC_BIOSNAME, m_biosName);
	DDX_Text(pDX, IDC_BIOSVERSION, m_biosVersion);
	DDX_Text(pDX, IDC_CHIPSETID, m_chipsetID);
	DDX_Text(pDX, IDC_CHIPSETVENDOR, m_chipsetVendor);
	DDX_Text(pDX, IDC_NAME, m_chipsetName);
	DDX_Text(pDX, IDC_FSBSPEED, m_fsbSpeed);
	DDX_Text(pDX, IDC_PCILATENCY, m_pciLatency);
	DDX_Text(pDX, IDC_BUSTYPE, m_busType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtMBInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CExtMBInfoDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_OTHERPCI, OnOtherpci)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtMBInfoDlg message handlers

BOOL CExtMBInfoDlg::OnEraseBkgnd(CDC* pDC) 
{
	
	return TRUE;
}

HBRUSH CExtMBInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

			pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	return hbr;
}

BOOL CExtMBInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CDeviceInformations devInfo;
	CCPUInformations cpuInfo;

	GetDlgItem(IDC_LBL)->SetFont(&fntLbl);

	m_chipsetName=devInfo.GetChipsetName();
	m_fsbSpeed=cpuInfo.GetFSBSpeed();
	m_chipsetID=devInfo.GetChipsetID();
	m_busType=cpuInfo.GetBusType();
	m_chipsetVendor=devInfo.GetChipsetVendor();
	m_pciLatency=devInfo.GetChipsetPCILatency();
	m_biosName=devInfo.GetBIOSName();
	m_biosVersion=devInfo.GetBIOSVersion();
	m_biosDate=devInfo.GetBIOSDate();

	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExtMBInfoDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(&dc,&r);
	
	// Do not call CDialog::OnPaint() for painting messages
}


void CExtMBInfoDlg::Update(){

	CCPUInformations cpuInfo;

	m_fsbSpeed="";

	UpdateData(FALSE);

	m_fsbSpeed=cpuInfo.GetFSBSpeed();

	UpdateData(FALSE);


	Invalidate();


}

void CExtMBInfoDlg::OnOtherpci() 
{

	CDevicesListDlg dlg;

	dlg.DoModal();
	
}
