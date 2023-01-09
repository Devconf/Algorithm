#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string n,cmp;
int x, y;
long long location = 0;

void solution()
{
	long long changedIdx = 0;
	long long idx = 0;
	while(idx < n.size())
	{
		if(n[idx] - '0' > y)
		{
			cmp[idx] = '0' + y;
			location = idx + 1;
			return;
		}
		if(n[idx] - '0' == y)
		{
			cmp[idx] = '0' + y;
			location = idx + 1;
			idx++;
		}
		else if(n[idx] - '0' == x)
		{
			cmp[idx] = '0' + x;
			location = idx + 1;
			idx++;
		}
		else if(n[idx] - '0' <y && n[idx] - '0' >x)
		{
			cmp[idx] = '0' + x;
			location = idx + 1;
			return;
		}
		else if(n[idx] - '0' < x)
		{
			location = idx;
			if(idx == changedIdx)
			{
				return;
			}
			cmp[idx] = '0';
			changedIdx = idx;
			if(idx > 0)
			{
				n[idx - 1] = n[idx - 1] - 1;
				
			}
			idx--;
		}
		if(idx < 0)
		{
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for(int i = 1; i <= T; i++)
	{
		
		cin >> n >> x >> y;

		cmp = "";
		string result = "";

		for(long long j = 0; j < n.size(); j++)
		{
			cmp.push_back('0');
		}
	
		solution();

		
		if(cmp.size() == 1)
		{
			result.push_back(cmp[0]);
		}
		else
		{
			if(location == 0)
			{
				for(long long j = 0; j <= location; j++)
				{
					if(cmp[0] != '0')
					{
						result.push_back(cmp[j]);
					}
				}

				for(long long j = 1; j < n.size(); j++)
				{
					result.push_back('0' + y);
				}
			}
			else
			{
				for(long long j = 0; j < location; j++)
				{
					if(cmp[0] != '0')
					{
						result.push_back(cmp[j]);
					}
				}

				for(long long j = location; j < n.size(); j++)
				{
					result.push_back('0' + y);
				}
			}

		}
		
		if(result == "0")
		{
			cout << "#" << i << " " << -1 << "\n";
		}
		else
		{
			cout << "#" << i << " " << result << "\n";
		}
	}
}