typedef int TreeItem;
typedef struct btnode *btlink;

struct btnode {
    TreeItem element;
    btlink left;
    btlink right;
} Btnode;

btlink NewBNode();

typedef struct binarytree *BinaryTree;

typedef struct binarytree {
    btlink root;
} BTree;

BinaryTree BinaryInit();

int BinaryEmpty(BinaryTree T);

TreeItem Root(BinaryTree T);

void MakeTree(TreeItem x, BinaryTree T, BinaryTree L, BinaryTree R);

TreeItem BreakTree(BinaryTree T, BinaryTree L, BinaryTree R);

void PreOrder(void(*visit)(btlink u), btlink t);

void InOrder(void(*visit)(btlink u), btlink t);

void PostOrder(void(*visit)(btlink u), btlink t);

void LevelOrder(void(*visit)(btlink u), btlink t);

void outnode(btlink t);

void PreOut(BinaryTree T);

void InOut(BinaryTree T);

void PostOut(BinaryTree T);

void LevelOut(BinaryTree T);

int Height(btlink t);
