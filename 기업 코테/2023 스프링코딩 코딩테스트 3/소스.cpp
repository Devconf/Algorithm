#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
char map[1002][1002];
bool visit[1002][1002];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int total = 0;
bool isSide = false;

void dfs(int a, int b, int &num)
{
	if(visit[a][b])
	{
		return;
	}
	visit[a][b] = true;
	num++;

	for(int i = 0; i < 4; i++)
	{
		int nx = a + dx[i];
		int ny = b + dy[i];
		if(nx<1 || nx>n || ny <1 || ny >m)
		{
			isSide = true;
			continue;
		}

		if(visit[nx][ny] == true || map[nx][ny] == '#')
		{
			continue;
		}
		else
		{
			dfs(nx, ny,num);
		}
	}
}

int solution(vector<string> grid)
{
	memset(map, 'x', sizeof(map));

	queue<pair<int, int>> q;

	n = grid.size();
	m = grid[0].size();

	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[i].size(); j++)
		{
			if(grid[i][j] == '.')
			{
				q.push({ i + 1,j + 1 });
			}
			map[i + 1][j + 1] = grid[i][j];
		}
	}

	while(!q.empty())
	{
		pair<int, int> f = q.front();
		q.pop();

		int num = 0;
		isSide = false;
		dfs(f.first, f.second, num);
		if(isSide == true)
		{
			total += num;
		}
	}
	
	int answer = n * m - total;
	cout << answer;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> v;

	string a, b, c, d, e, f;
	a = ".....####";
	b = "..#...###";
	c = ".#.##..##";
	d = "..#..#...";
	e = "..#...#..";
	f = "...###...";

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);
	
	solution(v);


}