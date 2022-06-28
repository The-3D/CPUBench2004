// FlexGUIButton.cpp : implementation file
//

#include "stdafx.h"
#include "cpubench2004.h"
#include "FlexGUIButton.h"
#include "gradient.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlexGUIButton

CFlexGUIButton::CFlexGUIButton()
{
	state=0;
}

CFlexGUIButton::~CFlexGUIButton()
{
}


BEGIN_MESSAGE_MAP(CFlexGUIButton, CButton)
	//{{AFX_MSG_MAP(CFlexGUIButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlexGUIButton message handlers

void CFlexGUIButton::DrawItem(LPDRAWITEMSTRUCT lpDIS) 
{

	CDC* dc=CDC::FromHandle(lpDIS->hDC);

	CRect r;

	GetClientRect(&r);

	if(lpDIS->itemAction == ODA_SELECT || lpDIS->itemAction == ODA_DRAWENTIRE){


		if(state == 0){
			//not clicked

			CGradient g;


			g.SetGradientColors(RGB(253,253,253),RGB(255,255,255));

			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+3,r.top+3,r.right-2,r.bottom-3));

			g.SetGradientColors(RGB(217,222,227),RGB(255,255,255));

			g.DrawLinearGradient(dc,CRect(r.left+5,r.top+5,r.right-4,r.bottom-3));

/*			CPen p(PS_SOLID |  PS_INSIDEFRAME | PS_ENDCAP_ROUND,1,RGB(255,255,255));


			dc->SelectObject(GetStockObject(NULL_BRUSH));


			dc->SelectObject(&p);

			dc->RoundRect(CRect(r.left+4,r.top+4,r.right-3,r.bottom-3),CPoint(4,4));
*/

			g.SetGradientColors(RGB(230,233,237),RGB(190,197,224));
		
			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+5,r.bottom-4,r.right-1,r.bottom-2));

			g.SetDirection(CGradient::LTR);

			g.SetGradientColors(RGB(255,255,255),RGB(190,197,224));

			g.DrawLinearGradient(dc,CRect(r.right-4,r.top+5,r.right-1,r.bottom-1));


		
/*
			g.SetGradientColors(RGB(255,255,255),RGB(240,240,234));

			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+1,r.top+1,r.right-1,r.bottom-4));

			g.SetGradientColors(RGB(236,235,230),RGB(214,208,197));

			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+1,r.bottom-4,r.right-1,r.bottom-1));


*/

		}


		else if(state == 1){

			CGradient g;

			g.SetGradientColors(RGB(230,230,224),RGB(224,224,215));

			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+1,r.top+5,r.right-1,r.bottom-4));

			g.SetGradientColors(RGB(226,226,218),RGB(242,241,238));

			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+1,r.bottom-4,r.right-1,r.bottom-1));

			g.SetGradientColors(RGB(209,204,193),RGB(230,230,224));
		
			g.SetDirection(CGradient::TTB);

			g.DrawLinearGradient(dc,CRect(r.left+1,r.top,r.right-1,r.top+5));



		}


		CString strCaption;

	GetWindowText(strCaption);


	CFont f;

	f.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
			CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");

	dc->SelectObject(&f);
	
	dc->SetBkMode(TRANSPARENT);

	CSize size;

	GetTextExtentPoint32(*dc,strCaption,strCaption.GetLength(),&size);

	int posX=(r.Width()-size.cx)/2;
	int posY=(r.Height()-size.cy)/2;
	dc->TextOut(posX,posY,strCaption);


	DrawBorder(dc);

	}


		



	
}

void CFlexGUIButton::DrawBorder(CDC* dc){


		CRect r;

		GetClientRect(&r);

		CPen p1(PS_SOLID | PS_INSIDEFRAME | PS_ENDCAP_ROUND ,1,RGB(128,142,159));
		CPen p4(PS_SOLID | PS_INSIDEFRAME | PS_ENDCAP_ROUND ,1,RGB(188,202,219));

		CPen p2(PS_SOLID |  PS_INSIDEFRAME | PS_ENDCAP_ROUND,1,RGB(205,211,217));
		CPen p3(PS_SOLID |  PS_INSIDEFRAME | PS_ENDCAP_ROUND,1,RGB(215,221,227));


		dc->SelectObject(GetStockObject(NULL_BRUSH));


		dc->SelectObject(&p2);

		dc->RoundRect(r,CPoint(8,7));
		dc->RoundRect(r,CPoint(9,9));

	
		



//		dc->SelectObject(GetStockObject(NULL_BRUSH));

		dc->SelectObject(&p3);
		dc->RoundRect(CRect(r.left+2,r.top+2,r.right-1,r.bottom-1),CPoint(8,7));
		dc->RoundRect(CRect(r.left+1,r.top+1,r.right-1,r.bottom-1),CPoint(9,9));

		dc->SelectObject(&p1);


		dc->RoundRect(CRect(r.left+1,r.top+1,r.right-1,r.bottom-1),CPoint(8,7));





/*		dc->SelectObject(&p1);

		dc->MoveTo(r.left+1,r.top);
		dc->LineTo(r.right-2,r.top);
		dc->SelectObject(&p2);
		dc->LineTo(r.right-2,r.top);
		dc->LineTo(r.right-2,r.top+1);
		dc->LineTo(r.right-1,r.top+1);
		dc->SelectObject(&p1);
		dc->LineTo(r.right-1,r.bottom-2);
		dc->SelectObject(&p2);
		dc->LineTo(r.right-1,r.bottom-2);
		dc->LineTo(r.right-2,r.bottom-2);
		dc->LineTo(r.right-2,r.bottom-1);
		dc->SelectObject(&p1);
		dc->LineTo(r.left+1,r.bottom-1);
		dc->SelectObject(&p2);
		dc->LineTo(r.left+1,r.bottom-1);
		dc->LineTo(r.left+1,r.bottom-2);
		dc->LineTo(r.left,r.bottom-2);
		dc->SelectObject(&p1);
		dc->LineTo(r.left,r.top+1);
		dc->SelectObject(&p2);
		dc->LineTo(r.left,r.top+1);
		dc->LineTo(r.left+1,r.top+1);
		dc->LineTo(r.left+1,r.top);
		//angoli

		dc->SetPixel(r.right-3,r.top+1,RGB(191,206,220));
		dc->SetPixel(r.right-2,r.top+2,RGB(191,206,220));

		dc->SetPixel(r.right-2,r.bottom-3,RGB(191,206,220));
		dc->SetPixel(r.right-3,r.bottom-2,RGB(191,206,220));

		dc->SetPixel(r.left+1,r.bottom-3,RGB(191,206,220));
		dc->SetPixel(r.left+2,r.bottom-2,RGB(191,206,220));

		dc->SetPixel(r.left+1,r.top+2,RGB(191,206,220));
		dc->SetPixel(r.left+2,r.top+1,RGB(191,206,220));

  */

}

void CFlexGUIButton::OnLButtonDown(UINT nFlags, CPoint point) 
{

	state=1;
	
	CButton::OnLButtonDown(nFlags, point);
}

void CFlexGUIButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	
	state = 0;
	CButton::OnLButtonUp(nFlags, point);
}

BOOL CFlexGUIButton::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;//CButton::OnEraseBkgnd(pDC);
}

void CFlexGUIButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	SetFocus();
	CButton::OnMouseMove(nFlags, point);
}

void CFlexGUIButton::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	

}
