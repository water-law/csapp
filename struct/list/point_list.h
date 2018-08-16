typedef struct node *link;
typedef int ListItem;
typedef struct node {
    ListItem element;
    link next;
}Node;

link NewNode();  // 节点初始化

typedef struct llist *List;
typedef struct llist {  // 指针结构
   link first;
}Llist;

List ListInit();  // 创建空表
int ListEmpty();  // 判断表是否为空
int ListLength(List L);  // 表长度
ListItem ListRetrieve(int k, List L);  // 取出表第 k 个元素
int ListLocate(ListItem x, List L);  // 获取元素 x 在表中的位置
void ListInsert(int k, ListItem x, List L);  // 往表位置 k 插入元素 x
List ListDelete(int k, List L);  // 删除表位置 k 的元素
void PrintList(List L);  // 打印表
