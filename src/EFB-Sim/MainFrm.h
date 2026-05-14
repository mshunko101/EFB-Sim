
// MainFrm.h: интерфейс класса CMainFrame
//

#pragma once

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame() noexcept;

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	BOOL HideToolbar(UINT nIDToolbar);
	BOOL ShowToolbar(UINT nIDToolbar);
// Реализация
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CMap<UINT, UINT, CToolBar*, CToolBar*> m_toolbars;
// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


