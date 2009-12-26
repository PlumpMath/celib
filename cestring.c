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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cetypes.h"
#include "cestring.h"

/* Definite CeString Object */
struct _CeString {
        CeUsChar *data;
        CeInt    len;           /**< string length excluding trailing '\0' */
};

/** 
 * just initail the CeString Object
 *
 */
CeString * ce_string_new(void)
{
        CeString *self  = (CeString *) malloc( sizeof(CeString) );
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
        self->len = 0;
        free(self);
}

void ce_string_free(CeString *self)
{
        free(self->data);
        self->data = NULL;
        self->len = 0;
}

CeInt * ce_string_set_data(CeString *self, const CeUsChar *str)
{
        CeInt i;
        CeInt new_len = strlen(str);
        
        /* Free the CeString Object first */
        if(0 != self->len) {
                free(self->data);
        }

        self->len = new_len;
        self->data = (CeUsChar *) malloc( sizeof(CeUsChar) * (new_len + 1) );
        
        /* Now let's copy new string to our CeString */
        for(i = 0; i < new_len; i++) {
                self->data[i] = str[i];
        }
        self->data[i] = '\0';   /* end of line character */
}

CeUsChar * ce_string_get_data(CeString *self)
{
        return (self->data);
}

CeInt ce_string_get_length(CeString *self)
{
        return (self->len);
}


/* end of cestring.c */
