/*==============================================================================
 
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

#ifndef qcbor_decode_malloc_h
#define qcbor_decode_malloc_h

#include "qcbor.h"


/**
 @brief This returns a string allocator that uses malloc
 
 @return pointer to string allocator or NULL
 
 Call this to get the string allocator and then configure it into
 the decoder by calling QCBORDecode_SetUpAllocator().  If you
 don't call this, there will be no dependency on malloc
 in QCBOR. Some deployments of QCBOR might even exclude
 the implementation of this function if they don't have
 malloc() at all.
 
 If you do set up this malloc-based string allocator, then
 every string marked as allocated in a QCBORItem must be
 freed. They are marked by uDataAlloc and uLabelAlloc
 in QCBORItem.
 */
QCBORStringAllocator *QCBOR_DMalloc(void);


#endif /* qcbor_decode_malloc_h */
