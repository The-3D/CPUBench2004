#if !defined(AFX_IMAGECTRL_H__B33136C4_CA9E_4F1F_805F_04B5C227E142__INCLUDED_)
#define AFX_IMAGECTRL_H__B33136C4_CA9E_4F1F_805F_04B5C227E142__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl window

class CImageCtrl : public CStatic
{
// Construction
public:
	CImageCtrl();
	void LoadImage(CString str);
	CBitmap bmp;
	bool bLoaded;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageCtrl)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECTRL_H__B33136C4_CA9E_4F1F_805F_04B5C227E142__INCLUDED_)
