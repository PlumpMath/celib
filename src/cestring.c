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
typedef struct  {
       CeUChar *data;
       CeInt    len;     /**< string length excluding trailing '\0' */
} _CeString;

/*
 * Because the child in CeString is constant, we need to
 * use pointer to change the CeString.
 */
static _CeString *_self;
#define CE_STRING_INITIAL() _self = ( _CeString * ) self;
        
/** 
 * Initial the CeString Object without setting any data.
 * 
 * 
 * @return          The CeString Object
 */
CeString * ce_string_new(void)
{
        CeString *self  = (CeString *) malloc( sizeof( CeString ) );

        if(!_self) {
                _self  = (_CeString *) malloc( sizeof( _CeString ) );        
        }

        CE_STRING_INITIAL();

        _self->data = NULL;
        _self->len = 0;

        return self;
}

/** 
 * Initial the CeString Object and set the data and length.
 * 
 * @param data      A String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_new_data(const CeUChar *data)
{
        CeString *self  = ce_string_new();

        return ce_string_set_data(self, data);
}

/** 
 * Initial the CeString Object and set the data in range.
 * 
 * @param data      A String Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object.
 * 
 * @return          The CeString Object
 */
CeString * ce_string_new_data_inrange(const CeUChar *data, CeInt begin, CeInt end)
{
        CeString *self  = ce_string_new();

        return ce_string_set_data_inrange(self, data, begin, end);
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
                free( self->data );
        }
        
	_self->len = 0;
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
        _self->data = NULL;
        _self->len = 0;
}

/** 
 * Setting the data in CeString Object
 * 
 * @param self      The CeString Object
 * @param data      A string that you want to put in CeString Object 
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_set_data(CeString *self, const CeUChar *data)
{
        return ce_string_set_data_inrange(self, data, 1, -1);
}

/** 
 * Setting the data in range in CeString Object
 * 
 * @param self      The CeString Object
 * @param data      A String Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_set_data_inrange(CeString *self, const CeUChar *data, CeInt begin, CeInt end)
{
        CE_STRING_INITIAL();

        CeInt length = strlen(data);

        CE_RANGE_INITIAL(begin, end, length);

        length = end - begin + 1;
        
        /* Free the CeString Object first */
        if(0 != _self->len) {
                free(self->data);
        }

        _self->len = length;
        _self->data = (CeUChar *) malloc( sizeof(CeUChar) * (length + 1) );
        
        /* Now let's copy new string to our CeString */
        memcpy(_self->data, data + begin, length);
        _self->data[length] = '\0';   /* end of line */

        return self;
}

/** 
 * Get the data of CeString Object
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
inline
CeUChar * ce_string_get_data(CeString *self)
{
        return (self->data);
}

/** 
 * Get the data of CeString Object in range
 * 
 * @param self      The CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeUChar  * ce_string_get_data_inrange(CeString *self, CeInt begin, CeInt end)
{
        CE_STRING_INITIAL();

        CE_RANGE_INITIAL(begin, end, self->len);
        
        CeInt length = end - begin + 1;
        CeUChar *data = (CeUChar *) malloc( sizeof(CeUChar) * length + 1 );
        
        memcpy(data, self->data + begin, length);
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
inline
CeInt ce_string_get_length(CeString *self)
{
        return (self->len);
}

/** 
 * Get the length of CeString Object in range
 * 
 * @param self　　　　The CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The length of CeString Object in range
 */
CeInt ce_string_get_length_inrange(CeString *self, CeInt begin, CeInt end)
{
        CE_RANGE_INITIAL(begin, end, self->len);

        return (end - begin + 1);
}

