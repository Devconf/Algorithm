#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <cstring>
using namespace std;

vector<int> adj[300001];
bool visited[300001];


void kDistNode(int dist, int startNode)
{
	vector<int> goal;
	queue<pair<int,int>> q;
	int minDist = 0;
	visited[startNode] = true;
	q.push({ startNode,minDist });

	while(!q.empty())
	{
		int node = q.front().first;
		int currentDist = q.front().second;
		q.pop();

		if(visited[node])
		{
			if(currentDist == dist)
			{
				goal.push_back(node);
			}
		}
		

		for(int i = 0; i < adj[node].size(); i++)
		{
			if(!visited[adj[node][i]])
			{
				q.push({ adj[node][i], currentDist+1 });
				visited[adj[node][i]] = true;
			}
		}
	}

	if(goal.size() == 0)
	{
		cout << -1;
	}
	else
	{
		sort(goal.begin(), goal.end());
		for(int i = 0; i < goal.size(); i++)
		{
			cout << goal[i] << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, x;

	cin >> n >> m >> k >> x;

	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	memset(visited, false, 300001 * sizeof(bool));

	kDistNode(k,x);
}