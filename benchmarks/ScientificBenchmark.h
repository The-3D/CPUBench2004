// ScientificBenchmark.h: interface for the CScientificBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCIENTIFICBENCHMARK_H__5BAFF5DB_E8C2_4606_B257_E4C7EFB5F15E__INCLUDED_)
#define AFX_SCIENTIFICBENCHMARK_H__5BAFF5DB_E8C2_4606_B257_E4C7EFB5F15E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Benchmark.h"

#include <GL\gl.h>
#include <GL\glu.h>

class CScientificBenchmark : public CBenchmark  
{
public:
	CScientificBenchmark(){

		m_name="Molecular viewer";

		m_description="Protein/molecule analisys and visualization is a typical task in medicine, genetic engineering, and more.";
		m_description+="This test measures CPU performance displaying a DNA molecule using two common rendering techniques."; 

		m_techDetails="Data source: Protein data bank\n\nAPI used: OpenGL";


	}


	virtual ~CScientificBenchmark();

protected:

	bool InitBenchmarkData(CBenchmarkEnvironment *e);

	bool StartBenchmark(CBenchmarkEnvironment *e);

	void EndBenchmark() {}



private:
	HDC hDC;
	HGLRC hRC;


};

#endif // !defined(AFX_SCIENTIFICBENCHMARK_H__5BAFF5DB_E8C2_4606_B257_E4C7EFB5F15E__INCLUDED_)
