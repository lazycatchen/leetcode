#include "builtree.h"
int main() {
	int n;
	while (std::cin >> n) {
		n--;
		int value;
		std::cin >> value;
		TreeNode root(value);
		Solution sss;
		while (n--) {
			int newValue;
			std::cin >> newValue;	
			sss.inertNode(&root, newValue);
		}

		std::cout << "inOrder is:";
		
		int rest = sss.sumOfLeftLeaves(&root);
		//int res = ss.getMinimumDifference(&root);
		std::cout << rest;
	}

}