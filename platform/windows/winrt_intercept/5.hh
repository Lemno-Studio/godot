
#include <synchapi.h>
#include <threadpoolapiset.h>
#include <combaseapi.h>
#include <roapi.h>

#define WINRT_WaitForSingleObject(/** [in] */ hd, /** [in] */ msec)	\
	WaitForSingleObject((HANDLE)(hd), (DWORD)(msec))

#define WINRT_TrySubmitThreadpoolCallback(/** [in] */ pfns, /** [in, out, opt] */ pv, /** [in, opt] */ pcbe)	\
	TrySubmitThreadpoolCallback((PTP_SIMPLE_CALLBACK)(pfns), (PVOID)(pv), (PTP_CALLBACK_ENVIRON)(pcbe))

#define WINRT_CreateThreadpoolTimer(/** [in] */ pfnti, /** [in, out, opt] */ pv, /** [in, opt] */ pcbe)	\
	CreateThreadpoolTimer((PTP_TIMER_CALLBACK)(pfnti), (PVOID)(pv), (PTP_CALLBACK_ENVIRON)(pcbe))

/**
 * @param[in, out]	timer
 * @param[in, opt]	time
 * @param[in]		period
 * @param[in]		windows
 * */
#define WINRT_SetThreadpoolTimer(timer, time, period, windows)	\
	SetThreadpoolTimer((PTP_TIMER)(timer), (PFILETIME)(time), (DWORD)(period), (DWORD)(windows))

#define WINRT_CloseThreadpoolTimer(/** [in, out] */ timer)	\
	CloseThreadpoolTimer((PTP_TIMER)(timer))

#define WINRT_CreateThreadpoolWait(/** [in] */ pfnwa, /** [in, out, opt] */ pv, /** [in, opt] */ pcbe)	\
	CreateThreadpoolWait((PTP_WAIT_CALLBACK)(pfnwa), (PVOID)(pv), (PTP_CALLBACK_ENVIRON)(pcbe))

#define WINRT_SetThreadpoolWait(/** [in, out] */ pwa, /** [in, opt] */ hndl, /** [in, opt] */ pftmout)	\
	SetThreadpoolWait((PTP_WAIT)(pwa), (HANDLE)(hndl), (PFILETIME)(pftmout))

#define WINRT_CloseThreadpoolWait(/** [in, out] */ pwa)	\
	CloseThreadpoolWait((PTP_WAIT)(pwa))

/**
 * @param[in]			fl
 * @param[in]			pfnio
 * @param[in, out, opt]	pv
 * @param[in, opt]		pcbe
 * */
#define WINRT_CreateThreadpoolIo(fl, pfnio, pv, pcbe)	\
	CreateThreadpoolIo((HANDLE)(fl), (PTP_WIN32_IO_CALLBACK)(pfnio)	\
			, (PVOID)(pv), (PTP_CALLBACK_ENVIRON)(pcbe))

#define WINRT_StartThreadpoolIo(/** [in, out] */ pio)	StartThreadpoolIo((PTP_IO)pio)
#define WINRT_CancelThreadpoolIo(/** [in, out] */ pio)	CancelThreadpoolIo((PTP_IO)pio)
#define WINRT_CloseThreadpoolIo(/** [in, out] */ pio)	CloseThreadpoolIo((PTP_IO)pio)

#define WINRT_CanUnloadNow	CanUnloadNow

#define WINRT_GetActivationFactory(/** [in] */ clsid, /** [out] */ factory)	\
	GetActivationFactory((HSTRING)(clsid), (void**)(factory))

#ifdef GODOT_HIGHLIGHT_INCOMPLETE
#elif	0
extern "C"	/** original */
{
	uint32_t WINRT_CALL WINRT_WaitForSingleObject(void* handle, uint32_t milliseconds) noexcept;
	int32_t  WINRT_CALL WINRT_TrySubmitThreadpoolCallback(void(WINRT_CALL *callback)(void*, void* context), void* context, void*) noexcept;
	winrt::impl::ptp_timer WINRT_CALL WINRT_CreateThreadpoolTimer(void(WINRT_CALL *callback)(void*, void* context, void*), void* context, void*) noexcept;
	void     WINRT_CALL WINRT_SetThreadpoolTimer(winrt::impl::ptp_timer timer, void* time, uint32_t period, uint32_t window) noexcept;
	void     WINRT_CALL WINRT_CloseThreadpoolTimer(winrt::impl::ptp_timer timer) noexcept;
	winrt::impl::ptp_wait WINRT_CALL WINRT_CreateThreadpoolWait(void(WINRT_CALL *callback)(void*, void* context, void*, uint32_t result), void* context, void*) noexcept;
	void     WINRT_CALL WINRT_SetThreadpoolWait(winrt::impl::ptp_wait wait, void* handle, void* timeout) noexcept;
	void     WINRT_CALL WINRT_CloseThreadpoolWait(winrt::impl::ptp_wait wait) noexcept;
	winrt::impl::ptp_io WINRT_CALL WINRT_CreateThreadpoolIo(void* object, void(WINRT_CALL *callback)(void*, void* context, void* overlapped, uint32_t result, std::size_t bytes, void*) noexcept, void* context, void*) noexcept;
	void     WINRT_CALL WINRT_StartThreadpoolIo(winrt::impl::ptp_io io) noexcept;
	void     WINRT_CALL WINRT_CancelThreadpoolIo(winrt::impl::ptp_io io) noexcept;
	void     WINRT_CALL WINRT_CloseThreadpoolIo(winrt::impl::ptp_io io) noexcept;

	int32_t WINRT_CALL WINRT_CanUnloadNow() noexcept;
	int32_t WINRT_CALL WINRT_GetActivationFactory(void* classId, void** factory) noexcept;
}
#endif
