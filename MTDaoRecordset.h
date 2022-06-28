// MTDaoRecordset.h: interface for the CMTDaoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTDAORECORDSET_H__AF2EC5F0_1722_455F_8407_AC68B467139F__INCLUDED_)
#define AFX_MTDAORECORDSET_H__AF2EC5F0_1722_455F_8407_AC68B467139F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxmt.h>
#include <afxdao.h>

class CMTDaoRecordset;

////////////////////////////////////////////////////////////////////////
// CDaoDatabase - a DAO Database

class CMTDaoDatabase : public CDaoDatabase
{
	friend CMTDaoRecordset;
protected:
	static CCriticalSection m_cs;

	DECLARE_DYNAMIC(CMTDaoDatabase)

// Constructors
public:
	CMTDaoDatabase(CDaoWorkspace* pWorkspace = NULL) : CDaoDatabase(pWorkspace)
	{
	}

	virtual void Create(LPCTSTR lpszName,
		LPCTSTR lpszLocale = dbLangGeneral, int dwOptions = 0)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::Create(lpszName, lpszLocale, dwOptions);
	}

	virtual void Open(LPCTSTR lpszName, BOOL bExclusive = FALSE,
		BOOL bReadOnly = FALSE, LPCTSTR lpszConnect = _T(""))
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::Open(lpszName, bExclusive, bReadOnly, lpszConnect);
	}
	virtual void Close()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::Close();
	}

// Attributes
public:

	BOOL IsOpen() const
	{
		return CDaoDatabase::IsOpen();
	}
	BOOL CanUpdate()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::CanUpdate();
	}
	BOOL CanTransact()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::CanTransact();
	}

	CString GetName()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetName();
	}
	CString GetConnect()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetConnect();
	}

	CString GetVersion()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetVersion();
	}
	short GetQueryTimeout()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetQueryTimeout();
	}
	void SetQueryTimeout(short nSeconds)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::SetQueryTimeout(nSeconds);
	}
	long GetRecordsAffected()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetRecordsAffected();
	}

// Operations
public:
	void Execute(LPCTSTR lpszSQL, int nOptions = dbFailOnError)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::Execute(lpszSQL, nOptions);
	}

	void DeleteTableDef(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::DeleteTableDef(lpszName);
	}
	void DeleteQueryDef(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::DeleteQueryDef(lpszName);
	}

	void CreateRelation(LPCTSTR lpszName, LPCTSTR lpszTable,
		LPCTSTR lpszForeignTable, long lAttributes,
		LPCTSTR lpszField, LPCTSTR lpszForeignField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::CreateRelation(lpszName, lpszTable, lpszForeignTable, lAttributes, lpszField, lpszForeignField);
	}
	void CreateRelation(CDaoRelationInfo& relinfo)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::CreateRelation(relinfo);
	}
	void DeleteRelation(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::DeleteRelation(lpszName);
	}

	short GetTableDefCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetTableDefCount();
	}
	void GetTableDefInfo(int nIndex, CDaoTableDefInfo& tabledefinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetTableDefInfo(nIndex, tabledefinfo, dwInfoOptions);
	}
	void GetTableDefInfo(LPCTSTR lpszName, CDaoTableDefInfo& tabledefinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetTableDefInfo(lpszName, tabledefinfo, dwInfoOptions);
	}

	short GetRelationCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetRelationCount();
	}
	void GetRelationInfo(int nIndex, CDaoRelationInfo& relinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetRelationInfo(nIndex, relinfo, dwInfoOptions);
	}
	void GetRelationInfo(LPCTSTR lpszName, CDaoRelationInfo& relinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetRelationInfo(lpszName, relinfo, dwInfoOptions);
	}

	short GetQueryDefCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoDatabase::GetQueryDefCount();
	}
	void GetQueryDefInfo(int nIndex, CDaoQueryDefInfo& querydefinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetQueryDefInfo(nIndex, querydefinfo, dwInfoOptions);
	}
	void GetQueryDefInfo(LPCTSTR lpszName, CDaoQueryDefInfo& querydefinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoDatabase::GetQueryDefInfo(lpszName, querydefinfo, dwInfoOptions);
	}

// Implementation
public:
	virtual ~CMTDaoDatabase()
	{
	}

#ifdef _DEBUG
	virtual void AssertValid() const
	{
		CDaoDatabase::AssertValid();
	}
	virtual void Dump(CDumpContext& dc) const
	{
		CDaoDatabase::Dump(dc);
	}
#endif

};

////////////////////////////////////////////////////////////////////////
// CMTDaoRecordset - the result of a query or base table browse

class CMTDaoRecordset : public CDaoRecordset
{
// Constructor
public:
	CMTDaoRecordset(CDaoDatabase* pDatabase = NULL) : CDaoRecordset(pDatabase)
	{
	}

	DECLARE_DYNAMIC(CMTDaoRecordset)

