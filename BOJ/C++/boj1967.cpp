#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int n;
vector<pair<int,int>> node[100001];
vector<int> diameter(100001);

int DFS(int parent)
{
	int maxWeigh = 0;
	int current = 0;
	if(node[parent].size() == 0)// leaf node
	{
		return 0;
	}

	for(int i = 0; i < node[parent].size(); i++)
	{
		current += DFS(node[parent][i].first) + node[parent][i].second;
		maxWeigh = max(maxWeigh, DFS(node[parent][i].first) + node[parent][i].second);
	}
	diameter[parent] = current;
	return maxWeigh;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int p, c, w;
		cin >> p >> c >> w;
		node[p - 1].push_back({ c - 1,w });
	}

	DFS(0);

	sort(diameter.begin(), diameter.end(), greater<int>());
	cout << diameter[0];
}