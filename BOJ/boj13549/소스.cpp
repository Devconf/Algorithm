#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

bool visited[100001];


void dijk(int start,int end)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	visited[start] = true;

	while(!pq.empty())
	{
		int time = pq.top().first;
		int next = pq.top().second; 
		pq.pop();

		if(next == end)
		{
			cout << time;
		}

		if(next > 100000 || next < 0)
		{
			continue;
		}

		if(next * 2 <= 100000 && !visited[next * 2])
		{
			visited[next * 2] = true;
			pq.push({ time, next * 2 });
		}

		if(next + 1 <= 100000 && !visited[next + 1])
		{
			visited[next + 1] = true;
			pq.push({ time + 1, next + 1 });
		}
		if(next - 1 >= 0 && !visited[next - 1])
		{
			visited[next - 1] = true;
			pq.push({ time + 1, next - 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(visited, false, sizeof(visited));

	int n, k;

	cin >> n >> k;

	dijk(n,k);
}