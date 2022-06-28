// VideoCompressionBenchmark.cpp: implementation of the CVideoCompressionBenchmark class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Benchmarks.h"
#include "VideoCompressionBenchmark.h"
#include <qedit.h>          
#include <dshowutil.h>

#define ASSUMED_LENGTH  20.0    /* Default media length if unknown */


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVideoCompressionBenchmark::~CVideoCompressionBenchmark()
{



	this->m_pPlaybackGraph.Release();
	this->m_pCompressor.Release();

}



bool CVideoCompressionBenchmark::StartBenchmark(CBenchmarkEnvironment *v){


	result =0;

	v->UpdateStatus("Caching media, please wait...");


	if(!PlayMedia(v->GetOutTarget(0))){
		v->UpdateStatus("Caching media failed. Aborting...");
		return false;
	}


	Sleep(45000);


	if(v->StopExecutionRequested())
		return true;
	

	v->SetFinished(FALSE);

	v->UpdateStatus("Status: Compression pass 1...");

	if(!Compress(v,1)){
		v->UpdateStatus("Pass 1 compression failed. Aborting...");
		return false;
	}

	if(v->StopExecutionRequested())
		return true;
	


	v->StepTotalProgress(3);
	
	v->UpdateStatus("Status: Compression pass 2...");

	if(!Compress(v,2)){
		v->UpdateStatus("Pass 2 compression failed. Aborting...");
		return false;
	}

	if(v->StopExecutionRequested())
		return true;



	v->StepTotalProgress(6);


	v->UpdateStatus("Status: Compression pass 3...");

	if(!Compress(v,3)){
		v->UpdateStatus("Pass 3 compression failed. Aborting...");
		return true;
	}


	v->StepTotalProgress(10);


	v->SetFinished(TRUE);


	result/=6.0; //sommatoria dei pesi per ogni pass - 1 alla prima, 2 alla seconda, 3 alla terza

	return true;
}




bool CVideoCompressionBenchmark::PlayMedia(CStatic* renderTarget){


	HRESULT hr;

	renderTarget->ModifyStyle(0, WS_CLIPCHILDREN);

    // Make the filename a WIDE string
    USES_CONVERSION;
    TCHAR * tFilename = m_file.GetBuffer(MAX_PATH);
    WCHAR * wFilename = T2W(tFilename);

    // First make sure that the file exists
    DWORD dwAttr = GetFileAttributes(tFilename);
    if ((dwAttr == (DWORD) -1) || (dwAttr == FILE_ATTRIBUTE_DIRECTORY))
    {
        AfxMessageBox(TEXT("The specified file does not exist.\r\n\r\n")
                       TEXT("Please provide a valid media filename."));
        return false;
    }
    
    // Create a graph to play the requested file
    hr = m_pPlaybackGraph.CoCreateInstance(CLSID_FilterGraph);
    if(!m_pPlaybackGraph)
    {
        AfxMessageBox(TEXT("Could not create a graph"));
        return false;
    }

    // Render the media file
    hr = m_pPlaybackGraph->RenderFile(wFilename, NULL);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not render selected file"));
        return false;
    }

    // Set video window to be a child window of the screen and
    // position it properly
    CComQIPtr< IVideoWindow, &IID_IVideoWindow > pVW(m_pPlaybackGraph);
    hr = pVW->put_Owner((OAHWND) renderTarget->GetSafeHwnd());

    // If the selected file has no video component, fail gracefully
    // and still play the audio portion
    if (SUCCEEDED(hr))
    {
        // The video window must have the WS_CHILD style
        hr = pVW->put_WindowStyle(WS_CHILD);

        // Read coordinates of video container window
        RECT rc;
        renderTarget->GetClientRect(&rc);
        long width =  rc.right - rc.left;
        long height = rc.bottom - rc.top;

        // Ignore the video's original size and stretch to fit bounding rectangle
        hr = pVW->SetWindowPosition(rc.left, rc.top, width, height);
        if (FAILED(hr))
        {
            AfxMessageBox(TEXT("Failed to set window position"));
            return false;
        }
    }

    // Start running the graph
    CComQIPtr< IMediaControl, &IID_IMediaControl > m_pPlaybackControl(m_pPlaybackGraph);
    hr = m_pPlaybackControl->Run();
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not run playback graph"));
        return false;
    }


	return true;
}



