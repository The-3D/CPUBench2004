// BenchmarkResultItem.h: interface for the CBenchmarkResultItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARKRESULTITEM_H__B8AC860F_88E1_4EFF_80D7_DA3B604BA40F__INCLUDED_)
#define AFX_BENCHMARKRESULTITEM_H__B8AC860F_88E1_4EFF_80D7_DA3B604BA40F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlexGUIItem.h"

class CBenchmarkResultItem : public CFlexGUIItem  
{
public:
	CBenchmarkResultItem();

	void SetCurrentResult(int currResult){

		m_currentResult.Format("%d CPUMarks",currResult);
	}

	void SetBestResult(int bestResult){

		m_bestResult.Format("%d",bestResult);
	}



	void DrawContent(CDC* dc){

		CFont fLbl;
		CFont fText;
		CFont fResult;
		CSize size;

		fLbl.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

		fText.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");

		fResult.CreateFont(-18,0,0,0,FW_BOLD,TRUE,FALSE,0,ANSI_CHARSET,OUT_TT_PRECIS,
					CLIP_TT_ALWAYS,ANTIALIASED_QUALITY,DEFAULT_PITCH | FF_SWISS, "TAHOMA");


		CGdiObject *pOldObj=dc->SelectObject(&fLbl);


		dc->SetTextColor(0);

		dc->TextOut(itemRect.left+26,itemRect.top+12,"Current result: ");


		dc->SelectObject(&fText);

		dc->SetTextColor(0);

		dc->TextOut(itemRect.left+100,itemRect.top+12,m_currentResult);


		dc->TextOut(itemRect.left+26,itemRect.top+34,"Your best result: ");

		dc->SelectObject(&fResult);

		GetTextExtentPoint32(*dc,m_bestResult,m_bestResult.GetLength(),&size);
		dc->SetTextColor(0);


		dc->TextOut(itemRect.left+110,itemRect.top+27,m_bestResult);


		if(m_bestResult != "none"){

			dc->SelectObject(&fText);

			dc->SetTextColor(0);
			dc->TextOut(itemRect.left+110+size.cx+5,itemRect.top+34,"CPUMarks ");
		}



		dc->SelectObject(pOldObj);

	}



		
	virtual ~CBenchmarkResultItem();
	CString m_currentResult,m_bestResult;

};

#endif // !defined(AFX_BENCHMARKRESULTITEM_H__B8AC860F_88E1_4EFF_80D7_DA3B604BA40F__INCLUDED_)
