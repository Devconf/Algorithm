#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int v;
vector<pair<int, int>> adj[100001];
bool visited[100001];
int startIdx = 0;
int maxWeight = 0;

void dfs(int idx, int sumWeight)
{
	if(visited[idx] == true)
	{
		return;
		
	}

	visited[idx] = true;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		pair<int, int> front = adj[idx][i];
		int nextNode = front.first;
		int weight = front.second;

		if(maxWeight <= sumWeight + weight && visited[nextNode] == false)
		{
			startIdx = nextNode;
			maxWeight = sumWeight + weight;
		}
		dfs(nextNode, sumWeight + weight);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(visited, false, sizeof(visited));

	cin >> v;

	for(int i = 1; i <= v; i++)
	{
		int end = 0;
		int vIdx = 0;
		cin >> vIdx;

		int cnt = 0;
		int node, w;
		while(end != -1)
		{
			cnt++;
			cin >> end;
			if(cnt % 2 == 1)//연결된 노드
			{
				node = end;
			}
			else
			{
				w = end;
				adj[vIdx].push_back({ node,w });
			}
		}
	}

	dfs(1,0);

	maxWeight = 0;
	memset(visited, false, sizeof(visited));

	dfs(startIdx,0);

	cout << maxWeight;
}