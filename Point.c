/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in Netz.h                                           *
 *******************************************************************/
/*Header Guard*/
#ifndef _POINT_C_
#define _POINT_C_
#include "Point.h"
#include <stdio.h>
#include <stdlib.h>

Point_t* newPoint(double init_x, double init_y){
    Point_t* initial = malloc(sizeof(Point_t));
    initial->x = init_x;
    initial->y = init_y;
    return initial;
}

double getx(Point_t* this){
   return this->x;
}

void setx(Point_t* this, double x){
    this->x = x;
}

double gety(Point_t* this){
    return this->y;
}

void sety(Point_t* this,double y){
    this->y=y;
}

void printPoint(Point_t* this){
    printf("x-Coordinate:%lf\n",this->x);
    printf("y-Coordinate:%lf\n",this->y);
}

#endif