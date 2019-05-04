#pragma once
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
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root);
	void  inertNode(TreeNode *node, int value);
	std::vector<int> result;
	int getMinimumDifference(TreeNode* root);
	void inorder(TreeNode *node);
};
