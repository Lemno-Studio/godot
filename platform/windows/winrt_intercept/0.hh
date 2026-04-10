#include <roapi.h>
#include <combaseapi.h>
#include <roerrorapi.h>

#define WINRT_GetRestrictedErrorInfo(/** [out] */ info)	\
	GetRestrictedErrorInfo((IRestrictedErrorInfo **)(info))

#define WINRT_RoGetActivationFactory(classid, iid, factory)	\
	((HRESULT)(RoGetActivationFactory(		\
			(HSTRING)(classid)	\
			, (REFIID)(iid)		\
			, (void**)(factory)	\
			)))

#define	WINRT_RoInitialize(/** [in] */ ty)	\
	RoInitialize((RO_INIT_TYPE)(ty))

#define	WINRT_RoOriginateLanguageException(/** [in] */ err, /** [in, opt] */msg, /** [in] */ex)	\
	((BOOL)RoOriginateLanguageException((HRESULT)(err), (HSTRING)(msg), (IUnknown*)(ex)))

#define WINRT_RoUninitialize	RoUninitialize
#define	WINRT_SetRestrictedErrorInfo(/** [in] */info)	\
	SetRestrictedErrorInfo((IRestrictedErrorInfo*)(info))

#define WINRT_RoGetAgileReference(/** [in] */ opts, /** in */ riid, /** in */obj, /** in, out */ ref)	\
	RoGetAgileReference((AgileReferenceOptions)(opts), (REFIID)(riid), (IUnknown*)(obj), (IAgileReference**)(ref))

#define WINRT_CoIncrementMTAUsage(pCookie)			\
	((HRESULT)CoIncrementMTAUsage((CO_MTA_USAGE_COOKIE*)(pCookie)))


#if	0			/** originals */
extern "C" {
	int32_t WINRT_CALL WINRT_GetRestrictedErrorInfo(void** info) noexcept;
	int32_t WINRT_CALL WINRT_RoGetActivationFactory(void* classId, winrt::guid const& iid, void** factory) noexcept;
	int32_t WINRT_CALL WINRT_RoInitialize(uint32_t type) noexcept;
	int32_t WINRT_CALL WINRT_RoOriginateLanguageException(int32_t error, void* message, void* exception) noexcept;
	void    WINRT_CALL WINRT_RoUninitialize() noexcept;
	int32_t WINRT_CALL WINRT_SetRestrictedErrorInfo(void* info) noexcept;
	int32_t WINRT_CALL WINRT_RoGetAgileReference(uint32_t options, winrt::guid const& iid, void* object, void** reference) noexcept;
	int32_t WINRT_CALL WINRT_CoIncrementMTAUsage(void** cookie) noexcept;
}
#endif
