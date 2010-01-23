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

#ifndef _CE_SWAP_H
#define _CE_SWAP_H


void  ce_int_swap (CeInt    *p1, CeInt    *p2);
void  ce_char_swap(CeChar   *p1, CeChar   *p2);
void  ce_short_swap(CeShort  *p1, CeShort  *p2);
void  ce_float_swap(CeFloat  *p1, CeFloat  *p2);
void  ce_double_swap(CeDouble *p1, CeDouble *p2);

void  ce_uint_swap (CeUInt    *p1, CeUInt    *p2);
void  ce_uchar_swap(CeUChar   *p1, CeUChar   *p2);
void  ce_ushort_swap(CeUShort  *p1, CeUShort  *p2);

#endif /* _CE_SWAP_H */

