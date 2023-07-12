#include "add.h"
void SeqListInit(SL* ps)        //顺序表初始化
{
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;

}                             
void SeqListPushBack(SL* ps,SQDataType x)         //尾插
{
    SeqListCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}
void SeqListPushFront(SL* ps,SQDataType x)        //头插
{
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while(end >= 0)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[0] = x;
    ps->size++;

}
void SeqListPrint(SL* ps)                 //打印数组
{
   for(int i = 0;i<ps->size;i++)
   {
    printf("%d ",ps->a[i]);
   }
   printf("\n");
}
void SeqListCheckCapacity(SL* ps)          //检测是否需要扩容
{
     if(ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
        SQDataType* tmp = (SQDataType*) realloc(ps->a,newcapacity*sizeof(SQDataType));
        if(tmp == NULL)
        {
            printf("realloc failed\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity = newcapacity;
        }
    }
}
void SeqListPopBack(SL* ps)         // 尾删
{
  assert(ps->size > 0);
  ps->size--;
}
void SeqListPopFront(SL* ps)        //头删
{
    int start = 1;
    while(start < ps->size)
    {
      ps->a[start-1] = ps->a[start];
      start++;
    }
    ps->size--;
}
void SeqListInsert(SL* ps,int pos,SQDataType x)  // 插入
{
    assert(pos < ps->size);
    SeqListCheckCapacity(ps);
    int end = ps->size-1;
    while (end >= pos)
    {
        ps->a[end+1]=ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;   
}
void SeqListEarse(SL* ps,int pos)     //删除下标元素
{
    assert(pos < ps->size);
    int start = pos + 1;
    while(start < ps->size)
    {
        ps->a[start-1] = ps->a[start];
        start++;
    }
    ps->size--;
}
void SeqListDestory(SL* ps)  //回收使用后的空间
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
int SeqListFind(SL* ps,SQDataType x)  //查找元素下标
{
    int i = 0;
    for(i=0;i < ps->size;i++)
    {
        if (ps->a[i] == x)
        {
            return i;
        }
        
    }
    return -1;
}
void SeqListModify(SL* ps,int pos,SQDataType x) //修改下标元素
{
    assert(pos < ps->size);
    ps->a[pos] = x;
}