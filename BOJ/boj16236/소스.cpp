#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int n;
int startX, startY;
int eat = 0, sharkSize = 2;
int totalTime = 0;
int map[22][22];
bool visited[22][22];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

struct compare
{
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
	{
		if(a.second == b.second)
		{
			if(a.first.first == b.first.first)
			{
				return a.first.second > b.first.second;
			}
			else
			{
				return a.first.first > b.first.first;
			}
		}
		else
		{
			return a.second > b.second;
		}
	}
};

bool solution()
{
	priority_queue<pair<pair<int, int>,int>, vector<pair<pair<int, int>, int>>,compare> pq;
	pq.push({ { startX,startY },0 });

	bool isFindFood = false;

	while(!pq.empty())
	{
		pair<pair<int, int>, int > f = pq.top();
		int x = f.first.first;
		int y = f.first.second;
		int t = f.second;
		pq.pop();		

		if(map[x][y]>0 && map[x][y] < sharkSize)
		{
			eat++;
			startX = x;
			startY = y;
			map[x][y] = 0;
			totalTime += t;
			isFindFood = true;
			break;
		}

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false && map[nx][ny] <= sharkSize)
			{
				visited[nx][ny] = true;
				pq.push({ { nx,ny }, t + 1 });
			}
		}
	}

	return isFindFood;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, -1, sizeof(map));

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 9)
			{
				startX = i;
				startY = j;
				map[i][j] = 0;
			}
		}
	}

	while(solution())
	{
		memset(visited,false, sizeof(visited));
		if(eat == sharkSize)
		{
			sharkSize++;
			eat = 0;
		}
	}
	cout << totalTime;
}