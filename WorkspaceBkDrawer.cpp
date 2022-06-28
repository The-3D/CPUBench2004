// WorkspaceBkDrawer.cpp: implementation of the CWorkspaceBkDrawer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "WorkspaceBkDrawer.h"
#include "itembkdrawer.h"
#include "gradient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorkspaceBkDrawer::CWorkspaceBkDrawer(CString bk)
{

	bmp=CBitmap::FromHandle((HBITMAP)LoadImage(AfxGetInstanceHandle(),bk,IMAGE_BITMAP,0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE));

}

CWorkspaceBkDrawer::~CWorkspaceBkDrawer()
{

	bmp->DeleteObject();
	bmp=NULL;

}


void CWorkspaceBkDrawer::DrawBk(CDC* dc,CRect* guiRect){





		CDC memDC;

		memDC.CreateCompatibleDC(dc);
	
		memDC.SelectObject(bmp);

		dc->BitBlt(0,0,guiRect->Width(),guiRect->Height(),&memDC,0,0,SRCCOPY);


		memDC.DeleteDC();

/*		CGradient g;

		g.SetGradientColors(RGB(255,255,255),

	//	dc->FillSolidRect(0,0,guiRect->Width(),guiRect->Height(),RGB(166,177,189));
*/




}
