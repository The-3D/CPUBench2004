// WorkspaceBkDrawer.h: interface for the CWorkspaceBkDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKSPACEBKDRAWER_H__F7372048_B6B9_40D9_B062_9EDF5E2BD2F7__INCLUDED_)
#define AFX_WORKSPACEBKDRAWER_H__F7372048_B6B9_40D9_B062_9EDF5E2BD2F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWorkspaceBkDrawer  
{
public:
	CWorkspaceBkDrawer(CString bk);

	void DrawBk(CDC* dc,CRect *guiRect);
	virtual ~CWorkspaceBkDrawer();

private:
	CBitmap *bmp;

};

#endif // !defined(AFX_WORKSPACEBKDRAWER_H__F7372048_B6B9_40D9_B062_9EDF5E2BD2F7__INCLUDED_)
