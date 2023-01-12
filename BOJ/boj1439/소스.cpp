#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	int oneCnt = 0, zeroCnt = 0;

	for(int i = 0; i < s.size() - 1; i++)
	{
		if(s[0] == '1')
		{
			oneCnt++;
		}
		else
		{
			zeroCnt++;
		}

		if(s[i] != s[i + 1])
		{
			if(s[i] == '0')
			{
				oneCnt++;
			}
			else
			{
				zeroCnt++;
			}
		}
	}

	cout << min(oneCnt, zeroCnt);
}