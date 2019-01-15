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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode((l1->val+l2->val)%10);
        ListNode* key = result;
        int next =(l1->val+l2->val)/10;
        while(l1->next||l2->next||next)
        {
            int tmp = next;
            if(l1->next) {
                tmp+=l1->next->val;
                l1 = l1->next;
            }
            if(l2->next) {
                tmp+=l2->next->val;
                l2 = l2->next;
            }
            next = tmp/10;
            tmp %=10;
            ListNode* re = new ListNode(tmp);
            key->next = re ;
            key = re;
        } 
        return result;
    }
};
