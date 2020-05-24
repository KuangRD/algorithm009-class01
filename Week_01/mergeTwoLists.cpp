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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head= new ListNode(-1);;
        ListNode *movePtr = head;
        while(l1 != nullptr && l2!= nullptr){
            if(l1->val < l2->val){
                movePtr->next = l1;
                l1 = l1->next;
            }
            else{
                movePtr->next = l2;
                l2 = l2->next;
            }
            movePtr = movePtr->next;
        }
        movePtr->next = l1 == nullptr? l2 : l1; 
        return head->next;
    }
};