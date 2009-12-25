/* CELIB - cldnew's C libraries designed for CEMACS
 * Copyright (C) 2009  Yen-Chin, Lee <coldnew.tw@gmail.com>
 *
 * This file is part of CELIB.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#include "cetypes.h"
#include "ceswap.h"

#include <stdio.h>

#define SWAP_CORE  tmp = *p1; *p1 = *p2; *p2 = tmp    

/* Int() */
inline void  cc_swap_int(CeInt *p1, CeInt *p2)
{
        CeInt SWAP_CORE;
}

/* Char() */
inline void  cc_swap_char(CeChar *p1, CeChar *p2)
{
        CeChar SWAP_CORE;
}

/* Short() */
inline void  cc_swap_short(CeShort *p1, CeShort *p2)
{
        CeShort SWAP_CORE;
}

/* Float() */
inline void  cc_swap_float(CeFloat *p1, CeFloat *p2)
{
        CeFloat SWAP_CORE;
}

/* Double() */
inline void  cc_swap_double(CeDouble *p1, CeDouble *p2)
{
        CeDouble SWAP_CORE;
}


/* end of swap.c */
