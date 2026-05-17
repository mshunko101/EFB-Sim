#pragma once

// Просмотр CWorkspaceView

class CWorkspaceView : public CEFBSimView
{
	DECLARE_DYNCREATE(CWorkspaceView)

protected:
	CWorkspaceView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CWorkspaceView();

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


