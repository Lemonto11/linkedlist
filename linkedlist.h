#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct stu{
    int id;
    int num;
    char name[20];
    float score;
}data_t;

typedef struct node{
    data_t data;
    struct node *next;
}Node_t;


//创建链表
Node_t* createlist();
//求长度
int listLength(Node_t* head);
//插入数据
void insertList(Node_t* head, int pos, data_t data);
//按位置删除结点
void deleteNode(Node_t* head, int pos);
//按学号查找
Node_t* searchByNum(Node_t* head, int target);
//修改
int modify(Node_t *head, int target, data_t data);
//逆序
void reverseList(Node_t* head);
//插入排序
Node_t *insertSort(Node_t* head);
//打印
void showList(Node_t* head);

#endif


