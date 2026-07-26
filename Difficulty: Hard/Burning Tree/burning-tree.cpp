/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution {
  public:
    int finddistance(map<Node*,Node*>&mpp,Node* res){
        queue<Node*>q;
        q.push(res);
        map<Node*,int> vis;
        vis[res] = 1;
        int maxi = 0;
        while(!q.empty()){
            int sz = q.size();
            int fl = 0;
            for(int i = 0;i < sz;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl = 1; 
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl = 1; 
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(mpp[node] && !vis[mpp[node]]){
                    fl = 1; 
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if(fl)maxi++;
        }
        return maxi;
    }
    Node* mapparent(Node* root,map<Node*,Node*>&mpp,int target){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target)res = node;
            q.pop();
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        map<Node*,Node*>mpp;
        Node* res = mapparent(root,mpp,target);
        int maxi = finddistance(mpp,res);
        return maxi;
    }
};