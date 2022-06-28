// videocompressor.h : main header file for the VIDEOCOMPRESSOR DLL
//

#if !defined(AFX_VIDEOCOMPRESSOR_H__C3E563AD_DB12_47C3_9600_911F9BCC6C14__INCLUDED_)
#define AFX_VIDEOCOMPRESSOR_H__C3E563AD_DB12_47C3_9600_911F9BCC6C14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVideocompressorApp
// See videocompressor.cpp for the implementation of this class
//

class CVideocompressorApp : public CWinApp
{
public:
	CVideocompressorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideocompressorApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CVideocompressorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOCOMPRESSOR_H__C3E563AD_DB12_47C3_9600_911F9BCC6C14__INCLUDED_)
