// benchmarks.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "benchmarks.h"
#include "BenchmarkEnvironment.h"
#include "videocompressionbenchmark.h"
#include "direct3dbenchmark.h"
#include "scientificbenchmark.h"
#include "databasebenchmark.h"
#include "raytracingbenchmark.h"
#include "cadbenchmark.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CBenchmarksApp

BEGIN_MESSAGE_MAP(CBenchmarksApp, CWinApp)
	//{{AFX_MSG_MAP(CBenchmarksApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchmarksApp construction

CBenchmarksApp::CBenchmarksApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBenchmarksApp object

CBenchmarksApp theApp;



DWORD WINAPI RunBench(LPVOID arg){

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString *res=(CString*)arg;

	try{

		CBenchmarkEnvironment *v=new CBenchmarkEnvironment;


		CVideoCompressionBenchmark* b=new CVideoCompressionBenchmark;

		v->SetFinished(TRUE);
		v->SetOutMode(CBenchmarkDlg::SINGLE_WINDOW);
		v->InitBenchmarkingEnvironment();

		v->SetFinished(FALSE);

		b->Run(v);

		float f1=b->GetBenchmarkResult();

		v->SetFinished(TRUE);

		v->CleanBenchmarkingEnvironment();

		delete b;

		if(v->StopExecutionRequested()){

			v->CloseBenchmarkingEnvironment();

			delete v;

			return -1;
		}

		CDirect3DBenchmark *b2=new CDirect3DBenchmark;
		
		b2->Run(v);

		v->StepTotalProgress(20);

		float f2=b2->GetBenchmarkResult();

		delete b2;

		if(v->StopExecutionRequested()){

			v->CloseBenchmarkingEnvironment();

			delete v;

			return -1;
		}


		v->SetFinished(TRUE);

		v->CleanBenchmarkingEnvironment();

		v->SetOutMode(CBenchmarkDlg::MULTI_WINDOW);

		v->CleanBenchmarkingEnvironment();

		CScientificBenchmark* b3=new CScientificBenchmark;
	
		b3->Run(v);

		float f3=b3->GetBenchmarkResult();

		delete b3;

		if(v->StopExecutionRequested()){

			v->CloseBenchmarkingEnvironment();

			delete v;

			return -1;
		}


		v->SetFinished(TRUE);

		v->SetOutMode(CBenchmarkDlg::MULTI_WINDOW);

		v->CleanBenchmarkingEnvironment();

		CCadBenchmark b5;
	
		b5.Run(v);

		float f4=b5.GetBenchmarkResult();

		if(v->StopExecutionRequested()){

			v->CloseBenchmarkingEnvironment();

			delete v;

			return -1;
		}

		v->CleanBenchmarkingEnvironment();

		v->SetOutMode(CBenchmarkDlg::SINGLE_WINDOW);

		v->CleanBenchmarkingEnvironment();


		CRayTracingBenchmark b4;
	
		b4.Run(v);

		float f5=b4.GetBenchmarkResult();

		if(v->StopExecutionRequested()){

			v->CloseBenchmarkingEnvironment();

			delete v;

			return -1;
		}

		v->CleanBenchmarkingEnvironment();

		CDatabaseBenchmark b6;
	
		b6.Run(v);

		float f6=b6.GetBenchmarkResult();

		Sleep(3000);


		v->CloseBenchmarkingEnvironment();

		delete v;


//		res->Format("Video compression: %1.2f fps\nD3D Rendering: %1.2f fps\nMolecule viewer: %1.2f fps\nCAD benchmark: %1.2f seconds\n",f1,f2,f3,f4);

		return 0;


	}catch(CBenchmarkEnvironmentException *e){

		MessageBox(NULL,e->GetErrorMessage(),"CPUBench2006 error",MB_OK);
		*res="failed";

		return -1;
	}

}



extern "C" float WINAPI EXPORT RunBenchmark()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	CString res;

//	CWinThread* t=AfxBeginThread((AFX_THREADPROC)RunBench,NULL,THREAD_PRIORITY_NORMAL);

//	::WaitForSingleObject(t->m_hThread,INFINITE);


	RunBench(NULL);

//	MessageBox(NULL,res,NULL,NULL);

	return 0;


	
}
