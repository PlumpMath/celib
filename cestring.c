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
#include "cemacros.h"

/* Make another CeString Object but it's child is not constant. */
struct _CeStringP {
       CeUChar *data;
       CeInt    len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeStringP CeStringP;

/* Because the child in CeString is constant, we need to
 * use pointer to change the CeString.
 */
static CeStringP *selfp;
#define CE_STRING_INITIAL() selfp = (CeStringP *) self;

/** 
 * Initial the CeString Object without setting any data.
 * 
 * 
 * @return          The CeString Object
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

/** 
 * Initial the CeString Object and set the data and length.
 * 
 * @param data      A String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_new_with_data(const CeUChar *data)
{
        CeString *self  = ce_string_new();

        return ce_string_set_data(self, data);
}

/** 
 * Initial the CeString Object and set the data in range.
 * 
 * @param data      A String Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object.
 * 
 * @return          The CeString Object
 */
CeString * ce_string_new_with_data_inrange(const CeUChar *data, CeInt start, CeInt end)
{
        CeString *self  = ce_string_new();

        return ce_string_set_data_inrange(self, data, start, end);
}

/** 
 * Totally free the CeString Object.
 * 
 * @param self      The CeString Object
 */
void ce_string_delete(CeString *self)
{
        CE_STRING_INITIAL();
        if ( !self->data ) {
                free(self->data);
        }
        selfp->len = 0;
        free(self);
}

/** 
 * Clear data and length in CeString Object
 * 
 * @param self      The CeString Object
 */
void ce_string_clear(CeString *self)
{
        CE_STRING_INITIAL();

        free(self->data);
        selfp->data = NULL;
        selfp->len = 0;
}

/** 
 * Setting the data in CeString Object
 * 
 * @param self      The CeString Object
 * @param data      A string that you want to put in CeString Object 
 * 
 * @return          The CeString Object
 */
CeString * ce_string_set_data(CeString *self, const CeUChar *data)
{
        return ce_string_set_data_inrange(self, data, 1, -1);
}

/** 
 * Setting the data in range in CeString Object
 * 
 * @param self      The CeString Object
 * @param data      A String Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_set_data_inrange(CeString *self, const CeUChar *data, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

        CeInt length = strlen(data);

        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (length);
        end   += ( end   > 0 ) ? (-1) : (length);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
        }

        length = end - start + 1;
        
        /* Free the CeString Object first */
        if(0 != selfp->len) {
                free(self->data);
        }

        selfp->len = length;
        selfp->data = (CeUChar *) malloc( sizeof(CeUChar) * (length + 1) );
        
        /* Now let's copy new string to our CeString */
        memcpy(selfp->data, data + start, length);
        selfp->data[length] = '\0';   /* end of line */

        return self;
}


/** 
 * Get the data of CeString Object
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
CeUChar * ce_string_get_data(CeString *self)
{
        return (self->data);
}

/** 
 * Get the data of CeString Object in range
 * 
 * @param self      The CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeUChar  * ce_string_get_data_inrange(CeString *self, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end   > 0 ) ? (-1) : (self->len);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
        }
        
        CeInt length = end - start + 1;
        CeUChar *data = (CeUChar *) malloc( sizeof(CeUChar) * length + 1 );
        
        memcpy(data, self->data + start, length);
        data[length] = '\0';    /* end of line */
        
        return data;
}

/** 
 * Get the length of CeString Object
 * 
 * @param self      The CeString Object
 * 
 * @return          The length of CeString Object
 */
CeInt ce_string_get_length(CeString *self)
{
        return (self->len);
}

/** 
 * Get the length of CeString Object in range
 * 
 * @param self　　　　The CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The length of CeString Object in range
 */
CeInt ce_string_get_length_inrange(CeString *self, CeInt start, CeInt end)
{
        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end   > 0 ) ? (-1) : (self->len);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
        }

        return (end - start + 1);
}

