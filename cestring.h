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
#ifndef _CE_STRING_H_
#define _CE_STRING_H_

struct _CeString_Class_get;
typedef struct _CeString_Class_get CeString_Class_get;
struct _CeString_Class_set;
typedef struct _CeString_Class_set CeString_Class_set;

struct _CeString;
typedef struct _CeString CeString;


CeString *ce_string_new(void);
void ce_string_delete(CeString *str);
CeInt * ce_string_set_data(CeString *self, const uCeChar *src);
uCeChar * ce_string_get_data(CeString *self);


#endif  /* _CE_STRING_H_ */
