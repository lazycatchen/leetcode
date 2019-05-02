#include <iostream>
using namespace std;
#include <cmath>
class Solution1 {
public:
	bool isHappy(int n) {
		int temp = 0;
		while (n)
		{
			temp = pow(n % 10,2) + temp;
			n = n / 10;
		}
		if (temp == 1||temp == 7)
		{
			return true;
		}
		else if (temp >= 10)
		{
			return isHappy(temp);
		}
		else 
		{
			return false;
		}

	}
};

bool main()
{
	int n = 1111111;
	Solution1 ss;
	bool x = ss.isHappy(n);
	cout << x << endl;
	system("pause");
}