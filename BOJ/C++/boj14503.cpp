#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int n, m;
int r, c, d;
int cnt = 0;
pair<int, int> nextStep[4] = { {0,-1},{-1,0},{0,1},{1,0} };
int direction[4] = { 3,0,1,2 };
vector<vector<int>> arr;

vector<int> StringPaser(string row)
{
	vector<int> result;
	string tmp;
	stringstream ss(row);
	while(getline(ss, tmp, ' '))
	{
		if(tmp == "1")
		{
			result.push_back(stoi(tmp)+1);
		}
		else
		{
			result.push_back(stoi(tmp));
		}
	}
	return result;
}

void Search(int x, int y, int dir)
{
	int startDir = dir;
	int check = 0;
	if(arr[x][y] == 0)
	{
		arr[x][y] = 1;
		cnt++;
	}

	while(1)
	{
		check++;
		if(check == 5)
		{
			x = x + nextStep[direction[dir]].first;
			y = y + nextStep[direction[dir]].second;
			if(arr[x][y] == 2)
			{
				cout << cnt;
				exit(0);
			}
			Search(x, y, dir);
			return;
		}
		if(arr[x + nextStep[dir].first][y + nextStep[dir].second] == 0)
		{
			Search(x + nextStep[dir].first, y + nextStep[dir].second, direction[dir]);
			return;
		}
		else
		{
			dir = direction[dir];
			continue;
		}
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> r >> c >> d;

	cin.clear();
	cin.ignore();
	
	for(int i = 0; i < n; i++)
	{
		string row;
		getline(cin, row);
		arr.push_back(StringPaser(row));
	}

	Search(r, c, d);
}