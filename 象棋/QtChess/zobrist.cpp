#include "zobrist.h"

Zobrist::Zobrist()
{
    reset();
}

Zobrist::~Zobrist()
{

}

void Zobrist::reset()
{
    key = 0;
    lock0 = 0;
    lock1 = 0;
}

void Zobrist::init(RC4 &rc4)
{
    key = rc4.next4Bytes();
    lock0 = rc4.next4Bytes();
    lock1 = rc4.next4Bytes();
}

void Zobrist::Xor(const Zobrist &zobr)
{
    key ^= zobr.key;
    lock0 ^= zobr.lock0;
    lock1 ^= zobr.lock1;
}

void Zobrist::Xor(const Zobrist &zobr1, const Zobrist &zobr2)
{
    key = zobr1.key ^ zobr2.key;
    lock0 = zobr1.lock0 ^ zobr2.lock0;
    lock1 = zobr1.lock1 ^ zobr2.lock1;
}

