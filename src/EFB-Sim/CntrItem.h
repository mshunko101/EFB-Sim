
// CntrItem.h: интерфейс класса CEFBSimCntrItem
//

#pragma once

class CEFBSimDoc;
class CEFBSimView;

class CEFBSimCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CEFBSimCntrItem)

// Конструкторы
public:
	CEFBSimCntrItem(CEFBSimDoc* pContainer = nullptr);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами.  Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
public:
	CEFBSimDoc* GetDocument()
		{ return reinterpret_cast<CEFBSimDoc*>(COleClientItem::GetDocument()); }
	CEFBSimView* GetActiveView()
		{ return reinterpret_cast<CEFBSimView*>(COleClientItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);
	virtual BOOL CanActivate();

// Реализация
public:
	~CEFBSimCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

