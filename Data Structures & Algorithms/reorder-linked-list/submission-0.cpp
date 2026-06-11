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
    void reorderList(ListNode* head) {
        /*so its like [first element, last element, second ele, second ele, third ele, 
        last third] and so on so its [0,n-1,1,n-2,2,n-3,3,n-4.....]
        so now the approach would be since we cannot use an index because its not an array
        so primarily what we do have are ethe pointer variables like head, head->next,
        head-> next->next so we can use recursion to do the repeated 0,n-1,1,n-2,2
        so its like current,(size-1)-current until u reach a point where n-1-current=current
        but for some reason which is overflow we cannot use recurrsion, so use slow and fast 
        pointers.
        so the approch is to find the centre using slow and fast so if fast==NULL return slow
        that will be the centre of the list and then we reverse the second half and then merge
        now reversing is using current and prev and merging is using  */
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* head2;
        
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        head2=slow->next; 
        slow->next=nullptr;
        /*now reverse the second half*/
        ListNode* curr=head2;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            /*now merge the two*/
        
        
       while(head != nullptr && prev != nullptr){
                ListNode* tmp1 = head->next;
                ListNode* tmp2 = prev->next;
                head->next = prev;
                prev->next = tmp1;
                head = tmp1;
                prev = tmp2;
}
                
            
            
    }
        

};
