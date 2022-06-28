// RayTracingBenchmark.h: interface for the CRayTracingBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAYTRACINGBENCHMARK_H__A5E202C7_5686_4CCB_A7B8_F429E32169E9__INCLUDED_)
#define AFX_RAYTRACINGBENCHMARK_H__A5E202C7_5686_4CCB_A7B8_F429E32169E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Benchmark.h"

class CRayTracingBenchmark : public CBenchmark  
{
public:

	CRayTracingBenchmark(){

		m_name="Raytracing rendering";

		m_description="This test measures CPU performance using a raytracing engine.";

		m_techDetails="Instruction set: SSE2\n\nNumber of threads: 2";

	}

	
	static void CALLBACK Step(int s);

	virtual ~CRayTracingBenchmark();


protected:
	bool InitBenchmarkData(CBenchmarkEnvironment *e);

	bool StartBenchmark(CBenchmarkEnvironment *e);

	void EndBenchmark() {}


};

#endif // !defined(AFX_RAYTRACINGBENCHMARK_H__A5E202C7_5686_4CCB_A7B8_F429E32169E9__INCLUDED_)
