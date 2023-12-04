#include <bits/stdc++.h>
 
using namespace std;

const int max_n = 1000000007;

typedef long double ld;

// estrutura que representa o ponto
struct Point{
   ld x,y;
   Point operator +(const Point& a) const {return Point{x+a.x, y+a.y};}
   Point operator -(const Point& a) const {return Point{x-a.x, y-a.y};}
   ld operator *(const Point& a) const {return (ld) x*a.y - (ld) y*a.x;}
};
