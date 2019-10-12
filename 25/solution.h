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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        
        ListNode *fst = NULL, *snd = NULL;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode * tmp = start;
        while(tmp->next != NULL){
            if(cnt == 0){
                fst = tmp;
            }
            cnt++;
            if(cnt == k){
                cnt = 0;
                snd = tmp->next;
                ListNode * a = fst->next;
                ListNode * b = a->next;
                ListNode * c = b->next;
                fst->next = c;
                c->next = b;
                b->next = a;
                a->next = snd;
            }
            tmp = tmp->next;
        }
        return start->next;
    }
};