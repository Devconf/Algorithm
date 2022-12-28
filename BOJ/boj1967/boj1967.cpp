#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;

int n;
pair<int, int> maxNode = { 0,0 };
bool visited[100001];
vector<pair<int,int>> node[100001];

void DFS(int parent, int w,int totalWeight)
{
	visited[parent] = true;

	for(int i = 0; i < node[parent].size(); i++)
	{
		int child = node[parent][i].first;
		int weight = node[parent][i].second;
		if(!visited[child])
		{
			DFS(child, weight, (totalWeight + weight));
		}
	}

	int nodeNum = maxNode.first;
	int maxTotal = maxNode.second;
	if(maxTotal < totalWeight)
	{
		maxNode = { parent,totalWeight };
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(node, 0, sizeof(node));
	memset(visited, false, sizeof(visited));

	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int p, c, w;
		cin >> p >> c >> w;
		node[p].push_back({ c,w });
		node[c].push_back({ p,w });
	}

	DFS(1, 0, 0);
	
	int startNode = maxNode.first;
	memset(visited, false, sizeof(visited));
	maxNode = { 0,0 };

	DFS(startNode, 0, 0);

	cout << maxNode.second;
}