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

    char DotListAddressCurrent[10];
    char DotListAddress_Ox_Current[10];
    char DotListAddress_Ox_Next[10];
    char DotListAddress_Ox_Prev[10];
    char DotListValue[10];
    itoa((int)lst_el , DotListAddressCurrent , 10);
    itoa((int)lst_el , DotListAddress_Ox_Current , 16);
    itoa((int)(lst_el->next) , DotListAddress_Ox_Next , 16);
    itoa((int)(lst_el->prev) , DotListAddress_Ox_Prev , 16);
    itoa( lst_el->value , DotListValue , 10);

    fputs("\n   " , DotFile);
    fputs(DotListAddressCurrent , DotFile);
    fputs(" [label =\"{Current | Previous | Next | Value} | {" , DotFile);
    fputs(DotListAddress_Ox_Current , DotFile);
    fputs(" | " , DotFile);
    fputs(DotListAddress_Ox_Prev , DotFile);
    fputs(" | " , DotFile);
    fputs(DotListAddress_Ox_Next , DotFile);
    fputs(" | " , DotFile);
    fputs(DotListValue , DotFile);
    fputs("}\" , style=filled , color=\"#40e100:#40e0f0\"];\n" , DotFile);

    return 0;
}

int DotListElCon(FILE* DotFile , ListEl* lst_el)
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

    char DotListAddressCurrent[10];
    itoa((int)lst_el , DotListAddressCurrent , 10);

    if(lst_el->next)
    {
        char DotListAddressNext[10];
        itoa((int)lst_el->next , DotListAddressNext , 10);

        fputs("\n   " , DotFile);
        fputs(DotListAddressCurrent , DotFile);
        fputs(" -> " , DotFile);
        fputs(DotListAddressNext , DotFile);
        fputs(";\n" , DotFile);
    }

    if(lst_el->prev)
    {
        char DotListAddressPrev[10];
        itoa((int) lst_el->prev, DotListAddressPrev, 10);

        fputs("\n   " , DotFile);
        fputs(DotListAddressCurrent, DotFile);
        fputs(" -> ", DotFile);
        fputs(DotListAddressPrev, DotFile);
        fputs(";\n", DotFile);
    }

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
    fputs("digraph ViewOfConnections {\n"
                  "   node[shape = record];\n" , DotFile);

    ListEl* current = lst->first;
    while(current)
    {
        DotListElLabel(DotFile , current);
        current = current->next;
    }

    current = lst->first;
    while(current)
    {
        DotListElCon(DotFile , current);
        current = current->next;
    }

    fputs("\n}\n", DotFile);

    int res = system("C:\\Programme\\Graphviz2.38\\bin\\dot.exe -Tpng C:\\Programme\\List2.0\\ViewOfConnections.txt "
                             "-oC:\\Programme\\List2.0\\ViewOfConnections.png");

    printf("\nResult of dot: %d\n" , res);

    fclose(DotFile);
    return 0;
}