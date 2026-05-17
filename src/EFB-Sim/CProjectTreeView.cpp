// CProjectTreeView.cpp: файл реализации
//

#include "pch.h"
#include "EFB-Sim.h"
#include "CProjectTreeView.h"


// CProjectTreeView

IMPLEMENT_DYNCREATE(CProjectTreeView, CTreeView)

CProjectTreeView::CProjectTreeView()
{

}

CProjectTreeView::~CProjectTreeView()
{
}

BEGIN_MESSAGE_MAP(CProjectTreeView, CTreeView)
END_MESSAGE_MAP()


// Диагностика CProjectTreeView

#ifdef _DEBUG
void CProjectTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CProjectTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CProjectTreeView
