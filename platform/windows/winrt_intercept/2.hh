
#include <handleapi.h>
#include <combaseapi.h>
#include <stringapiset.h>
#include <heapapi.h>
#include <winbase.h>
#include <errhandlingapi.h>
#include <sysinfoapi.h>
#include <hstring.h >

#define WINRT_CoCreateFreeThreadedMarshaler(	\
		/** [in] */ outer	\
		, /** [out] */ mrshlr	\
		)	\
		CoCreateFreeThreadedMarshaler((LPUNKNOWN)(outer), (LPUNKNOWN*)(mrshlr))

/**
 * @param[in]	clsid
 * @param[in]	outr
 * @param[in]	ctx
 * @param[in]	iid
 * @param[out]	obj
 * */
#define WINRT_CoCreateInstance(clsid, outr, ctx, iid, obj)	\
	CoCreateInstance((REFCLSID)(clsid), (LPUNKNOWN)(outr), (DWORD)(ctx), (REFIID)(iid), (LPVOID*)(obj))


#if	0
#define	WINRT_CoGetCallContext(/** [in] */ iid, /** [out] */ obj)	\
	CoGetCallContext((REFIID)(iid), (void**)(obj))
#else
#define	WINRT_CoGetCallContext	CoGetCallContext
#endif

#define WINRT_CoGetObjectContext(/** [in] */ iid, /** [out] */ obj)	\
	CoGetObjectContext((REFIID)(iid), (LPVOID*)(obj))


#define WINRT_CoGetApartmentType(ty, qlfr)	\
	CoGetApartmentType((APTTYPE*)(ty), (APTTYPEQUALIFIER*)(qlfr))

#define WINRT_CoTaskMemAlloc(/** [in] */ cb)	\
	CoTaskMemAlloc((SIZE_T)(cb))

#define	WINRT_CoTaskMemFree(/** [in, opt] */ pv)	\
	CoTaskMemFree((_Frees_ptr_opt_ LPVOID)(pv))

#define WINRT_SysFreeString(/** [in, opt] */ bstr)	\
	SysFreeString((_Frees_ptr_opt_ BSTR)(bstr))

#define WINRT_SysStringLen(/** [in, opt] */ bstr)	\
	SysStringLen((BSTR)(bstr))

#define	WINRT_IIDFromString(/** [in] */ lpsz, /** [out] */ lpiid)	\
	IIDFromString((LPCOLESTR)(lpsz), (LPIID)(lpiid))

#define WINRT_CloseHandle(/** [in] */ h)	\
	CloseHandle((HANDLE)(h))

/**
 * @param[in]		cp
 * @param[in]		flags
 * @param[in]		mbs
 * @param[in]		mb
 * @param[out, opt]	wcs
 * @param[in]		wc
 * */
#define WINRT_MultiByteToWideChar(cp, flags, mbs, mb, wcs, wc)	\
	MultiByteToWideChar((UINT)(cp), (DWORD)(flags)	\
			, (_In_NLS_string_(cbMultiByte)LPCCH)(mbs)	\
			, (int)(mb), (LPWSTR)(wcs), (int)(wc))

/**
 * @param[in]		cp
 * @param[in]		flags
 * @param[in]		wcs
 * @param[in]		wc
 * @param[out, opt]	mbs
 * @param[in]		mb
 * @param[in, opt]	ch_default
 * @param[out, opt]	used_default
 * */
#define WINRT_WideCharToMultiByte(cp, flags, wcs, wc, mbs, mb, ch_default, used_default)	\
	WideCharToMultiByte((UINT)(cp), (DWORD)(flags)	\
			, (_In_NLS_string_(cchWideChar)LPCWCH)(wcs)	\
			, (int)(wc)	\
			, (LPSTR)(mbs)	\
			, (int)(mb)	\
			, (LPCCH)(ch_default)	\
			, (LPBOOL)(used_default)	\
			)

