// CWorkspaceView.cpp: файл реализации
//

#include "pch.h"
#include "EFB-Sim.h"
#include "CWorkspaceView.h"


// CWorkspaceView

IMPLEMENT_DYNCREATE(CWorkspaceView, CView)

CWorkspaceView::CWorkspaceView()
{

}

CWorkspaceView::~CWorkspaceView()
{
}

BEGIN_MESSAGE_MAP(CWorkspaceView, CView)
END_MESSAGE_MAP()


// Рисование CWorkspaceView

void CWorkspaceView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: добавьте код отрисовки
}


// Диагностика CWorkspaceView

#ifdef _DEBUG
void CWorkspaceView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWorkspaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CWorkspaceView
