#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s = " ";

	while(true)
	{
		stack<char> st;
		getline(cin,s);

		if(s == ".")
		{
			break;
		}

		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '(')
			{
				st.push('(');
			}
			if(s[i] == '[')
			{
				st.push('[');
			}
			if(s[i] == ']')
			{
				if(!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					st.push(']');
					break;
				}
			}
			if(s[i] == ')')
			{
				if(!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					st.push(')');
					break;
				}
			}
		}

		if(st.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}