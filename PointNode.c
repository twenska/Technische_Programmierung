/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in PointNode.h                                       *
 *******************************************************************/
/*Header Guard*/
#ifndef _NODE_C_
#define _NODE_C_
#include "PointNode.h"
#include<stdlib.h>

PointNode_t* newPointNode(Point_t* data){
    PointNode_t* initial = malloc(sizeof(PointNode_t));
    initial->value = data;
    initial->next=0;
    return initial;
}

Point_t* get_PointValue(PointNode_t* this){
   return this->value;
}

void set_PointValue(PointNode_t* this, Point_t* punkt){
    this->value = punkt;
}


#endif