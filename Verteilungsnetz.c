/*
    Verteilungsstaionen S1 bis Sn definiert als Punkte mit x und y; Netz ist ein Polygon mit S1-Sn als Eckpunkten
    Kunden K1-Kn sind definiert als Punkte mit x und y

    User-Story:
    In meinem Programm nöchte ich ein Netz vorgeben und für beliebige Punkte meiner Wahl (Kunde) bestimmen können,
    ob der Punkt innerhalb oder außerhalb des vorgegebenen Netzes liegt.

    Netz darf keine Überkreuzungen haben.

    Polygon ist eine verkettet Liste von Punkten
        -> Datenstruktur LinkedList für Point_t (aus Structs_Example) als Content
    Abstrakter Datentyp Netz_t
                            -enthält LinkedList für Point_t
                            -Schnittstellenfunktionen
                            -Funktion int liegtimNetz(Netz_t*,Point_t)
*/
#include <stdio.h>
#include"Point.c"
#include"Netz.c"

int main()
{
    /* code */
    
    Point_t* P1 = newPoint(2,2);
    Point_t* P2 = newPoint(2,4);
    Point_t* P3 = newPoint(3,6);
    Point_t* P4 = newPoint(5,6);
    Point_t* P5 = newPoint(6,5);
    Point_t* P6 = newPoint(6,3);
    Point_t* P7 = newPoint(4,2);
    Point_t* test = newPoint(2,4);
    Netz_t* Netz = newNetz();

    add_Point(Netz,P1);
    add_Point(Netz,P2);
    add_Point(Netz,P3);
    add_Point(Netz,P4);
    add_Point(Netz,P5);
    add_Point(Netz,P6);
    add_Point(Netz,P7);
    make_Lines(Netz);
    print_Netz(Netz);
    
 
    int ergebnis = check_Netz(Netz);
    printf("Ergebnis ist %i\n",ergebnis);
    ergebnis = PunktInNetz(test,Netz);
    printf("Ergebnis2 ist %i\n",ergebnis);

}
