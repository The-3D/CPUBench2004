// DevicesListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "DevicesListDlg.h"
#include "deviceinformations.h"
#include "itembkdrawer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDevicesListDlg dialog


CDevicesListDlg::CDevicesListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDevicesListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDevicesListDlg)
	//}}AFX_DATA_INIT

	m_fntTitle.CreateFont(-11,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

}


void CDevicesListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDevicesListDlg)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_DEVLIST, m_devicesList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDevicesListDlg, CDialog)
	//{{AFX_MSG_MAP(CDevicesListDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDevicesListDlg message handlers

BOOL CDevicesListDlg::OnEraseBkgnd(CDC* pDC) 
{

	CRect r;

	GetClientRect(&r);

	CItemBkDrawer::DrawBk(pDC,&r);
	return TRUE;
}

HBRUSH CDevicesListDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC){

		pDC->SetBkMode(TRANSPARENT);
		//pDC->SetTextColor(RGB(0,0x74,0xDC));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}	
	
	return hbr;
}

BOOL CDevicesListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_devicesList.InsertColumn(0,"Item");
	m_devicesList.InsertColumn(1,"Description");
	m_devicesList.SetColumnWidth(0,100);
	m_devicesList.SetColumnWidth(1,350);



	GetDlgItem(IDC_TITLE)->SetFont(&m_fntTitle);

	CDeviceInformations devs;


	for(int i=0; i<devs.GetNumOfDevices()*6; i+=6){

		m_devicesList.InsertItem(i,"Device name:");
		m_devicesList.SetItemText(i,1,devs.GetDeviceName(i/6));

		m_devicesList.InsertItem(i+1,"Device Vendor:");
		m_devicesList.SetItemText(i+1,1,devs.GetDeviceVendor(i/6));

		m_devicesList.InsertItem(i+2,"Device ID:");
		m_devicesList.SetItemText(i+2,1,devs.GetDeviceID(i/6));

		m_devicesList.InsertItem(i+3,"Device Vendor ID:");
		m_devicesList.SetItemText(i+3,1,devs.GetDeviceVendorID(i/6));

		m_devicesList.InsertItem(i+4,"PCI Latency:");
		m_devicesList.SetItemText(i+4,1,devs.GetDevicePCILatency(i/6));

		m_devicesList.InsertItem(i+5,"");

	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
