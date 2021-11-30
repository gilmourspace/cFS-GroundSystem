/*
**      Copyright (c) 2021 Rene Hexel
**      All rights reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
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
