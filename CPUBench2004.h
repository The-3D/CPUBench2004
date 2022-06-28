// CPUBench2004.h : main header file for the CPUBENCH2004 application
//

#if !defined(AFX_CPUBENCH2004_H__53AC0C07_55AC_4534_9B09_86CEBD3F15AA__INCLUDED_)
#define AFX_CPUBENCH2004_H__53AC0C07_55AC_4534_9B09_86CEBD3F15AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCPUBench2004App:
// See CPUBench2004.cpp for the implementation of this class
//

class CCPUBench2004App : public CWinApp
{
public:
	CCPUBench2004App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUBench2004App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCPUBench2004App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUBENCH2004_H__53AC0C07_55AC_4534_9B09_86CEBD3F15AA__INCLUDED_)