/** 
 * Reverse the data in CeString Object
 * 
 * @param self      The CeString Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_reverse(CeString *self)
{
        return ce_string_reverse_inrange(self, 1, -1);
}

/** 
 * Reverse the data in CeString Object in range
 * 
 * @param self      The CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_reverse_inrange(CeString *self, CeInt begin, CeInt end)
{
        CE_STRING_INITIAL();

        if ( 1 == _self->len) {
                return self;
        }

        CE_RANGE_INITIAL(begin, end, self->len);

        CeInt i = 0;
        CeInt tmp_len = (end - begin) / 2;
        CeUChar tmp_data;

        for(; i <= tmp_len; i++) {
                tmp_data = _self->data[i + begin];
                _self->data[i + begin] = _self->data[end - i];
                _self->data[end - i] = tmp_data;
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
inline
CeString * ce_string_toupper(CeString *self)
{
        return ce_string_toupper_inrange(self, 1, -1);
}

/** 
 * Make the cahracters in CeString object in range to uppercase
 * 
 * @param self      The CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_toupper_inrange(CeString *self, CeInt begin, CeInt end)
{
        CE_STRING_INITIAL();

        CE_RANGE_INITIAL(begin, end, self->len);

        CeInt i = begin;

        for (; i <= end; i++) {
                _self->data[i] = toupper( _self->data[i] );
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
inline
CeString * ce_string_tolower(CeString *self)
{
        return ce_string_tolower_inrange(self, 1, -1);
}

/** 
 * Make the cahracters in CeString object in range to lowercase 
 * 
 * @param self      The CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_tolower_inrange(CeString *self, CeInt begin, CeInt end)
{
        CE_STRING_INITIAL();

        CE_RANGE_INITIAL(begin, end, self->len);
        
        CeInt i = begin;

        for (; i <= end; i++) {
                _self->data[i] = tolower(_self->data[i]);
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
inline
CeInt ce_string_compare(CeString *selfA, CeString *selfB)
{
        return strcmp(selfA->data, selfB->data);
}

/** 
 * Compare two CeString Object in range
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          1 : selfA <  selfB
 *                  0 : selfA == selfB
 *                 -1 : selfA >  selfB
 */
