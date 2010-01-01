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

#ifndef _CE_BIGINT_H_
#define _CE_BIGINT_H_

/* Declare CeBigInt Object */
struct _CeBigInt {
        CeUChar* const data;
        CeInt    const len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeBigInt CeBigInt;


/* Declare Public Method */
CeBigint * ce_bigint_new(void);
void ce_string_delete(CeBigInt *self)
void ce_bigint_clear(CeBigInt *self)

#endif  /* _CE_BIGINT_H_ */
