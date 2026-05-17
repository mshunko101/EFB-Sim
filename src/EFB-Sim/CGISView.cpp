// CGISView.cpp: файл реализации
//

#include "pch.h"
#include "EFB-Sim.h"
#include "CGISView.h"


// CGISView

IMPLEMENT_DYNCREATE(CGISView, CView)

CGISView::CGISView()
{

}

CGISView::~CGISView()
{
}

BEGIN_MESSAGE_MAP(CGISView, CView)
END_MESSAGE_MAP()


// Рисование CGISView

void CGISView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: добавьте код отрисовки
}


// Диагностика CGISView

#ifdef _DEBUG
void CGISView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CGISView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CGISView
