/********************************
 * author:                      *
 * Leon Twenning                *
 *                              *
 * Beschreibung in Line.h       *
 *******************************/

/*Header Guard*/
#ifndef _LINE_C_
#define _LINE_C_
#include"Line.h"
#include"Point.c"
#include<stdlib.h>

Line_t* newLine(Point_t* p1,Point_t* p2){
    Line_t*  initial = malloc(sizeof(Line_t));
    if (initial != 0)
    {
        initial->punkt1 = p1;
        initial->punkt2 = p2;

        //Gleichung für spätere Schnittpunktbestimmung
        initial->nx = (initial->punkt1->y) - (initial->punkt2->y);
        initial->ny = (initial->punkt2->x) - (initial->punkt1->x);

        initial->d = initial->nx * initial->punkt1->x + initial->ny * initial->punkt1->y;
    }
    return initial;
}

double evalPoint(Line_t* line, Point_t* point)
{
    return line->nx * point->x + line->ny * point->y - line->d;
}

int habenSchnittpunkt(Line_t* l1, Line_t* l2)
{
    //Gibt 0 zurück wenn kein Schnittpunkt existiert, sonst 1
    double test1 = evalPoint(l1, l2->punkt1) * evalPoint(l1, l2->punkt2);

    double test2 = evalPoint(l2, l1->punkt1) * evalPoint(l2, l1->punkt2);

    if (test1 > 0 || test2 > 0)
    {
        return 0;
    }

    return 1;
}

#endif