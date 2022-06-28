#if !defined(AFX_FLEXGUIBUTTON_H__DB547E0D_8B27_4A3C_9731_3A46412136E3__INCLUDED_)
#define AFX_FLEXGUIBUTTON_H__DB547E0D_8B27_4A3C_9731_3A46412136E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlexGUIButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlexGUIButton window

class CFlexGUIButton : public CButton
{
// Construction
public:
	CFlexGUIButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlexGUIButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlexGUIButton();

	void DrawBorder(CDC* dc);

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlexGUIButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	int state;

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLEXGUIBUTTON_H__DB547E0D_8B27_4A3C_9731_3A46412136E3__INCLUDED_)