bool CVideoCompressionBenchmark::GetXVidCompressor(){


    HRESULT hr = 0;

	  // create an enumerator object
    CComPtr<ICreateDevEnum> pCreateDevEnum;
    hr = CoCreateInstance(
                        CLSID_SystemDeviceEnum, 
                        NULL, 
                        CLSCTX_INPROC_SERVER,
                        IID_ICreateDevEnum, 
                        (void**) &pCreateDevEnum);

    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Failed to create system enumerator"));
        return false;
    }

    // tell the enumerator to enumerate Video Compressors
    CComPtr< IEnumMoniker > pEm;
    hr = pCreateDevEnum->CreateClassEnumerator(
                        CLSID_VideoCompressorCategory,
                        &pEm, 
                        0);

    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Failed to create class enumerator"));
        return false;
    }

    // start enumerating at the beginning
    pEm->Reset();

    // Look for all Video Compressors and add them to the combo box.
    // Note that we do NOT alphabetize the compressors in the list,
    // because we expect them to be in the same order when the user selects
    // an item.  At that point, we will enumerate through the video compressors
    // again in the same order and select the requested item.

	bool bFound=false;
   
    while(1)
    {
        // Ask for the next VideoCompressor Moniker.
        // A Moniker represents an object, but is not the object itself.
        // You must get the object using the moniker's BindToObject
        // or you can get a "PropertyBag" by calling BindToStorage
        //
        ULONG cFetched = 0;
        CComPtr< IMoniker > pMoniker;

        hr = pEm->Next(1, &pMoniker, &cFetched);
        if(!pMoniker)
        {
            break;
        }
        
        // convert the Moniker to a PropertyBag, an object you can use to
        // ask the object's Name
        CComPtr< IPropertyBag > pBag;

        hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag, (void**) &pBag);


     if(!FAILED(hr))
        {
            // each video compressor has a name, so ask for it
            VARIANT var;
            var.vt = VT_BSTR;

            hr = pBag->Read(L"FriendlyName",&var, NULL);

            if(hr == NOERROR)
            {
                USES_CONVERSION;
                TCHAR * tName = W2T(var.bstrVal);
	            SysFreeString(var.bstrVal);
   
				if(strcmp(tName,"XviD MPEG-4 Codec")==0){


					bFound=true;


					hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**) &m_pCompressor);
					
					if(FAILED(hr))
					{
					  AfxMessageBox(TEXT("Failed to bind to object"));
					  return false;
					}

					return true;

				} 
            }
        }
    }

	AfxMessageBox("Could not find Xvid MPEG encoder. Make sure it's installed correctly.");

	return false;

}




