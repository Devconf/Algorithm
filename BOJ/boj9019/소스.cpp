#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int visited[10001];

string solution()
{
	int  a, b;
	cin >> a >> b;

	queue<pair<int, string>> q;
	q.push({ a,"" });
	visited[a] = true;

	while(!q.empty())
	{
		int num = q.front().first;
		string s = q.front().second;
		q.pop();

		if(num == b)
		{
			cout << s << "\n";
			break;
		}

		int nextD = num, nextS = num, nextL = num, nextR = num;
		
		nextD = (num * 2) % 10000;
		if(!visited[nextD] || num != 0)
		{
			visited[nextD] = true;
			if(nextD == b)
			{
				return s + "D";
			}
			q.push({nextD,s + "D" });
		}
		

		nextS = (num - 1) < 0?9999:num - 1;
		if(!visited[nextS])
		{
			visited[nextS] = true;
			if(nextS == b)
			{
				return s + "S";
			}
			q.push({ nextS,s + "S" });
		}
		

		nextL = (num % 1000) * 10 + (num / 1000);
		if(!visited[nextL])
		{
			visited[nextL] = true;
			if(nextL == b)
			{
				return s + "L";
			}
			q.push({ nextL,s + "L" });
		}
		

		nextR = (num % 10) * 1000 + (num / 10);
		if(!visited[nextR])
		{
			visited[nextR] = true;
			if(nextR == b)
			{
				return s + "R";
			}
			q.push({ nextR,s + "R" });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		memset(visited, false, sizeof(visited));
		cout<< solution()<<"\n";
	}
}