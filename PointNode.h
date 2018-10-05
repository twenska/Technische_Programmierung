/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * PointNode ist das Inhaltselement der einfach verketteten Liste   *
 * PointList. Es enthält einen Punkt und einen Pointer auf das      *
 * folgende PointNode-Element.                                      *
 *******************************************************************/
/*Header Guard*/
#ifndef _POINTNODE_H_
#define _POINTNODE_H_
#include "Point.h"
struct PointNode_s{
    Point_t* value;
    struct PointNode_s* next;
};
typedef struct PointNode_s PointNode_t;
PointNode_t* newPointNode(Point_t*);
Point_t* get_PointValue(PointNode_t*);
void set_PointValue(PointNode_t*,Point_t*);

#endif