/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(nullptr == root){
            return ans;
        }
        ans.push_back(root->val);
        for(auto elem : root->children){
            preorder(elem);
        }
        return ans;
    }

private:
    vector<int> ans;
};