/* CELIB - cldnew's C libraries designed for CEMACS
 *
 * Copyright (C) 2009-2010  Yen-Chin, Lee. All Rights Reserved. 
 *
 * This file is part of CELIB.
 *
 * The contents of this file are subject to the terms of one of the
 * following licenses: 
 *
 *    1) GNU Lesser General Public License (LGPL)
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

#ifndef _CE_MACROS_H
#define _CE_MACROS_H

/* Convert str to string */
#define _CE_STR(str) #str
#define CE_STR(str) _CC_STR(str)

/* Find Max value or Min value */
#define CE_MAX(x,y) ( (x) > (y) ? (x) : (y) )
#define CE_MIN(x,y) ( (x) < (y) ? (x) : (y) )

#define CE_POWER_2(x) ( (x) * (x) )
#define CE_POWER_3(x) ( (x) * (x) * (x) )

/* Make a character to upcase or downcase */
#define CE_UPCASE(c)   ( ( (c) >= 'a' && (c) <= 'z') ? ( (c) - 0x20) : (c) )
#define CE_DOWNCASE(c) ( ( (c) >= 'A' && (c) <= 'Z') ? ( (c) + 0x20) : (c) )

/* Shift the value to left or right */
#define CE_LSHIFT(x, offset) ( (x) << (offset) )
#define CE_RSHIFT(x, offset) ( (x) >> (offset) )

/* Logic Arithmatic */
#define CE_NOT(a)    ( ~(a) )
#define CE_OR(a, b)  ( (a) | (b) )
#define CE_AND(a, b) ( (a) & (b) )
#define CE_XOR(a, b) ( (a) ^ (b) )
#define CE_NOR(a, b)  ( ~( (a) | (b) ) )
#define CE_NAND(a, b) ( ~( (a) & (b) ) )


#endif /* _CE_MACROS_H */

