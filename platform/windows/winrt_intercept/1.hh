#define __WRL_WINRT_STRINGS_ENABLED__

#include <winstring.h>

#define WINRT_WindowsCreateString(p1, p2, p3)    \
    ((HRESULT)WindowsCreateString(		\
			(PCNZWCH)(p1)		\
			, (UINT32)(p2)		\
			, (HSTRING*)(p3)		\
			))

#define	WINRT_WindowsCreateStringReference(p1, p2, p3, p4)    \
    ((HRESULT)WindowsCreateStringReference(		\
			(PCWSTR)(p1)				\
			, (UINT32)(p2)				\
			, (HSTRING_HEADER*)(p3)		\
			, (HSTRING*)(p4)				\
			))

#define WINRT_WindowsGetStringRawBuffer(p1, p2)        \
    ((PCWSTR)WindowsGetStringRawBuffer(	\
		(HSTRING)(p1)					\
		, (UINT32*)(p2)					\
		))

#define WINRT_WindowsDeleteString(a)        \
    ((HRESULT)WindowsDeleteString((HSTRING)(a)))

#define WINRT_WindowsGetStringLen(a)        \
    ((UINT32)WindowsGetStringLen((HSTRING)(a)))

#define	WINRT_WindowsStringHasEmbeddedNull(str, r_hasembednil)	\
	((HRESULT)WindowsStringHasEmbeddedNull(	\
			(HSTRING)(str)					\
			, (BOOL*)(r_hasembednil)		\
			))

#define WINRT_WindowsPreallocateStringBuffer(len, chbuf, bufhandle)	\
	(HRESULT)(WindowsPreallocateStringBuffer(	\
			(UINT32)(len)		\
			, (WCHAR**)(chbuf)	\
			, (HSTRING_BUFFER*)(bufhandle)	\
			))

#define	WINRT_WindowsDuplicateString(str, newstr)	\
	((HRESULT)WindowsDuplicateString(	\
		(HSTRING)(str)					\
		, (HSTRING*)newstr				\
		))

#define WINRT_WindowsDeleteStringBuffer(buf)	\
	WindowsDeleteStringBuffer((HSTRING_BUFFER)(buf))

#define	WINRT_WindowsPromoteStringBuffer(buf, r_str)	\
	WindowsPromoteStringBuffer((HSTRING_BUFFER)(buf), (HSTRING*)(r_str))

#define WINRT_WindowsConcatString(s0, s1, ret)	\
	WindowsConcatString((HSTRING)(s0), (HSTRING)(s1), (HSTRING*)(ret))


#if	GODOT_HIGHLIGHT_INCOMPLETE /** original */
#elif	0
extern "C" {

	int32_t WINRT_CALL WINRT_WindowsCreateString(wchar_t const* sourceString, uint32_t length, void** string) noexcept;
	int32_t WINRT_CALL WINRT_WindowsCreateStringReference(wchar_t const* sourceString, uint32_t length, void* hstringHeader, void** string) noexcept;
	int32_t WINRT_CALL WINRT_WindowsDuplicateString(void* string, void** newString) noexcept;
	int32_t WINRT_CALL WINRT_WindowsDeleteString(void* string) noexcept;
	int32_t WINRT_CALL WINRT_WindowsStringHasEmbeddedNull(void* string, int* hasEmbedNull) noexcept;
	int32_t WINRT_CALL WINRT_WindowsPreallocateStringBuffer(uint32_t length, wchar_t** charBuffer, void** bufferHandle) noexcept;
	int32_t WINRT_CALL WINRT_WindowsDeleteStringBuffer(void* bufferHandle) noexcept;
	int32_t WINRT_CALL WINRT_WindowsPromoteStringBuffer(void* bufferHandle, void** string) noexcept;
	int32_t WINRT_CALL WINRT_WindowsConcatString(void* string1, void* string2, void** newString) noexcept;
	wchar_t const* WINRT_CALL WINRT_WindowsGetStringRawBuffer(void* string, uint32_t* length) noexcept;
	uint32_t WINRT_CALL WINRT_WindowsGetStringLen(void* string) noexcept;
}

#endif
