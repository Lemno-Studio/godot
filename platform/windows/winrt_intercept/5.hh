
#include <synchapi.h>
#include <interlockedapi.h>

#define WINRT_SleepConditionVariableSRW(	\
		/** [in, out] */ cv	\
		, /** [in, out] */ lock	\
		, /** [in] */ msec	\
		, /** [in] */ flags	\
		)		\
	((BOOL)SleepConditionVariableSRW(	\
			(PCONDITION_VARIABLE)(cv)	\
			, (PSRWLOCK)(lock)	\
			, (DWORD)(msec)		\
			, (ULONG)(flags)	\
			))

#define	WINRT_WakeAllConditionVariable(/** [in, out] */ cv)	\
	WakeAllConditionVariable((PCONDITION_VARIABLE)(cv))

#define	WINRT_InterlockedPushEntrySList(	\
		/** [in, out] */ ListHead					\
		, /** [in, out] */ListEntry					\
		)											\
	((PSLIST_ENTRY)InterlockedPushEntrySList(		\
			(PSLIST_HEADER)(ListHead)				\
			, (__drv_aliasesMem PSLIST_ENTRY)(ListEntry)		\
			))

#define WINRT_InitializeSListHead(/** [in, out] */ ListHead)	\
	InitializeSListHead((PSLIST_HEADER)(ListHead))

#define WINRT_AcquireSRWLockShared(/** [in, out] */ lock)	\
	AcquireSRWLockShared((PSRWLOCK)(lock))

#define WINRT_AcquireSRWLockExclusive(/** [in, out] */ lock)	\
	AcquireSRWLockExclusive((PSRWLOCK)(lock))

#define WINRT_WakeConditionVariable(/** [in, out] */ cv)	\
	WakeConditionVariable((PCONDITION_VARIABLE)(cv))	\

#define WINRT_ReleaseSRWLockShared(/** [in, out] */ lock)	\
	ReleaseSRWLockShared((PSRWLOCK)(lock))

#if	1	/** original */
extern "C" {

	void    WINRT_CALL WINRT_AcquireSRWLockExclusive(winrt::impl::srwlock* lock) noexcept;
	void    WINRT_CALL WINRT_AcquireSRWLockShared(winrt::impl::srwlock* lock) noexcept;
	uint8_t WINRT_CALL WINRT_TryAcquireSRWLockExclusive(winrt::impl::srwlock* lock) noexcept;
	uint8_t WINRT_CALL WINRT_TryAcquireSRWLockShared(winrt::impl::srwlock* lock) noexcept;
	void    WINRT_CALL WINRT_ReleaseSRWLockExclusive(winrt::impl::srwlock* lock) noexcept;
	void    WINRT_CALL WINRT_ReleaseSRWLockShared(winrt::impl::srwlock* lock) noexcept;
	int32_t WINRT_CALL WINRT_SleepConditionVariableSRW(winrt::impl::condition_variable* cv, winrt::impl::srwlock* lock, uint32_t milliseconds, uint32_t flags) noexcept;
	void    WINRT_CALL WINRT_WakeConditionVariable(winrt::impl::condition_variable* cv) noexcept;
	void    WINRT_CALL WINRT_WakeAllConditionVariable(winrt::impl::condition_variable* cv) noexcept;
	void    WINRT_CALL WINRT_InitializeSListHead(void* head) noexcept;
	void*   WINRT_CALL WINRT_InterlockedPushEntrySList(void* head, void* entry) noexcept;
	void*   WINRT_CALL WINRT_InterlockedFlushSList(void* head) noexcept;
}
#endif
