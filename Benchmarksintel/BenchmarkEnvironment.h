// BenchmarkEnvironment.h: interface for the CBenchmarkEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_)
#define AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "benchmarkdlg.h"


class CBenchmarkEnvironment  
{
public:
	CBenchmarkEnvironment();

	void InitBenchmarkingEnvironment();

	void CloseBenchmarkingEnvironment();

	CStatic* GetOutTarget() { return m_wndEnv->GetOutTarget(); }

	void UpdateStatus(CString status){

		m_wndEnv->UpdateStatus(status);

	}

	void Step(int val) {

		m_wndEnv->Step(val);

	}

	void SetFinished(BOOL bFinished){

		m_wndEnv->SetFinished(bFinished);

	}

	virtual ~CBenchmarkEnvironment();

private:
	void ShowTestSplash(CString testName,CString testDescription);


private:

	CBenchmarkDlg* m_wndEnv;
};

#endif // !defined(AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_)
