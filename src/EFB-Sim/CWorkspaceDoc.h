#pragma once
// Документ CWorkspaceDoc

class CWorkspaceDoc : public CEFBSimDoc
{
	DECLARE_DYNCREATE(CWorkspaceDoc)

public:
	CWorkspaceDoc();
	virtual ~CWorkspaceDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // перезапись для входа/выхода документа
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
