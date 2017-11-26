#include "ListLib.h"
#include "DotLib.h"
#include <stdlib.h>


int DotListElLabel(FILE* DotFile , ListEl* lst_el)
{
    if (!DotFile)
    {
        printf("ERROR. Pointer on DotFile = NULL\n");
        return 2;
    }

    if (!lst_el)
    {
        printf("ERROR. Pointer on List = NULL\n");
        return 1;
    }

    char DotListAddress[10];
    char DotListValue[10];
    itoa((int)lst_el , DotListAddress , 10);
    itoa( lst_el->value , DotListValue , 10);

    fputs("\n   " , DotFile);
    fputs(DotListAddress , DotFile);
    fputs(" [label = " , DotFile);
    fputs(DotListValue , DotFile);
    fputs("];\n" , DotFile);

    return 0;
}


int DotListElCon(FILE* DotFile , ListEl* out ,  ListEl* in)
{
    if (!DotFile)
    {
        printf("ERROR. Pointer on DotFile = NULL\n");
        return 2;
    }

    if (!out || !in)
    {
        printf("ERROR. Pointer on List = NULL\n");
        return 1;
    }

    char DotListAddressOut[10];
    itoa((int)out , DotListAddressOut , 10);

    char DotListAddressIn[10];
    itoa((int)in , DotListAddressIn , 10);

    fputs("\n   " , DotFile);
    fputs(DotListAddressIn , DotFile);
    fputs(" -> " , DotFile);
    fputs(DotListAddressOut , DotFile);
    fputs(";\n   " , DotFile);
    fputs(DotListAddressOut , DotFile);
    fputs(" -> " , DotFile);
    fputs(DotListAddressIn , DotFile);
    fputs(";\n" , DotFile);

    return 0;
}

int DotDumpList(List* lst)
{
    if(!lst)
    {
        printf("ERROR. Pointer on List = NULL\n");
        return 1;
    }


    FILE* DotFile = fopen("C:\\Programme\\List2.0\\ViewOfConnections.txt" , "w+");
    fputs("digraph ViewOfConnections {\n" , DotFile);

    ListEl* current = lst->first;
    while(current)
    {
        DotListElLabel(DotFile , current->prev);
        DotListElLabel(DotFile , current);

        DotListElCon(DotFile , current->prev , current);

        current = current->next;
    }

    fputs("\n}\n", DotFile);

    int res = system("C:\\Programme\\Graphviz2.38\\bin\\dot.exe -Tpng C:\\Programme\\List2.0\\ViewOfConnections.txt "
                             "-oC:\\Programme\\List2.0\\ViewOfConnections.png");

    printf("\nResult of dot: %d\n" , res);

    fclose(DotFile);
    return 0;
}