	virtual void Open(int nOpenType = AFX_DAO_USE_DEFAULT_TYPE,
		LPCTSTR lpszSQL = NULL, int nOptions = 0)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Open(nOpenType, lpszSQL, nOptions);
	}
	virtual void Open(CDaoQueryDef* pQueryDef,
		int nOpenType = dbOpenDynaset, int nOptions = 0)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Open(pQueryDef, nOpenType, nOptions);
	}
	virtual void Open(CDaoTableDef* pTableDef,
		int nOpenType = dbOpenTable, int nOptions = 0)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Open(pTableDef, nOpenType, nOptions);
	}
	virtual void Close()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Close();
	}

	BOOL CanUpdate() const
	{
		return CDaoRecordset::CanUpdate();
	}
	BOOL CanAppend() const
	{
		return CDaoRecordset::CanAppend();
	}
	BOOL CanScroll() const
	{
		return CDaoRecordset::CanScroll();
	}
	BOOL CanRestart()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::CanRestart();
	}
	BOOL CanTransact()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::CanTransact();
	}
	BOOL CanBookmark()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::CanBookmark();
	}

	BOOL IsOpen() const
	{
		return CDaoRecordset::IsOpen();
	}
	BOOL IsBOF() const
	{
		return CDaoRecordset::IsBOF();
	}
	BOOL IsEOF() const
	{
		return CDaoRecordset::IsEOF();
	}
	BOOL IsDeleted() const
	{
		return CDaoRecordset::IsDeleted();
	}

	BOOL IsFieldDirty(void* pv)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldDirty(pv);
	}
	BOOL IsFieldNull(void* pv)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldNull(pv);
	}
	BOOL IsFieldNullable(void* pv)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldNullable(pv);
	}

	CString GetName()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetName();
	}
	short GetType()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetType();
	}
	short GetEditMode()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetEditMode();
	}
	CString GetSQL() const
	{
		return CDaoRecordset::GetSQL();
	}

	COleDateTime GetDateCreated()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetDateCreated();
	}
	COleDateTime GetDateLastUpdated()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetDateLastUpdated();
	}
	COleVariant GetLastModifiedBookmark()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetLastModifiedBookmark();
	}
	CString GetValidationRule()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetValidationRule();
	}
	CString GetValidationText()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetValidationText();
	}
	CString GetCurrentIndex()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetCurrentIndex();
	}
	void SetCurrentIndex(LPCTSTR lpszIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetCurrentIndex(lpszIndex);
	}

	long GetRecordCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetRecordCount();
	}

// Operations
public:
	// Cursor operations
	void MoveNext()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::MoveNext();
	}
	void MovePrev()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::MovePrev();
	}
	void MoveFirst()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::MoveFirst();
	}
	void MoveLast()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::MoveLast();
	}
	virtual void Move(long lRows)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Move(lRows);
	}

	BOOL FindNext(LPCTSTR lpszFilter)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::FindNext(lpszFilter);
	}
	BOOL FindPrev(LPCTSTR lpszFilter)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::FindPrev(lpszFilter);
	}
	BOOL FindFirst(LPCTSTR lpszFilter)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::FindFirst(lpszFilter);
	}
	BOOL FindLast(LPCTSTR lpszFilter)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::FindLast(lpszFilter);
	}
	virtual BOOL Find(long lFindType, LPCTSTR lpszFilter)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::Find(lFindType, lpszFilter);
	}

	COleVariant GetBookmark()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetBookmark();
	}
	void SetBookmark(COleVariant varBookmark)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetBookmark(varBookmark);
	}
	long GetAbsolutePosition()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetAbsolutePosition();
	}
	void SetAbsolutePosition(long lPosition)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetAbsolutePosition(lPosition);
	}
	float GetPercentPosition()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetPercentPosition();
	}
	void SetPercentPosition(float fPosition)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetPercentPosition(fPosition);
	}

	// seek allowed on recordset opened as tables (max keys = 13)
	BOOL Seek(LPCTSTR lpszComparison, COleVariant* pKey1,
		COleVariant* pKey2 = NULL, COleVariant* pKey3 = NULL)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return 	CDaoRecordset::Seek(lpszComparison, pKey1, pKey2, pKey3);
	}
	BOOL Seek(LPCTSTR lpszComparison, COleVariant* pKeyArray, WORD nKeys)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Seek(lpszComparison, pKeyArray, nKeys);
	}

	// edit buffer operations
	virtual void AddNew()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::AddNew();
	}
	virtual void Edit()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Edit();
	}
	virtual void Update()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Update();
	}
	virtual void Delete()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Delete();
	}
	virtual void CancelUpdate()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::CancelUpdate();
	}

	// field operations
	virtual void GetFieldValue(LPCTSTR lpszName, COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetFieldValue(lpszName, varValue);
	}
	virtual void GetFieldValue(int nIndex, COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetFieldValue(nIndex, varValue);
	}
	virtual void SetFieldValue(LPCTSTR lpszName,
		const COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValue(lpszName, varValue);
	}
	virtual void SetFieldValue(int nIndex,
		const COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValue(nIndex, varValue);
	}
	void SetFieldValue(int nIndex, LPCTSTR lpszValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValue(nIndex, lpszValue);
	}
	void SetFieldValue(LPCTSTR lpszName, LPCTSTR lpszValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValue(lpszName, lpszValue);
	}
	void SetFieldValueNull(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValueNull(lpszName);
	}
	void SetFieldValueNull(int nIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldValueNull(nIndex);
	}

	virtual COleVariant GetParamValue(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetParamValue(lpszName);
	}
	virtual COleVariant GetParamValue(int nIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetParamValue(nIndex);
	}
	virtual void SetParamValue(LPCTSTR lpszName,
		const COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetParamValue(lpszName, varValue);
	}
	virtual void SetParamValue(int nIndex,
		const COleVariant& varValue)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetParamValue(nIndex, varValue);
	}
	void SetParamValueNull(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetParamValueNull(lpszName);
	}
	void SetParamValueNull(int nIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetParamValueNull(nIndex);
	}

	void SetFieldDirty(void* pv, BOOL bDirty = TRUE)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldDirty(pv, bDirty);
	}
	void SetFieldNull(void* pv, BOOL bNull = TRUE)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetFieldNull(pv, bNull);
	}

	void SetLockingMode(BOOL bPessimistic)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetLockingMode(bPessimistic);
	}
	BOOL GetLockingMode()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetLockingMode();
	}

	// Recordset operations
	virtual void Requery()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::Requery();
	}

	// Jet's remote data caching operations
	void SetCacheStart(COleVariant varBookmark)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetCacheStart(varBookmark);
	}
	COleVariant GetCacheStart()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetCacheStart();
	}
	void SetCacheSize(long lSize)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetCacheSize(lSize);
	}
	long GetCacheSize()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetCacheSize();
	}
	void FillCache(long* pSize = NULL, COleVariant* pBookmark = NULL)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::FillCache(pSize, pBookmark);
	}

	short GetFieldCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetFieldCount();
	}
	void GetFieldInfo(int nIndex, CDaoFieldInfo& fieldinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetFieldInfo(nIndex, fieldinfo, dwInfoOptions);
	}
	void GetFieldInfo(LPCTSTR lpszName, CDaoFieldInfo& fieldinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetFieldInfo(lpszName, fieldinfo, dwInfoOptions);
	}

	short GetIndexCount()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetIndexCount();
	}
	void GetIndexInfo(int nIndex, CDaoIndexInfo& indexinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetIndexInfo(nIndex, indexinfo, dwInfoOptions);
	}
	void GetIndexInfo(LPCTSTR lpszName, CDaoIndexInfo& indexinfo,
		DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetIndexInfo(lpszName, indexinfo, dwInfoOptions);
	}

