class LRUCache {
public:

    class Node {   /*doubly linked list node* next and prev and int me key value pairs ka data in class node*/
        public: /*this is the doubly linked list node struct*/
        int key,val;
        Node* prev;
        Node* next;
        Node(int k, int v ){ /*constructor*/
            key=k;
            val=v;
            prev=next=NULL;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mpp;
    int limit;
    void addNode(Node* newNode){
                Node* oldnext=head->next;
                head->next=newNode;
                oldnext->prev=newNode;
                newNode->next=oldnext;
                newNode->prev=head;
        }
    void delNode(Node* oldnode){
        Node* oldPrev=oldnode->prev;
        Node* oldnext=oldnode->next;

        oldPrev->next=oldnext;
        oldnext->prev=oldPrev;
    }



    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {//to get the keys value 
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* ansNode=mpp[key];
        int ans=ansNode->val;
        mpp.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        mpp[key]=ansNode;
        return ans;
        
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* oldnode=mpp[key];
            delNode(oldnode);
            mpp.erase(key);
        }
        if(mpp.size()==limit){
            /*cache cap rwached*/
            /*delete lru data*/
            mpp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addNode(newNode);
        mpp[key]=newNode;
        

        
    }
};
