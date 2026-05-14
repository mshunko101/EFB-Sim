// dllmain.h: объявление класса модуля.

class CEFBSimHandlersModule : public ATL::CAtlDllModuleT<CEFBSimHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_EFBSimHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_EFBSIMHANDLERS, "{c6b5ecd6-667d-45f9-a20b-1c5882303fe5}")
};

extern class CEFBSimHandlersModule _AtlModule;
