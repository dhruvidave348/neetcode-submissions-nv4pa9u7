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
    struct compare {
    bool operator()(ListNode* a, ListNode* b) {
         return a->val>b->val; //priority=value,higher means less important
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;

        //put all heads in heap
        for( ListNode* head : lists){  //for head in lists
            if(head!=nullptr){
                minHeap.push(head);
            }


        } 
        ListNode dummy(0); //dont need star bcoz its not a pointer its an object/Node
        ListNode* tail= &dummy; //address of dummy to know the starting point
        while(!minHeap.empty()){
            ListNode* node=minHeap.top();
            minHeap.pop();
            tail->next=node;//set next smallest ele as smallest after popping smallest
            tail=tail->next;
            if(node->next){//push everything after the smallest ele in the lists
                minHeap.push(node->next);

            }
            
        }
        return dummy.next;

        
    }
};
