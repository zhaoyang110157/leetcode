You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

To solve this problem, we might refer to full adder.
We add each node at the same level and get the carry bit.
The cycle stops only when both l1 and l2 have no more node and the carry bit is 0. 