#define WINRT_HeapFree(/** [in] */ heap, /** [in] */ flags, /** [in] */ mem)	\
	HeapFree((HANDLE)(heap), (DWORD)(flags), (_Frees_ptr_opt_ LPVOID)(mem))

#define	WINRT_GetProcessHeap	GetProcessHeap

/**
 * @param[in]		flags
 * @param[in, opt]	src
 * @param[in]		msgid
 * @param[in]		langid
 * @param[out]		buf
 * @param[in]		nsz
 * @param[in, opt]	args
 * */
#define WINRT_FormatMessageW(flags, src, msgid, langid, buf, nsz, args)	\
	FormatMessageW((DWORD)(flags), (LPCVOID)(src), (DWORD)(msgid)	\
			, (DWORD)(langid), (LPWSTR)(buf), (DWORD)(nsz), (va_list*)(args))

#define WINRT_GetLastError	GetLastError

#define WINRT_GetSystemTimePreciseAsFileTime(/** [out] */ ret)	\
	GetSystemTimePreciseAsFileTime((LPFILETIME)(ret))

#define WINRT_GetCurrentThreadStackLimits(/** [out] */ lowlmt, /** [out] */ hghlmt)	\
	GetCurrentThreadStackLimits((PULONG_PTR)(lowlmt), (PULONG_PTR)(hghlmt))

#ifdef GODOT_HIGHLIGHT_INCOMPLETE
#elif	0
extern "C" {
	int32_t  WINRT_CALL WINRT_CoCreateFreeThreadedMarshaler(void* outer, void** marshaler) noexcept;
	int32_t  WINRT_CALL WINRT_CoCreateInstance(winrt::guid const& clsid, void* outer, uint32_t context, winrt::guid const& iid, void** object) noexcept;
	int32_t  WINRT_CALL WINRT_CoGetCallContext(winrt::guid const& iid, void** object) noexcept;
	int32_t  WINRT_CALL WINRT_CoGetObjectContext(winrt::guid const& iid, void** object) noexcept;
	int32_t  WINRT_CALL WINRT_CoGetApartmentType(int32_t* type, int32_t* qualifier) noexcept;
	void*    WINRT_CALL WINRT_CoTaskMemAlloc(std::size_t size) noexcept;
	void     WINRT_CALL WINRT_CoTaskMemFree(void* ptr) noexcept;
	void     WINRT_CALL WINRT_SysFreeString(winrt::impl::bstr string) noexcept;
	uint32_t WINRT_CALL WINRT_SysStringLen(winrt::impl::bstr string) noexcept;
	int32_t  WINRT_CALL WINRT_IIDFromString(wchar_t const* string, winrt::guid* iid) noexcept;
	int32_t  WINRT_CALL WINRT_CloseHandle(void* hObject) noexcept;
	int32_t  WINRT_CALL WINRT_MultiByteToWideChar(uint32_t codepage, uint32_t flags, char const* in_string, int32_t in_size, wchar_t* out_string, int32_t out_size) noexcept;
	int32_t  WINRT_CALL WINRT_WideCharToMultiByte(uint32_t codepage, uint32_t flags, wchar_t const* int_string, int32_t in_size, char* out_string, int32_t out_size, char const* default_char, int32_t* default_used) noexcept;
	int32_t  WINRT_CALL WINRT_HeapFree(void* heap, uint32_t flags, void* value) noexcept;
	void*    WINRT_CALL WINRT_GetProcessHeap() noexcept;
	uint32_t WINRT_CALL WINRT_FormatMessageW(uint32_t flags, void const* source, uint32_t code, uint32_t language, wchar_t* buffer, uint32_t size, va_list* arguments) noexcept;
	uint32_t WINRT_CALL WINRT_GetLastError() noexcept;
	void     WINRT_CALL WINRT_GetSystemTimePreciseAsFileTime(void* result) noexcept;
	void     WINRT_CALL WINRT_GetCurrentThreadStackLimits(uintptr_t* low_limit, uintptr_t* high_limit) noexcept;
}

#endif
