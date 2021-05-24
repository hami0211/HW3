#include<stdio.h>
#include<stdlib.h>

struct dnode{
	int key;
	struct dnode *next;
};

void h_insert(struct dnode **hTab,int maxhash,int key);
void h_find(struct dnode **hTab,int maxhash,int key);
struct dnode *L_insert(struct dnode *L,int key);
void L_find(struct dnode *L,int key);

int hash17(int a,int len)
{
	int b = (a * 17) % len;
	return b;
}

struct dnode **hash_insert(struct dnode **hTAB,int a[],int len)
{
	int i;
	int maxhash = len;
	struct dnode **hTab = hTAB;
	hTab = (struct dnode **)malloc(sizeof(struct dnode *)*maxhash);
	for(i=0;i<maxhash;i++){
		hTab[i] = NULL;
	}
	for(i=0;i<maxhash;i++){
		h_insert(hTab,maxhash,a[i]);
	}
    return hTab;
}

void hash_find(struct dnode **hTAB,int len,int b[],int findlen)
{
	int i;
	int maxhash = len;
	struct dnode **hTab = hTAB;
	for(i=0;i<findlen;i++){
		h_find(hTab,maxhash,b[i]);
	}
}

void h_insert(struct dnode **hTab,int maxhash,int key)
{
	int hv;
	struct dnode *L;
	hv = hash17(key,maxhash);
	L = hTab[hv];
	hTab[hv] = L_insert(L,key);
}

void h_find(struct dnode **hTab,int maxhash,int key)
{
	int hv;
	struct dnode *L;
	hv = hash17(key,maxhash);
	L = hTab[hv];
	L_find(L,key);
}

struct dnode *L_insert(struct dnode *L,int key)
{
	struct dnode *p;
	p = (struct dnode *)malloc(sizeof(struct dnode));
	p->key = key;
	p->next = L;

	return p;
}

void L_find(struct dnode *L,int key)
{
	struct dnode *p = L;
	while(p){
		if(p->key == key){
			return;
		}
		p = p->next;
	}
	return;
}