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

#ifndef _CE_STRING_H_
#define _CE_STRING_H_

/* Declare CeString Object */
struct _CeString {
        CeUChar* const data;
        CeInt    const len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeString CeString;


/* Declare Public Method */
CeString * ce_string_new(void);
CeString * ce_string_new_with_data(const CeUChar *data);
CeString * ce_string_new_with_data_inrange(const CeUChar *data, CeInt start, CeInt end);
void       ce_string_delete(CeString *self);
void       ce_string_clear(CeString *self);
CeString * ce_string_set_data(CeString *self, const CeUChar *data);
CeString * ce_string_set_data_inrange(CeString *self, const CeUChar *str, CeInt start, CeInt end);
CeUChar  * ce_string_get_data(CeString *self);
CeUChar  * ce_string_get_data_inrange(CeString *self, CeInt start, CeInt end);
CeInt      ce_string_get_length(CeString *self);
CeInt      ce_string_get_length_inrange(CeString *self, CeInt start, CeInt end);
CeString * ce_string_reverse(CeString *self);
CeString * ce_string_reverse_inrange(CeString *self, CeInt start, CeInt end);
CeString * ce_string_toupper(CeString *self);
CeString * ce_string_toupper_inrange(CeString *self, CeInt start, CeInt end);
CeString * ce_string_tolower(CeString *self);
CeString * ce_string_tolower_inrange(CeString *self, CeInt start, CeInt end);


/* use macro instead of function by deafault */


#endif  /* _CE_STRING_H_ */
