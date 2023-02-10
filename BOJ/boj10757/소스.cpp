#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	string s = "";
	if(a.size() > b.size())
	{
		for(int i = 0; i < a.size() - b.size(); i++)
		{
			s.push_back('0');
		}
		s += b;
		b = s;
	}
	else if(a.size() < b.size())
	{
		for(int i = 0; i < b.size() - a.size(); i++)
		{
			s.push_back('0');
		}
		s += a;
		a = s;
	}
	
	stack<char> num;
	int carry = 0;
	string result = "";
	for(int i = a.size()-1; i >=0 ; i--)
	{
		int add = (a[i] - '0') + (b[i] - '0') + carry;
		carry = 0;
		if(add >= 10)
		{
			carry = 1;
		}
		num.push(add % 10);
	}

	if(carry == 1)
	{
		result = "1";
	}

	while(!num.empty())
	{
		result.push_back(num.top()+'0');
		num.pop();
	}

	cout <<result;
}