
#include <processthreadsapi.h>
#include <securitybaseapi.h>

#define WINRT_OpenProcessToken(/** [in] */ proc, /** [in] */ access, /** [out] */ tok)	\
	OpenProcessToken((HANDLE)(proc), (DWORD)(access), (PHANDLE)(tok))

#define WINRT_GetCurrentProcess	GetCurrentProcess

#define WINRT_DuplicateToken(/** [in] */ existing, /** [in] */ lvl, /** [out] */ duptok)	\
	DuplicateToken((HANDLE)(existing), (SECURITY_IMPERSONATION_LEVEL)(lvl), (PHANDLE)(duptok))

/**
 * @param[in]	thrd
 * @param[in]	access
 * @param[in]	self
 * @param[out]	tok
 * */
#define WINRT_OpenThreadToken(thrd, access, self, tok)	\
	OpenThreadToken((HANDLE)(thrd), (DWORD)(access), (BOOL)(self), (PHANDLE)(tok))

#define WINRT_GetCurrentThread	GetCurrentThread

#define WINRT_SetThreadToken(/** [in, opt] */ thrd, /** [in, opt] */ tok)	\
	SetThreadToken((PHANDLE)(thrd), (HANDLE)(tok))

#ifdef GODOT_HIGHLIGHT_INCOMPLETE
#elif	0
extern "C" {
	int32_t  WINRT_CALL WINRT_OpenProcessToken(void* process, uint32_t access, void** token) noexcept;
	void*    WINRT_CALL WINRT_GetCurrentProcess() noexcept;
	int32_t  WINRT_CALL WINRT_DuplicateToken(void* existing, uint32_t level, void** duplicate) noexcept;
	int32_t  WINRT_CALL WINRT_OpenThreadToken(void* thread, uint32_t access, int32_t self, void** token) noexcept;
	void*    WINRT_CALL WINRT_GetCurrentThread() noexcept;
	int32_t  WINRT_CALL WINRT_SetThreadToken(void** thread, void* token) noexcept;
}

#endif
