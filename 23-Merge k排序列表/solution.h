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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i=0;
        while(i<lists.size())
        {
            if(lists[i] == NULL)
            {
                lists.erase(lists.begin()+i);
                --i;
            }
            ++i;
        }
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 0) return NULL;
        ListNode* res = new ListNode(0);
        ListNode* now = res;
        while(lists.size() > 1)
        {
            int a(lists[0]->val),b(0);
            for(int i=1;i<lists.size();i++)
            {
                if(lists[i]->val < a)
                {
                    a = lists[i]->val;
                    b = i;
                }
            }
            now->val = a;
            ListNode* n = new ListNode(0);
            now->next = n;
            now = n;
            if(lists[b]->next)
            {
                lists[b] = lists[b]->next;
            }
            else {
                lists.erase(lists.begin()+b);
            }
        }
        now->val = lists[0]->val;
        now->next = lists[0]->next;
        
        return res;
    }
};
