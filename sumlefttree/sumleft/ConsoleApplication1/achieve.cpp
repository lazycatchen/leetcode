#include "builtree.h"

void Solution::inertNode(TreeNode *node, int value) {
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

int Solution:: getMinimumDifference(TreeNode* root) {
	inorder(root);
	int  minresult = INT_MAX;
	int  size = result.size();
	for (int i = 1; i < size; ++i)
	{
		minresult = min(minresult, abs(result[i] - result[i - 1]));
	}
	return minresult;


}

void Solution:: inorder(TreeNode *node)
{

	if (node)
	{
		inorder(node->left);
		result.push_back(node->value);
		inorder(node->right);
	}
}

int Solution::sumOfLeftLeaves(TreeNode* root) {
	int temp = 0;
	int lefttemp = 0;
	int righttemp = 0;
	if (!root)
	{
		return 0;
	}
	
	else 
		if (root->left&&!root->left->left&&!root->left->right)
		{
			temp = root->left->value;
			
		}
	lefttemp = sumOfLeftLeaves(root->left);
	righttemp = sumOfLeftLeaves(root->right);
	temp = temp + lefttemp+ righttemp;
	return temp;
}