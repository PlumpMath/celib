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

#ifndef _CE_RANDOM_H_
#define _CE_RANDOM_H_


CeUInt ce_random(CeUInt max);
CeChar ce_random_digit(void);
CeChar ce_random_letter(void);
CeChar ce_random_letter_upcase(void);
CeChar ce_random_letter_downcase(void);


#endif  /* _CE_RANDOM_H_ */
