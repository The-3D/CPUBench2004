// DatabaseBenchmark.h: interface for the CDatabaseBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEBENCHMARK_H__DA2D0712_5095_4B47_BFC5_ED8936522215__INCLUDED_)
#define AFX_DATABASEBENCHMARK_H__DA2D0712_5095_4B47_BFC5_ED8936522215__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Benchmark.h"

class CDatabaseBenchmark : public CBenchmark  
{
public:
	CDatabaseBenchmark() {

		m_name="Database test";

		m_description="This benchmark measures CPU performance using Microsoft office Jet Database engine";

		m_techDetails="Engine used: MS Jet 4.0\n\nInterface: OLE DB";

	}

	virtual ~CDatabaseBenchmark();


protected:

	bool InitBenchmarkData(CBenchmarkEnvironment *e){
	
		return true;
	}

	int StartSimulation(char* schema,int);

	bool RunSchema(int numSchema,CBenchmarkEnvironment *e,CString& out,char* schema,CString query,int numprocesses,int repeatCount,bool bShow);


	bool StartBenchmark(CBenchmarkEnvironment *e);


	void EndBenchmark() {}


};

#endif // !defined(AFX_DATABASEBENCHMARK_H__DA2D0712_5095_4B47_BFC5_ED8936522215__INCLUDED_)
