// FlexGUIItem.h: interface for the CFlexGUIItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLEXGUIITEM_H__CA1AB383_FA83_4ECE_9EA9_D38044D54CE6__INCLUDED_)
#define AFX_FLEXGUIITEM_H__CA1AB383_FA83_4ECE_9EA9_D38044D54CE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "gradient.h"

class CFlexGUIItem {

public:

	CFlexGUIItem(){

		bOpened=true;
		bResized=false;
		lastSize=100;
		logo=NULL;
		bRequireBk=true;

}

	
	void SetIcon(CString icon){

		logo=(HICON)LoadImage(AfxGetInstanceHandle(),icon,IMAGE_ICON,20,20,0);
	}


	void SetOriginAndSize(int x,int y,int width){

		xPos=x;
		yPos=y;

		captionRect=CRect(xPos,yPos,xPos+width,yPos+27);

		itemRect=CRect(captionRect.left,captionRect.top+captionRect.Height()+1,captionRect.left+captionRect.Width(),captionRect.top+captionRect.Height()+1+lastSize);



	}

	void SetSize(int s){
		
		itemRect.bottom=itemRect.top+s;
	}

	void SetCaptionString(CString s){

		captionStr=s;
	}

	BOOL CheckCaptionHit(CPoint pt){

		return captionRect.PtInRect(pt);
	}

	CRect GetItemRect(){

		if(bOpened)
			return itemRect;

		return captionRect;

	}

	bool IsOpened(){

		return bOpened;
	}

	void ChangeItemState(){

		if(bOpened)
			bOpened=false;

		else bOpened=true;
	}

	int GetFullItemSize(){

		if(bOpened)
			return captionRect.Height()+itemRect.Height();

		return captionRect.Height();

	}

	bool WasResized(){

		return bResized;
	}

	void DrawBackground(CDC* dc) {


		CDC memDC;

		memDC.CreateCompatibleDC(dc);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(dc,itemRect.Width(),itemRect.Height());

		memDC.SelectObject(&bmp);

		BLENDFUNCTION bf;

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha =255;
		bf.AlphaFormat = 0;
	


		CGradient g;

		g.SetGradientColors(RGB(0xE3,0xE3,0xEC),RGB(255,255,255));

		g.SetDirection(g.BTT);

		g.DrawLinearGradient(&memDC,CRect(0,0,itemRect.Width(),itemRect.Height()));

//		memDC.FillSolidRect(0,0,itemRect.Width(),itemRect.Height(),RGB(255,255,255));

		AlphaBlend(*dc,itemRect.left,itemRect.top,itemRect.Width(),itemRect.Height(),memDC,0,0,itemRect.Width(),itemRect.Height(),bf);


		CGdiObject *pOb=dc->SelectObject(new CPen(PS_SOLID,1,RGB(0x70,0x6F,0x91)));


		dc->MoveTo(itemRect.left,itemRect.top);
		dc->LineTo(itemRect.left,itemRect.top+itemRect.Height()-1);
		dc->LineTo(itemRect.right,itemRect.top+itemRect.Height()-1);
		dc->LineTo(itemRect.right,itemRect.top-1);

	}

	//abstract function

	virtual void DrawContent(CDC *dc) =0;



	void DrawItem(CDC* dc){

			//disegno l'ombra

		CDC memDC;
		memDC.CreateCompatibleDC(dc);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(dc,itemRect.Width(),itemRect.Height()+captionRect.Height());
		memDC.SelectObject(&bmp);

		memDC.FillSolidRect(0,0,itemRect.Width(),itemRect.Height()+captionRect.Height(),0);
		//memDC.FillSolidRect(0,itemRect.Height()+captionRect.Height()-3,itemRect.Width(),itemRect.Height()+captionRect.Height(),0);
		BLENDFUNCTION bf;

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha =20;
		bf.AlphaFormat = 0;
		AlphaBlend(*dc,captionRect.right,captionRect.top+4,3,itemRect.Height()+captionRect.Height()-1,memDC,0,0,3,itemRect.Height()+captionRect.Height(),bf);
		AlphaBlend(*dc,captionRect.left+3,itemRect.top+itemRect.Height(),itemRect.Width()-2,2,memDC,0,0,itemRect.Width(),3,bf);


		CFont f;

		f.CreateFont(-16,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
				CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "ARIAL");

		dc->SetTextColor(0x00FFFFFF);



		CGradient g;


//		g.SetGradientColors(RGB(175,186,197),RGB(149,161,175));
//		g.SetGradientColors(RGB(0x70,0x6F,0x91),RGB(0xC7,0xc7,0xD8));
		g.SetGradientColors(RGB(121,121,135),RGB(0xDD,0xDD,0xE7));

		g.SetDirection(g.TTB);

		g.DrawLinearGradient(dc,new CRect(captionRect.left,captionRect.top+1,captionRect.right,captionRect.bottom-1));

		dc->FillSolidRect(captionRect.left+1,captionRect.top+1,captionRect.Width()-1,1,RGB(152,152,156));
		dc->FillSolidRect(captionRect.left+1,captionRect.bottom-1,captionRect.Width()-1,1,RGB(192,192,213));


		dc->SetBkMode(TRANSPARENT);

		dc->SelectObject(&f);

		dc->TextOut(xPos+1,yPos+4," "+captionStr);

		if(logo)
				dc->DrawState(CPoint(captionRect.Width()-20,captionRect.Height()+10),CSize(20,20),logo,DST_ICON,(CBrush*)NULL);

		CGdiObject *pOb=dc->SelectObject(new CPen(PS_SOLID,1,RGB(0x70,0x6F,0x91)));


		dc->MoveTo(captionRect.left+1,captionRect.top);
		dc->LineTo(captionRect.left+captionRect.Width()-1,captionRect.top);
		dc->LineTo(captionRect.left+captionRect.Width()-1,captionRect.top+1);
		dc->LineTo(captionRect.left+captionRect.Width(),captionRect.top+1);
		dc->LineTo(captionRect.left+captionRect.Width(),captionRect.top+captionRect.Height());
		dc->LineTo(captionRect.left,captionRect.top+captionRect.Height());
		dc->LineTo(captionRect.left,captionRect.top+1);
		dc->LineTo(captionRect.left+1,captionRect.top+1);
		dc->LineTo(captionRect.left+1,captionRect.top);




		dc->SelectObject(pOb);

		if(bOpened){
			
			if(bRequireBk) DrawBackground(dc);
			DrawContent(dc);

		}



	}

protected:
	CRect captionRect;
	CString captionStr;
	CRect itemRect;
	CRect totalRect;
	int xPos,yPos,lastSize;
	HICON logo;
	bool bOpened;
	bool bResized;
	bool bRequireBk;

};

#endif // !defined(AFX_FLEXGUIITEM_H__CA1AB383_FA83_4ECE_9EA9_D38044D54CE6__INCLUDED_)
