// Benchmark.h: interface for the CBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_)
#define AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "benchmarkenvironment.h"


class CBenchmark  
{
public:
	CBenchmark();

	CString GetBenchmarkName() { return m_name; }
	CString GetBenchmarkDescription() { return m_description; }


	bool Run(CBenchmarkEnvironment* e){
		if(PrepareBenchmarkExecution(e) && StartBenchmark(e)){
			EndBenchmark();
			return true;
		}

		return false;
	}
	float GetBenchmarkResult() { return result; }

	virtual ~CBenchmark();

protected:

	virtual bool InitBenchmarkData(CBenchmarkEnvironment *e) =0;
	virtual bool StartBenchmark(CBenchmarkEnvironment *e) =0;
	virtual void EndBenchmark() =0;

	bool PrepareBenchmarkExecution(CBenchmarkEnvironment *e){
	

		e->SetTestInfo(m_name,m_description,m_techDetails);

		CBenchmarkDlg::OUT_MODE oldMode=e->GetOutMode();

		e->SetOutMode(CBenchmarkDlg::SINGLE_WINDOW);

		e->CleanBenchmarkingEnvironment();

		e->ShowBenchDescriptionImage(m_name);

		result=InitBenchmarkData(e);

		Sleep(2500);

		if(!result)
			e->UpdateStatus("Test initialization failed. Aborting...");


		e->SetOutMode(oldMode);

		e->CleanBenchmarkingEnvironment();

		return result;

	}


	CString m_name,m_description,m_techDetails;
	float result;
};

#endif // !defined(AFX_BENCHMARK_H__9CD0A782_E078_400C_965C_99439ABCC847__INCLUDED_)
