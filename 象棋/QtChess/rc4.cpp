#include "rc4.h"

RC4::RC4()
{

}

RC4::~RC4()
{

}

void RC4::init()
{
    index1 = 0;
    index2 = 0;
    for (int i = 0; i < 256; ++i)
    {
        key[i] = i;
    }

    int j = 0;
    unsigned char c = 0;
    for (int i = 0; i < 256; ++i)
    {
        j = (j + key[i]) & 255;
        c = key[i];
        key[i] = key[j];
        key[j] = c;
    }
}

unsigned char RC4::nextByte()
{
    unsigned char c = 0;
    index1 = (index1 + 1) & 255;
    index2 = (index2 + key[index1]) & 255;

    c = key[index1];
    key[index1] = key[index2];
    key[index2] = c;

    return key[(key[index1] + key[index2]) & 255];
}

unsigned long RC4::next4Bytes()
{
    unsigned char a = nextByte();
    unsigned char b = nextByte();
    unsigned char c = nextByte();
    unsigned char d = nextByte();

    return a + (b << 8) + (c << 16) + (d << 24);
}

