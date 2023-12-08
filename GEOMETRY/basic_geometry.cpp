#include "geometry.h"

// lembrar de implementar struct para point 3d

// para pontos do tipo 2d
ld dot(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}

// norma de a: |a|² = a*a
ld norm(Point a){
    return dot(a, a);
}

// tamanho de a: |a| = sqrt(a*a)
ld abs_lenght(Point a){
    return sqrt(norm(a));
}

// projecao de a em b: (a*b)/|b|
ld proj(Point a, Point b){
    return dot(a,b)/abs_lenght(b);
}

// angulo entre dois vetores: arccos ((a*b)/(|a|*|b|))
ld angle(Point a, Point b){
    return acos(dot(a,b)/(abs_lenght(a)*abs_lenght(b)));
}
