// BenchmarkEnvironment.h: interface for the CBenchmarkEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_)
#define AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "benchmarkdlg.h"

class CBenchmarkEnvironmentException {

protected:
	CString errCode;

public:
	CString GetErrorMessage() const {

		return errCode;
	}

};

class CInitFailureException : public CBenchmarkEnvironmentException {

public:
	CInitFailureException(){
		
		errCode="The application fails to init basic benchmarking environment features; cannot run the benchmark.";
	}

};

class CBenchmarkEnvironment  
{


	void ChangeVideoResolution(int width,int height,int bpp,int frequency){


		DEVMODE d;
		ZeroMemory(&d,sizeof(DEVMODE));

		d.dmSize=sizeof(DEVMODE);
		d.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL | DM_DISPLAYFREQUENCY;

		d.dmPelsWidth = width;
		d.dmPelsHeight = height;
		d.dmBitsPerPel=bpp;
		d.dmDisplayFrequency=frequency;


		if(ChangeDisplaySettings(&d,0) != DISP_CHANGE_SUCCESSFUL)
			throw new CInitFailureException();


	}

public:
	CBenchmarkEnvironment();

	void InitBenchmarkingEnvironment();

	void CloseBenchmarkingEnvironment();

	void CleanBenchmarkingEnvironment(){

		m_wndEnv->CleanOutTarget();

	}


	CStatic* GetOutTarget(int target) { return m_wndEnv->GetOutTarget(target); }

	void SetOutMode(CBenchmarkDlg::OUT_MODE mode){

		m_wndEnv->SetOutMode(mode);
	}

	CBenchmarkDlg::OUT_MODE GetOutMode(){

		return m_wndEnv->GetOutMode();
	}

	void UpdateStatus(CString status){

		m_wndEnv->UpdateStatus(status);
	}

	void Step(int val) {

		m_wndEnv->Step(val);

	}

	void StepTotalProgress(int val) {

		m_wndEnv->StepTotalProgress(val);

	}


	void SetTestInfo(CString name,CString testDesc,CString features){

		m_wndEnv->SetTestInfo(name,testDesc,features);

	}



	void SetFinished(BOOL bFinished){

		m_wndEnv->SetFinished(bFinished);

	}


	bool StopExecutionRequested(){
		return m_wndEnv->StopExecutionRequested();
	}


	void ShowBenchDescriptionImage(CString testName);

	virtual ~CBenchmarkEnvironment();

private:

	CBenchmarkDlg* m_wndEnv;
	DWORD m_msgThreadID;

	DEVMODE m_oldMode; //memorizzo la risoluzione dello schermo
};

#endif // !defined(AFX_BENCHMARKENVIRONMENT_H__F8C5BD45_A0EC_49D9_9CFB_314AFE4EE767__INCLUDED_)
