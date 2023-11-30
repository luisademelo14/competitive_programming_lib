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

// p eh um vetor de pontos

// a area eh calculada a partir do determinante da matriz 
// com os pontos
ld area_polygon(vector<Point> p){
	ld result = 0.0, x1, y1, x2, y2;
	for(int i=0; i<(int)p.size(); i++){
		int j = (i+1)%(int)p.size();
		x1 = p[i].x;
		x2 = p[j].x;
		y1 = p[i].y;
		y2 = p[j].y;
		result += (x1*y2 - x2*y1);
	}

	return fabs(result/2.0);
}
