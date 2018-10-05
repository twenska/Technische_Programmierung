/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * LineNode ist das Inhaltselement einer der verketteten Liste      *
 * LineList. LineNode enthält eine Line und einen Pointer auf       *
 * den nächsten LineNode.                                           *
 *******************************************************************/
/*Header Guard*/

#ifndef _LINENODE_H_
#define _LINENODE_H_
#include "Line.h"

struct LineNode_s{
    Line_t* value;
    struct LineNode_s* next;
};

typedef struct LineNode_s LineNode_t;
//Erstellt einen neuen LineNode mit gegebener Line
LineNode_t* newLineNode(Line_t*);
//Getter und Setter für den Inhalt des LineNodes
Line_t* get_LineValue(LineNode_t*);
void set_LineValue(LineNode_t*,Line_t*);

#endif