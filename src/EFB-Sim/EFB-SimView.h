
// EFB-SimView.h: интерфейс класса CEFBSimView
//

#pragma once

class CEFBSimCntrItem;

class CEFBSimView : public CView
{
protected: // создать только из сериализации
	CEFBSimView() noexcept;
	DECLARE_DYNCREATE(CEFBSimView)

// Атрибуты
public:
	CEFBSimDoc* GetDocument() const;
	// m_pSelection захватывает выделенную область в текущий CEFBSimCntrItem.
	// Для многих приложений, такая переменная-член не достаточна для
	//  представления выделенной области, например в случае выделения не смежных областей или
	//  выделения объектов, которые не являются объектами CEFBSimCntrItem.  Этот способ выделения
	//  предоставляется с целью помощи начинающим

	// TODO: замените данный способ выделения в вашем приложении
	CEFBSimCntrItem* m_pSelection;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Поддержка контейнера

// Реализация
public:
	virtual ~CEFBSimView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	afx_msg void OnCancelEditSrvr();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в EFB-SimView.cpp
inline CEFBSimDoc* CEFBSimView::GetDocument() const
   { return reinterpret_cast<CEFBSimDoc*>(m_pDocument); }
#endif

