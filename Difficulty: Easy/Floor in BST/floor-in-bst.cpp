/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
       int ans = -1;
       while(root){
           if(root->data == k){
               ans = root->data;
               return ans;
           }
           if(k > root->data){
               ans = root->data;
               root = root->right;
           }else root = root->left;
       }
       return ans;
    }
};