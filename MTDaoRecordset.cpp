// MTDaoRecordset.cpp: implementation of the CMTDaoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MTDaoRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNAMIC(CMTDaoDatabase, CDaoDatabase)
IMPLEMENT_DYNAMIC(CMTDaoRecordset, CDaoRecordset)

CCriticalSection CMTDaoDatabase::m_cs;