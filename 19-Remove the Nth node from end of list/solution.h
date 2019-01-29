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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next ) return NULL;
        ListNode* first = head;
        for(int i = 0 ;i<n;++i)/**/
        {
            first = first->next;
        }
        ListNode* third = head;
        ListNode* second = head->next;
        if(first == NULL ) return head->next;/**/
        first = first->next;
        while(first != NULL)
        {
            first = first->next;
            second = second->next;
            third = third->next;
        }
        third->next = second->next;
        delete second;
        return head;
    }
};
/*双指针，
同时注意，为了防止删除头指针，要进行一定处理 在/**/位置
*/
