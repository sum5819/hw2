#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ElementType int
#define int32 unsigned int

typedef struct lnode{
	int key;
	struct lnode *next;
}Node;

typedef struct TNode * Position;   
typedef Position BinTree;    
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

struct dnode{
	int key;
	struct dnode *next; 
};

Node *ll_insert(Node *l,int key){
	Node *p;
	p=malloc(sizeof(Node));
	p->key=key;
	p->next=l;
	return p;
}

void ll_query(Node *l,int q){
	while(l){
		if(l->key==q) break;
		else l=l->next;
	}
}

void arr_insert(int *arr,int d,int *arr_d){
	for(int i=0;i<d;i++){
		arr_d[i]=arr[i];
	}
}

void arr_query(int *arr_d,int q,int d,int *arr_q){
	for(int i=0;i<q;i++){
		for(int j=0;j<d;j++){
			if(arr_q[i]==arr_d[j]){
				continue;
			}
		}
	}
}

int my_cmp(const void *int1,const void *int2){
	const int *int1_ptr=(const int *)int1;
	const int *int2_ptr=(const int *)int2;
	return *int1_ptr - *int2_ptr;
}

void bs_insert(int *arr,int d,int *arr_d){
	for(int i=0;i<d;i++){
		arr_d[i]=arr[i];
	}
	qsort(arr_d,d,sizeof(int),my_cmp);
}

int bs_query(int *arr_d,int target,int d){
	int low = 0; 
	int upper = d-1; 
	int mid;
	while (low <= upper){
		mid = (low + upper) / 2;
		if (arr_d[mid] == target){
			return mid;
		}
		else if (arr_d[mid] > target){
			upper = mid - 1;
		}
		else if (arr_d[mid] < target){
			low = mid + 1;
		}
	}
	return -1;
}

Position bst_query(BinTree BST, ElementType X){
	if(!BST) return NULL;	        
	if(X>BST->Data)
		return bst_query(BST->Right,X);
	else if(X<BST->Data)
		return bst_query(BST->Left,X); 
	 else
		 return BST;          
}

BinTree bst_insert(BinTree BST,ElementType X){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if(X<BST->Data) 
			BST->Left = bst_insert(BST->Left,X);
		else
			BST->Right = bst_insert(BST->Right,X);
	}
	return BST;
}

struct dnode *l_insert(struct dnode *L,int key){
	struct dnode *p;
	p=(struct dnode *)malloc(sizeof(struct dnode));
	p->key=key;
	p->next=L;
	return p;
}

struct dnode *l_query(struct dnode *L,int key){
	struct dnode *p;
	if(L==NULL) return NULL;
	p=L;
	while(p){
		if(p->key==key) return p;
		p=p->next;
	}
	return NULL;
}

void hash_insert(struct dnode **hTab,int maxHash,int key){
	int32 hv;
	struct dnode *dptr;
	hv=key%maxHash;
	dptr=hTab[hv];
	hTab[hv]=l_insert(dptr,key);
}

struct dnode *hash_query(struct dnode **hTab,int maxHash,int key){
	int32 hv;
	struct dnode *dptr;
	hv=key%maxHash;
	dptr=hTab[hv];
	return l_query(dptr,key);
}



