#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;


char rgb[102][102];
char rb[102][102];
bool visited[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;
int rgbCnt = 0, rbCnt = 0;


void dfs(int x, int y, char arr[][102],char c)
{
	if(visited[x][y])
	{
		return;
	}

	visited[x][y] = true;

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]|| arr[nx][ny] != c)
		{
			continue;
		}
		
		dfs(nx, ny, arr,c);
	}


}

void solution()
{
	memset(rgb, 'x', sizeof(rgb));
	memset(rb, 'x', sizeof(rb));
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == 'G')
			{
				rgb[i][j+1] = 'G';
				rb[i][j+1] = 'R';
			}
			else
			{
				rgb[i][j+1] = s[j];
				rb[i][j+1] = s[j];
			}
		}
	}

	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!visited[i][j])
			{
				dfs(i, j, rgb, rgb[i][j]);
				rgbCnt++;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!visited[i][j])
			{
				dfs(i, j, rb, rb[i][j]);
				rbCnt++;
			}
		}
	}

	cout << rgbCnt << " " << rbCnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solution();
}