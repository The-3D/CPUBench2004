#ifndef _LOADDRV_H_
#define _LOADDRV_H_ 
#include <windows.h>


class LoadDriver
{
public:
    LoadDriver();
    virtual ~LoadDriver();
    virtual void Init(char *sDriverName, char *sDriverFile, DWORD startLevel=SERVICE_AUTO_START,
                      char *sDriverPath = NULL, BOOL fUseReg = FALSE);
    virtual BOOL Create()=0;
    virtual BOOL Delete()=0;
    virtual BOOL Start()=0;
    virtual BOOL Stop()=0;
    char *GetLastMsg();
    virtual BOOL HasErr();
    virtual BOOL HasWrn();
    virtual BOOL HasMsg();

protected:
    virtual void PrintErr(char *msg);
    virtual void PrintWrn(char *msg);
    virtual void ClearErr();
    virtual void SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath);
    virtual BOOL OpenSCMHandle()=0;
    virtual void CloseSCMHandle()=0;

    char m_sLastMsg[2000];
    BOOL m_fUseReg;
    HANDLE m_h;
    BOOL m_fHasErr;
    BOOL m_fHasWrn;
    DWORD m_iStartLevel;
    char m_sDriverName[1000];
    char m_sDriverFile[1000];
    char m_sDriverPath[1000];
};

class LoadDriver95 : public LoadDriver
{
public:
    LoadDriver95();
    virtual ~LoadDriver95();
    virtual BOOL Create();
    virtual BOOL Delete();
    virtual BOOL Start();
    virtual BOOL Stop();
protected:
    virtual BOOL OpenSCMHandle();
    virtual void CloseSCMHandle();
    virtual void SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath);
};

class LoadDriverNT : public LoadDriver
{
public:
    LoadDriverNT();
    virtual ~LoadDriverNT();
    virtual BOOL Create();
    virtual BOOL Delete();
    virtual BOOL Start();
    virtual BOOL Stop();
    virtual BOOL CreateReg();
    virtual BOOL DeleteReg();
protected:
    virtual BOOL OpenSCMHandle();
    virtual void CloseSCMHandle();
    virtual void SetPaths(char *sDriverName, char *sDriverFile, char *sDriverPath);
};

LoadDriver *NewLoadDriver();

#endif _LOADDRV_H_
