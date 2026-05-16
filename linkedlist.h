#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct stu{
    int id;
    int num;
    char name[20];
    float score;
}data_t;

typeof struct node{
    data_t data;
    struct node *next;
}Node_t;


#endif


