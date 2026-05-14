
// EFB-SimDoc.h: интерфейс класса CEFBSimDoc 
//


#pragma once


class CEFBSimSrvrItem;

class CEFBSimDoc : public COleServerDoc
{
protected: // создать только из сериализации
	CEFBSimDoc() noexcept;
	DECLARE_DYNCREATE(CEFBSimDoc)

// Атрибуты
public:
	CEFBSimSrvrItem* GetEmbeddedItem()
		{ return reinterpret_cast<CEFBSimSrvrItem*>(COleServerDoc::GetEmbeddedItem()); }

// Операции
public:

// Переопределение
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	afx_msg void OnUpdateCommand(CCmdUI* pCmdUI);
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CEFBSimDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
