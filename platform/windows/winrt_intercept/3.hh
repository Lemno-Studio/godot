
#include <handleapi.h>

#define WINRT_CloseHandle(/** [in] */ h)	\
	CloseHandle((HANDLE)(h))

#if	1	/** original */

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
