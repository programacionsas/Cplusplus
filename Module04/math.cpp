#include "math.hpp"

namespace Math
{
    int sum(int x, int y)
    {
        return x + y;
    }
    
    int abs(int x)
    {
        if (x < 0)
        {
            return -x;
        }

        return x;
    }
}