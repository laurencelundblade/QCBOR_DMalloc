/*==============================================================================
 
 Copyright (c) 2018-2019, Laurence Lundblade.
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

#ifndef qcbor_decode_malloc_h
#define qcbor_decode_malloc_h

#include "qcbor.h"


/**
 @brief This returns a string allocator that uses malloc.
 
 @param[out] pfAllocator  Place where pointer to allocate
                          function is returned.
 @param[out] ppCtx        Place where pointer to allocate
                          context is returned.
 
 
 Call this to get the string allocator and then configure it into the
 decoder by calling QCBORDecode_SetUpAllocator().  If you don't call
 this, there will be no dependency on malloc in QCBOR.
 
 If you do set up this malloc-based string allocator, then \c free()
 must be called on every string marked as allocated in a \ref
 QCBORItem. They are marked by \c uDataAlloc and \c uLabelAlloc in
 \ref QCBORItem.
 
 An older version of QCBOR supported a different form of of the string
 allocator. They are not compatible.
 */
void QCBOR_DMalloc(QCBORStringAllocate *pfAllocator, void **ppCtx);

#endif /* qcbor_decode_malloc_h */
