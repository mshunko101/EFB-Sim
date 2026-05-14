
// MainFrm.cpp: реализация класса CMainFrame
//

#include "pch.h"
#include "framework.h"
#include "EFB-Sim.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // индикатор строки состояния
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// Создание или уничтожение CMainFrame

CMainFrame::CMainFrame() noexcept
{
	// TODO: добавьте код инициализации члена
}

CMainFrame::~CMainFrame()
{
	// TODO : Add destroyer for TOOLBARS
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Не удалось создать панель инструментов\n");
		return -1;      // не удалось создать
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Не удалось создать строку состояния\n");
		return -1;      // не удалось создать
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Удалите эти три строки, если не собираетесь закреплять панель инструментов
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU;

	return TRUE;
}

BOOL CMainFrame::ShowToolbar(UINT nIDToolbar)
{
	CToolBar* pToolBar = nullptr;
	auto c = m_toolbars.Lookup(nIDToolbar, pToolBar);
	if (!pToolBar)
	{
		CToolBar* pBar = new CToolBar;
		if (!pBar)
			return FALSE;

		if (!pBar->CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) || !pBar->LoadToolBar(nIDToolbar))
		{
			delete pBar;
			return FALSE;
		}
		m_toolbars.SetAt(nIDToolbar, pBar);
		pToolBar = pBar;
	}
	else
	{ 
		pToolBar->ShowWindow(SW_SHOW);
	}
	if (pToolBar != nullptr)
	{
		pToolBar->EnableDocking(CBRS_ALIGN_ANY); 
		DockControlBar(pToolBar);
	}
	return TRUE;
}

BOOL CMainFrame::HideToolbar(UINT nIDToolbar)
{
	CToolBar* pToolBar = nullptr;
	auto c = m_toolbars.Lookup(nIDToolbar, pToolBar);

	if (pToolBar == nullptr)
	{
		return FALSE;
	}

	pToolBar->ShowWindow(SW_HIDE);

	RecalcLayout();

	return TRUE;
}

// Диагностика CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// Обработчики сообщений CMainFrame

