// mbinfo.h : main header file for the MBINFO DLL
//

#if !defined(AFX_MBINFO_H__57F632E4_3717_4069_B673_C148B5E25FE6__INCLUDED_)
#define AFX_MBINFO_H__57F632E4_3717_4069_B673_C148B5E25FE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMbinfoApp
// See mbinfo.cpp for the implementation of this class
//

class CMbinfoApp : public CWinApp
{
public:
	CMbinfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMbinfoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMbinfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MBINFO_H__57F632E4_3717_4069_B673_C148B5E25FE6__INCLUDED_)
