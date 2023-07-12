#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int SQDataType;
typedef struct SeqList
{
    SQDataType* a;
    int size;                 //有效数据个数
    int capacity;             //容量空间大小
}SL;
void SeqListInit(SL* ps);          //顺序表初始化
void SeqListCheckCapacity(SL* ps);       //检测是否需要扩容
void SeqListPushFront(SL* ps,SQDataType x);    //头插
void SeqListPushBack(SL* ps,SQDataType x);     //尾插
void SeqListPopBack(SL* ps);                   // 尾删
void SeqListPopFront(SL* ps);                  //头删
void SeqListInsert(SL* ps,int pos,SQDataType x);        // 插入
void SeqListPrint(SL* ps);                              //打印数组
void SeqListEarse(SL* ps,int pos);                      //删除下标元素
void SeqListDestory(SL* ps);                            //回收使用后的空间
int SeqListFind(SL* ps,SQDataType x);                   //查找元素下标
void SeqListModify(SL* ps,int pos,SQDataType);          //修改下标元素