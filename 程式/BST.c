#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
	int key;
	struct tnode *lchild;
	struct tnode *rchild;
};

struct tnode *t_insert(struct tnode *T,int key);
void t_find(struct tnode *T,int key);

struct tnode *BST_insert(struct tnode *T,int a[],int len)
{
	struct tnode *root = T;
	int i;
	for(i=0;i<len;i++){
		root = t_insert(root,a[i]);
	}
	return root;
}

void BST_find(struct tnode *T,int b[],int findlen)
{
	struct tnode *root = T;
	int i;
	for(i=0;i<findlen;i++){
		t_find(root,b[i]);
	}
}

struct tnode *t_insert(struct tnode *T,int key)
{
	struct tnode *p;
	if(T==NULL){
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->key = key;
		p->lchild = NULL; p->rchild = NULL;
		return p;
	}
	if(T->key > key){
		T->lchild = t_insert(T->lchild,key);
	}else{
		T->rchild = t_insert(T->rchild,key);	
	}

	return T;
}

void t_find(struct tnode *T,int key)
{
	if(T==NULL){return;}
	if(T->key==key){
		return;
	}
	if(T->key>key){
		t_find(T->lchild,key);
	}else{
		t_find(T->rchild,key);
	}
}