// CadBenchmark.h: interface for the CCadBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CADBENCHMARK_H__73CDEED2_14AC_4050_8BDC_8A4A25757FD8__INCLUDED_)
#define AFX_CADBENCHMARK_H__73CDEED2_14AC_4050_8BDC_8A4A25757FD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Benchmark.h"
#include "headrenderer.h"

class CCadBenchmark : public CBenchmark  
{
public:

	CCadBenchmark(){

		
		m_name="Computer Aided Design test";

		m_description="This test measures CPU performance displaying a 3D model in three views to simulate typical CAD usage under OpenGL";

		m_techDetails="Data source: Autocad\n\nAPI used: OpenGL";

	}

	
	virtual ~CCadBenchmark();


protected:

	bool InitBenchmarkData(CBenchmarkEnvironment *e);

	bool StartBenchmark(CBenchmarkEnvironment *e);

	void EndBenchmark() {}

private:
	HDC hDC;
	HGLRC hRC;


};

#endif // !defined(AFX_CADBENCHMARK_H__73CDEED2_14AC_4050_8BDC_8A4A25757FD8__INCLUDED_)
