#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct {
	char hoten[30];
	int masv;
	float diemtb;
}Data;

typedef struct tagNode{
	Data infor;
	struct tagNode *next,*prev;
}Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}DList;

void initList(DList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

int emptyList(DList L){
	return(L.spt==0);
}

void insert_Head(DList *L,Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	if(pp==NULL) return;	
	pp->infor = x;
	pp->next = NULL;
	pp->prev = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}else{
		L->pHead->prev = pp;
		pp->next = L->pHead;
		L->pHead = pp;
	}
	L->spt++
}

void insert_Tail(DList *L,Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->next = NULL;
	pp->prev = NULL;
	if(emptyList(*L)){
		L->pHead =pp;
		L->pTail = pp;
	}else{
		L->pTail->next = pp;
		pp->prev = L->pTail;
		L->pTail = pp;
	}
	L->spt++;	
}

void insert_After(DList *L,Node *q,Data x){
	Node *pp;
	if(q==NULL) return;
	else{
		pp = (Node*)malloc(sizeof(Node));
		pp->infor = x;
		pp->prev = q;                
		q->next->prev = pp;				
		pp->next = q->next;			 
		q->next = pp;			 
		if(L->pTail == q){
			L->pTail = pp;
		}
	}
	L->spt++;
}

void del_Head(DList *L){
	if(emptyList(*L)) return;
	else{
		if(L->pHead == L->pTail){
			L->pHead = NULL;
			L->pTail = NULL;
		}
		L->pHead = L->pHead->next;
		L->pHead->next->prev = NULL;
	}
	L->spt--;
} 

