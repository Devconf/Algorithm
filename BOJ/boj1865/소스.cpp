#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;

void Bellman_Ford()
{
	int n, m, w;
	cin >> n >> m >> w;

	vector<vector<pair<int,int>>> adj(n);
	vector<int> len(n,INF);

	for(int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;

		adj[s-1].push_back({ e-1,t });
		adj[e-1].push_back({ s-1,t });
	}

	for(int i = 0; i < w; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		adj[s-1].push_back({ e-1,-t });
	}

	bool isCycle = false;
	len[0] = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < adj[j].size(); k++)
			{
				int from = j, to = adj[j][k].first, cost = adj[j][k].second;

				if(len[to] > len[from] + cost)
				{
					len[to] = len[from] + cost;
					if(i == n-1)
					{
						isCycle = true;
					}
				}
			}
		}		
	}

	if(isCycle) cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	cin >> t;

	while(t)
	{
		Bellman_Ford();
		t--;
	}
	

}