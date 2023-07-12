#include "add.h"
void TestSeqList1()
{
    SL s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1,1);
    SeqListPushBack(&s1,2);
    SeqListPushBack(&s1,3);
    SeqListPushBack(&s1,4);
    SeqListPushFront(&s1,0);
    SeqListEarse(&s1,3);
    SeqListPrint(&s1);
}

int main()
{   
    TestSeqList1();
    return 0;
}       
