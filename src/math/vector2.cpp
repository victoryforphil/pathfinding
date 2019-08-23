#include "vector2.hpp"

using namespace Math;

Vector2::Vector2(){
    m_x = 0;
    m_y = 0;
}

Vector2::Vector2(int x, int y){
    m_x = x;
    m_y = y;
}

int Vector2::SetX(int x){
    m_x = x;
    return m_x;
}

int Vector2::SetY(int y){
    m_y = y;
    return m_y;
}

int Vector2::GetX(){
    return m_x;
}

int Vector2::GetY(){
    return m_y;
}

int Vector2::GetDistanceInt(Vector2 other){
    // Say it with me now kids, A squared + B square is C squared
    int a = pow(m_x, other.GetX());
    int b = pow(m_y, other.GetY());
    int c = a + b;

    return sqrt(c);
}


Vector2 Vector2::operator+(const Vector2 &b){
    return Vector2(m_x + b.m_x, m_y + b.m_y);
}
