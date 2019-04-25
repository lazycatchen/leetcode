#include<iostream>
#include<stack>
#include<queue>
//节点结构体
struct Node {
	int value;
	Node * left;
	Node * right;
	Node(int value) :value(value), left(NULL), right(NULL) {}
};
//构建二叉树
void inertNode(Node *node, int value) {
	if (value <= node->value) {
		if (!node->left) {
			node->left = new Node(value);
		}
		else {
			inertNode(node->left, value);
		}
	}
	else {
		if (!node->right) {
			node->right = new Node(value);
		}
		else {
			inertNode(node->right, value);
		}
	}
}

void inOrder(Node *node) {
	if (node) {
		inOrder(node->left);
		std::cout << node->value;
		inOrder(node->right);
	}
}

void inOrder1(Node *node) {
	std::stack<Node *> nstack;
	Node *temp = node;
	while (temp || !nstack.empty()) {
		if (temp) {
			nstack.push(temp);
			temp = temp->left;
		}
		else {
			temp = nstack.top();
			std::cout << temp->value;
			nstack.pop();
			temp = temp->right;
		}
	}
}

int main() {
	int n;
	while (std::cin >> n) {
		n--;
		int value;
		std::cin >> value;
		Node root(value);
		while (n--) {
			int newValue;
			std::cin >> newValue;
			inertNode(&root, newValue);
		}
		
		std::cout << "inOrder is:";
		inOrder(&root);
		std::cout << std::endl;
	}

}