// VideoCompressionBenchmark.h: interface for the CVideoCompressionBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_)
#define AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "benchmarkenvironment.h"


interface IBaseFilter;


class CVideoCompressionBenchmark {


public:

	CVideoCompressionBenchmark(){

		m_name="Video compression benchmark";

		m_description="This benchmark measures CPU performance with Xvid video compression.";


		m_file=".\\videodata\\data.dat";

		CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

		TCHAR szNum[256];
		GetPrivateProfileString(TEXT("DexCompress"), TEXT("CompressorNumber"), TEXT("1"), 
								  szNum, 256, TEXT("DexCompress.ini"));
		szNum[255] = 0; // ensure this comes in null terminated

		 m_pPlaybackGraph = NULL;

	}

	

	void InitBenchmarkData() {}

	void StartBenchmark(HWND hWndOut, HWND progress, HWND info);

	float GetBenchmarkResult() { return result; }

	void EndBenchmark() {}



	virtual ~CVideoCompressionBenchmark();

private:

	void PlayMedia(CStatic*);
	void Compress(CBenchmarkEnvironment *v);

    CComPtr<IBaseFilter>   m_pCompressor;
    CComPtr<IGraphBuilder> m_pPlaybackGraph;

	void GetXVidCompressor();
	CString m_file;
	float result;
	CString m_name, m_description;

};

#endif // !defined(AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_)
