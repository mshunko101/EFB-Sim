
// EFB-SimDoc.cpp: реализация класса CEFBSimDoc 
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
#include "SrvrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEFBSimDoc

IMPLEMENT_DYNCREATE(CEFBSimDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CEFBSimDoc, COleServerDoc)
	// Включите реализацию контейнера OLE
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &COleServerDoc::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, &COleServerDoc::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, &COleServerDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, &COleServerDoc::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &COleServerDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CEFBSimDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &COleServerDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &COleServerDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// Создание или уничтожение CEFBSimDoc

CEFBSimDoc::CEFBSimDoc() noexcept
{
	// Используйте объединенные файлы OLE
	EnableCompoundFile();

	// TODO: добавьте код для одноразового вызова конструктора

}

CEFBSimDoc::~CEFBSimDoc()
{
}

BOOL CEFBSimDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}


// Реализация сервера CEFBSimDoc

COleServerItem* CEFBSimDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem вызывается рабочей средой для получения COleServerItem,
	//  который связан с этим документом.  Вызывается при необходимости.

	CEFBSimSrvrItem* pItem = new CEFBSimSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}




// Сериализация CEFBSimDoc

void CEFBSimDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}

	// Вызов базового класса COleServerDoc включает сериализацию
	//  объектов COleClientItem документа контейнера.
	COleServerDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CEFBSimDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CEFBSimDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CEFBSimDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CEFBSimDoc

#ifdef _DEBUG
void CEFBSimDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CEFBSimDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG


// Команды CEFBSimDoc
