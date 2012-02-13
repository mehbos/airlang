#ifndef _UTIL_H_
#define _UTIL_H_

#include <stddef.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

///////////////////////////////////////////////////////////

namespace x	{

///////////////////////////////////////////////////////////

template <const size_t N>
static inline
char* strncpy_s (char (& dest)[N], char const* const src, size_t const n) {
	assert(N > n);
	strncpy(&dest[0], src, n);
	dest[N - 1] = '\0';
	return &dest[0];
}

template <const size_t N>
static inline
char* strcpy_s (char (& dest)[N], char const* const src) {
	return strncpy_s(dest, src, N-1);
}

///////////////////////////////////////////////////////////

template <typename T>
static inline
T* memset0 (T& o) {
	memset(&o, 0x00, sizeof(o));
	return &o;
}

///////////////////////////////////////////////////////////

template <const size_t N>
static inline
int vsprintf_s (char (& buf)[N], char const* const format, va_list argp)
	{ return vsnprintf(&buf[0], N, format, argp); }

template <const size_t N>
static inline
int sprintf_s (char (& buf)[N], char const* const format, ...) {
	va_list argp;
	va_start(argp, format);

	int const retval = vsprintf_s(buf, format, argp);

	va_end(argp);

	return retval;
}

///////////////////////////////////////////////////////////

template <typename ElemType>
struct const_of
	{ typedef ElemType const T; };

template <typename ElemType, const size_t N>
struct const_of<ElemType [N]>
	{ typedef typename const_of<ElemType>::T T[N]; };

///////////////////////////////////////////////////////////

}	// x

///////////////////////////////////////////////////////////

#endif
