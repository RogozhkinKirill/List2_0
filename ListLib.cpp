#include "ListLib.h"
#include <stdio.h>
#include <stdlib.h>



ListEl::ListEl()
{
    this->value = 0;
    this->next = this->prev = NULL;
    return;
}

ListEl::ListEl(value_t value)
{
    this->value = value;
    this->prev = this->next = NULL;
    return;
}

ListEl::~ListEl()
{
    this->value = 0;
    this->prev = this->next = NULL;
    return;
}

List::List()
{
    this->first = this->last = NULL;
    return;
}

List::~List()
{
    while(this->first != NULL)
    {
        ListEl* lst_el = this->first;
        this->first = this->first->next;
        delete lst_el;
    }

    return;
}



ListEl* List::Find(value_t value)
{
    ListEl* current = this->first;
    while(current)
    {
        if(current->value == value)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

ListEl* List::Insert(value_t value, value_t El, int place)
{
    if(!this)
    {
        printf("ERROR. Pointer on List = NULL\n");
        return NULL;
    }

    ListEl* lst_el = new ListEl(value);

    switch(place)
    {
        case BEGIN:
        {
            if(this->first)
            {
                lst_el->next = this->first;
                this->first->prev = lst_el;
                this->first = lst_el;
            }
            else
            {
                this->first = this->last = lst_el;
            }
        }
            break;

        case MIDDLE:
        {
            if(!this->first)
            {
                this->first = this->last = lst_el;
                break;
            }

            ListEl* tmp = this->Find(El);
            if(!tmp)
            {
                delete lst_el;
                return NULL;
            }

           if(this->last == tmp)
           {
               lst_el->prev = tmp;
               tmp->next = lst_el;
               this->last = lst_el;
           }
            else
           {
               lst_el->prev = tmp;
               lst_el->next = tmp->next;
               tmp->next = lst_el;
           }
        }
            break;

        case LAST:
        {
            if(this->last)
            {
                lst_el->prev = this->last;
                this->last->next = lst_el;
                this->last = lst_el;
            }
            else
            {
                this->first = this->last = lst_el;
            }
        }
            break;

        default:
        {
            printf("ERROR. List::Insert(). Wrong place transmitted\n");
            delete lst_el;
            return NULL;
        }
    }

    return lst_el;
}

value_t List::DeleteElem(value_t value)
{
    if(!this)
        return 0;

    ListEl* tmp = this->Find(value);

    if(tmp)
    {
        if (tmp->prev && tmp->next)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        else if(!tmp->next && tmp->prev)
        {
            tmp->prev->next = NULL;
            this->last = tmp->prev;
        }else if(!tmp->prev && tmp->next)
        {
            tmp->next->prev = NULL;
            this->first = tmp->next;
        }else if(!tmp->prev && !tmp->next)
        {
            this->last = this->first = NULL;
        }

        delete tmp;
    }
    else
    {
        printf("List::DeleteElem. Element %d was not found\n\n" , value);
        return 0;
    }

    return value;
}

void List::ListDump()
{
    if(!this)
    {
        printf("ERROR. List is empty\n");
        return;
    }

    printf("List:\nthis:        0x%p\nthis->first: 0x%p\nthis->last:  0x%p\n" , this , this->first , this->last);

    int count = 0;
    ListEl* current = this->first;
    while(current)
    {
        printf("\nElement %d:\n\tvalue    = %d\n\tcurrent->prev 0x%p\n\tcurrent       0x%p\n\tcurrent->next 0x%p\n" ,
               count + 1 , current->value , current->prev , current , current->next);
        ++count;
        current = current->next;
    }

    printf("Dump finished\n");

    return;
}