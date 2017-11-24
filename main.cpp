#include <stdio.h>
#include "ListLib.h"


int main()
{
    List* lst = new List();

    for(int i=0; i<4; ++i)
    {

        ListEl *lst_el = lst->Insert(i, 1, BEGIN);
        printf("%d\n", lst_el->value);
    }

    lst->DeleteElem(0);
    lst->DeleteElem(3);
    lst->DeleteElem(1);
    lst->DeleteElem(4);


    DumpList(lst);
    printf("\n");
    for(int i=0; i<1; ++i)
    {
        ListEl *lst_el = lst->Insert(i, 2, MIDDLE);
        printf("%d\n", lst_el->value);
    }

    DumpList(lst);
    printf("\n");
    for(int i=0; i<4; ++i)
    {
        ListEl *lst_el = lst->Insert(i, 1, LAST);
        printf("%d\n", lst_el->value);
    }

    DumpList(lst);
    delete lst;

    return 0;
}

