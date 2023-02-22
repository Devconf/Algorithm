#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char map[64][64];
string result = "";

void solution(int x, int y, int num) // num은 분할 크기
{
	char startNum = map[x][y];

	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			if(map[x + i][y + j] != startNum)
			{
				result.push_back('(');
				int next = num / 2;
				solution(x, y, next);
				solution(x, y + next, next);
				solution(x + next, y, next);
				solution(x + next, y + next, next);
				result.push_back(')');
				return;
			}
		}
	}
	result.push_back(startNum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, ' ', sizeof(map));

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
		}
	}

	solution(0, 0, n);
	
	cout << result;
}