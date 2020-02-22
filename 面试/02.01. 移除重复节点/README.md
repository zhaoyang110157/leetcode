# 题目

![img](./image/q.png)
![img](./image/q1.png)

# 算法

```python

```

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = NULL;
        ListNode* tmp = NULL;
        while(p1 != NULL)
        {
            tmp = p1;
            p2 = p1->next;
            while(p2 != NULL)
            {
                if(p1->val == p2->val)
                {
                    tmp->next = p2->next;
                }
                else
                {
                    tmp = p2;
                }
                p2 = tmp->next;
            }
            p1 = p1->next;
        }
        return head;
    }
};
```

