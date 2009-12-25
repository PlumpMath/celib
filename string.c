
#include "celib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ce_string_set_data(CeString *str, const uchar *src);
static uchar * ce_string_get_data(CeString *self);

static CeString_Class_get get = {ce_string_get_data};

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

int ce_string_set_data(CeString *str, const uchar *src)
{
        int i;
        int new_len = strlen(src);
        
        /* Free the CeString Object first */
        if(0 != str->len) {
                free(str->data);
        }

        str->len = new_len;
        str->data = (uchar *)malloc(sizeof(uchar) * new_len);
        
        /* Now let's copy new string to our CeString */
        for(i = 0; i < new_len; i++) {
                str->data[i] = src[i];
        }
        
}

uchar *ce_string_get_data(CeString *self)
{
        return (self->data);
}

