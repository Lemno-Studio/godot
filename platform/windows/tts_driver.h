/**************************************************************************/
/*  tts_driver.h                                                          */
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

#include "core/object/object.h"
#include "core/typedefs.h"

#ifndef _MSC_VER

#include <cstdint>

#define	_ReturnAddress()	__builtin_return_address(0)

_ALWAYS_INLINE_ bool _InterlockedCompareExchange128(
		int64_t volatile *Destination,
		int64_t          ExchangeHigh,
		int64_t          ExchangeLow,
		int64_t          *ComparandResult
		)
{
	typedef int64_t	LONG64;

	// Use __int128 (supported in GCC and Clang on 64-bit targets)
	__int128 exchange = ((__int128)ExchangeHigh << 64) | (uint64_t)ExchangeLow;
	__int128 comparand = ((__int128)ComparandResult[1] << 64) | (uint64_t)ComparandResult[0];

	__int128 old = __atomic_compare_exchange_n(
			(__int128*)Destination,          // target pointer
			&comparand,                      // expected (updated to actual old value on failure)
			exchange,                        // desired
			false,                           // weak? false = strong (preferred for this intrinsic)
			__ATOMIC_SEQ_CST,                // success memory order
			__ATOMIC_SEQ_CST                 // failure memory order
			);

	// Write the original value back into ComparandResult (MS semantics)
	ComparandResult[0] = (LONG64)comparand;
	ComparandResult[1] = (LONG64)(comparand >> 64);

	return (bool)old;   // returns non-zero (true) if the exchange happened
}
#endif

class TTSDriver : public Object {
	GDSOFTCLASS(TTSDriver, Object);

	public:
	virtual bool is_speaking() const = 0;
	virtual bool is_paused() const = 0;
	virtual Array get_voices() const = 0;

	virtual void speak(const String &p_text, const String &p_voice, int p_volume = 50, float p_pitch = 1.f, float p_rate = 1.f, int64_t p_utterance_id = 0, bool p_interrupt = false) = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void stop() = 0;

	virtual void process_events() = 0;

	virtual bool init() = 0;

	virtual ~TTSDriver() {}
};
