// PublishersSet.cpp : implementation file
//

#include "stdafx.h"
#include "benchmarks.h"
#include "PublishersSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPublishersSet

IMPLEMENT_DYNAMIC(CPublishersSet, CDaoRecordset)

CPublishersSet::CPublishersSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPublishersSet)
	m_PubID = 0;
	m_Name = _T("");
	m_Company_Name = _T("");
	m_Address = _T("");
	m_City = _T("");
	m_State = _T("");
	m_Zip = _T("");
	m_Telephone = _T("");
	m_Fax = _T("");
	m_Comments = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


CString CPublishersSet::GetDefaultDBName()
{
	return _T(".\\data.mdb");
}

CString CPublishersSet::GetDefaultSQL()
{
	return _T("[Publishers]");
}

void CPublishersSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPublishersSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[PubID]"), m_PubID);
	DFX_Text(pFX, _T("[Name]"), m_Name);
	DFX_Text(pFX, _T("[Company Name]"), m_Company_Name);
	DFX_Text(pFX, _T("[Address]"), m_Address);
	DFX_Text(pFX, _T("[City]"), m_City);
	DFX_Text(pFX, _T("[State]"), m_State);
	DFX_Text(pFX, _T("[Zip]"), m_Zip);
	DFX_Text(pFX, _T("[Telephone]"), m_Telephone);
	DFX_Text(pFX, _T("[Fax]"), m_Fax);
	DFX_Text(pFX, _T("[Comments]"), m_Comments);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPublishersSet diagnostics

#ifdef _DEBUG
void CPublishersSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CPublishersSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
