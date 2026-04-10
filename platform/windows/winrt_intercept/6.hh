


#if	1
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
