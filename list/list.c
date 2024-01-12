/*
 * @Author: qiang.li qiang.li@xchengtech.com
 * @Date: 2024-01-11 11:00:48
 * @LastEditors: qiang.li qiang.li@xchengtech.com
 * @LastEditTime: 2024-01-12 13:52:23
 * @FilePath: \c\list.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: qiang.li qiang.li@xchengtech.com
 * @Date: 2024-01-11 11:00:48
 * @LastEditors: qiang.li qiang.li@xchengtech.com
 * @LastEditTime: 2024-01-12 11:14:46
 * @FilePath: \c\list.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "list.h"

int initLinkList(List_t** list)
{
    List_t *temp = (List_t *)malloc(sizeof(List_t));
    if(temp == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    temp->pxIndex = NULL;
    temp->uxNumberOfItems = 0;
    *list = temp;
    return 0;
}

int initLinkListItem(List_Item_t** new_item)
{
    List_Item_t *temp = (List_Item_t *)malloc(sizeof(List_Item_t));
    memset(temp,0,sizeof(List_Item_t));
    if(temp == NULL)
    {
        printf( "malloc error\n");
        return -1;
    }
    temp->elem = 0;
    temp->next = NULL;
    *new_item = temp;
    return 0;
}

int LinkListInsert(List_t *list, List_Item_t *list_item)
{
    List_Item_t *p = list;
    uint32_t item_value = list->uxNumberOfItems;
    if(list->uxNumberOfItems >= NODE_MAX_SIZE)
    {
        printf("list is full\n");
        return -3;
    }
    if(list != NULL && list_item != NULL)
    {
        if(list->pxIndex == NULL)
        {
            list->pxIndex = list_item;
        }
        else
        {
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = list_item;
        }
        list->uxNumberOfItems++;
        list_item->xItemValue = item_value + 1;
        list_item->next = NULL;
    }
    else
    {
        printf("list or list_item is null\n");
        return -1;
    }
    return 0;
}

List_Item_t* linkListGet(List_t *list, int elem)
{
    List_Item_t *p = list->pxIndex;
    if(p == NULL)
    {
        printf("list is null\n");
        return NULL;
    }
    while (p != NULL)
    {
        if(p->elem == elem)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    printf("not find node\n");
    return NULL;
}