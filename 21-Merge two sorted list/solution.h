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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int fint; 
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;//防止有空指针出现调用不了val
        if(l1->val<l2->val)
        {
            fint = l1->val;
            l1 = l1->next;
        }
        else{
            fint = l2->val;
            l2 = l2->next;
        }
        ListNode* head = new ListNode(fint);
        ListNode* tmp = head;
        while( l1 != NULL || l2 !=NULL)
        {
            int a = (l1 == NULL )? INT_MAX : l1->val;
            int b = (l2 == NULL )? INT_MAX : l2->val;
            if(a<b)
            {
                fint = a;
                l1 = l1->next;
            }
            else{
            fint = b;
            l2 = l2->next;
            }
            ListNode* next = new ListNode(fint);
            tmp->next = next;
            tmp = next;
        }
        return head;
    }
};
