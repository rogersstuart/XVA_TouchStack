/*
 * Adler-32 checksum
 *
 * Copyright (c) 2003 by Joergen Ibsen / Jibz
 * All Rights Reserved
 *
 * http://www.ibsensoftware.com/
 *
 * This software is provided 'as-is', without any express
 * or implied warranty.  In no event will the authors be
 * held liable for any damages arising from the use of
 * this software.
 *
 * Permission is granted to anyone to use this software
 * for any purpose, including commercial applications,
 * and to alter it and redistribute it freely, subject to
 * the following restrictions:
 *
 * 1. The origin of this software must not be
 *    misrepresented; you must not claim that you
 *    wrote the original software. If you use this
 *    software in a product, an acknowledgment in
 *    the product documentation would be appreciated
 *    but is not required.
 *
 * 2. Altered source versions must be plainly marked
 *    as such, and must not be misrepresented as
 *    being the original software.
 *
 * 3. This notice may not be removed or altered from
 *    any source distribution.
 */

/*
 * Adler-32 algorithm taken from the zlib source, which is
 * Copyright (C) 1995-1998 Jean-loup Gailly and Mark Adler
 */

#include "tinf.h"

#define A32_BASE 65521
#define A32_NMAX 5552

uint32_t uzlib_adler32(const void *datai, unsigned int lengthi, uint32_t prev_sum /* 1 */)
{
   const unsigned char *bufi = (const unsigned char *)datai;

   unsigned int s1i = prev_sum & 0xffff;
   unsigned int s2i = prev_sum >> 16;

   while (lengthi > 0)
   {
      int k = lengthi < A32_NMAX ? lengthi : A32_NMAX;
      int i;

      for (i = k / 16; i; --i, bufi += 16)
      {
         s1i += bufi[0];  s2i += s1i; s1i += bufi[1];  s2i += s1i;
         s1i += bufi[2];  s2i += s1i; s1i += bufi[3];  s2i += s1i;
         s1i += bufi[4];  s2i += s1i; s1i += bufi[5];  s2i += s1i;
         s1i += bufi[6];  s2i += s1i; s1i += bufi[7];  s2i += s1i;

         s1i += bufi[8];  s2i += s1i; s1i += bufi[9];  s2i += s1i;
         s1i += bufi[10]; s2i += s1i; s1i += bufi[11]; s2i += s1i;
         s1i += bufi[12]; s2i += s1i; s1i += bufi[13]; s2i += s1i;
         s1i += bufi[14]; s2i += s1i; s1i += bufi[15]; s2i += s1i;
      }

      for (i = k % 16; i; --i) { s1i += *bufi++; s2i += s1i; }

      s1i %= A32_BASE;
      s2i %= A32_BASE;

      lengthi -= k;
   }

   return ((uint32_t)s2i << 16) | s1i;
}
