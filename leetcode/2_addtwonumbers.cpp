/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* checking on leetcode this is faster than 95% of other cpp submissions
 * looking at my python3 implementation which was 95% slower than other
 * python implementation =(, this is more focused on performance than
 * readability.
*/
class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//pointers to l1 and l2
    ListNode *i = l1, *j = l2;
    ListNode *res = new ListNode(0);
    ListNode *head = res;
    int carry = 0;
		// smarter approach, iterate through all of l1 then l2,
		// if l1 becomes NULL, finish l2 adding.
    while (i != NULL){
        if (j != NULL){
            int val = ((i->val)+(j->val)+carry)%10;
						// rather than adding branches to mess with pipeline prediction
						// use divide
            carry = ((i->val)+(j->val)+carry)/10;
            res->next = new ListNode(val);
            j = j->next;
        } else {
            //j is NULL so iterate rest of i
            int val = ((i->val)+carry)%10;
            carry = ((i->val)+carry)/10;
            res->next = new ListNode(val);
        }
        res = res->next;
        i = i->next;
    }
    while (j != NULL){
        int val = ((j->val)+carry)%10;
        carry = ((j->val)+carry)/10;
        res->next = new ListNode(val);
        res = res->next;
        j = j->next;
    }
		// shorthand for change into to bool and handle carry case
    if (!!carry){ 
        res->next = new ListNode(1);
    }
    return head->next;
}
};
