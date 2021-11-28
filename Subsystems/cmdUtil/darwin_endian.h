/*    $Id$    */
/*
 * Copyright (c) 2021 Rene Hexel
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef ENDIAN_H_
#define ENDIAN_H_   1

#include <machine/endian.h>

#ifndef htobe16
#if BYTE_ORDER == BIG_ENDIAN
#include <libkern/_OSByteOrder.h>

#define htobe16(x) (x)
#define htole16(x) __DARWIN_OSSwapInt16(x)
#define be16toh(x) (x)
#define le16toh(x) __DARWIN_OSSwapInt16(x)
#define htobe32(x) (x)
#define htole32(x) __DARWIN_OSSwapInt32(x)
#define be32toh(x) (x)
#define le32toh(x) __DARWIN_OSSwapInt32(x)
#define htobe64(x) (x)
#define htole64(x) __DARWIN_OSSwapInt64(x)
#define be64toh(x) (x)
#define le64toh(x) __DARWIN_OSSwapInt64(x)

#else // little endian

#define htobe16(x) ntohs(x)
#define htole16(x) (x)
#define be16toh(x) ntohs(x)
#define le16toh(x) (x)
#define htobe32(x) ntohl(x)
#define htole32(x) (x)
#define be32toh(x) ntohl(x)
#define le32toh(x) (x)
#define htobe64(x) ntohll(x)
#define htole64(x) (x)
#define be64toh(x) ntohll(x)
#define le64toh(x) (x)

#endif // big/little endian
#endif // htobe16

#endif /* ENDIAN_H_ */
