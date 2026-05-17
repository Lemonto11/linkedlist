#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

//创建链表
Node_t* createlist(){
    Node_t* head = (Node_t*)malloc(sizeof(Node_t));
    if(NULL == head) return NULL;
    head -> next = NULL;
    return head;
}

//求长度
int listLength(Node_t* head){
    if(NULL==head) return -1;
    int len = 0;
    Node_t *p = head;
    while(p->next){
	len++;
	p = p->next;
    }
    return len;

}
//插入
void insertList(Node_t* head, int pos, data_t data){
    if(NULL==head) return;
    int len = listLength(head);
    if(pos<0 || pos>len) return;

    Node_t* new= (Node_t*)malloc(sizeof(Node_t));
    if(NULL==new) return;

    Node_t* p = head;

    new -> data = data;
    new -> next = NULL;

    while(pos--){
	p = p->next;
    }
    
    new -> next = p -> next;
    p -> next = new;
    
}

//按位置删除结点
void deleteNode(Node_t* head, int pos){
    if(NULL==head) 
	return;

    int len = listLength(head);
    if(pos<0||pos>len)
	return;
    Node_t* p = head;

    while(pos--){
	p = p->next;
    }
    Node_t* temp = p->next;
    p->next = temp->next;
    free(temp);
    temp = NULL;
}

//按学号查找
Node_t* searchByNum(Node_t* head, int target){
    if(NULL==head)
    	return NULL;
    Node_t* p = head;
    while(p){
    	if(p->data.num==target){
		return p;
	}
	p = p -> next;
    }
    return NULL;
}

//修改
int modify(Node_t *head, int target, data_t data){
    if(NULL==head)
        return -1;
    Node_t* p = searchByNum(head, target);
    if(p==NULL) return -1;

    p->data = data;

    return 0;
}

//逆序
void reverseList(Node_t* head){
    if(NULL==head) return;
    Node_t* p = head ->next;//存第一个元素
    head -> next = NULL;//断开头指针
    Node_t* q = NULL;
    while(p){
	q = p->next;//存下一个元素
	p->next = head->next;//把p放到末尾
	head -> next = p;//和头指针连接
	p = q;
    }
    return;
}


//插入排序
Node_t *insertSort(Node_t* head){
    if(NULL==head) return NULL;
    Node_t* curr = head->next;
    Node_t* sorted = NULL;
    Node_t* next = NULL;
    while(curr){
        next = curr -> next;
	if(sorted == NULL||curr->data.num < sorted->data.num){
		curr -> next = sorted;
		sorted = curr;
	}
	else{
		Node_t *p = sorted;
		while(p->next && p->next->data.num < curr->data.num){
			p = p->next;
		}
		curr->next = p->next;
		p->next = curr;
	}
	curr = next;
    }
    Node_t* newHead = (Node_t*)malloc(sizeof(Node_t));
    if (NULL == newHead) return sorted;  // 如果分配失败，返回无头结点版本
    newHead->next = sorted;
    return newHead; 

}

//两个有序链表合并
    
//遍历打印输出
void showList(Node_t* head){
    if(NULL==head) return;
    Node_t* p = head->next;
    while(p){
	printf("%d %d %s %.1f\n", p->data.id, p->data.num, p->data.name, p->data.score);
	p = p->next;
    }
    
}
