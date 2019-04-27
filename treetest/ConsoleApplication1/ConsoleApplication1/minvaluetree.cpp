#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 struct TreeNode {
     int value;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : value(x), left(NULL), right(NULL) {}
 };

 void inertNode(TreeNode *node, int value) {
	 if (value <= node->value) {
		 if (!node->left) {
			 node->left = new TreeNode(value);
		 }
		 else {
			 inertNode(node->left, value);
		 }
	 }
	 else {
		 if (!node->right) {
			 node->right = new TreeNode(value);
		 }
		 else {
			 inertNode(node->right, value);
		 }
	 }
 }
 class Solution {
 public:
	 std::vector<int> result;

	 int getMinimumDifference(TreeNode* root) {
		 inorder(root);
		 int  minresult= INT_MAX;
		 int  size = result.size();
		 for (int i = 1; i < size; ++i)
		 {
			  minresult = min(minresult, abs(result[i] - result[i - 1]));
		 }
		 return minresult;
		

	 }
	 void inorder(TreeNode *node)
	 {
		 
		 if (node)
		 {
			 inorder(node->left);
			 result.push_back(node->value);
			 inorder(node->right);
		 }
	 }
 };


 int main() {
	 int n;
 	 while (std::cin >> n) {
		 n--;
		 int value;
		 std::cin >> value;
		 TreeNode root(value);
		 while (n--) {
			 int newValue;
			 std::cin >> newValue;
			 inertNode(&root, newValue);
		 }

		 std::cout << "inOrder is:";
		 Solution ss;
		 int res=ss.getMinimumDifference(&root);
		 std::cout << res;
	 }

 }