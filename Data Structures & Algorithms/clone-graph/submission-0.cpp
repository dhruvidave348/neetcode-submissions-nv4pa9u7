/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

         unordered_map<Node*, Node*> mp;

         return dfs(node,mp);

        

        
    }

    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp){
        if(mp.find(node)!=mp.end()) return mp[node];
        if(node==nullptr) return node;

        Node* dc= new Node(node->val);

        mp[node]=dc;

        for(Node* neighbor:node->neighbors){
            dc->neighbors.push_back(dfs(neighbor,mp));
        }
        return dc;





    }
};
