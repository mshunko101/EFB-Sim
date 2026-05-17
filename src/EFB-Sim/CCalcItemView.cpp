// CCalcItemView.cpp: файл реализации
//

#include "pch.h"
#include "EFB-Sim.h"
#include "CCalcItemView.h"


// CCalcItemView

IMPLEMENT_DYNCREATE(CCalcItemView, CEFBSimView)

CCalcItemView::CCalcItemView()
{

}

CCalcItemView::~CCalcItemView()
{
}

BEGIN_MESSAGE_MAP(CCalcItemView, CEFBSimView)
END_MESSAGE_MAP()


// Рисование CCalcItemView

void CCalcItemView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: добавьте код отрисовки
}


// Диагностика CCalcItemView

#ifdef _DEBUG
void CCalcItemView::AssertValid() const
{
	CEFBSimView::AssertValid();
}

#ifndef _WIN32_WCE
void CCalcItemView::Dump(CDumpContext& dc) const
{
	CEFBSimView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CCalcItemView
