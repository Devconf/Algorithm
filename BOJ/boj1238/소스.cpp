#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;

int n, m, x;
vector<pair<int,int>> adj[1001];

int dajik(int start, int end)
{
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while(!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for(int i = 0; i < adj[cur_node].size(); i++)
		{
			int next_node = adj[cur_node][i].first;
			int next_dist = adj[cur_node][i].second;
			if(dist[next_node] > (cur_dist + next_dist))
			{
				dist[next_node] = cur_dist + next_dist;
				pq.push({ cur_dist + next_dist, next_node });
			}
		}
	}
	return dist[end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;

	for(int i = 0; i < m; i++)
	{
		int s, e, t;

		cin >> s >> e >> t;

		adj[s].push_back({ e,t });
	}
	
	int maxLength = 0;
	for(int i = 1; i <= n; i++)
	{
		int goParty = dajik(i, x);
		int goHome = dajik(x, i);

		maxLength = max(maxLength, (goParty + goHome));
	}

	cout << maxLength;
}