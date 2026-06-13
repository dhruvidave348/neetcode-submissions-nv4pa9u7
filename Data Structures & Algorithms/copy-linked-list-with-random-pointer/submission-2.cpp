/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*1. make a simple copy of the given linked list with just the heads
  2. use oldtemp and newtemp pointers */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*> m;
        m[nullptr] = nullptr;
        Node* newhead=new Node(head->val);
        Node* oldtemp=head->next;
        Node* newtemp=newhead;
        
        m[head]=newhead;
        
        while(oldtemp!=NULL){
            
            
            Node* copynode=new Node(oldtemp->val);
            m[oldtemp]=copynode;
            newtemp->next=copynode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        newtemp=newhead;
        oldtemp=head;
        while(oldtemp!=nullptr){
            newtemp->random=m[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;

        
        
    }
};
