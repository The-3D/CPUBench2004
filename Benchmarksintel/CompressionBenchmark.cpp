// CompressionBenchmark.cpp: implementation of the CCompressionBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarksintel.h"
#include "CompressionBenchmark.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCompressionBenchmark::CCompressionBenchmark()
{

}

CCompressionBenchmark::~CCompressionBenchmark()
{

}



bool CCompressionBenchmark::CreateData(){


	CStdioFile f;


	if(!f.Open(".\\tempdata\\file01.txt",CFile::modeWrite | CFile::modeCreate))
		return false;

	CString s="ABCDEFGHILMNOPQRSTUVZ";
	CString s2="ZVUTSRQPONMLIHGFEDCBA";


	for(int i=0; i<10000000; i++){

		if(i%2) f.WriteString(s);
		else f.WriteString(s2);

	}

	f.Close();


	return true;

}




