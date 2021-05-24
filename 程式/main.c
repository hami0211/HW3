#include"array.h"
#include"BinarySearch.h"
#include"BST.h"
#include"linkedlist.h"
#include"hash.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>
#define	TRUE	1
#define False	0

void ARRAY(int random[],int len,int Finding[],int Findlen);
void BINARYSEARCH(int random[],int len,int Finding[],int Findlen);
void LINKEDLIST(int random[],int len,int Finding[],int Findlen);
void BST(int random[],int len,int Finding[],int Findlen);
void HASH(int random[],int len,int Finding[],int Findlen);

struct lnode{
	int key;
	struct lnode *next;
};

struct tnode{
	int key;
	struct tnode *lchild;
	struct tnode *rchild;
};

struct dnode{
	int key;
	struct dnode *next;
};

int main(int argc,char **argv){
	int len = 0;
	int Findlen = 0;
	int Findrange;
	int i;
	int array = False;
	int BinarySearch = False;
	int linkedList = False;
	int bst = False;
	int hash = False;

	//指令判斷
	for(i=1;i<argc;i++){
		if(argv[i][0] == '-'){
			if(argv[i][1] == 'd'){
				i++;
				if(argv[i][2]=='4'){
					len = 10000;
				}
				else if(argv[i][2]=='5'){
					len = 100000;
				}
				else if(argv[i][2]=='6'){
					len = 1000000;
				}
			}
			else if(argv[i][1] == 'q'){
				i++;
				if(argv[i][2]=='3'){
					Findlen = 1000;
				}
				else if(argv[i][2]=='4'){
					Findlen = 10000;
				}
				else if(argv[i][2]=='5'){
					Findlen = 100000;
				}
			}
			else if(argv[i][1] == 'b' && argv[i][2] == 's'){
				if(argv[i][3] == 't'){
					if(argv[i][4] == '\0'){
						bst = TRUE;
					}
				}
				else if(argv[i][3] == '\0'){
					BinarySearch = TRUE;
				}
			}
			else if(argv[i][1] == 'l' && argv[i][2] == 'l' && argv[i][3] == '\0' ){
				linkedList = TRUE;
			}
			else if(argv[i][1] == 'a' && argv[i][2] == 'r' && argv[i][3] == 'r' && argv[i][4] == '\0'){
				array = TRUE;
			}
			else if(argv[i][1] == 'h' && argv[i][2] == 'a' && argv[i][3] == 's' && argv[i][4] == 'h' && argv[i][5] == '\0'){
				hash = TRUE;
			}
		}
	}
	Findrange = len*2;

	//製造N筆唯一資料
	int *random;
	int change;
	int pos;
	random = (int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++){
		random[i] = i+1;
	}
	srand(time(NULL));
	for(i=0;i<len;i++){
		pos = rand() % len;
		change = random[i];
		random[i] = random[pos];
		random[pos] = change;
	}

	//製造M筆隨機資料
	int Finding[Findlen];
	for(i=0;i<Findlen;i++){
		Finding[i] = rand() % Findrange + 1;
	}


	//資料結構實作
	if(array){
		ARRAY(random,len,Finding,Findlen);
	}

	if(BinarySearch){
		BINARYSEARCH(random,len,Finding,Findlen);
	}

	if(linkedList){
        LINKEDLIST(random,len,Finding,Findlen);
	}

	
	if(bst){
        BST(random,len,Finding,Findlen);
	}

	
	if(hash){
        HASH(random,len,Finding,Findlen);
	}


	return 0;
}

void ARRAY(int random[],int len,int Finding[],int Findlen)
{
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    int arr[len];
    gettimeofday(&start, NULL);
	array_insert(arr,len,random);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  
    printf("arr:\n");
    printf("build: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    
	gettimeofday(&start, NULL);
	array_find(arr,len,Finding,Findlen);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;   
    printf("query: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}

void BINARYSEARCH(int random[],int len,int Finding[],int Findlen)
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    int BSarr[len];
    gettimeofday(&start, NULL);
	Binary_Search_insert(BSarr,len,random);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("BinarySearch:\n");
	printf("build: %ld us (equal %f sec)\n", diff, diff / 1000000.0);

	gettimeofday(&start, NULL);
	Binary_Search_find(BSarr,len,Finding,Findlen);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}

void LINKEDLIST(int random[],int len,int Finding[],int Findlen)
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    struct lnode *head = NULL;
		gettimeofday(&start, NULL);
		head = linkedlist_insert(head,random,len);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("linkedlist:\n");
    	printf("build: %ld us (equal %f sec)\n", diff, diff / 1000000.0);

    	gettimeofday(&start, NULL);
		linkedlist_find(head,Finding,Findlen);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    	printf("query: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}

void BST(int random[],int len,int Finding[],int Findlen)
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    struct tnode *root = NULL;
		gettimeofday(&start, NULL);
		root = BST_insert(root,random,len);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("BST:\n");
    	printf("build: %ld us (equal %f sec)\n", diff, diff / 1000000.0);

    	gettimeofday(&start, NULL);
		BST_find(root,Finding,Findlen);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    	printf("query: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}

void HASH(int random[],int len,int Finding[],int Findlen)
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    struct dnode **hash_arr;
		gettimeofday(&start, NULL);
		hash_arr = hash_insert(hash_arr,random,len);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("hash:\n");
    	printf("build: %ld us (equal %f sec)\n", diff, diff / 1000000.0);

    	gettimeofday(&start, NULL);
		hash_find(hash_arr,len,Finding,Findlen);
    	gettimeofday(&end, NULL);
    	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    	printf("query: %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}