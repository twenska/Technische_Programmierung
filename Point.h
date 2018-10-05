/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Enthält die Datenstruktur für einen einzelnen Punkt.             *
 *******************************************************************/
/*Header Guard*/
#ifndef _POINT_H_
#define _POINT_H_
struct Point_s{
    double x;
    double y;
};
typedef struct Point_s Point_t;
//Erstellt einen neuen Punkt mit den angegebenen Koordinaten
Point_t* newPoint(double,double);

//Getter und Setter für die X und Y Koordinate des Punktes
double getx(Point_t*);
void setx(Point_t*,double);
double gety(Point_t*);
void sety(Point_t*,double);
void printPoint(Point_t*);

#endif