inline
CeInt ce_string_compare_inrange(CeString *selfA, CeString *selfB, CeInt begin, CeInt end)
{
        return strcmp(ce_string_get_data_inrange(selfA, begin, end),
                      ce_string_get_data_inrange(selfB, begin, end));
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
inline
CeInt ce_string_compare_data(CeString *self, CeUChar *data)
{
        return strcmp(self->data, data);
}

/** 
 * Compare the data in CeString Object with another String Object in range
 * 
 * @param self      A CeString Object
 * @param data      A String   Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          1 : self->data <  data
 *                  0 : self->data == data
 *                 -1 : self->data >  data
 */
CeInt ce_string_compare_data_inrange(CeString *self, CeUChar *data, CeInt begin, CeInt end)
{
        CeString *test_data = ce_string_new_data_inrange(data, begin, end);
        CeInt resault = strcmp(ce_string_get_data_inrange(self, begin, end), test_data->data);

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
inline
CeBool ce_string_isequal(CeString *selfA, CeString *selfB)
{
        CeInt resault = ce_string_compare(selfA, selfB);

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
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          if equal : CE_TRUE
 *                  else     : CE_FALSE
 */
inline
CeBool ce_string_isequal_inrange(CeString *selfA, CeString *selfB, CeInt begin, CeInt end)
{
        CeInt resault = ce_string_compare_inrange(selfA, selfB, begin, end);

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
inline
CeString * ce_string_copy(CeString *dst, CeString *src)
{
        return ce_string_copy_inrange(dst, src, 1, -1);
}

/** 
 * Copy the second CeString Object to the first one in range
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_copy_inrange(CeString *dst, CeString *src, CeInt begin, CeInt end)
{
        ce_string_clear(dst);
        ce_string_set_data_inrange(dst, src->data, begin, end);

        return dst;
}

/** 
 * Swap two CeString Object
 * 
 * @param selfA     A CeString Object
 * @param selfB     A CeString Object
 */
inline
void ce_string_swap(CeString *selfA, CeString *selfB)
{
	_self = (_CeString *) selfA;
	selfA = selfB;
	selfB = (CeString  *) _self;
}

/** 
 * Concat two CeString Object
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_concat(CeString *dst, CeString *src)
{
        return ce_string_concat_data_inrange(dst, src->data, 1, -1);
}

/** 
 * Concat two CeString Object in range.
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_concat_inrange(CeString *dst, CeString *src, CeInt begin, CeInt end)
{
        return ce_string_concat_data_inrange(dst, src->data, begin, end);
}

/** 
 * Concat a data to CeString Object.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_concat_data(CeString *self, CeUChar *data)
{
        return ce_string_concat_data_inrange(self, data, 1, -1);
}

/** 
 * Concat a data to CeString Object in range.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_concat_data_inrange(CeString *self, CeUChar *data, CeInt begin, CeInt end)
{
        CeInt data_len = strlen(data);
        
        CE_RANGE_INITIAL(begin, end, data_len);

        CeInt new_len = self->len + data_len;
        CeInt cpy_len = end - begin + 1;
        CeUChar *new_data = (CeUChar *) malloc( sizeof(CeUChar) * (new_len + 1) );
                
        /* Copy old data to new one */
        memcpy(new_data, self->data, self->len);
        memcpy(new_data + self->len, data + begin , cpy_len);
        new_data[new_len] = '\0';   /* end of line */

        ce_string_set_data(self, new_data);

        return self;
}

/** 
 * Append data into CeString Object another one.
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_append(CeString *dst, CeString *src)
{
        return ce_string_append_data_inrange(dst, src->data, 1, -1);
}

/** 
 * Append data into CeString Object another one in range.
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_append_inrange(CeString *dst, CeString *src, CeInt begin, CeInt end)
{
        return ce_string_append_data_inrange(dst, src->data, begin, end);
}


/** 
 * Append data to a CeString Object.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_append_data(CeString *self, CeUChar *data)
{
        return ce_string_append_data_inrange(self, data, 1, -1);
}

/** 
 * Append data to a CeString Object in range.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_append_data_inrange(CeString *self, CeUChar *data, CeInt begin, CeInt end)
{
        CeInt data_len = strlen(data);
        
        CE_RANGE_INITIAL(begin, end, data_len);

        CeInt new_len = self->len + data_len;
        CeInt cpy_len = end - begin + 1;
        CeUChar *new_data = (CeUChar *) malloc( sizeof(CeUChar) * (new_len + 1) );
                
        /* Copy old data to new one */
        memcpy(new_data, self->data, self->len);
        memcpy(new_data + self->len, data + begin, cpy_len);
        new_data[new_len] = '\0';   /* end of line */

        ce_string_set_data(self, new_data);

        return self;
}


/** 
 * Prepend data into CeString Object another one.
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_prepend(CeString *dst, CeString *src)
{
        return ce_string_prepend_data_inrange(dst, src->data, 1, -1);
}

/** 
 * Prepend data into CeString Object another one in range.
 * 
 * @param dst       A CeString Object
 * @param src       A CeString Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_prepend_inrange(CeString *dst, CeString *src, CeInt begin, CeInt end)
{
        return ce_string_prepend_data_inrange(dst, src->data, begin, end);
}


/** 
 * Prepend data to a CeString Object.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * 
 * @return          The CeString Object
 */
inline
CeString * ce_string_prepend_data(CeString *self, CeUChar *data)
{
        return ce_string_prepend_data_inrange(self, data, 1, -1);
}

/** 
 * Prepend data to a CeString Object in range.
 * 
 * @param self      A CeString Object
 * @param data      A String Object
 * @param begin     The first char is 1, the second is 2, blah blah blah.
 * @param end       The last char is -1 or the length of String Object
 * 
 * @return          The CeString Object
 */
CeString * ce_string_prepend_data_inrange(CeString *self, CeUChar *data, CeInt begin, CeInt end)
{
        CeInt data_len = strlen(data);
        
        CE_RANGE_INITIAL(begin, end, data_len);

        CeInt new_len = self->len + data_len;
        CeInt cpy_len = end - begin + 1;
        CeUChar *new_data = (CeUChar *) malloc( sizeof(CeUChar) * (new_len + 1) );
                
        /* Copy old data to new one */
        memcpy(new_data, data + begin, cpy_len);
        memcpy(new_data + cpy_len, self->data, self->len);
        new_data[new_len] = '\0';   /* end of line */

        ce_string_set_data(self, new_data);

        return self;
}

/** 
 * print CeString Object
 * 
 * @param self      A CeString Object
 */
void ce_string_print(CeString *self)
{
        printf("%s", self->data);
}






/* end of cestring.c */