/** 
 * Reverse the data in CeString Object
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_reverse(CeString *self)
{
        return ce_string_reverse_inrange(self, 1, -1);
}

/** 
 * Reverse the data in CeString Object in range
 * 
 * @param self      The CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_reverse_inrange(CeString *self, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

        if ( 1 == selfp->len) {
                return self;
        }

        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end   > 0 ) ? (-1) : (self->len);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
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

/** 
 * Make all the cahracters in CeString object to uppercase
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_toupper(CeString *self)
{
        return ce_string_toupper_inrange(self, 1, -1);
}

/** 
 * Make the cahracters in CeString object in range to uppercase
 * 
 * @param self      The CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_toupper_inrange(CeString *self, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end   > 0 ) ? (-1) : (self->len);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
        }

        CeInt i = start;

        for (; i <= end; i++) {
                selfp->data[i] = toupper(selfp->data[i]);
        }

        return self;
}

/** 
 * Make all the cahracters in CeString object to lowercase
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_tolower(CeString *self)
{
        return ce_string_tolower_inrange(self, 1, -1);
}

/** 
 * Make the cahracters in CeString object in range to lowercase 
 * 
 * @param self      The CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_tolower_inrange(CeString *self, CeInt start, CeInt end)
{
        CE_STRING_INITIAL();

        /* Reset start and end variables */
        start += ( start > 0 ) ? (-1) : (self->len);
        end   += ( end   > 0 ) ? (-1) : (self->len);

        /* If start gratter than end, we need to swap them */
        if ( start > end ) {
                ce_int_swap(&start, &end);
        }
        
        CeInt i = start;

        for (; i <= end; i++) {
                selfp->data[i] = tolower(selfp->data[i]);
        }

        return self;
}

/** 
 * Compare two CeString Object 
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 * 
 * @return          1 : selfA <  selfB
 *                  0 : selfA == selfB
 *                 -1 : selfA >  selfB
 */
CeInt ce_string_compare(CeString *selfA, CeString *selfB)
{
        return strcmp(selfA->data, selfB->data);
}

/** 
 * Compare two CeString Object in range
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          1 : selfA <  selfB
 *                  0 : selfA == selfB
 *                 -1 : selfA >  selfB
 */
CeInt ce_string_compare_inrange(CeString *selfA, CeString *selfB, CeInt start, CeInt end)
{
        return strcmp(ce_string_get_data_inrange(selfA, start, end),
                      ce_string_get_data_inrange(selfB, start, end));
}

/** 
 * Compare the data in CeString Object with another String Object
 * 
 * @param self      A CeString Object
 * @param data      A String   Object
 * 
 * @return          1 : self->data <  data
 *                  0 : self->data == data
 *                 -1 : self->data >  data
 */
CeInt ce_string_compare_data(CeString *self, CeUChar *data)
{
        return strcmp(self->data, data);
}

/** 
 * Compare the data in CeString Object with another String Object in range
 * 
 * @param self      A CeString Object
 * @param data      A String   Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          1 : self->data <  data
 *                  0 : self->data == data
 *                 -1 : self->data >  data
 */
CeInt ce_string_compare_data_inrange(CeString *self, CeUChar *data, CeInt start, CeInt end)
{
        CeString *test_data = ce_string_new_with_data_inrange(data, start, end);
        CeInt resault = strcmp(ce_string_get_data_inrange(self, start, end), test_data->data);
        ce_string_delete(test_data);

        return resault;
}

/** 
 * Test if two CeString Object is equal or not
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 * 
 * @return          if equal : CE_TRUE
 *                  else     : CE_FALSE
 */
CeBool ce_string_isequal(CeString *selfA, CeString *selfB)
{
        int resault = ce_string_compare(selfA, selfB);

        if ( !resault ) {
                return CE_TRUE;
        }
        else {
                return CE_FALSE;
        }
}

/** 
 * Test if two CeString Object is equal or not in range
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          if equal : CE_TRUE
 *                  else     : CE_FALSE
 */
CeBool ce_string_isequal_inrange(CeString *selfA, CeString *selfB, CeInt start, CeInt end)
{
        int resault = ce_string_compare_inrange(selfA, selfB, start, end);

        if ( !resault ) {
                return CE_TRUE;
        }
        else {
                return CE_FALSE;
        }
}

/** 
 * Copy the second CeString Object to the first one
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_copy(CeString *dst, CeString *src)
{
        return ce_string_copy_inrange(dst, src, 1, -1);
}

/** 
 * Copy the second CeString Object to the first one in range
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * @param start     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_copy_inrange(CeString *dst, CeString *src, CeInt start, CeInt end)
{
        ce_string_clear(dst);
        ce_string_set_data_inrange(dst, src->data, start, end);

        return dst;
}


/** 
 * Swap two CeString Object
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 */
void ce_string_swap(CeString *selfA, CeString *selfB)
{
	selfp = (CeStringP *) selfA;
	selfA = selfB;
	selfB = selfp;
}

/* end of cestring.c */
