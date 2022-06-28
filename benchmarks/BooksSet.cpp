// BooksSet.cpp : implementation file
//

#include "stdafx.h"
#include "benchmarks.h"
#include "BooksSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBooksSet

IMPLEMENT_DYNAMIC(CBooksSet, CDaoRecordset)

CBooksSet::CBooksSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBooksSet)
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


CString CBooksSet::GetDefaultDBName()
{
	return _T(".\\data.mdb");
}

CString CBooksSet::GetDefaultSQL()
{
	return _T("");
}

void CBooksSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBooksSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBooksSet diagnostics

#ifdef _DEBUG
void CBooksSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CBooksSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