bool CVideoCompressionBenchmark::Compress(CBenchmarkEnvironment *v,int numPass){

    HRESULT hr = 0;

    // make the filename a WIDE string
    USES_CONVERSION;
    TCHAR * tFilename = m_file.GetBuffer(MAX_PATH);
    WCHAR * wFilename = T2W(tFilename);

    // First make sure that the file exists
    DWORD dwAttr = GetFileAttributes(tFilename);
    if ((dwAttr == (DWORD) -1) || (dwAttr == FILE_ATTRIBUTE_DIRECTORY))
    {
        AfxMessageBox(TEXT("The specified input file does not exist.\r\n\r\n")
                       TEXT("Please provide a valid media filename."));
        return false;
    }
    
    // create a filter graph
    CComPtr< IGraphBuilder > pGraph;
    pGraph.CoCreateInstance(CLSID_FilterGraph);
    if(!pGraph)
    {
        AfxMessageBox(TEXT("Could not create a graph"));
        return false;
    }

    // create a CaptureGraphBuilder to help connect filters
    CComPtr<ICaptureGraphBuilder> pBuilder;
    pBuilder.CoCreateInstance(CLSID_CaptureGraphBuilder);

    // tell the capture graph builder what graph we're using
    hr = pBuilder->SetFiltergraph(pGraph);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not setup capture graph"));
        return false;
    }

    // ask directshow to add the appropriate source filter for the given file
    CComPtr<IBaseFilter> pSourceBase;
    hr = pGraph->AddSourceFilter(wFilename, L"Source", &pSourceBase);
 
	if(!pSourceBase)
    {
        AfxMessageBox(TEXT("Could not load source filter for file"));
        return false;
    }

    // get a pointer to the compressor we want to use
    m_pCompressor.Release();
	
	if(!SetCodecDefaults())
		return false;

	
	if(!GetXVidCompressor())
		return false;

    // in order to force the source filter to produce uncompressed video,
    // we create a SampleGrabber (which only accepts compressed video) and
    // tell it what bit depth to accept

    CComPtr<IBaseFilter> pVideoFilter;
    pVideoFilter.CoCreateInstance(CLSID_SampleGrabber);
    if(!pVideoFilter)
    {
        AfxMessageBox(TEXT("Could not create SampleGrabber from Qedit.dll"));
        return false;
    }

    // ask for the ISampleGrabber interface, so we can tell the Grabber to
    // only accept 24 bit uncompressed video

    CComQIPtr< ISampleGrabber, &IID_ISampleGrabber > pVideoGrab(pVideoFilter);

    CMediaType VideoType;
    VideoType.SetType(&MEDIATYPE_Video);
    VideoType.SetSubtype(&MEDIASUBTYPE_RGB24);

    hr = pVideoGrab->SetMediaType(&VideoType);

    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not set sample grabber's media type"));
        return false;
    }

    // Have the graph builder automatically create a MUX and FileWriter for us,
    // and insert them into the graph, by just specifying an output filename
    CComPtr< IBaseFilter > pMux;
    CComPtr< IFileSinkFilter > pWriter;

    // For UNICODE support, copy the CString into a TCHAR array
    TCHAR szOutFilename[MAX_PATH];
    _tcscpy(szOutFilename, ".\\tempdata\\data1.avi");

    hr = pBuilder->SetOutputFileName(
                                    &MEDIASUBTYPE_Avi,
                                    T2W(szOutFilename),
                                    &pMux,
                                    &pWriter);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Cannot set up MUX and File Writer"));
        return false;
    }

    CComQIPtr< IBaseFilter, &IID_IBaseFilter > pWriterBase(pWriter);

    // we have to add the SampleGrabber and Compressor ourselves, but the
    // other filters have already been added to the graph for us
    hr = pGraph->AddFilter(pVideoFilter, L"VideoGrabber");
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not add VideoGrabber to the graph"));
        return false;
    }

    hr = pGraph->AddFilter(m_pCompressor, L"Compressor");
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not add selected compressor to the graph.\r\n\r\n")
                       TEXT("The input file format may not be compatible with the selected encoder.\r\n")
                       TEXT("Some encoders (like Windows Media encoders or DRM-enabled encoders)\r\n")
                       TEXT("cannot be used without appropriate licensing."));
        return false;
    }

    // get a set of pins
    CComPtr<IPin> pSourcePin     = GetOutPin(pSourceBase,   0);
    CComPtr<IPin> pVideoIn       = GetInPin (pVideoFilter,  0);
    CComPtr<IPin> pVideoOut      = GetOutPin(pVideoFilter,  0);
    CComPtr<IPin> pCompressorIn  = GetInPin (m_pCompressor, 0);
    CComPtr<IPin> pCompressorOut = GetOutPin(m_pCompressor, 0);
    CComPtr<IPin> pMuxIn1        = GetInPin (pMux, 0);

    // connect the source to the sample grabber
    hr = pGraph->Connect(pSourcePin, pVideoIn);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Cannot connect up video chain"));
        return false;
    }

    // connect the sample grabber to the compressor
    hr = pGraph->Connect(pVideoOut, pCompressorIn);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not connect video to selected compressor.\r\n\r\n")
                       TEXT("The input file format may not be compatible with the\r\n")
                       TEXT("selected encoder.  Not all encoders are compatible."));
        return false;
    }

    // connect the compressor to the MUX
    hr = pGraph->Connect(pCompressorOut, pMuxIn1);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not connect compressor to mux.\r\n\r\n")
                      TEXT("The selected compressor may not be compatible with this content.\r\n")
                      TEXT("Some encoders (like Windows Media encoders or DRM-enabled encoders)\r\n")
                      TEXT("cannot be used without appropriate licensing."));
        return false;
    }
