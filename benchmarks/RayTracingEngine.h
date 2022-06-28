// RayTracingEngine.h: interface for the CRayTracingEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAYTRACINGENGINE_H__EB06480C_61FF_4FF1_B0A8_A4B4E784A401__INCLUDED_)
#define AFX_RAYTRACINGENGINE_H__EB06480C_61FF_4FF1_B0A8_A4B4E784A401__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



typedef BOOL (CALLBACK* _AddSphere)(float,float,float,float,char*,float,float,float);
typedef BOOL (CALLBACK* _AddPlane)(float,float,float,float,char*,float,float,float);
typedef  BOOL (CALLBACK* _AddLight)(float,float,float,int,int,int);
typedef void (CALLBACK* StepFunc)(int);
typedef BOOL (__stdcall* _AddMesh)(const char*);


typedef BOOL (CALLBACK* _Render)(HWND,StepFunc);
typedef BOOL (CALLBACK* _InitEngine)(int,int);

class CRayTracingEngine  
{
public:
	CRayTracingEngine(int width,int height);

	void AddSphere(float,float,float,float,char*,float,float,float);
	void AddPlane(float,float,float,float,char*,float,float,float);
	void AddLight(float,float,float,int,int,int);
		void AddMesh(CString mesh);



	void Render(HWND,StepFunc);


	virtual ~CRayTracingEngine();


private:
	_Render Render_;
	_AddSphere AddSphere_;
	_AddPlane AddPlane_;
	_AddMesh AddMesh_;
	_InitEngine InitEngine_;
	_AddLight AddLight_;
};

#endif // !defined(AFX_RAYTRACINGENGINE_H__EB06480C_61FF_4FF1_B0A8_A4B4E784A401__INCLUDED_)
