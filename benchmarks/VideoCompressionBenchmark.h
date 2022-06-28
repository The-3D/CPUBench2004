// VideoCompressionBenchmark.h: interface for the CVideoCompressionBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_)
#define AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "benchmarkenvironment.h"
#include "benchmark.h"

interface IBaseFilter;


class CVideoCompressionBenchmark : public CBenchmark {


public:

	CVideoCompressionBenchmark(){

		m_name="Video compression";

		m_description="This test measures CPU performance executing a video compression task.";

		m_techDetails="Video Format: 720x480@25 fps\n\nCodec used: XviD codec\n\nInterface: MS DirectShow 9.0";

		m_file=".\\videodata\\data.dat";


		//per inizializzare COM con CoInitializeEx è necessario
		//inserire nelle proprietà del progetto, tra le definizioni del preprocessore
		//il tag _WIN32_WINNT_=0x400
		CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

		TCHAR szNum[256];
		GetPrivateProfileString(TEXT("DexCompress"), TEXT("CompressorNumber"), TEXT("1"), 
								  szNum, 256, TEXT("DexCompress.ini"));
		szNum[255] = 0; // ensure this comes in null terminated

		 m_pPlaybackGraph = NULL;

	}


	virtual ~CVideoCompressionBenchmark();


protected:

	bool InitBenchmarkData(CBenchmarkEnvironment *v) { return true;}

	bool StartBenchmark(CBenchmarkEnvironment *v);

	void EndBenchmark() {}


private:

	bool PlayMedia(CStatic*);
	bool Compress(CBenchmarkEnvironment *v,int pass);
	bool SetCodecDefaults();

    CComPtr<IBaseFilter>   m_pCompressor;
    CComPtr<IGraphBuilder> m_pPlaybackGraph;

	bool GetXVidCompressor();
	CString m_file;


};

#endif // !defined(AFX_VIDEOCOMPRESSIONBENCHMARK_H__14CA8FD0_306A_4A37_A11B_808F37952AD1__INCLUDED_)
