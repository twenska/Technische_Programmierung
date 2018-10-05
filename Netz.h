/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * In Netz ist die Struktur des Netzes definiert, welche aus zwei   *
 * Listen besteht, welche die Punkte und die Linien des Netzes      *
 * beinhalten. Zudem wird die Anzahl der Punkte und der Linien mit- *
 * geführt, sowie die maximalen und minimalen X und Y Werte der     *
 * Punkte.                                                          *
 *******************************************************************/
/*Header Guard*/
#ifndef _NETZ_H_
#define _NETZ_H_
#include"PointList.h"
#include"LineList.h"
#include"Point.h"

struct Netz_s{
    PointList_t* PointList;
    LineList_t* LineList;
    int anzahlPunkte, anzahlLines;
    double max_X, min_X, max_Y, min_Y;
};
typedef struct Netz_s Netz_t;

//Erstellt ein neues leeres Netz
Netz_t* newNetz();
//Fügt einen Punkt der PointList des Netzes hinzu
void add_Point(Netz_t*, Point_t*);
//Erstellt aus den eingegebenen Punkte die zugehörigen Lines und legt diese in die LineList ab
void make_Lines(Netz_t*);
//Überprüft das Netz auf Gültigkeit, d.h. keine Überschneidungen von Linien außer an den Eckpunkten
//Gibt 0 zurück wenn Netz ungültig und 1 wenn Netz gültig
int check_Netz(Netz_t*);
//Überprüft ob der angegebene Punkt innerhalb des Netzes liegt
//Gibt 0 zurück wenn der Punkt außerhalb ist ind 1 wenn der Punkt innerhalb ist
int PunktInNetz(Point_t* punkt, Netz_t* netz);
//Gibt das Netz in einer übersichtlichen Form in die Konsole aus
int print_Netz(Netz_t*);
//Gibt die Anzahl an Schnittpunkten des Netzes und einer Strecke aus dem gegebenen Punkt und einem außerhalb liegenden Punktes zurück
//Wird für Funktion PunktInNetz benötigt
int SchnittpunkteMitNetz(Netz_t* netz, Point_t* punkt);

#endif