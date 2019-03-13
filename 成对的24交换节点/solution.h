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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* sec = head->next;
        ListNode* tmp = head->next->next;
        head->next = tmp;
        tmp =head;
        head = sec;
        head ->next = tmp;
        while(tmp -> next!=NULL && tmp->next->next!=NULL)
       {
           ListNode* a = tmp->next;
            ListNode*b = a->next;
            ListNode*c = b->next;
            tmp->next = b;
            b->next = a;
            a->next = c;
            tmp = a;
        }
        return head;
    }
};
