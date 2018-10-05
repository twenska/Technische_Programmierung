/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in LineNode.h                                       *
 *******************************************************************/
/*Header Guard*/
#ifndef _LINENODE_C_
#define _LINENODE_C_
#include "LineNode.h"
#include<stdlib.h>

LineNode_t* newLineNode(Line_t* data){
    LineNode_t* initial = malloc(sizeof(LineNode_t));
   initial->value = data;
   initial->next=0;
   return initial;
}

Line_t* get_LineValue(LineNode_t* this){
   return this->value;
}

void set_LineValue(LineNode_t* this, Line_t* line){
    this->value = line;
}


#endif