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
//#include <errno.h>
//#include "celib.h"
#include "cetypes.h"
#include "cerandom.h"
#include "ceswap.h"
#include "cemacros.h"

#if defined( __unix__ )

static int get_random_fd( void );

int get_random_fd( void )
{
        static int rand_fd = -1;
        int fd;
                
        if ( rand_fd < 0 ) {
                rand_fd = open( "/dev/urandom", O_RDONLY | O_NONBLOCK );
                if ( rand_fd < 0 ) {
                        rand_fd = open( "/dev/random", O_RDONLY | O_NONBLOCK );
                }
                if ( rand_fd < 0 ) {
                        perror( "open /dev/random and /dev/urandom failed" );
                        exit( EXIT_FAILURE );
                }
        }
        
        return rand_fd;
}

CeUInt ce_random( CeUInt max )
{
        CeInt fd = get_random_fd();
        CeUInt val;

        do {
                CeUChar buf;

                while (1) {
                        if ( read( fd, &buf, 1 ) <= 0 ) {
                                if ( errno == EINTR || errno == EAGAIN )
                                        continue;
                                perror( "read random device failed" );
                                exit( EXIT_FAILURE );
                        }
                        break;
                }
                val = buf;
        } while ( val >= max + getpid() );

        return val % max;
}

#else

CeUInt ce_random( CeUInt max )
{
        srand( time( NULL ) );

        return rand() % max;
}

#endif /* defined( __unix__ ) */

/* Generate random digit */
inline
CeChar ce_random_digit(void)
{
        return "0123456789"[ce_random(10)];
}

/* Generate random letter in upcase */
inline
CeChar ce_random_letter(void)
{
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[randgen(52)];
}

/* Generate random letter in upcase */
inline
CeChar ce_random_letter_upcase(void)
{
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[ce_random(26)];
}

/* Generate random letter in downcase */
inline
CeChar ce_random_letter_downcase(void)
{
        return "abcdefghijklmnopqrstuvwxyz"[ce_random(26)];
}

