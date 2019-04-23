#include <iostream>
#include <string>
#include <stack>  

using namespace std;
class Solution {
public:

	string addBinary(string a, string b) 
	{

		//long a1 = std::stol(a);
		//long b1 = std::stol(b);
		int  temp = 0;
		
		stack <string>stk1;
		while (a.length()!=0 || b.length() != 0 ||temp)
		{
			int a1 = 0;
			int b1 = 0;
			if (a.length() != 0)
			{
				char x = a.at(a.length() - 1);
				a1 = x - '0';
				a.pop_back();
			}


			if (b.length() != 0)
			{
				char x1 = b.at(b.length() - 1);
				b1 = x1 - '0';
				b.pop_back();
			}


			int sumdata = (a1 + b1  + temp)%2;
			temp = (a1 + b1 + temp) / 2;

			stk1.push(std::to_string(sumdata));

		}
		string  result = "";
		while (!stk1.empty())
		{
			string temp2 = stk1.top();
			result = result + temp2;
			stk1.pop();
		}
		return result;
	}
   };
int main()
{
	string a = "110";
	string b= "101";
	Solution x1;
	string result=x1.addBinary(a, b);
	cout<<result;
	system("pause");
}