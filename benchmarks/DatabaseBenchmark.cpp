// DatabaseBenchmark.cpp: implementation of the CDatabaseBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "DatabaseBenchmark.h"
#include "publishersset.h"
#include "booksset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


bool CDatabaseBenchmark::StartBenchmark(CBenchmarkEnvironment *e){


	CString SQL_simpleRead_small_data_set="SELECT * FROM Account WHERE AccountNo BETWEEN 1 AND 50000";
	CString SQL_simpleRead_large_data_set="SELECT * FROM Account WHERE AccountNo BETWEEN 1 AND 350000";
	CString SQL_join;
	CString SQL_update_small_data_set = "UPDATE Account SET Balance = Balance + 1 WHERE AccountNo BETWEEN 1 AND 10000";
	CString SQL_update_large_data_set = "UPDATE Account SET Balance = Balance + 1 WHERE AccountNo BETWEEN 1 AND 350000";


	SQL_join="SELECT * FROM Account AS A";
	SQL_join+=" WHERE EXISTS (";
	SQL_join+=" SELECT *";
	SQL_join+=" FROM Orders,OrderDetails,Products P";
	SQL_join+=" WHERE OrderDetails.OrderID=Orders.OrderID AND Orders.AccountNo = A.AccountNo AND OrderDetails.productID=P.productID AND P.ProductName = 'Northwoods Cranberry Sauce')";

	CString out;
	CString temp;

	CStatic *outTarget=e->GetOutTarget(0);

//	ASSERT_VALID(outTarget);

//	ASSERT_KINDOF(CStatic,outTarget);

	out="\nCPUBench benchmarking environment output console version 1.0.0\n\n";

	out+="preparing to run Benchmark: Database performance test (using MS Jet SQL engine)\n";

	outTarget->SetWindowText(out);


	//RunSchema(0,e,out,"SQL_insert",SQL_insert,1,true);

	out+="\nCaching data for data reading tests, please wait...";

	outTarget->SetWindowText(out);

	if(!RunSchema(2,e,out,"SQL_cacheData",SQL_simpleRead_large_data_set,3,1,false))
		return false;


	if(!RunSchema(1,e,out,"SQL_simpleRead_large_data_set",SQL_simpleRead_large_data_set,50,5,true))
		return false;


	e->Step(33);

	if(!RunSchema(2,e,out,"SQL_simpleRead_small_data_set",SQL_simpleRead_small_data_set,50,10,true))
		return false;

	e->Step(66);

	if(!RunSchema(3,e,out,"SQL_join",SQL_join,50,3,true))
		return false;

	e->Step(100);

	out+="Test completed. Now removing temporary data, please wait...";

	outTarget->SetWindowText(out);


	outTarget->SetWindowText(out);

	return true;

}



bool CDatabaseBenchmark::RunSchema(int numSchema,CBenchmarkEnvironment *e,CString& out,char* schema,CString query,int numProcesses,int repeatCount,  bool bShowInfo){


	CString temp;

	CStatic *outTarget=e->GetOutTarget(0);
	
	
	temp.Format("%d: '%s'",numSchema,schema);

	if(bShowInfo){

		out+="\n\nPreparing test schema n° "+temp;


		if(numProcesses == 1)
			out+=" serving 1 client request";
	
		else {
			temp.Format(" serving %d clients request",numProcesses);
			out+=temp;
		}
	
		out+="\nAssociated query:	\n\n"+query+CString("\n");
	
		out+="\nTesting (please wait)...";

		outTarget->SetWindowText(out);

	}

	e->UpdateStatus("Working...");

	int totalTime=0;


	//posizione della progress bar
	int pos=33*(numSchema-1);

	for(int i=0; i<repeatCount; i++){
		int result=StartSimulation(schema,numProcesses);
		if(result == -1)
			return false;

		totalTime+=result;

		if(bShowInfo) e->Step(++(++pos));
	}


	
	if(bShowInfo){
		temp.Format("%d ms",totalTime);
		out+="simulation completed in "+temp+"\n\n";

		outTarget->SetWindowText(out);

	}

	e->UpdateStatus("Step completed.");

}


int CDatabaseBenchmark::StartSimulation(char* schema,int numProcesses){

	HANDLE processes[100];
	HANDLE threads[100];
	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	int start=timeGetTime();

	for(int i=0; i<numProcesses; i++){

		ZeroMemory(&pi,sizeof(pi));
		ZeroMemory(&si,sizeof(si));
	
		if(!CreateProcess( ".\\dbdata\\dbtest.exe",
							(char*)schema,
							NULL,
							NULL,
							TRUE,
							REALTIME_PRIORITY_CLASS | DETACHED_PROCESS,
							NULL,NULL,&si,&pi)){

			MessageBox(NULL,"Error opening process",NULL,NULL);
			return -1;
		}

		processes[i]=pi.hProcess;
		threads[i]=pi.hThread;


	}

		WaitForMultipleObjects(numProcesses,processes,TRUE,INFINITE);

		int stop=timeGetTime();

		for(i=0; i<numProcesses; i++){
			CloseHandle(processes[i]);
			CloseHandle(threads[i]);
		}

		return stop-start;

}




CDatabaseBenchmark::~CDatabaseBenchmark()
{

}
