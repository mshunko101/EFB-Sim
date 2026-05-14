
// SrvrItem.cpp: реализация класса CEFBSimSrvrItem
//

#include "pch.h"
#include "framework.h"
#include "EFB-Sim.h"

#include "EFB-SimDoc.h"
#include "SrvrItem.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Реализация CEFBSimSrvrItem

IMPLEMENT_DYNAMIC(CEFBSimSrvrItem, COleServerItem)

CEFBSimSrvrItem::CEFBSimSrvrItem(CEFBSimDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: добавьте код для одноразового вызова конструктора
	//  (например, добавление дополнительных форматов для буфера обмена в источнике данных элемента)
}

CEFBSimSrvrItem::~CEFBSimSrvrItem()
{
	// TODO: добавьте код очистки
}

void CEFBSimSrvrItem::Serialize(CArchive& ar)
{
	// CEFBSimSrvrItem::Serialize вызывается платформой, если
	//  элемент копируется в буфер обмена.  Это может произойти автоматически
	//  посредством обратного вызова OLE OnGetClipboardData.  Для внедренного элемента
	//  по умолчанию рекомендуется просто делегировать в функцию Serialize
	//  документа.  В случае поддержки ссылок возможно потребуется сериализовать
	//  отдельную часть документа.

	if (!IsLinkedItem())
	{
		CEFBSimDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL CEFBSimSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Большинство приложений (например, это) обрабатывают только отрисовку аспектов содержимого
	//  элемента. Для поддержки других аспектов, например
	//  DVASPECT_THUMBNAIL (с помощью переопределения OnDrawEx)
	//  измените реализацию OnGetExtent для поддержки
	//  дополнительных аспектов.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CEFBSimSrvrItem::OnGetExtent вызывается для получения величины в
	//  единицах HIMETRIC целого элемента.  В реализации по умолчанию
	//  просто возвращается количество единиц.

	// TODO: замените этот случайный размер

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC единиц

	return TRUE;
}

BOOL CEFBSimSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// Удалите этот код, если вы используете rSize
	UNREFERENCED_PARAMETER(rSize);

	// TODO: задайте режим отображения и величину
	//  (Величина обычно совпадает с размером, возвращенным из OnGetExtent)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: добавьте код отрисовки.  Кроме того, заполните величину HIMETRIC.
	//  Все рисунки производятся в контексте устройства метафайла (pDC).

	// TODO: также нарисовать внедренные объекты CEFBSimCntrItem.

	// Следующий код нарисует первый элемент в случайном положении.

	// TODO: удалите этот код после завершения вашего кода рисования

	CEFBSimDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;

	POSITION pos = pDoc->GetStartPosition();
	CEFBSimCntrItem* pItem = DYNAMIC_DOWNCAST(CEFBSimCntrItem, pDoc->GetNextClientItem(pos));
	if (pItem != nullptr)
		pItem->Draw(pDC, CRect(10, 10, 1010, 1010));
	return TRUE;
}


// Диагностика CEFBSimSrvrItem

#ifdef _DEBUG
void CEFBSimSrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CEFBSimSrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

