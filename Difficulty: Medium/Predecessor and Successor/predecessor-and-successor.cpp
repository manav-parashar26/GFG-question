/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	public:
	vector<Node*> findPreSuc(Node* root, int key) {
		Node* pre = nullptr;
		Node* suc = nullptr;
		
		Node* cur = root;

		while (cur) {
			if (key <= cur->data)
				cur = cur->left;
			else {
				pre = cur;
				cur = cur->right;
			}
		}
		
		cur = root;
		
		while (cur) {
			if (key >= cur->data)
				cur = cur->right;
			else {
				suc = cur;
				cur = cur->left;
			}
		}
		
		return {pre, suc};
	}
};
