#if !defined(AFX_EXTPROGRESS_H__41EB1946_3B81_46BD_890F_73F0CA7362D3__INCLUDED_)
#define AFX_EXTPROGRESS_H__41EB1946_3B81_46BD_890F_73F0CA7362D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtProgress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtProgress window

class CExtProgressCtrl : public CProgressCtrl
{
// Construction
public:
	CExtProgressCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtProgress)
	//}}AFX_VIRTUAL

	void SetAlertPos(int pos,BOOL bLessThan = TRUE){

		m_alertPos=pos;
		m_bLessThan=bLessThan;
	}


	int m_alertPos;
	BOOL m_bLessThan; // se TRUE la barra diventa rossa quando il valore è < di m_alertPos

// Implementation
public:
	virtual ~CExtProgressCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CExtProgressCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnNcPaint();
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTPROGRESS_H__41EB1946_3B81_46BD_890F_73F0CA7362D3__INCLUDED_)
