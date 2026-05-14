
// ChildFrm.cpp: реализация класса CChildFrame
//

#include "pch.h"
#include "framework.h"
#include "EFB-Sim.h"
#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()

// Создание или уничтожение CChildFrame

CChildFrame::CChildFrame() noexcept
	:m_nIDToolbar1(IDR_SCHEME)
{
	// TODO: добавьте код инициализации члена
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: измените число строк, столбцов
		CSize(10, 10),	// TODO: измените минимальный размер области
		pContext);
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: измените класс Window или стили посредством изменения CREATESTRUCT cs
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return TRUE;
}

void CChildFrame::OnUpdateFrameMenu(BOOL bActivate, CWnd* pActivateWnd, HMENU hMenuAlt)
{
	CMainFrame* pFrame = static_cast<CMainFrame*>(GetMDIFrame());

	if (bActivate)
		pFrame->ShowToolbar(m_nIDToolbar1);
	else
		pFrame->HideToolbar(m_nIDToolbar1);

	CMDIChildWnd::OnUpdateFrameMenu(bActivate, pActivateWnd, hMenuAlt);
}

BOOL CChildFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{ 

	return CMDIChildWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext);
}
// Диагностика CChildFrame

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// Обработчики сообщений CChildFrame
