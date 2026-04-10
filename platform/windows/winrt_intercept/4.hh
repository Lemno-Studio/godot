#if	1	/** original */
extern "C" {
	int32_t  WINRT_CALL WINRT_OpenProcessToken(void* process, uint32_t access, void** token) noexcept;
	void*    WINRT_CALL WINRT_GetCurrentProcess() noexcept;
	int32_t  WINRT_CALL WINRT_DuplicateToken(void* existing, uint32_t level, void** duplicate) noexcept;
	int32_t  WINRT_CALL WINRT_OpenThreadToken(void* thread, uint32_t access, int32_t self, void** token) noexcept;
	void*    WINRT_CALL WINRT_GetCurrentThread() noexcept;
	int32_t  WINRT_CALL WINRT_SetThreadToken(void** thread, void* token) noexcept;
}

#endif
