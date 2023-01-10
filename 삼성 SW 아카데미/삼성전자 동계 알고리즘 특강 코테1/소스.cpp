#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[22][22];
bool visited[26];
int r, c;
int maxNum = 0;

void solution(int w, int x, int y)
{
	if(!visited[map[x][y]])
	{
		visited[map[x][y]] = true;
	}

	int cnt = 0;
	for(int i = 0; i < 4; i++)
	{
		cnt++;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<1 || nx >r || ny<1 || ny>c || visited[map[nx][ny]] == true)
		{
			continue;
		}
		else
		{
			solution(w + 1, nx, ny);
		}

	}

	if(cnt == 4)
	{
		maxNum = max(maxNum, w);
		visited[map[x][y]] = false;
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for(int i = 1; i <= T; i++)
	{
		maxNum = 0;
		cin >> r >> c;

		memset(map, -1, sizeof(map));
		memset(visited, false, sizeof(visited));

		for(int j = 1; j <= r; j++)
		{
			string s;
			cin >> s;
			for(int k = 1; k <= c; k++)
			{
				map[j][k] = s[k-1] - 'A';
			}
		}

		solution(1,1,1);
		

		cout << "#" << i << " " << maxNum << "\n";
	}
}