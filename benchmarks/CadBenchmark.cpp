// CadBenchmark.cpp: implementation of the CCadBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "benchmarks.h"
#include "CadBenchmark.h"
#include "headrenderer.h"
#include "staircaserenderer.h"
#include <afxmt.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static CSemaphore sem(1,1);

static CStaircaseRenderer* renderer;

DWORD Thread1(LPVOID arg){


		CBenchmarkEnvironment *e=(CBenchmarkEnvironment*)arg;


		PIXELFORMATDESCRIPTOR pfd;
		int iFormat;
		HDC hDC;
		HGLRC hRC;

		CWnd *outTarget=e->GetOutTarget(0);

		// get the device context (DC)
		hDC = outTarget->GetDC()->m_hDC;

		// set the pixel format for the DC
		ZeroMemory( &pfd, sizeof( pfd ) );
		pfd.nSize = sizeof( pfd );
		pfd.nVersion = 1;

		int pFormat=1;
		int count =1+ DescribePixelFormat(hDC,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		while(--count){

			DescribePixelFormat(hDC,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

			if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

			  (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
		
			  (pfd.dwFlags & PFD_GENERIC_FORMAT) &&

			  (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

			  ( pfd.cDepthBits == 32 ) &&

			  ( pfd.cColorBits == 32 ) &&

			  (pfd.iPixelType == PFD_TYPE_RGBA)){

				iFormat = count;
				break;
		  
		   }
		}



		//iFormat = ChoosePixelFormat( hDC, &pfd );
		SetPixelFormat( hDC, iFormat, &pfd );

		// create and enable the render context (RC)
		hRC = wglCreateContext( hDC );
		wglMakeCurrent( hDC, hRC );


		CFont f;


		f.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
						CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");


		CDC* dc=CDC::FromHandle(hDC);

		dc->SelectObject(&f);

		dc->SetTextColor(0x00FFFFFF);

		wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 

		glListBase (1000); 

 

		CRect r;
  
		outTarget->GetClientRect(&r);
		
		glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

		
		glMatrixMode(GL_PROJECTION);				
		glLoadIdentity();							

		//imposto la projection matrix
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,15000.0f);		// 	  Position      View	   Up Vector


		CSingleLock sl(&sem);

		sl.Lock();

//		CStaircaseRenderer renderer;

		sl.Unlock();

		int start=timeGetTime();

		renderer->RenderPerspectiveView(hDC);

		renderer->RenderPerspectiveShadedView(hDC);
		
		int stop=timeGetTime();



		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( hRC );

		return 0;

}



DWORD Thread2(LPVOID arg){


		CBenchmarkEnvironment *e=(CBenchmarkEnvironment*)arg;


		PIXELFORMATDESCRIPTOR pfd;
		int iFormat;
		HDC hDC;
		HGLRC hRC;

		CWnd *outTarget=e->GetOutTarget(1);

		// get the device context (DC)
		hDC = outTarget->GetDC()->m_hDC;

		// set the pixel format for the DC
		ZeroMemory( &pfd, sizeof( pfd ) );
		pfd.nSize = sizeof( pfd );
		pfd.nVersion = 1;

		int pFormat=1;
		int count =1+ DescribePixelFormat(hDC,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		while(--count){

			DescribePixelFormat(hDC,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

			if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

			  (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
		
			  (pfd.dwFlags & PFD_GENERIC_FORMAT) &&

			  (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

			  ( pfd.cDepthBits == 32 ) &&

			  ( pfd.cColorBits == 32 ) &&

			  (pfd.iPixelType == PFD_TYPE_RGBA)){

				iFormat = count;
				break;
		  
		   }
		}



		//iFormat = ChoosePixelFormat( hDC, &pfd );
		SetPixelFormat( hDC, iFormat, &pfd );

		// create and enable the render context (RC)
		hRC = wglCreateContext( hDC );
		wglMakeCurrent( hDC, hRC );


		CFont f;


		f.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
						CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");


		CDC* dc=CDC::FromHandle(hDC);

		dc->SelectObject(&f);

		dc->SetTextColor(0x00FFFFFF);

		wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 

		glListBase (1000); 

 

		CRect r;
  
		outTarget->GetClientRect(&r);
		
		glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

		
		glMatrixMode(GL_PROJECTION);				
		glLoadIdentity();							

		//imposto la projection matrix
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,15000.0f);		// 	  Position      View	   Up Vector


		CSingleLock sl(&sem);

		sl.Lock();


		sl.Unlock();

		int start=timeGetTime();

		renderer->RenderUpView(hDC);

		int stop=timeGetTime();

		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( hRC );

		return 0;

}



DWORD Thread3(LPVOID arg){


		CBenchmarkEnvironment *e=(CBenchmarkEnvironment*)arg;


		PIXELFORMATDESCRIPTOR pfd;
		int iFormat;
		HDC hDC;
		HGLRC hRC;

		CWnd *outTarget=e->GetOutTarget(2);

		// get the device context (DC)
		hDC = outTarget->GetDC()->m_hDC;

		// set the pixel format for the DC
		ZeroMemory( &pfd, sizeof( pfd ) );
		pfd.nSize = sizeof( pfd );
		pfd.nVersion = 1;

		int pFormat=1;
		int count =1+ DescribePixelFormat(hDC,pFormat,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

		while(--count){

			DescribePixelFormat(hDC,count,sizeof(PIXELFORMATDESCRIPTOR),&pfd);

			if((pfd.dwFlags & PFD_SUPPORT_OPENGL) &&

			  (pfd.dwFlags & PFD_DRAW_TO_WINDOW) &&
		
			  (pfd.dwFlags & PFD_GENERIC_FORMAT) &&

			  (pfd.dwFlags & PFD_DOUBLEBUFFER) &&

			  ( pfd.cDepthBits == 32 ) &&

			  ( pfd.cColorBits == 32 ) &&

			  (pfd.iPixelType == PFD_TYPE_RGBA)){

				iFormat = count;
				break;
		  
		   }
		}



		//iFormat = ChoosePixelFormat( hDC, &pfd );
		SetPixelFormat( hDC, iFormat, &pfd );

		// create and enable the render context (RC)
		hRC = wglCreateContext( hDC );
		wglMakeCurrent( hDC, hRC );


		CFont f;


		f.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
						CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");


		CDC* dc=CDC::FromHandle(hDC);

		dc->SelectObject(&f);

		dc->SetTextColor(0x00FFFFFF);

		wglUseFontBitmaps (dc->m_hDC, 0, 255, 1000); 

		glListBase (1000); 

 

		CRect r;
  
		outTarget->GetClientRect(&r);
		
		glViewport(0,0,r.Width(),r.Height());						// Make our viewport the whole window

		
		glMatrixMode(GL_PROJECTION);				
		glLoadIdentity();							

		//imposto la projection matrix
		gluPerspective(45.0f,(GLfloat)(r.Width())/(GLfloat)r.Height(), .5f ,15000.0f);		// 	  Position      View	   Up Vector


		CSingleLock sl(&sem);

		sl.Lock();

		sl.Unlock();

		int start=timeGetTime();

		renderer->RenderLeftView(hDC);

		int stop=timeGetTime();

		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( hRC );

		return 0;

}



CCadBenchmark::~CCadBenchmark()
{

	delete renderer;
}


bool CCadBenchmark::InitBenchmarkData(CBenchmarkEnvironment *e){

	try{
		renderer=new CStaircaseRenderer;
	}
	catch(CException* e){
		delete e;
		return false;
	}


	return true;

}

bool CCadBenchmark::StartBenchmark(CBenchmarkEnvironment *e){

	CWinThread *t1 = AfxBeginThread((AFX_THREADPROC)Thread1,e,THREAD_PRIORITY_NORMAL);
	CWinThread *t2 = AfxBeginThread((AFX_THREADPROC)Thread2,e,THREAD_PRIORITY_NORMAL);
	CWinThread *t3 = AfxBeginThread((AFX_THREADPROC)Thread3,e,THREAD_PRIORITY_NORMAL);


	HANDLE hThreads[3];

	hThreads[0]=t1->m_hThread;
	hThreads[1]=t2->m_hThread;
	hThreads[2]=t3->m_hThread;

	::WaitForMultipleObjects(3,hThreads,TRUE,INFINITE);


	return true;


}