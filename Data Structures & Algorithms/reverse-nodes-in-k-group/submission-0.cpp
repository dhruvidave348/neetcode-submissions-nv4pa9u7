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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        
        int count=0;
        while(count<k && curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
            
        }
        if(count==k){
            head->next=reverseKGroup(curr,k);
            return prev;
        }
        curr=prev;
        prev=nullptr;
        while(count--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;





        
    }
};
