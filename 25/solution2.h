/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<queue>
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        queue<ListNode*> temp;
        ListNode* start = head;
        for(int i = 0; i < k  ; i++){
            temp.push(head);
            head = head->next;
            if(i<k-1 && head == NULL)
                return start;
        }
        ListNode* re = reverseKGroup(head,k);
        
        for(int i = 0; i < k ; i++){
            start = temp.front();
            temp.pop();
            start->next = re;
            re = start;
        }
        return re;
    }
};