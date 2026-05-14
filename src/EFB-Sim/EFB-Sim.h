
// EFB-Sim.h: основной файл заголовка для приложения EFB-Sim
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CEFBSimApp:
// Сведения о реализации этого класса: EFB-Sim.cpp
//

class CEFBSimApp : public CWinApp
{
public:
	CEFBSimApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	COleTemplateServer m_server;
		// Объект сервера для создания документа
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEFBSimApp theApp;
