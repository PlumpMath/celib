/* CELIB - coldnew's evil library for C programming.
 *
 * Copyright (C) 2009-2010  Yen-Chin, Lee. All Rights Reserved.
 *
 * This file is part of CELIB.
 *
 * The contents of this file are subject to the terms of one of the
 * following licenses:
 *
 *    1) GNU Lesser General Public License (GNU LGPL)
 *    2) Common Development and Distribution License (CDDL)
 *    3) Yen-Chin, Lee, as the author of this code, expressly permits you to
 *       statically or dynamically link your code (or bind by name)
 *       to this file, while you keep this file unmodified.
 *
 * You can select the license that you prefer but you may not use this file
 * except in compliance with one of these Licenses.
 *
 * See the Licenses for the specific language governing permissions and
 * limitations under the Licenses.
 *
 */

#ifndef _CE_MACROS_H_
#define _CE_MACROS_H_

/* program is allowed to contain its own definitions, so ... */
#undef  STR
#undef  POWER2
#undef  POWER3
#undef  MAX
#undef  MIN
#undef  UPCASE
#undef  DOWNCASE
#undef  LSHIFT
#undef  RSHIFT
#undef  NOT
#undef  OR
#undef  AND
#undef  XOR
#undef  NOR
#undef  NAND

/* Convert str to string */
#define _CE_STR(str) #str
#define STR(str) _CE_STR(str)

#define POWER2(x) ( (x) * (x) )
#define POWER3(x) ( (x) * (x) * (x) )

/* Find Max value or Min value */
#define MAX(x, y) ( (x) > (y) ? (x) : (y) )
#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

/* Make a character to upcase or downcase */
#define UPCASE(c)   ( ( (c) >= 'a' && (c) <= 'z') ? ( (c) - 0x20) : (c) )
#define DOWNCASE(c) ( ( (c) >= 'A' && (c) <= 'Z') ? ( (c) + 0x20) : (c) )

/* Shift the value to left or right */
#define LSHIFT(x, offset) ( (x) << (offset) )
#define RSHIFT(x, offset) ( (x) >> (offset) )

/* Logic Arithmatic */
#define NOT(a)     ( ~(a) )
#define OR(a, b)   ( (a) | (b) )
#define AND(a, b)  ( (a) & (b) )
#define XOR(a, b)  ( (a) ^ (b) )
#define NOR(a, b)  ( ~( (a) | (b) ) )
#define NAND(a, b) ( ~( (a) & (b) ) )


#endif /* _CE_MACROS_H_ */

