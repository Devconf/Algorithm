#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> list[32001];
int entry[32001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(list, 0, sizeof(list));
	memset(entry, 0, sizeof(entry));

	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < m; i++)
	{
		int pre, now;

		cin >> pre >> now;
		list[pre].push_back(now);
		entry[now]++;
	}


	for(int i = 1; i <= n; i++)
	{
		if(entry[i] == 0)
		{
			pq.push(i);
		}
	}

	while(!pq.empty())
	{
		int num = pq.top();
		pq.pop();

		for(int j = 0; j < list[num].size(); j++)
		{
			int next = list[num][j];
			entry[next]--;

			if(entry[next] == 0) pq.push(next);
		}
		cout << num << " ";
	}
}