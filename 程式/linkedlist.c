#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lnode{
	int key;
	struct lnode *next;
};

struct lnode *l_insert(struct lnode *L,int key);
void l_find(struct lnode *L,int key);

struct lnode *linkedlist_insert(struct lnode *L,int a[],int len)
{
	struct lnode *head = L;
	int i;
	for(i=0;i<len;i++){
		head = l_insert(head,a[i]);
	}
	return head;
}

void linkedlist_find(struct lnode *L,int b[],int findlen)
{
	struct lnode *head = L;
	int i;
	for(i=0;i<findlen;i++){
		l_find(head,b[i]);
	}
}

struct lnode *l_insert(struct lnode *L,int key)
{
	struct lnode *p;
	p = (struct lnode *)malloc(sizeof(struct lnode));
	p->key = key;
	p->next = L;

	return p;
}

void l_find(struct lnode *L,int key)
{
	struct lnode *p = L;
	while(p){
		if(p->key == key){
			return;
		}
		p = p->next;
	}
	return;
}