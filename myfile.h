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
Node *ll_insert();
void ll_query();
void arr_insert();
void arr_query();
int my_cmp();
void bs_insert();
int bs_query();
Position bst_query();
BinTree bst_insert();
struct dnode *l_insert();
struct dnode *l_query();
void hash_insert();
struct dnode *hash_query();

