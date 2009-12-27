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
//#include "celib.h"
#include "cetypes.h"
#include "cestring.h"
#include "ceswap.h"

/* a pointer for cestring */
struct _CeStringP {
       CeUChar *data;
       CeInt    len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeStringP CeStringP;

static CeStringP *selfp;

#define CE_STRING_INITIAL() selfp = (CeStringP *) self;

/** 
 * just initail the CeString Object
 *
 */
CeString * ce_string_new(void)
{
        CeString *self  = (CeString *) malloc( sizeof(CeString) );

        if(!selfp) {
                selfp  = (CeStringP *) malloc( sizeof(CeStringP) );        
        }

        CE_STRING_INITIAL();

        selfp->data = NULL;
        selfp->len = 0;

        return self;
}

CeString * ce_string_new_with_data(const CeUChar *data)
{
        CeString *self  = ce_string_new();

        ce_string_set_data(self, data);
        
        return self;
}


/** 
 * Totally free the CeString Object
 * 
 * @param self
 */
void ce_string_delete(CeString *self)
{
        CE_STRING_INITIAL();

        free(self->data);
        selfp->len = 0;
        free(self);
}

void ce_string_free(CeString *self)
{
        CE_STRING_INITIAL();

        free(self->data);
        selfp->data = NULL;
        selfp->len = 0;
}



CeInt * ce_string_set_data(CeString *self, const CeUChar *str)
{
        CE_STRING_INITIAL();

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
        return (self->data);
}

CeInt ce_string_get_length(CeString *self)
{
        return (self->len);
}

CeString * ce_string_reverse_all(CeString *self)
{
        CE_STRING_INITIAL();

        if ( 1 == selfp->len) {
                return self;
        }

        CeInt i = 0;
        CeInt tmp_len = selfp->len / 2;
        CeUChar tmp_data;

        for(; i < tmp_len; i++) {
                tmp_data = selfp->data[i];
                selfp->data[i] = selfp->data[selfp->len - i - 1];
                selfp->data[selfp->len - i - 1] = tmp_data;
        }

        return self;
}

CeString * ce_string_reverse_inrange(CeString *self, const CeInt start, const CeInt end)
{
        CE_STRING_INITIAL();

        if ( 1 == selfp->len) {
                return self;
        }

        CeInt i = 0;
        CeInt tmp_len = (end - start) / 2;
        CeUChar tmp_data;

        for(; i <= tmp_len; i++) {
                tmp_data = selfp->data[i + start];
                selfp->data[i + start] = selfp->data[end - i];
                selfp->data[end - i] = tmp_data;
        }

        return self;
}



CeString * ce_string_toupper_all(CeString *self)
{
        CE_STRING_INITIAL();

        CeInt i = 0;

        for (; i < selfp->len; i++) {
                selfp->data[i] = toupper(selfp->data[i]);
        }

        return self;
}

CeString * ce_string_toupper_inrange(CeString *self, const CeInt start, const CeInt end)
{
        CE_STRING_INITIAL();

        CeInt i = start;

        for (; i <= end; i++) {
                selfp->data[i] = toupper(selfp->data[i]);
        }

        return self;
}


CeString * ce_string_tolower_all(CeString *self)
{
        CE_STRING_INITIAL();

        CeInt i = 0;

        for (; i < selfp->len; i++) {
                selfp->data[i] = tolower(selfp->data[i]);
        }

        return self;
}

CeString * ce_string_tolower_inrange(CeString *self, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

//        if ( start < 0 ) {
//                start += self->len ;
//        }
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end > 0   ) ? (-1) : (self->len);
        
//        if ( end < 0 ) {
//                end += self->len;
//        }
        if ( start > end ) {
                ce_swap_ceint(&start, &end);
        }
        
        CeInt i = start;

        for (; i <= end; i++) {
                selfp->data[i] = tolower(selfp->data[i]);
        }

        return self;
}




/* end of cestring.c */
