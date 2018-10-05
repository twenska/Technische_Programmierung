/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * LineList implementiert eine einfach verkettete Liste, deren      *
 * Inhalt LineNode-Elemente sind. Für den hier gegebenen            *
 * Anwendungsfall sind nur unten angegebene Funktionen nötig        *
 *******************************************************************/
#ifndef _LINELIST_H_
#define _LINELIST_H_
#include "Point.h"
#include "LineNode.h"

struct LineList_s{
    LineNode_t* head;
};

typedef struct LineList_s LineList_t;
//Erstellt eine neue leere LineList
LineList_t* newLineList();
//Hängt eine Line an die angegebene LineList an
void append_Line(LineList_t*,Line_t*);

#endif