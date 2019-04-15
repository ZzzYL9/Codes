#ifndef ZOBRIST_H
#define ZOBRIST_H
#include "rc4.h"

class Zobrist
{
public:
    Zobrist();
    ~Zobrist();
    void reset();
    void init(RC4 &rc4);
    void Xor(const Zobrist &zobr);
    void Xor(const Zobrist &zobr1, const Zobrist &zobr2);

    unsigned long key;
    unsigned long lock0;
    unsigned long lock1;
};

#endif // ZOBRIST_H
