#include<stdio.h>
#include<stdlib.h>

void array_insert(int a[],int len,int b[])
{
	int i;
	for(i=0;i<len;i++){
		a[i] = b[i];
	}
}

void array_find(int a[],int len,int b[],int findlen)
{
	int i, j;
	for(j=0;j<findlen;j++){
		for(i=0;i<len;i++){
			if(a[i]==b[j]){
				break;
			}
		}
	}
}