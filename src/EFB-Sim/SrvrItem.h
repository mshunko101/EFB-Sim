
// SrvrItem.h: интерфейс класса CEFBSimSrvrItem
//

#pragma once

class CEFBSimSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CEFBSimSrvrItem)

// Конструкторы
public:
	CEFBSimSrvrItem(CEFBSimDoc* pContainerDoc);

// Атрибуты
	CEFBSimDoc* GetDocument() const
		{ return reinterpret_cast<CEFBSimDoc*>(COleServerItem::GetDocument()); }

// Переопределение
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Реализация
public:
	~CEFBSimSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // перезапись для входа/выхода документа
};

