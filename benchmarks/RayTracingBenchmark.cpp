// RayTracingBenchmark.cpp: implementation of the CRayTracingBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "RayTracingBenchmark.h"
#include "raytracingengine.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBenchmarkEnvironment *m=NULL;


void CRayTracingBenchmark::Step(int s){

	if(m != NULL)
		m->Step(s);
}


CRayTracingBenchmark::~CRayTracingBenchmark()
{

}


bool CRayTracingBenchmark::InitBenchmarkData(CBenchmarkEnvironment *e){

	return true;

}


bool CRayTracingBenchmark::StartBenchmark(CBenchmarkEnvironment *e){


	CRayTracingEngine rt(800,600);


	rt.AddPlane(0,-1,0,0,".\\textures\\cemento.bmp",0.7,10,20);

	rt.AddMesh(".\\rtdata\\statua3.3ds");

	
	rt.AddLight(20,-490,-220,255,255,255);
	rt.AddLight(-40,-490,-220,255,255,255);
	rt.AddLight(0,-490,40,255,255,255);


	m=e;
	
	e->UpdateStatus("rendering...");

	int start=timeGetTime();

	rt.Render(e->GetOutTarget(0)->m_hWnd,Step);

	int stop=timeGetTime();


	result=(float)(stop-start)/1000.0f;


	return true;

}

