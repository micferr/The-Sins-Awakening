#ifndef ENDIANNESS_H
#define ENDIANNESS_H

#include "order32.h"

template<typename T>
T swap_endianness(T t) {
    T t2;

    unsigned char* a=static_cast<unsigned char*>(&t);
    unsigned char* b=static_cast<unsigned char*>(&t2);

    for (unsigned i=0, t_size=sizeof(t); i<t_size; ++i)
        b[i]=a[t_size-1-i];

    return t2;
}

template<typename T>
void swap_endianness_reference(T& t) {
    T t2;

    unsigned char* a=static_cast<unsigned char*>(static_cast<void*>(&t));
    unsigned char* b=static_cast<unsigned char*>(static_cast<void*>(&t2));

    for (unsigned i=0, t_size=sizeof(t); i<t_size; ++i)
        b[i]=a[t_size-1-i];

    t=t2;
}

#endif // MCD_ENDIANNESS_H
