#include "../template.h"

// estrutura que representa o ponto
struct Point{
   ld x,y;
   Point operator +(const Point& a) const {return Point{x+a.x, y+a.y};}
   Point operator -(const Point& a) const {return Point{x-a.x, y-a.y};}
   ld operator *(const Point& a) const {return (ld) x*a.y - (ld) y*a.x;}
};
