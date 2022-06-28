// ProvaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "ProvaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProvaDlg dialog


CProvaDlg::CProvaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProvaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProvaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProvaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProvaDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProvaDlg, CDialog)
	//{{AFX_MSG_MAP(CProvaDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProvaDlg message handlers
