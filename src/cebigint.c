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
#include "cebigint.h"
#include "ceswap.h"
#include "cemacros.h"

/* Make another CeBigInt Object but it's child is not constant. */
struct _CeBigIntP {
       CeUChar *data;
       CeInt    sign;    /**< the sign of cebigint */
       CeInt    len;     /**< string length excluding trailing '\0' */
};
typedef struct _CeBigIntP CeBigIntP;

/*
 * Because the child in CeBigInt is constant, we need to
 * use pointer to change the CeBigInt.
 */
static CeBigIntP *selfp;
#define CE_BIGINT_INITIAL() selfp = (CeBigIntP *) self;
        
/** 
 * Initial the CeBigInt Object without setting any data.
 * 
 * 
 * @return          The CeBigInt Object
 */
CeBigInt * ce_bigint_new(void)
{
        CeBigInt *self  = (CeBigInt *) malloc( sizeof(CeBigInt) );

        if(!selfp) {
                selfp  = (CeBigIntP *) malloc( sizeof(CeBigIntP) );        
        }

        CE_BIGINT_INITIAL();

        selfp->data = NULL;
	selfp->sign = 0; /**< 0 is positive, 1 is negative */
        selfp->len = 0;

        return self;
}


/** 
 * Totally free the CeBigInt Object.
 * 
 * @param self      The CeBigInt Object
 */
void ce_bigint_delete(CeBigInt *self)
{
        CE_BIGINT_INITIAL();
        
        if ( !self->data ) {
                free(self->data);
        }

        selfp->len  = 0;
	selfp->sign = 0; /**< 0 is positive, 1 is negative */

        free(self);
}

/** 
 * Clear data and length in CeBigInt Object
 * 
 * @param self      The CeBigInt Object
 */
void ce_bigint_clear(CeBigInt *self)
{
        CE_BIGINT_INITIAL();

        free(self->data);
        selfp->data = NULL;
        selfp->len = 0;
	selfp->sign = 0; /**< 0 is positive, 1 is negative */
}
