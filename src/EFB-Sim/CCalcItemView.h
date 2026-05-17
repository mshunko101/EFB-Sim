#pragma once


// Просмотр CCalcItemView

class CCalcItemView : public CEFBSimView
{
	DECLARE_DYNCREATE(CCalcItemView)

protected:
	CCalcItemView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CCalcItemView();

public:
	virtual void OnDraw(CDC* pDC);      // для отрисовки этого представления
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


