#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main(){
    Node_t *head = createlist();
    int len = listLength(head);
    printf("len = %d\n", len);

    data_t stu0 = {0, 56, "xiaoming", 90};
    data_t stu1 = {1, 72, "xiaodong", 80};
    data_t stu2 = {2, 44, "xiaohong", 97.5};
    data_t stu3 = {3, 89, "xiaox", 68};

    printf("插入------------------\n");
    insertList(head, 0, stu0);
    insertList(head, 1, stu1);
    insertList(head, 2, stu2);
    insertList(head, 3, stu3);

    showList(head);

    printf("删除-------------------\n");
    deleteNode(head, 0);
    showList(head);


    printf("查找-------------------\n");
    Node_t *p = searchByNum(head, 44);
    printf("%d %d %s %.1f\n", p->data.id, p->data.num, p->data.name, p->    data.score);
    
    printf("修改-------------------\n");
    modify(head, 72, stu0);
    showList(head);
  
    printf("逆序------------------\n");
    reverseList(head);
    showList(head);

    printf("插入排序--------------\n");
    Node_t* new = insertSort(head);
    showList(new);



    return 0;
}
