/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * PointList ist eine einfach verkettete Liste, die PointNodes      *
 * enthält. Für den hier gegebenen Anwendungsfall sind nur unten    *
 * angegebene Funktionen nötig                                      *
 *******************************************************************/
/*Header Guard*/
#ifndef _POINTLIST_H_
#define _POINTLIST_H_
#include "Point.h"
#include "PointNode.h"

struct PointList_s{
    PointNode_t* head;
};
typedef struct PointList_s PointList_t;
//Erstellt eine neue leere PointList
PointList_t* newPointList();
//Fügt einen Punkt in die Liste ein
void append(PointList_t*,Point_t*);

#endif