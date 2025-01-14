/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode dummy(0); //使用哑节点来简化链表操作
        ListNode *p = l1, *q = l2, *current = &dummy;

        int carry = 0;

        while(p!=nullptr || q!=nullptr || carry > 0){//carry > 0是防止最后一位有进位的时候
            int x = (p!=nullptr) ? p->val:0;
            int y = (q!=nullptr) ? q->val:0;

            int sum = x + y + carry;
            carry = sum/10;
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;
        
            if(p!=nullptr) p = p->next;
            if(q!=nullptr) q = q->next;
        }
        
      
        return dummy.next;

    }
};