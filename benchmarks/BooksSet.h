#if !defined(AFX_BOOKSSET_H__E675C048_FCBB_4588_A87F_2B7F94387ECE__INCLUDED_)
#define AFX_BOOKSSET_H__E675C048_FCBB_4588_A87F_2B7F94387ECE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BooksSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBooksSet DAO recordset

class CBooksSet : public CDaoRecordset
{
public:
	CBooksSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBooksSet)

// Field/Param Data
	//{{AFX_FIELD(CBooksSet, CDaoRecordset)
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBooksSet)
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

#endif // !defined(AFX_BOOKSSET_H__E675C048_FCBB_4588_A87F_2B7F94387ECE__INCLUDED_)
