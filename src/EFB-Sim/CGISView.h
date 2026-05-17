#pragma once


// Просмотр CGISView

class CGISView : public CView
{
	DECLARE_DYNCREATE(CGISView)

protected:
	CGISView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CGISView();

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


