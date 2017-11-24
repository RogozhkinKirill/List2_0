#ifndef LIST_LISTLIB_H
#define LIST_LISTLIB_H

#define BEGIN 0
#define MIDDLE 1
#define LAST 2


#define DumpList(x) printf("\nDump started:\n\Function: %s \nLine: %d\nFile: %s\n" , \
							__PRETTY_FUNCTION__ , \
							__LINE__ , __FILE__);\
                            x->ListDump();


typedef int value_t;

class ListEl
{
public:
    value_t value;
    ListEl* next;
    ListEl* prev;

    ListEl();
    ListEl(value_t);
    ~ListEl();
};

class List
{
public:
    ListEl* first;
    ListEl* last;

    List();
    ~List();

    ListEl* Find(value_t);
    ListEl* Insert(value_t , value_t ,  int); //include new element after transmitted element
    value_t DeleteElem(value_t);

    void ListDump();
};


#endif //LIST_LISTLIB_H
