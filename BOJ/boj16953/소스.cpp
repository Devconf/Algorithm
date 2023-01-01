#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	cin >> a >> b;

	int result = 0;
	while(b > a)
	{
		if(b % 2 == 1)
		{
			string s = to_string(b);
			if(s[s.size() - 1] == '1')
			{
				s = s.substr(0, s.size() - 1);
				b = stoi(s);
				result++;
				if(b < a)
				{
					result = -1;
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{
				result = -1;
				break;
			}
		}
		else
		{
			b /= 2;
			result++;
			if(b < a)
			{
				result = -1;
				break;
			}
		}
	}

	if(a == b)
	{
		result++;
	}
	
	cout << result;
}