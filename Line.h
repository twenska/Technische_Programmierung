/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Line ist die Datenstruktur für eine Linie des Polygon.           *
 * Sie beinhaltet zwei Punkte, die Start und Ende der Linie bilden. *
 * Zusätzlich ist eine Funktion implementiert, mit der zwei Linien  *
 * auf einen gemeinsamen Schnittpunkt geprüft werden können.        *
 *******************************************************************/

/*Header Guard*/
#ifndef _LINE_H_
#define _LINE_H_
#include "Point.h"

struct Line_s{
    Point_t* punkt1;
    Point_t* punkt2;
    int nx,ny,d;

};
typedef struct Line_s Line_t;
//Erstellt eine neue Line mit gegebenen Punkten und berechnet die Geradenfunktion
Line_t* newLine(Point_t*,Point_t*);
//Prüft ob ein Punkt unterhalb der gegebenen Linie, oberhalb oder auf ihr liegt und 
//gibt dementsprechend eine negative Zahl, eine positive Zahl oder 0 zurück
double evalPoint(Line_t*, Point_t*);
//Prüft ob zwei Linien einen gemeinsamen Schnittpunkt haben.
//Bei gemeinsamen Schnittpunkt wird 1 zurückgegeben, sonst 0
int habenSchnittpunkt(Line_t*, Line_t*); 
#endif