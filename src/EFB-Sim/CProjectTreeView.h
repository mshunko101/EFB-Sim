#pragma once

#include <afxcview.h>

// Просмотр CProjectTreeView

class CProjectTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CProjectTreeView)

protected:
	CProjectTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CProjectTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


