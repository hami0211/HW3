#include<stdio.h>
#include<stdlib.h>

void Binary_Search(int a[],int len,int key);

int compare(const void *a,const void *b)
{
    int c = *(int *)a;
    int d = *(int *)b;
    if(c==d){return 0;}
    else if(c>d){return 1;}
    else{return -1;}
}

void Binary_Search_insert(int a[],int len,int b[])
{
    int i;
    for(i=0; i<len; i++){
        a[i] = b[i];
    }
    qsort(a,len,sizeof(int),compare);
}

void Binary_Search_find(int a[],int len,int b[],int findlen)
{
    int j;;
    for(j=0;j<findlen;j++){
        Binary_Search(a,len,b[j]);
    }
}

void Binary_Search(int a[],int len,int key)
{
    int i = len;
    int low =0;
    int upper = i-1;
    int mid;
 
    while( low < upper-1 ){
        mid = (low+upper)/2;
        if( a[mid] == key ){
            return;
        }else if( a[mid] < key ){
            low = mid;
        }else{
            upper = mid;
        }
    }
}