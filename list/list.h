#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct LIST_ITEM{
    int elem;
    uint32_t xItemValue;
    struct List_Item_t *next;
}List_Item_t;

typedef struct LIST{
    uint32_t uxNumberOfItems;
    List_Item_t *pxIndex;
}List_t;


#define NODE_MAX_SIZE 10

int initLinkList(List_t** list);
int initLinkListItem(List_Item_t** item);
int LinkListInsert(List_t *list, List_Item_t *list_item);
List_Item_t* linkListGet(List_t *list, int elem);
#endif