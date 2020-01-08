**1. 合并两个有序链表**

https://leetcode-cn.com/problems/merge-two-sorted-lists/

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

```python
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

```c++
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{

	ListNode *dummy =  new ListNode(-1);
	ListNode *cur = dummy;
	while(l1 && l2)
	{
		if(l1->val < l2->val)
		{
			cur->next = l1;
			l1=l1->next;
		}
		else{
			cur->next=l2;
			l2=l2->next;
		}
		
		cur = cur->next;

	}
	cur->next=l1?l1:l2;
	return dummy->next;

}
```



**2. 删除链表的倒数第N个节点**

https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

示例：

```python
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

说明：

给定的 n 保证是有效的。



```c++
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        int numCount=0;
        while(head)
        {
            if(head->next==NULL)
            {
                numCount+=1;
                break;
            }
            numCount+=1;
            head = head->next;
        }
        if(numCount<=1)return temp->next=NULL;
        
        head = temp->next;
        int break_index =numCount-n;
        if(break_index==0)return temp->next->next;
        // printf(" --%d", break_index);
        for(int i =1; i <= numCount; ++i)
        {
            if(i == break_index)
                {
                 head->next=head->next->next;
                 break;   
                }
            else
                head=head->next;

            
        }
    
        return temp->next;

    }
```








**3. 旋转链表**

https://leetcode-cn.com/problems/rotate-list/

给定一个链表，旋转链表，将链表每个节点向右移动*k*个位置，其中*k*是非负数。

示例 1:

```python
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL

解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

示例 2:

```python
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL

解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

---

```c++
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL || k==0) return head;
    struct ListNode *p,*p1,*p2;
    p=p1=p2=head;
    int n=0;
    //计算链表长度
    while(p){
        n++;
        p=p->next;
    }
    k%=n;
    if(k>0){
        int n1=n-k;
        while(--n1){
            p2=p2->next;
        }
        p1=p2->next;
        p2->next=NULL;
        struct ListNode *head1=p1;
        while(p1&&p1->next){
            p1=p1->next;
        }
        p1->next=head;
        return head1;
        }
    return head;
}
```

