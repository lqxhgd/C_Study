#include "list.h"

List_t *data_list = NULL;
List_Item_t *item_arr[10] = {0};

int main(void)
{
    int ret = 0;
    printf("hello world\n");
    ret = initLinkList(&data_list);
    if(ret != 0)
    {
        printf("initLinkList error\n");
        return ret;
    }

    for(uint8_t i = 0; i < 20; i++)
    {
        List_Item_t *item = NULL;
    
        ret = initLinkListItem(&item);
        item->elem = i;
        if(ret != 0)
        {
            printf("initLinkListItem error\n");
            return ret;
        }
        if(LinkListInsert(data_list,item) != 0) break;
        item_arr[i] = item;
    }
    if(linkListGet(data_list, 5) == NULL)
    {
        printf("linkListGet error\n");
    }
    else
    {
        printf("linkListGet ok\n");
    }
    printf("main end");
    return 0;
}