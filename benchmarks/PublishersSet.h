#if !defined(AFX_PUBLISHERSSET_H__117C00FC_E914_4B7E_B979_717E914EBBA6__INCLUDED_)
#define AFX_PUBLISHERSSET_H__117C00FC_E914_4B7E_B979_717E914EBBA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PublishersSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPublishersSet DAO recordset

class CPublishersSet : public CDaoRecordset
{
public:
	CPublishersSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPublishersSet)

// Field/Param Data
	//{{AFX_FIELD(CPublishersSet, CDaoRecordset)
	long	m_PubID;
	CString	m_Name;
	CString	m_Company_Name;
	CString	m_Address;
	CString	m_City;
	CString	m_State;
	CString	m_Zip;
	CString	m_Telephone;
	CString	m_Fax;
	CString	m_Comments;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPublishersSet)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUBLISHERSSET_H__117C00FC_E914_4B7E_B979_717E914EBBA6__INCLUDED_)
