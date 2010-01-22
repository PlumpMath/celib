/* CELIB - cldnew's C libraries designed for CEMACS
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

#ifndef _CE_MACROS_H
#define _CE_MACROS_H


/* The true or false value for CeBool */
#define CE_FALSE 0
#define CE_TRUE  1

/* Convert str to string */
#define _CE_STR(str) #str
#define CE_STR(str) _CE_STR(str)

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

/* Initial the range */
#define CE_RANGE_INITIAL(begin, end, length)                                          \
		do {                                                                  \
				/* Reset begin and end variables */                   \
				begin += ( begin > 0 ) ? (-1) : (length);             \
				end   += ( end   > 0 ) ? (-1) : (length);             \
				/* If begin gratter than end, we need to swap them */ \
				if ( begin > end ) {                                  \
						ce_int_swap(&begin, &end);            \
				}                                                     \
		} while(0)



//////////////////////////////////////////

/* The true or false value for CeBool */
#undef  FALSE
#define FALSE 0

#undef  TRUE
#define TRUE  1

/* Find Max value or Min value */
#undef  MAX
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )

#undef  MIN
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )

/* Make a character to upcase or downcase */
#undef  UPCASE
#define UPCASE(c)   ( ( (c) >= 'a' && (c) <= 'z') ? ( (c) - 0x20) : (c) )

#undef  DOWNCASE
#define DOWNCASE(c) ( ( (c) >= 'A' && (c) <= 'Z') ? ( (c) + 0x20) : (c) )

/* Shift the value to left or right */
#undef  LSHIFT
#define LSHIFT(x, offset) ( (x) << (offset) )

#undef  RSHIFT
#define RSHIFT(x, offset) ( (x) >> (offset) )

/* Logic Arithmatic */
#undef  NOT
#define NOT(a)     ( ~(a) )

#undef  OR
#define OR(a, b)   ( (a) | (b) )

#undef  AND
#define AND(a, b)  ( (a) & (b) )

#undef  XOR
#define XOR(a, b)  ( (a) ^ (b) )

#undef  NOR
#define NOR(a, b)  ( ~( (a) | (b) ) )

#undef  NAND
#define NAND(a, b) ( ~( (a) & (b) ) )


#endif /* _CE_MACROS_H */

