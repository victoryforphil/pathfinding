#ifndef _MATH_VECTOR2_H_
#define _MATH_VECTOR2_H_

#include <cmath>

namespace Math{
    class Vector2
    {
    private:
        int m_x;
        int m_y;
    public:
        Vector2();
        Vector2(int x, int y);
        int SetX(int x);
        int SetY(int y);
        int GetX();
        int GetY();
        int GetDistanceInt(Vector2 other);  
        Vector2 operator +(const Vector2 &b);
        
        
    };

    
}

#endif