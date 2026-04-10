
#if	1	/** original */
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