// Overridables
public:
	virtual CString GetDefaultDBName()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetDefaultDBName();
	}
	virtual CString GetDefaultSQL()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetDefaultSQL();
	}

	// for recordset field exchange
	virtual void DoFieldExchange(CDaoFieldExchange* pFX)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::DoFieldExchange(pFX);
	}

// Implementation
public:
	virtual ~CMTDaoRecordset()
	{
	}

	// Out-of-date functions kept for backward compatability
	virtual COleVariant GetFieldValue(LPCTSTR lpszName)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetFieldValue(lpszName);
	}
	virtual COleVariant GetFieldValue(int nIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetFieldValue(nIndex);
	}

#ifdef _DEBUG
	virtual void AssertValid() const
	{
		CDaoRecordset::AssertValid();
	}
	virtual void Dump(CDumpContext& dc) const
	{
		CDaoRecordset::Dump(dc);
	}
#endif

	void SetCursorAttributes()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetCursorAttributes();
	}
	void GetDataAndFixupNulls()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::GetDataAndFixupNulls();
	}
	DWORD GetFieldLength(int nFieldIndex)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::GetFieldLength(nFieldIndex);
	}

	BOOL IsFieldStatusDirty(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldStatusDirty(nField);
	}
	void SetDirtyFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetDirtyFieldStatus(nField);
	}
	void ClearDirtyFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::ClearDirtyFieldStatus(nField);
	}

	BOOL IsFieldStatusNull(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldStatusNull(nField);
	}
	void SetNullFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetNullFieldStatus(nField);
	}
	void ClearNullFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::ClearNullFieldStatus(nField);
	}

	BOOL IsFieldStatusNullable(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldStatusNullable(nField);
	}
	void SetNullableFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetNullableFieldStatus(nField);
	}

	BOOL IsFieldStatusNullableKnown(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsFieldStatusNullableKnown(nField);
	}
	void SetNullableKnownFieldStatus(UINT nField)
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::SetNullableKnownFieldStatus(nField);
	}

	void ClearFieldStatusFlags()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		CDaoRecordset::ClearFieldStatusFlags();
	}
	BOOL IsMatch()
	{
		CSingleLock sl(&CMTDaoDatabase::m_cs, TRUE);
		return CDaoRecordset::IsMatch();
	}
};


#endif // !defined(AFX_MTDAORECORDSET_H__AF2EC5F0_1722_455F_8407_AC68B467139F__INCLUDED_)
