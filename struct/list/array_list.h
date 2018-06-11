typedef struct alist *List;
typedef int ListItem;
typedef struct alist {
	int n;
	int maxsize;
	ListItem *table;
}AList;
List ListInit(int size); /* 表结构初始化 */
int ListEmpty(List L); /* 判断表是否为空 */
int ListLength(List L); /* 求数组的长度 */
ListItem ListRetrieve(int k, List L); /* 返回表 L 的位置 k 处的元素 */
int ListLocate(ListItem x, List L); /* 元素 x 在 L 中的位置 */
void ListInsert(int k, ListItem x, List L); /* 在表 L 的位置 k 处插入元素 x*/
ListItem ListDelete(int k, List L); /* 从表 L 删除位置 k 的元素 */
void PrintList(List L); /* 打印表: L */

