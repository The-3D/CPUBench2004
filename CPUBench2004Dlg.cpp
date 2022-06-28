// CPUBench2004Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUBench2004.h"
#include "CPUBench2004Dlg.h"
#include "resultdlg.h"
#include "splashdlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004Dlg dialog

CCPUBench2004Dlg::CCPUBench2004Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUBench2004Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUBench2004Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPUBench2004Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUBench2004Dlg)
	DDX_Control(pDX, IDC_LOGO, m_logo);
	DDX_Control(pDX, IDC_EXIT, m_exit);
	DDX_Control(pDX, IDC_BUTTON2, m_bHelp);
	DDX_Control(pDX, IDC_RUNBENCHMARK, m_bRun);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCPUBench2004Dlg, CDialog)
	//{{AFX_MSG_MAP(CCPUBench2004Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_RUNBENCHMARK, OnRunbenchmark)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004Dlg message handlers

BOOL CCPUBench2004Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect r;

	GetClientRect(&r);
	
	w.SetCtrlRect(&r);

	w.BuildInterface();

	m_logo.LoadImage("logo");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCPUBench2004Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCPUBench2004Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		w.Draw(&dc);



	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCPUBench2004Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCPUBench2004Dlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	SetFocus();	
	CDialog::OnMouseMove(nFlags, point);
}

void CCPUBench2004Dlg::OnExit() 
{
	OnCancel();	
}

BOOL CCPUBench2004Dlg::OnEraseBkgnd(CDC* pDC) 
{
	

	return FALSE;//CDialog::OnEraseBkgnd(pDC);
}

void CCPUBench2004Dlg::OnRunbenchmark() 
{

	typedef float (CALLBACK* Run_Benchmark)();
	
	HINSTANCE hLib=AfxLoadLibrary("benchmarks.dll");

	if(hLib==NULL){
		MessageBox("Error loading Benchmarks DLL. Cannot run the benchmark.","Error",MB_OK | MB_ICONERROR);
		return;
	}

	HANDLE myHandle=GetCurrentProcess();

	SetPriorityClass(myHandle,REALTIME_PRIORITY_CLASS);


	Run_Benchmark RunBenchmark=(Run_Benchmark)GetProcAddress(hLib,"RunBenchmark");

	
	float result;
	if(RunBenchmark != NULL)
		result=RunBenchmark();
	else MessageBox("Cannot find benchmarks.dll. ","Error",MB_ICONWARNING);


	SetPriorityClass(myHandle,NORMAL_PRIORITY_CLASS);

	AfxFreeLibrary(hLib);
 

	CResultDlg dlg;

	dlg.DoModal();
	
}
