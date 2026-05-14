
// EFB-SimView.cpp: реализация класса CEFBSimView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "EFB-Sim.h"
#endif

#include "EFB-SimDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "EFB-SimView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEFBSimView

IMPLEMENT_DYNCREATE(CEFBSimView, CView)

BEGIN_MESSAGE_MAP(CEFBSimView, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CEFBSimView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CEFBSimView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CEFBSimView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CEFBSimView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CEFBSimView

CEFBSimView::CEFBSimView() noexcept
{
	m_pSelection = nullptr;
	// TODO: добавьте код создания

}

CEFBSimView::~CEFBSimView()
{
}

BOOL CEFBSimView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CEFBSimView

void CEFBSimView::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	CEFBSimDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	// TODO: также нарисуйте все элементы OLE в документе

	// Отрисуйте выделенный фрагмент в произвольном месте.  Этот код должен быть
	//  удален, поскольку реализован код отрисовки.  Это положение
	//  точно соответствует прямоугольнику, возвращенному CEFBSimCntrItem,
	//  для предоставления возможности редактирования по месту.

	// TODO: удалите этот код после завершения вашего кода рисования.
	if (m_pSelection != nullptr)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);

		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		m_pSelection->Draw(pDC, rect);
	}
}

void CEFBSimView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: удалите этот код, когда финальный код модели выбора будет написан
	m_pSelection = nullptr;    // инициализация выделения

}


// Печать CEFBSimView

BOOL CEFBSimView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CEFBSimView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CEFBSimView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CEFBSimView::OnDestroy()
{
	// Деактивируйте элемент при удалении; это важно
	// в случае использования представления разделителя
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CView::OnDestroy();
}



// Команды и поддержка клиента OLE

BOOL CEFBSimView::IsSelected(const CObject* pDocItem) const
{
	// Реализация ниже справедлива, если выделенный фрагмент состоит
	//  только из объектов CEFBSimCntrItem.  Чтобы управлять различными
	//  механизмами выбора следует заменить здесь реализацию

	// TODO: Реализуйте эту функцию, которая проверяет выбранный элемент клиента OLE

	return pDocItem == m_pSelection;
}

void CEFBSimView::OnInsertObject()
{
	// Откройте стандартное диалоговое окно "Вставка объекта" для получения информации
	//  для нового объекта CEFBSimCntrItem
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CEFBSimCntrItem* pItem = nullptr;
	TRY
	{
		// Создать новый элемент, связанный с этим документом
		CEFBSimDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CEFBSimCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Инициализируйте элемент из данных диалогового окна
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // любое исключение выполнит
		ASSERT_VALID(pItem);

        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// Поскольку дизайн интерфейса пользователя произвольный, это задает вставку выделенного
		//  фрагмента в последний элемент

		// TODO: повторите реализацию выделения, как это требуется в приложении
		m_pSelection = pItem;   // выделение последнего вставленного элемента
		pDoc->UpdateAllViews(nullptr);
	}
	CATCH(CException, e)
	{
		if (pItem != nullptr)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// Следующий обработчик команд предоставляет стандартный клавиатурный
//  интерфейс пользователя для отмены сеанса редактирования по месту.  Здесь
//  контейнер (не сервер) вызывает деактивацию
void CEFBSimView::OnCancelEditCntr()
{
	// Закройте в этом представлении все активные объекты редактирования по месту
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
}

// Для контейнера требуется специальная обработка OnSetFocus и OnSize,
//  если объект редактируется по месту
void CEFBSimView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// необходимо установить фокус на этот объект, если он находится в том же представлении
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != nullptr)
		{
			pWnd->SetFocus();   // не вызывайте базовый класс
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CEFBSimView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
		pActiveItem->SetItemRects();
}

void CEFBSimView::OnFilePrint()
{
	//По умолчанию печать активного документа запрашивается
	//с помощью IOleCommandTarget. Если такое поведение не требуется,
	//удалите вызов COleDocObjectItem::DoDefaultPrinting.
	//Если вызов будет неудачным по какой-либо причине, мы попробуем напечатать
	//docobject с помощью интерфейса IPrint.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != nullptr);
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;

	CView::OnFilePrint();

}


// Поддержка сервера OLE

// Следующий обработчик команд предоставляет стандартный клавиатурный
//  интерфейс пользователя для отмены сеанса редактирования по месту.  Здесь
//  сервер (не контейнер) вызывает деактивацию
void CEFBSimView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// Диагностика CEFBSimView

#ifdef _DEBUG
void CEFBSimView::AssertValid() const
{
	CView::AssertValid();
}

void CEFBSimView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEFBSimDoc* CEFBSimView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEFBSimDoc)));
	return (CEFBSimDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CEFBSimView
