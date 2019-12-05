/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode l(0);
        ListNode* ptr = &l;
        while(l1&&l2){
            if(l1->val <= l2->val){
                ptr->next= l1;
              //  ptr = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                //ptr = l2;
                l2 = l2->next;
            }
            ptr =ptr->next;
        }
            if(l1){
                ptr->next = l1;
            }
            if(l2){
                ptr->next = l2;
            }
        
            return l.next;
    }
    
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        if(lists.size()==2){
            return mergeTwoLists(lists[0],lists[1]);
        }
        int mid = lists.size()/2;
        vector<ListNode*> sub_list1;
        vector<ListNode*> sub_list2;
        for(int i = 0;i<mid;i++){
            sub_list1.push_back(lists[i]);
        }
        for(int i = mid;i<lists.size();i++){
            sub_list2.push_back(lists[i]);
        }
         ListNode* l1 = mergeKLists(sub_list1);
         ListNode* l2 = mergeKLists(sub_list2);
        return  mergeTwoLists(l1,l2);
    }
};
