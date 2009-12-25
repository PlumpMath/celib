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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cetypes.h"
#include "cestring.h"


struct _CeString_Class_get {
        uCeChar *(*data) (CeString *self);
};
struct _CeString_Class_set {
        uCeChar *(*data) (CeString *self, const uCeChar *src);
};


static int ce_string_set_data(CeString *self, const uCeChar *src);
static uCeChar * ce_string_get_data(CeString *self);

static CeString_Class_get get = {ce_string_get_data};
static CeString_Class_set set = {ce_string_set_data};

/** 
 * just initail the CeString Object
 *
 */
CeString *ce_string_new(void)
{
        CeString *self  = (CeString *) malloc(sizeof(CeString));
        self->data = NULL;
        self->len = 0;
        return self;
}

/** 
 * Totally free the CeString Object
 * 
 * @param self
 */
void ce_string_delete(CeString *self)
{
        free(self->data);
        free(self);
}

CeInt ce_string_set_data(CeString *self, const uCeChar *src)
{
        CeInt i;
        CeInt new_len = strlen(src);
        
        /* Free the CeString Object first */
        if(0 != self->len) {
                free(str->data);
        }

        self->len = new_len;
        self->data = (uCeChar *)malloc(sizeof(uCeChar) * new_len);
        
        /* Now let's copy new string to our CeString */
        for(i = 0; i < new_len; i++) {
                self->data[i] = src[i];
        }
        
}

uCeChar *ce_string_get_data(CeString *self)
{
        return (self->data);
}

