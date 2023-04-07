#include "square.h"
#define pi 3.14159265358979323846
void  square(double r, double* area_num, double* perimetr)
{
    *area_num = pi * r * r;
    *perimetr = 2 * pi * r;
}
