/**************************************************************************/
/*  tts_driver_onecore.h                                                  */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "tts_driver.h"

GODOT_GCC_WARNING_PUSH
GODOT_GCC_WARNING_IGNORE("-Wnon-virtual-dtor")
GODOT_GCC_WARNING_IGNORE("-Wctor-dtor-privacy")
GODOT_GCC_WARNING_IGNORE("-Wshadow")
GODOT_GCC_WARNING_IGNORE("-Wstrict-aliasing")
GODOT_CLANG_WARNING_PUSH
GODOT_CLANG_WARNING_IGNORE("-Wnon-virtual-dtor")

#include <windows.h>
#include <winstring.h>
#include <roapi.h>
#include <combaseapi.h>
#include <interlockedapi.h>
#include <handleapi.h>
#include <synchapi.h>

#define	WINRT_WindowsCreateStringReference(p1, p2, p3, p4)    \
    ((HRESULT)WindowsCreateStringReference(		\
			(PCWSTR)(p1)				\
			, (UINT32)(p2)				\
			, (HSTRING_HEADER*)(p3)		\
			, (HSTRING*)(p4)				\
			))

#define WINRT_WindowsCreateString(p1, p2, p3)    \
    ((HRESULT)WindowsCreateString(		\
			(PCNZWCH)(p1)		\
			, (UINT32)(p2)		\
			, (HSTRING)(p3)		\
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

#define WINRT_RoGetActivationFactory(classid, iid, factory)	\
	((HRESULT)(RoGetActivationFactory(		\
			(HSTRING)(classid)	\
			, (REFIID)(iid)		\
			, (void**)(factory)	\
			)))

#define WINRT_CoIncrementMTAUsage(pCookie)			\
	((HRESULT)CoIncrementMTAUsage((CO_MTA_USAGE_COOKIE*)(pCookie)))

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

#define WINRT_CloseHandle(/** [in] */ h)	\
	CloseHandle((HANDLE)(h))

#define WINRT_AcquireSRWLockExclusive(/** [in, out] */ lock)	\
	AcquireSRWLockExclusive((PSRWLOCK)(lock))

#define WINRT_AcquireSRWLockShared(/** [in, out] */ lock)	\
	AcquireSRWLockShared((PSRWLOCK)(lock))

#define	WINRT_WakeAllConditionVariable(/** [in, out] */ cv)	\
	WakeAllConditionVariable((PCONDITION_VARIABLE)(cv))

#define	WINRT_WindowsDuplicateString(str, newstr)	\
	((HRESULT)WindowsDuplicateString(	\
		(HSTRING)(str)					\
		, (HSTRING*)newstr				\
		))

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

#define	WINRT_WindowsStringHasEmbeddedNull(str, r_hasembednil)	\
	((HRESULT)WindowsStringHasEmbeddedNull(	\
			(HSTRING)(str)					\
			, (BOOL*)(r_hasembednil)		\
			))

#define WINRT_WakeConditionVariable(/** [in, out] */ cv)	\
	WakeConditionVariable((PCONDITION_VARIABLE)(cv))	\

#define WINRT_ReleaseSRWLockShared(/** [in, out] */ lock)	\
	ReleaseSRWLockShared((PSRWLOCK)(lock))
#define WINRT_WindowsPreallocateStringBuffer(len, chbuf, bufhandle)	\
	(HRESULT)(WindowsPreallocateStringBuffer(	\
			(UINT32)(len)		\
			(WCHAR**)(chbuf)	\
			(HSTRING_BUFFER*)(bufhandle)	\
			))

#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.Media.Core.h>
#include <winrt/Windows.Media.Playback.h>
#include <winrt/Windows.Media.SpeechSynthesis.h>
#include <winrt/Windows.Storage.Streams.h>

GODOT_GCC_WARNING_POP
GODOT_CLANG_WARNING_POP

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Foundation::Metadata;
using namespace winrt::Windows::Media::Core;
using namespace winrt::Windows::Media::Playback;
using namespace winrt::Windows::Media::SpeechSynthesis;
using namespace winrt::Windows::Storage::Streams;

struct TTSUtterance;

class TTSDriverOneCore : public TTSDriver {
	List<TTSUtterance> queue;

	bool playing = false;
	bool paused = false;
	bool update_requested = false;

	int64_t id = -1;
	Char16String string;
	std::shared_ptr<MediaPlayer> media;
	struct TrackData {
		TimedMetadataTrack track;
		winrt::event_token token{};
	};
	Vector<TrackData> tracks;
	winrt::event_token token_s{};
	winrt::event_token token_f{};
	winrt::event_token token_e{};
	int64_t offset = 0;

	void _dispose_current(bool p_silent = false, bool p_canceled = false);

	void _speech_cancel(int p_msg_id);
	void _speech_end(int p_msg_id);
	void _speech_index_mark(int p_msg_id, int p_index_mark);

	static TTSDriverOneCore *singleton;

public:
	virtual bool is_speaking() const override;
	virtual bool is_paused() const override;
	virtual Array get_voices() const override;

	virtual void speak(const String &p_text, const String &p_voice, int p_volume = 50, float p_pitch = 1.f, float p_rate = 1.f, int64_t p_utterance_id = 0, bool p_interrupt = false) override;
	virtual void pause() override;
	virtual void resume() override;
	virtual void stop() override;

	virtual void process_events() override;

	virtual bool init() override;

	TTSDriverOneCore();
	~TTSDriverOneCore();
};
