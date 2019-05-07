#include <iostream>
#include "point.h"

using std::istream;

istream& read(istream& is, Zuobiao& Z)
{
    is >> Z.no >> Z.ch >> Z.tem_1 >> Z.ch >> Z.tem_2 >> Z.ch >> Z.pa;
    return is;
}
