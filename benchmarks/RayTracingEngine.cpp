// RayTracingEngine.cpp: implementation of the CRayTracingEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RayTracingEngine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HINSTANCE hLib;


CRayTracingEngine::CRayTracingEngine(int width,int height)
{


    hLib=AfxLoadLibrary("rtengine.dll");

	if(hLib == NULL){

		MessageBox(NULL,"Error loading rtengine.dll",NULL,NULL);
		return;

	}

	
	AddMesh_=(_AddMesh)GetProcAddress(hLib,"AddMesh");

	if(AddMesh_ == NULL){

		MessageBox(NULL,"fallito1",NULL,NULL);
		return;
	}

	AddSphere_=(_AddSphere)GetProcAddress(hLib,"AddSphere");

	if(AddSphere_ == NULL){

		MessageBox(NULL,"fallito1",NULL,NULL);
		return;
	}

	AddPlane_=(_AddPlane)GetProcAddress(hLib,"AddPlane");

	if(AddPlane_ == NULL){

		MessageBox(NULL,"fallito1",NULL,NULL);
		return;
	}

	Render_=(_Render)GetProcAddress(hLib,"Render");

	if(Render_ == NULL){

		MessageBox(NULL,"fallito2",NULL,NULL);
		return;
	}

	AddLight_=(_AddLight)GetProcAddress(hLib,"AddLight");

	if(AddLight_ == NULL){

		MessageBox(NULL,"fallito2",NULL,NULL);
		return;
	}



	InitEngine_=(_InitEngine)GetProcAddress(hLib,"InitEngine");

	if(InitEngine_ == NULL){

		MessageBox(NULL,"fallito3",NULL,NULL);
		return;
	}

	InitEngine_(width,height);


}


void CRayTracingEngine::AddSphere(float x,float y,float z,float radius,char* text,float reflectivity,float shininess,float specular){

	AddSphere_(x,y,z,radius,text,reflectivity,shininess,specular);
}


void CRayTracingEngine::AddPlane(float nx,float ny,float nz,float displacement,char* text,float reflectivity,float shininess,float specular){

	AddPlane_(nx,ny,nz,displacement,text,reflectivity,shininess,specular);
}


void CRayTracingEngine::Render(HWND hWnd,StepFunc step){

	Render_(hWnd,step);

}

void CRayTracingEngine::AddLight(float x,float y,float z,int r,int g,int b){

	AddLight_(x,y,z,r,g,b);

}
	
CRayTracingEngine::~CRayTracingEngine()
{
	AfxFreeLibrary(hLib);


}

void CRayTracingEngine::AddMesh(CString mesh){

	AddMesh_(mesh);

}
	
