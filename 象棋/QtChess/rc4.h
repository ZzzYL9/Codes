#ifndef RC4_H
#define RC4_H


class RC4
{
public:
    RC4();
    ~RC4();
    void init();
    unsigned char nextByte();
    unsigned long next4Bytes();

private:
    unsigned char key[256];
    int index1;
    int index2;
};

#endif // RC4_H
