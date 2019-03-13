 class Solution {
 public:
	 ListNode* swapPairs(ListNode* head) {
		 if (!head||!head->next)
			 return head;
		 ListNode* p = head;
		 head = head->next;
		 p->next = head->next;
		 head->next = p;
		 p->next = swapPairs(p->next);
		 return head;
	 }
 };
//递归想法
