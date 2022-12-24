#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;
	int map[101][101] = { 0, };

	int start = 1;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			map[i][j] = start;
			start++;
		}
	}

	for(auto query :queries)
	{
		int minNum = 99999999;
		int sx, sy, ex, ey;
		for(int j = 0; j < query.size(); j++)
		{
			if(j == 0)
			{
				sx = query[j];
			}
			if(j == 1)
			{
				sy = query[j];
			}
			if(j == 2)
			{
				ex = query[j];
			}
			if(j == 3)
			{
				ey = query[j];
			}
		}

		int nx = sx-1;
		int ny = sy-1;
		int before;
		int next = map[sx-1][sy-1];
		while(true)
		{
			before = next;
			if(nx == sx-1 && ny < ey-1)
			{
				ny++;
			}
			else if(nx < ex-1 && ny == ey-1)
			{
				nx++;
			}
			else if(nx == ex-1 && ny > sy-1)
			{
				ny--;
			}
			else if(nx > sx-1 && ny == sy-1)
			{
				nx--;
			}

			next = map[nx][ny];
			map[nx][ny] = before;

			minNum = min(minNum, before);

			if(nx == sx-1 && ny == sy-1)
			{
				break;
			}
		}

		answer.push_back(minNum);		
	}
	return answer;
}

int main()
{
	vector<vector<int>> queries(3, vector<int>(4, 0));

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int num = 0;
			cin >> num;
			queries[i][j] = num;
		}
	}

	solution(6,6, queries);


}