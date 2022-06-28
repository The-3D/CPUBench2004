// Benchmark.h: interface for the CBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_)
#define AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "benchmarkenvironment.h"


class CInitFailureException : public CException {

};


class CBenchmark  
{
public:
	CBenchmark();

	CString GetBenchmarkName() { return m_name; }
	CString GetBenchmarkDescription() { return m_description; }

	virtual void InitBenchmarkData(CBenchmarkEnvironment *e) =0;
	virtual void StartBenchmark(CBenchmarkEnvironment *e) =0;
	virtual void EndBenchmark() =0;
	virtual float GetBenchmarkResult() =0;

	virtual ~CBenchmark();

protected:

	CString m_name,m_description;
};

#endif // !defined(AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_)
