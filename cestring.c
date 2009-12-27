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
#include <ctype.h>

#include "cetypes.h"
#include "cestring.h"

/* a pointer for cestring */
struct _CeString_Pointer {
       CeUChar *data;
       CeInt    *len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeString_Pointer CeString_Pointer;

static CeString_Pointer *selfp;

/** 
 * just initail the CeString Object
 *
 */
CeString * ce_string_new(void)
{
        CeString *self  = (CeString *) malloc( sizeof(CeString) );
    
        selfp  = (CeString_Pointer *) malloc( sizeof(CeString_Pointer) );
    
        selfp = self;
        selfp->data = NULL;
        selfp->len = 0;
        return self;
}

CeInt * ce_string_set_data(CeString *self, const CeUChar *str)
{
        CeInt i = 0;
        CeInt new_len = strlen(str);
        
        /* Free the CeString Object first */
        if(0 != selfp->len) {
                free(self->data);
        }

        selfp->len = new_len;
        selfp->data = (CeUChar *) malloc( sizeof(CeUChar) * (new_len + 1) );
        
        /* Now let's copy new string to our CeString */
        for(; i < new_len; i++) {
                selfp->data[i] = str[i];
        }
        selfp->data[i] = '\0';   /* end of line */
}

CeUChar * ce_string_get_data(CeString *self)
{
        return (selfp->data);
}



/* end of cestring.c */