/*
    if(m_bWantAudio)
    {
        // we have to find the correct audio output pin
        CComPtr< IPin > pOtherPin;
        CComPtr< IPin > pSourceAudioOut;

        pCompressorIn->ConnectedTo(&pOtherPin);
        FindOtherSplitterPin(pOtherPin, MEDIATYPE_Audio, 0, &pSourceAudioOut);

        if(pSourceAudioOut)
        {
            // create a sample grabber, so we can force uncompressed audio to
            // run into the MUX
            CComPtr< IBaseFilter > pAudioFilter;
            pAudioFilter.CoCreateInstance(CLSID_SampleGrabber);
            if(!pAudioFilter)
            {
                AfxMessageBox(TEXT("Could not create SampleGrabber from Qedit.dll"));
                return;
            }

            CComQIPtr< ISampleGrabber, &IID_ISampleGrabber > pAudioGrab(pAudioFilter);

            CMediaType AudioType;
            AudioType.SetType(&MEDIATYPE_Audio);
            pAudioGrab->SetMediaType(&AudioType);

            // Add the audio sample grabber to the graph
            hr = pGraph->AddFilter(pAudioFilter, L"AudioGrabber");
            if(FAILED(hr))
            {
                AfxMessageBox(TEXT("Could not add audio filter to graph"));
                return;
            }

            // Connect the audio source through to the mux
            CComPtr<IPin> pAudioIn = GetInPin(pAudioFilter, 0);

            hr = pGraph->Connect(pSourceAudioOut, pAudioIn);
            if(FAILED(hr))
            {
                AfxMessageBox(TEXT("Could not connect audio source to grabber"));
                return;
            }

            CComPtr<IPin> pAudioOut = GetOutPin(pAudioFilter, 0);
            CComPtr<IPin> pMuxIn2   = GetInPin(pMux, 1);

            hr = pGraph->Connect(pAudioOut, pMuxIn2);
            if(FAILED(hr))
            {
                AfxMessageBox(TEXT("Could not connect audio to mux"));
                return;
            }
        }
    }

  */
    // get filter graph interface pointers
    CComQIPtr< IMediaControl, &IID_IMediaControl > pControl(pGraph);
    CComQIPtr< IMediaSeeking, &IID_IMediaSeeking > pSeeking(pGraph);
    CComQIPtr< IMediaEvent,   &IID_IMediaEvent >   pEvent(pGraph);
    CComQIPtr< IMediaFilter,  &IID_IMediaFilter >  pMF(pGraph);

    // tell the graph to run as fast as possible, and not to skip any frames
    // Setting the sync source to NULL disables the clock.
    hr = pMF->SetSyncSource(NULL);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not SetSyncSource NULL on the graph"));
		return false;
    }

    // ask the graph how long it's going to run
    DWORD dwCaps=0;
    hr = pSeeking->GetCapabilities(&dwCaps);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not read input file seeking capabilities"));
        return false;
    }

    REFERENCE_TIME Duration = 0;
    hr = pSeeking->GetDuration(&Duration);

    // Some compressors have a bug where they don't field the GetDuration call
    // correctly. If this happens, then use a default media file duration.
    if(Duration == 0)
    {
        Duration = (REFERENCE_TIME) (ASSUMED_LENGTH * UNITS);
    }

    // tell the mux to loosely interleave the audio and the video, if possible
    CComQIPtr< IConfigInterleaving, &IID_IConfigInterleaving > pConfig(pMux);
    hr = pConfig->put_Mode(INTERLEAVE_FULL);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not set interleaving mode"));
        return false;
    }

    REFERENCE_TIME InterleaveTime = 1 * UNITS;
    REFERENCE_TIME PrerollTime    = 1 * UNITS;

    hr = pConfig->put_Interleaving(&InterleaveTime, &PrerollTime);
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not put interleave time"));
        return false;
    }

    // start running the graph to begin the compression process
    hr = pControl->Run();
    if(FAILED(hr))
    {
        AfxMessageBox(TEXT("Could not run compression graph"));
        return false;
    }


    // Remember that we're in the compressing state in case
    // the user wants to close the app
  //
    // Pump messages and update UI while waiting for recompression to complete
    //


	int start=timeGetTime();
    while(1)
    {
        long EvCode = 0;

        // Have we received the EC_COMPLETE event?
        hr = pEvent->WaitForCompletion(100, &EvCode);

     // If user is trying to close the app, stop compressing
/*        if (m_bCloseRequested)
            break;
*/
        // Update the compression progress bar
        REFERENCE_TIME Start = 0;
        pSeeking->GetCurrentPosition(&Start);

        double done = double(Start) * 100 / double(Duration);

		v->Step((int)done);

        // If compression is complete, leave the loop
        if(EvCode != 0)
        {
            break;
        }
    }

    // Stop the graph
    pControl->Stop();


	int stop=timeGetTime();

	float res=320.0f/((stop-start)/1000.0f);

	result+=float(numPass)*res;

	return true;

}


