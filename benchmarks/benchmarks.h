// benchmarks.h : main header file for the BENCHMARKS DLL
//

#if !defined(AFX_BENCHMARKS_H__7E222139_491E_49B5_80E1_5D5898B12219__INCLUDED_)
#define AFX_BENCHMARKS_H__7E222139_491E_49B5_80E1_5D5898B12219__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBenchmarksApp
// See benchmarks.cpp for the implementation of this class
//

class CBenchmarksApp : public CWinApp
{
public:
	CBenchmarksApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarksApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CBenchmarksApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKS_H__7E222139_491E_49B5_80E1_5D5898B12219__INCLUDED_)
