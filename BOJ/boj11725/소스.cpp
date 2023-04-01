#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[100001];
bool visited[100001] = { false, };
vector<int> adj[100001];

void trace(int parent)
{
	for(int i = 0; i < adj[parent].size(); i++)
	{
		//부모가 다르면
		if(adj[parent][i] != arr[parent])
		{
			arr[adj[parent][i]] = parent;
			trace(adj[parent][i]);
		}
	}
	visited[parent] = true;
}

void solution()
{
	//init
	for(int i = 0; i < 100000; i++)
	{
		arr[i] = i;
	}

	for(int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
	{
		if(visited[i])
		{
			continue;
		}
		trace(i);
	}

	for(int i = 2; i <= n; i++)
	{
		cout << arr[i] << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	solution();
	
}