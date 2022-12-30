#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;

	stack<string> st;
	vector<int> v;
	int num = 0;
	int start = 0;
	int cnt = 0;
	for(int i = 0; i <= s.size(); i++)
	{
		string sub;
		if(s[i] == '+' || s[i] == '-' || i == s.size())
		{
			sub = s.substr(start, cnt);
			start = i + 1;
			cnt = 0;
		}
		else
		{
			cnt++;
			continue;
		}
		st.push(sub);
		if(s[i] == '-')
		{
			st.push("-");
		}
	}

	int minNum = 0;
	while(!st.empty())
	{
		string top = st.top();
		st.pop();
		if(top != "-")
		{
			num += stoi(top);
			continue;
		}
		else
		{
			num *= -1;
			minNum += num;
		}
		num = 0;
	}

	minNum += num;

	cout << minNum;
}