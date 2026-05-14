
// ChildFrm.h: интерфейс класса CChildFrame
//

#pragma once

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame() noexcept;

// Атрибуты
protected:
	CSplitterWnd m_wndSplitter;
public:

// Операции
public:

// Переопределение
	public:
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdateFrameMenu(BOOL bActivate, CWnd* pActivateWnd, HMENU hMenuAlt) override;
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) override;
// Реализация
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

	UINT m_nIDToolbar1;
};
