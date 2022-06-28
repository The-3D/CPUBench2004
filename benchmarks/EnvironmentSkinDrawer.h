// EnvironmentSkinDrawer.h: interface for the CEnvironmentSkinDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENVIRONMENTSKINDRAWER_H__EC92022C_31C9_46EE_B2FB_A0327244CC17__INCLUDED_)
#define AFX_ENVIRONMENTSKINDRAWER_H__EC92022C_31C9_46EE_B2FB_A0327244CC17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEnvironmentSkinDrawer  
{
public:
	CEnvironmentSkinDrawer(int screenWidth,int screenHeight,int outWidth,int outHeight,int outWndY);
	void DrawSkin(CDC* pSrcDC);
	virtual ~CEnvironmentSkinDrawer();

private:

	int m_screenWidth,m_screenHeight,m_outWndWidth,m_outWndHeight,m_widthOffset,m_outWndY;
	CBitmap m_header,m_right,m_down;

};

#endif // !defined(AFX_ENVIRONMENTSKINDRAWER_H__EC92022C_31C9_46EE_B2FB_A0327244CC17__INCLUDED_)