bool CVideoCompressionBenchmark::SetCodecDefaults(){

	HKEY xvidKey;
	
	LONG res=RegOpenKeyEx(HKEY_CURRENT_USER,"software\\GNU\\XviD",0,KEY_ALL_ACCESS,&xvidKey);

	if(res != ERROR_SUCCESS)
		return false;

	DWORD val=0;


	//leggo i dati

	RegSetValueEx(xvidKey,"ar_mode",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=4;
	RegSetValueEx(xvidKey,"ar_x",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=3;
	RegSetValueEx(xvidKey,"ar_y",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"aspect_ratio",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"audio_mode",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=128;
	RegSetValueEx(xvidKey,"audio_rate",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"audio_size",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"audio_type",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=700;
	RegSetValueEx(xvidKey,"bitrate",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=100;
	RegSetValueEx(xvidKey,"bquant_offset",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=150;
	RegSetValueEx(xvidKey,"bquant_ratio",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"cartoon_mode",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"chromame",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"closed_gov",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"container_type",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"curve_compression_high",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"curve_compression_low",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"deblock_UV",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"deblock_Y",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"debug",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"dering",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=400;
	RegSetValueEx(xvidKey,"desired_quant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=570000;
	RegSetValueEx(xvidKey,"desired_size",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"discard1pass",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"display_status",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"FilmEffect",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"fourcc_used",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=2;
	RegSetValueEx(xvidKey,"fps",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"frame_drop_ratio",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"full1pass",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"gmc",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"hours",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"interlacing",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=10;
	RegSetValueEx(xvidKey,"keyframe_boost",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=20;
	RegSetValueEx(xvidKey,"kfreduction",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"kfthreshold",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"lum_masking",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=2;
	RegSetValueEx(xvidKey,"max_bframes",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=31;
	RegSetValueEx(xvidKey,"max_bquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=31;
	RegSetValueEx(xvidKey,"max_iquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=300;
	RegSetValueEx(xvidKey,"max_key_interval",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=31;
	RegSetValueEx(xvidKey,"max_pquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));

	val=1;
	RegSetValueEx(xvidKey,"min_bquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"min_iquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=1;
	RegSetValueEx(xvidKey,"min_pquant",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=30;
	RegSetValueEx(xvidKey,"minutes",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"mode",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=6;
	RegSetValueEx(xvidKey,"motion_search",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	val=0;
	RegSetValueEx(xvidKey,"turbo",0,REG_DWORD,(BYTE*)&val,sizeof(DWORD));

	char profile[] = "AS @ L5";

	RegSetValueEx(xvidKey,"profile",0,REG_SZ,(unsigned char*)profile,strlen(profile));

	RegCloseKey(xvidKey);

  
	return true;

  }
























































		


