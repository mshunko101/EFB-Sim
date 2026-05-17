// CWorkspaceDoc.cpp: файл реализации
//

#include "pch.h"
#include "EFB-Sim.h"
#include "CWorkspaceDoc.h"


// CWorkspaceDoc

IMPLEMENT_DYNCREATE(CWorkspaceDoc, CEFBSimDoc)

CWorkspaceDoc::CWorkspaceDoc()
{
}

BOOL CWorkspaceDoc::OnNewDocument()
{
	if (!CEFBSimDoc::OnNewDocument())
		return FALSE;
	return TRUE;
}

CWorkspaceDoc::~CWorkspaceDoc()
{
}


BEGIN_MESSAGE_MAP(CWorkspaceDoc, CEFBSimDoc)
END_MESSAGE_MAP()


// Диагностика CWorkspaceDoc

#ifdef _DEBUG
void CWorkspaceDoc::AssertValid() const
{
	CEFBSimDoc::AssertValid();
}

#ifndef _WIN32_WCE
void CWorkspaceDoc::Dump(CDumpContext& dc) const
{
	CEFBSimDoc::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// Cериализация CWorkspaceDoc

void CWorkspaceDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}
#endif


// Команды CWorkspaceDoc
