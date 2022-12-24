#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

char map[102][102];
int dist[102][102];
bool visit[102][102];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(vector<tuple<int, int, int>> &fire, int n, int m, int a, int b)
{
	memset(dist, 0, 102 * 102 * sizeof(int));
	memset(visit, false, 102 * 102 * sizeof(bool));

	queue<pair<int, int>> q;
	q.push({ a,b });

	while(!q.empty())
	{
		pair<int, int> front = q.front();
		int x = front.first;
		int y = front.second;
		q.pop();

		if(visit[x][y] == false)
		{
			visit[x][y] = true;

			for(int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny] == '#' || visit[nx][ny] == true)
				{
					continue;
				}
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	for(int i = 0; i < fire.size(); i++)
	{
		int fx = get<0>(fire[i]);
		int fy = get<1>(fire[i]);
		int d = get<2>(fire[i]);

		get<2>(fire[i]) = max(dist[fx][fy], d);
	}
}

int main()
{
	int  t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n, m, k;
		vector<tuple<int, int, int>> fire;
		cin >> n >> m >> k;

		memset(map, 'x', 102 * 102 * sizeof(char));

		for(int j = 1; j <= n; j++)
		{
			string s;
			cin >> s;
			for(int l = 0; l < s.length(); l++)
			{
				map[j][l + 1] = s[l];
			}
		}


		for(int j = 0; j < k; j++)
		{
			int fx, fy;
			cin >> fx >> fy;

			fire.push_back(make_tuple(fx, fy, 0));
		}

		for(int j = 0; j < k; j++)
		{
			int a = get<0>(fire[j]);
			int b = get<1>(fire[j]);
			bfs(fire, n, m, a, b);
		}

		int result = -1;
		for(int i = 0; i < fire.size(); i++)
		{
			int d = get<2>(fire[i]);
			if(d >= 0)
			{
				if(d > result)
				{
					result = d;
				}
			}
			else
			{
				result = -1;
				break;
			}
		}
		if(result % 2 == 0)
		{
			cout << "#" << i << " " << result / 2 << "\n";
		}
		else
		{
			cout << "#" << i << " " << result / 2 + 1 << "\n";
		}

	}
}

//#include <iostream>
//#include <string>
//#include <queue>
//#include <vector>
//#include <memory.h>
//#include <algorithm>
//
//#define MAX 101
//#define endl "\n"
//using namespace std;
//
//vector<pair<int, int>> s; // 인화 물질 탐색 좌표 저장용 vector
//bool visited[MAX][MAX];   // 탐색 좌표 저장용
//int dist[MAX][MAX];
//int minTime[10001];
//
//int dx[] = { -1, 1, 0, 0 }; // 상하좌우 x축 방향
//int dy[] = { 0, 0, -1, 1 }; // 상하좌우 y축 방향
//
//int T, N, M, K;
//
//char v[MAX][MAX];
//
//void bfs(int N, int M, int start_x, int start_y)
//{
//	visited[start_x][start_y] = true;
//	queue<pair<int, int>> q; // 탐색 좌표 저장용 queue
//	q.push(make_pair(start_x, start_y));
//
//	while(!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//
//		q.pop();
//
//		if(visited[x][y] == false)
//		{
//			visited[x][y] = true;
//			int nx = 0, ny = 0;
//			for(int i = 0; i < 4; i++)
//			{
//				nx = x + dx[i];
//				ny = y + dy[i];
//
//				if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || v[nx][ny] == '#')
//				{
//					continue;
//				}
//
//				visited[nx][ny] = true;
//				q.push(make_pair(nx, ny));
//				dist[nx][ny] = dist[x][y] + 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> T;
//
//	for(int t = 0; t < T; t++)
//	{
//		cin >> N >> M >> K;
//
//		// memset(visited, false, 101 * 101 * sizeof(bool));
//		// memset(dist, 0, 101 * 101 * sizeof(int));
//		// memset(minTime, 0, 10001 * sizeof(int));
//		// memset(v, '0', N * M * sizeof(char));
//		memset(minTime, 0, 10001 * sizeof(int));
//		memset(v, '0', 101 * 101 * sizeof(char));
//
//		//for(int i = 0; i < N; i++)
//		//{
//		//	v[i] = new char[M];
//		//} // N*M 2차원 배열 동적 할당
//
//		for(int j = 0; j < N; j++)
//		{
//			string row;
//			cin >> row;
//			for(int k = 0; k < M; k++)
//			{
//				v[j][k] = row[k];
//			}
//			
//
//		} // 2차원 배열에 문자열 입력
//
//		for(int l = 0; l < K; l++)
//		{
//			int a, b;
//			cin >> a >> b;
//			s.push_back(make_pair(a - 1, b - 1));
//
//		} // 인화물질 위치 정보
//
//		int count = 0;
//		for(int i = 0; i < N; i++)
//		{
//			for(int j = 0; j < M; j++)
//			{
//				memset(visited, false, 101 * 101 * sizeof(bool));
//				memset(dist, 0, 101 * 101 * sizeof(int));
//				if(v[i][j] == '#')
//				{
//					continue;
//				}
//				bfs(N, M, i, j);
//				int time = dist[s[0].first][s[0].second];
//				for(int k = 0; k < K; k++)
//				{
//					time = max(time, dist[s[k].first][s[k].second]);
//				}
//				minTime[count] = time;
//				count++;
//			}
//		}
//
//		int smallest = minTime[0];
//
//		for(int i = 0; i < N * M; i++)
//		{
//			if(minTime[i] == 0)
//			{
//				continue;
//			}
//			smallest = min(smallest, minTime[i]);
//		}
//
//		cout << '#' << t + 1 << ' ' << smallest << endl;
//
//		vector<pair<int, int>>().swap(s);
//		/*for(int i = 0; i < N; i++)
//		{
//			delete[] v[i];
//		}*/
//	}
//}