/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in LineList.h                                       *
 *******************************************************************/
#ifndef _LINELIST_C_
#define _LINELIST_C_
#include "LineList.h"
#include "LineNode.c"
#include"Point.c"
#include<stdlib.h>

LineList_t* newLineList(){
    LineList_t* initial = malloc(sizeof(LineList_t));
    initial->head = 0;
    return initial;
}
void append_Line(LineList_t* list, Line_t* line){
    if (list->head == 0) {
        list->head = newLineNode(line);
    }
    else
    {
        LineNode_t* iterator = list->head;
        
        while(iterator->next != 0){
            iterator = iterator->next;
        }
        iterator->next = newLineNode(line);
    }   
}


#endif