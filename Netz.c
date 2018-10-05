/********************************************************************
 * author:                                                          *
 * Leon Twenning                                                    *
 *                                                                  *
 * Beschreibung in Netz.h                                           *
 *******************************************************************/
/*Header Guard*/
#ifndef _NETZ_C_
#define _NETZ_C_
#include"Netz.h"
#include"PointList.c"
#include"LineList.c"
#include"Line.c"
#include<stdlib.h>
#include<stdio.h>

Netz_t* newNetz(){
    Netz_t* initial = malloc(sizeof(Netz_t));
    initial->anzahlPunkte = 0;
    initial->anzahlLines = 0;
    initial->PointList = newPointList();
    initial->LineList = newLineList();
    initial->max_X = 0;
    initial->min_X = 0;
    initial->max_Y = 0;
    initial->min_X = 0;
    return initial;
}
void add_Point(Netz_t* netz, Point_t* punkt){
   append_Point(netz->PointList,punkt);
   //Check if new Max/Min values need to be set
   if (punkt->x > netz->max_X) netz->max_X = punkt->x;
   if (punkt->x < netz->min_X) netz->min_X = punkt->x;
   if (punkt->y > netz->max_Y) netz->max_Y = punkt->y;
   if (punkt->y < netz->min_Y) netz->min_Y = punkt->y;

   netz->anzahlPunkte++;
}
void make_Lines(Netz_t* netz){
    PointNode_t* iter = netz->PointList->head;
    if(netz->anzahlPunkte > 2){
        for (int i = 0; i<netz->anzahlPunkte-1;i++){
            append_Line(netz->LineList,newLine(iter->value, iter->next->value));
            netz->anzahlLines++;
            iter=iter->next;
        }
    }
    
    append_Line(netz->LineList,newLine(iter->value, netz->PointList->head->value));
}

int check_Netz(Netz_t* netz){
    if(netz->anzahlPunkte > 2){
        LineNode_t* iter1 = netz->LineList->head;
        for (int i = 0; i<netz->anzahlLines; i++){
            Line_t* Line1 = iter1->value;
            //Hier nur bis zum direkten Nachbarn gehen, um Seg Fault zu vermeiden.
            LineNode_t* iter2 = iter1->next;
            for(int m = 0; m < netz->anzahlLines-2;m++){
                //wenn am Ende der Liste, gehe zum Anfang.
                if(iter2->next != 0){
                    iter2 = iter2 ->next;
                }else iter2 = netz->LineList->head;
                Line_t* Line2 = iter2->value;
                if(habenSchnittpunkt(Line1,Line2)){
                    return 0;
                }
            }
            iter1 = iter1->next;
        }
    }else return 0;

    return 1;
}

int print_Netz(Netz_t* netz){

    PointNode_t* iterator = netz->PointList->head;

    printf("-------------------------------\n");
    printf("| %-5s | %-8s | %-8s |\n", "Nr.", "X", "Y");
    printf("-------------------------------\n");

    for (int i = 0; i < netz->anzahlPunkte; i++)
    {
        if (iterator == 0)
        {
            return 0;
        }
        printf("| %-5i | % .5f | % .5f |\n", i, iterator->value->x, iterator->value->y);

        iterator = iterator->next;
    }

    printf("-------------------------------\n");
    printf("| %-5s | % .5f | % .5f |\n","max",netz->max_X,netz->max_Y);
    printf("| %-5s | % .5f | % .5f |\n","min",netz->min_X,netz->min_Y);
    printf("-------------------------------\n");
    printf("| Anzahl Punkte: %10i |\n", netz->anzahlPunkte);
    printf("-------------------------------\n");

    return 1;
}


int PunktInNetz(Point_t* punkt, Netz_t* netz){
    
    //Sonderfälle:  1. Punkt liegt genau auf Linie
    //              2. Punkt liegt auf Eckpunkt des Netzes
    if (netz->LineList->head == 0 || netz->PointList->head == 0 || netz->anzahlPunkte <= 2)
    {
        printf("Fehler: Netz wurde nicht validiert und scheint nicht gültig zu sein!\n");
        return 0;
    }

    //Ist Punkt innerhalb der maximalen und minimalen X und Y Werte des Netzes
    if( getx(punkt) > netz->max_X || getx(punkt) < netz->min_X || gety(punkt) > netz->max_Y || gety(punkt) < netz->min_Y)
    {
        return 0;
    }

    /*Wenn die Linie zwischen dem gegebenen Punkt und einem willkürlichen Punkt außerhalb des Netzes eine gerade Anzahl
     *an Schnittpunkten mit den Außenlinien des Netzes hat, ist der Punkt außerhalb und es wird 0 returned
     *Ansonsten ist der Punkt innerhalb des Netzes und es wird 1 zurückgegeben
     */

    return(SchnittpunkteMitNetz(netz, punkt) % 2);
}

int SchnittpunkteMitNetz(Netz_t* netz, Point_t* punkt){
    //Punkt erstellen der sicher außerhalb des Netzes liegt
    Point_t* PAusserhalb = newPoint((netz->max_X + 1.0), punkt->y);
    Line_t* ray = newLine(punkt, PAusserhalb);

    int AnzahlSchnittpunkte = 0;

    LineNode_t* iter = netz->LineList->head;

    /*check for intersections*/
    for(int i = 0; i < netz->anzahlLines; i++)
    {
        if(habenSchnittpunkt(iter->value, ray))
        {
            AnzahlSchnittpunkte++;
        }

        iter = iter->next;
    }

    return AnzahlSchnittpunkte;
}

#endif

