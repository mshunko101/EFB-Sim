// dllmain.cpp: реализация DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "EFBSimHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CEFBSimHandlersModule _AtlModule;

class CEFBSimHandlersApp : public CWinApp
{
public:

// Переопределение
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CEFBSimHandlersApp, CWinApp)
END_MESSAGE_MAP()

CEFBSimHandlersApp theApp;

BOOL CEFBSimHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CEFBSimHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
