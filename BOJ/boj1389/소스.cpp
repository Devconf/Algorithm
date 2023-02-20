#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
vector<int> adj[101];
bool visit[101];
int minCnt;

int solution(int start, int search, int cnt)
{
	visit[start] = true;

	bool isFind = false;
	for(int i = 0; i < adj[start].size(); i++)
	{
		if(adj[start][i] == search)
		{
			cnt++;
			isFind = true;
			break;
		}
	}

	if(isFind)
	{
		return cnt;
	}
	else
	{
		for(int i = 0; i < adj[start].size(); i++)
		{
			if(!visit[adj[start][i]])
			{
				minCnt = min(minCnt,solution(adj[start][i], search, ++cnt));
				visit[adj[start][i]] = false;
				cnt--;
			}
		}
		return minCnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	pair<int, int> answer = { 987654321,0 };
	for(int i = 1; i <= n; i++)
	{

		int sum = 0;
		for(int j = 1; j <= n; j++)
		{
			memset(visit, false, sizeof(visit));
			minCnt = 987654321;
			int cnt = 0;
			if(i != j)
			{
				sum += solution(i,j, cnt);
			}
		}
		if(sum < answer.first)
		{
			answer = { sum,i };
		}
	}
	cout << answer.second;
}