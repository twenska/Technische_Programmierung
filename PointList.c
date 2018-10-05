/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in LineNode.h                                       *
 *******************************************************************/
/*Header Guard*/
#ifndef _POINTLIST_C_
#define _POINTLIST_C_
#include "PointList.h"
#include "PointNode.c"
#include"Point.c"
#include<stdlib.h>

PointList_t* newPointList(){
     PointList_t* initial = malloc(sizeof(PointList_t));
    initial->head = 0;
    return initial;
}
void append_Point(PointList_t* list, Point_t* punkt){
    
    if (list->head == 0) {
        list->head = newPointNode(punkt);
    }
    else
    {
        PointNode_t* iterator = list->head;
        
        while(iterator->next != 0){
            iterator = iterator->next;
        }
        iterator->next = newPointNode(punkt);
    }   
}


#endif