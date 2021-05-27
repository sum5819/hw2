#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"myfile.h"
#define ElementType int
#define DEFMAXHASH 100000

int main(int argc,char **argv){
	if(argc>5){
		int d=1;
		int q=1;
		for(int i=0;i<argv[2][2]-48;i++){
			d=d*10;
		}
		for(int i=0;i<argv[4][2]-48;i++){
			q=q*10;
		}
		int arr[d];
		int arr_d[d];
		int arr_q[q];
		for(int i=0;i<d;i++){
			arr[i]=rand();
		}
		for(int i=0;i<q;i++){
			int j=rand()%d;
			arr_q[i]=arr[j];
		}
		for(int i=0;i<argc;i++){
			if(strcmp(argv[i],"-bst")==0){
 				BinTree BST = NULL;
				struct timeval start1,start2;
				struct timeval end1,end2;
				unsigned long diff1,diff2;

				gettimeofday(&start1,NULL);
				for(int i=0;i<d;i++){
					BST = bst_insert(BST,arr[i]);
				}
				gettimeofday(&end1, NULL);
				diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;

				gettimeofday(&start2,NULL);
				for(int i=0;i<q;i++){
					bst_query(BST,arr_q[i]);
				}
				gettimeofday(&end2, NULL);
				diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;

				printf("bst:\n");
				printf("building time %f sec\n",diff1/1000000.0);
				printf("query time %f sec\n\n",diff2/1000000.0);
			}
			if(strcmp(argv[i],"-bs")==0){
				struct timeval start1,start2;
				struct timeval end1,end2;
				unsigned long diff1,diff2;

				gettimeofday(&start1,NULL);
				bs_insert(arr,d,arr_d);
				gettimeofday(&end1, NULL);
				diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;

				gettimeofday(&start2,NULL);
				for(int i=0;i<q;i++){
					bs_query(arr_d,arr_q[i],d);
				}
				gettimeofday(&end2, NULL);
				diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;

				printf("bs:\n");
				printf("building time %f sec\n",diff1/1000000.0);
				printf("query time %f sec\n\n",diff2/1000000.0);
			}
			if(strcmp(argv[i],"-arr")==0){
				struct timeval start1,start2;
				struct timeval end1,end2;
				unsigned long diff1,diff2;

				gettimeofday(&start1,NULL);
				arr_insert(arr,d,arr_d);
				gettimeofday(&end1, NULL);
				diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;

				gettimeofday(&start2,NULL);
				arr_query(arr_d,q,d,arr_q);
				gettimeofday(&end2, NULL);
				diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;

				printf("arr:\n");
				printf("building time %f sec\n",diff1/1000000.0);
				printf("query time %f sec\n\n",diff2/1000000.0);
			}
			if(strcmp(argv[i],"-ll")==0){
				Node *list=NULL;
				struct timeval start1,start2;
				struct timeval end1,end2;
				unsigned long diff1,diff2;

				gettimeofday(&start1,NULL);
				for(int i=0;i<d;i++){
					list=ll_insert(list,arr[i]);
				}
				gettimeofday(&end1, NULL);
				diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;

				gettimeofday(&start2,NULL);
				for(int i=0;i<q;i++){
					ll_query(list,arr_q[i]);
				}
				gettimeofday(&end2, NULL);
				diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;

				printf("ll:\n");
				printf("building time %f sec\n",diff1/1000000.0);
				printf("query time %f sec\n\n",diff2/1000000.0);
			}
			if(strcmp(argv[i],"-hash")==0){
				struct dnode **hTab;
				struct dnode *dptr;
				int maxHash=DEFMAXHASH;
				hTab=(struct dnode **)malloc(sizeof(struct dnode *)*maxHash);
				for(int i=0;i<maxHash;i++){
					hTab[i]=NULL;
				}
				struct timeval start1,start2;
				struct timeval end1,end2;
				unsigned long diff1,diff2;
				gettimeofday(&start1,NULL);
				for(int i=0;i<d;i++){
					hash_insert(hTab,maxHash,arr[i]);
				}
				gettimeofday(&end1, NULL);
				diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;

				gettimeofday(&start2,NULL);
				for(int i=0;i<q;i++){
					dptr=hash_query(hTab,maxHash,arr_q[i]);
				}
				gettimeofday(&end2, NULL);
				diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
				printf("hash:\n");
				printf("building time %f sec\n",diff1/1000000.0);
				printf("query time %f sec\n\n",diff2/1000000.0);
			}
		}
		return 0;
	}
}
