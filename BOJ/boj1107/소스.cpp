#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int n, m, minCnt;
bool button[10];

void solution()
{
	minCnt = abs(n - 100);

	for(int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		button[num] = false;
	}

	if(n == 100)
	{
		cout << 0;
		return;
	}

	int result = 0;
	int num = 987654321;
	int answer = 987654321;
	string s;
	for(int i = 0; i <= 1000000; i++)
	{
		s = to_string(result);

		bool isOk = true;
		for(int j = 0; j < s.size(); j++)
		{
			if(!button[s[j] - '0'])
			{
				isOk = false;
				break;
			}
		}

		if(isOk)
		{
			if(answer > abs(n - result))
			{
				answer = abs(n - result);
				num = result;
			}
		}
		result++;
	}
	int tmp = (int)(answer + to_string(num).size());
	minCnt = min(minCnt, tmp);
	cout << minCnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(button, true, sizeof(button));

	cin >> n >> m;
	solution();
}