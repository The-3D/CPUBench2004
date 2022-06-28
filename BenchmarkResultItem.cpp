// BenchmarkResultItem.cpp: implementation of the CBenchmarkResultItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CPUBench2004.h"
#include "BenchmarkResultItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBenchmarkResultItem::CBenchmarkResultItem()
{

	this->m_bestResult="none";
	this->m_currentResult="Bench not run yet";

}

CBenchmarkResultItem::~CBenchmarkResultItem()
{

}
