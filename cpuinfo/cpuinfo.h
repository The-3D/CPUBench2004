// cpuinfo.h : main header file for the CPUINFO DLL
//

#if !defined(AFX_CPUINFO_H__1AD0ED21_8F45_4828_B087_CC795EA33880__INCLUDED_)
#define AFX_CPUINFO_H__1AD0ED21_8F45_4828_B087_CC795EA33880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCpuinfoApp
// See cpuinfo.cpp for the implementation of this class
//

class CCpuinfoApp : public CWinApp
{
public:
	CCpuinfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCpuinfoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CCpuinfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUINFO_H__1AD0ED21_8F45_4828_B087_CC795EA33880__INCLUDED_)
