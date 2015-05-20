/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/
#include <cstdlib>
#include <memory.hpp>
#include <types.hpp>

namespace cpu
{
    template<typename T>
    T* memAlloc(const size_t &elements)
    {
        if (!elements)
            return NULL;

        const size_t alloc_size = elements * sizeof(T);
        return static_cast<T*>(malloc(alloc_size));
    }

    template<typename T>
    void memFree(T* ptr)
    {
        free(ptr);
    }

    void garbageCollect() { }

    void pinnedGarbageCollect() { }

    void deviceMemoryInfo(size_t *alloc_bytes, size_t *alloc_buffers,
                          size_t *lock_bytes,  size_t *lock_buffers)
    {
    }

    template<typename T>
    T* pinnedAlloc(const size_t &elements)
    {
        return memAlloc<T>(elements);
    }

    template<typename T>
    void pinnedFree(T* ptr)
    {
        memFree<T>(ptr);
    }

#define INSTANTIATE(T)                                          \
    template T* memAlloc(const size_t &elements);               \
    template void memFree(T* ptr);                              \
    template T* pinnedAlloc(const size_t &elements);            \
    template void pinnedFree(T* ptr);                           \

    INSTANTIATE(float)
    INSTANTIATE(cfloat)
    INSTANTIATE(double)
    INSTANTIATE(cdouble)
    INSTANTIATE(int)
    INSTANTIATE(uint)
    INSTANTIATE(char)
    INSTANTIATE(uchar)
    INSTANTIATE(intl)
    INSTANTIATE(uintl)

}
