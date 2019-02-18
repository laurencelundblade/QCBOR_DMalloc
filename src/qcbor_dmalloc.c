/*==============================================================================

 Copyright (c) 2018-2019, Laurence Lundblade.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 Copyright (c) 2018, Laurence Lundblade.
 All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * The name "Laurence Lundblade" may not be used to
      endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ==============================================================================*/

#include "qcbor_dmalloc.h"
#include <stdlib.h> // for realloc and free


static UsefulBuf MemMallocFunction(void *pCtx, void *pOldMem, size_t uNewSize)
{
   (void)pCtx;

   if(uNewSize) {
      // ALLOCATION AND REALLOCATION MODE
      void *pNewMem = realloc(pOldMem, uNewSize);
      return (UsefulBuf){pNewMem, uNewSize};
   } else {
      if(pOldMem) {
         // FREE MODE
         free(pOldMem);
      } else {
         // DESTRUCT MODE
         // Nothing to do for this allocator
      }
   }
   return NULLUsefulBuf;
}


/*
 Public function. See qcbor.h
 */
void QCBOR_DMalloc(QCBORStringAllocate *ppfAllocator, void **ppContext)
{
   *ppfAllocator = MemMallocFunction;
   *ppContext    = NULL; // No context needed. 
}

   

