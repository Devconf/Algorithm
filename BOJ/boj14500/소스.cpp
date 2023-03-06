#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<pair<int, int>>> tetPosition;

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m,0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int maxSum = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			for(int k = 0; k < tetPosition.size(); k++)
			{
				bool inRange = true;
				int sum = 0;
				for(int l = 0; l < tetPosition[k].size(); l++)
				{
					int nx = i + tetPosition[k][l].first;
					int ny = j + tetPosition[k][l].second;
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						inRange = false;
						break;
					}
					sum += map[nx][ny];
				}

				if(!inRange)
				{
					continue;
				}
				else
				{
					maxSum = max(maxSum, sum);
				}
			}
		}
	}

	cout << maxSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	vector<pair<int, int>> pos1;
	pos1.push_back({ 0, 0 });
	pos1.push_back({ 0, 1 });
	pos1.push_back({ 0, 2 });
	pos1.push_back({ 0, 3 });

	vector<pair<int, int>> pos2;
	pos2.push_back({ 0, 0 });
	pos2.push_back({ 1, 0 });
	pos2.push_back({ 2, 0 });
	pos2.push_back({ 3, 0 });

	vector<pair<int, int>> pos3;
	pos3.push_back({ 0, 0 });
	pos3.push_back({ 1, 0 });
	pos3.push_back({ 0, 1 });
	pos3.push_back({ 1, 1 });

	vector<pair<int, int>> pos4;
	pos4.push_back({ 0, 0 });
	pos4.push_back({ 1, 0 });
	pos4.push_back({ 2, 0 });
	pos4.push_back({ 2, 1 });
	
	vector<pair<int, int>> pos5;
	pos5.push_back({ 0, 1 });
	pos5.push_back({ 1, 1 });
	pos5.push_back({ 2, 1 });
	pos5.push_back({ 2, 0 });

	vector<pair<int, int>> pos6;
	pos6.push_back({ 0, 0 });
	pos6.push_back({ 0, 1 });
	pos6.push_back({ 1, 1 });
	pos6.push_back({ 2, 1 });

	vector<pair<int, int>> pos7;
	pos7.push_back({ 0, 0 });
	pos7.push_back({ 0, 1 });
	pos7.push_back({ 1, 0 });
	pos7.push_back({ 2, 0 });

	vector<pair<int, int>> pos8;
	pos8.push_back({ 0, 0 });
	pos8.push_back({ 1, 0 });
	pos8.push_back({ 1, 1 });
	pos8.push_back({ 1, 2 });

	vector<pair<int, int>> pos9;
	pos9.push_back({ 0, 2 });
	pos9.push_back({ 1, 1 });
	pos9.push_back({ 1, 2 });
	pos9.push_back({ 1, 0 });

	vector<pair<int, int>> pos10;
	pos10.push_back({ 0, 0 });
	pos10.push_back({ 0, 1 });
	pos10.push_back({ 0, 2 });
	pos10.push_back({ 1, 2 });

	vector<pair<int, int>> pos11;
	pos11.push_back({ 0, 0 });
	pos11.push_back({ 1, 0 });
	pos11.push_back({ 0, 1 });
	pos11.push_back({ 0, 2 });

	vector<pair<int, int>> pos12;
	pos12.push_back({ 0, 0 });
	pos12.push_back({ 1, 0 });
	pos12.push_back({ 1, 1 });
	pos12.push_back({ 2, 1 });

	vector<pair<int, int>> pos13;
	pos13.push_back({ 0, 1 });
	pos13.push_back({ 1, 1 });
	pos13.push_back({ 1, 0 });
	pos13.push_back({ 2, 0 });

	vector<pair<int, int>> pos14;
	pos14.push_back({ 1, 0 });
	pos14.push_back({ 1, 1 });
	pos14.push_back({ 0, 1 });
	pos14.push_back({ 0, 2 });

	vector<pair<int, int>> pos15;
	pos15.push_back({ 0, 0 });
	pos15.push_back({ 0, 1 });
	pos15.push_back({ 1, 1 });
	pos15.push_back({ 1, 2 });

	vector<pair<int, int>> pos16;
	pos16.push_back({ 0, 1 });
	pos16.push_back({ 1, 0 });
	pos16.push_back({ 1, 1 });
	pos16.push_back({ 1, 2 });

	vector<pair<int, int>> pos17;
	pos17.push_back({ 0, 0 });
	pos17.push_back({ 0, 1 });
	pos17.push_back({ 0, 2 });
	pos17.push_back({ 1, 1 });

	vector<pair<int, int>> pos18;
	pos18.push_back({ 0, 0 });
	pos18.push_back({ 1, 0 });
	pos18.push_back({ 1, 1 });
	pos18.push_back({ 2, 0 });

	vector<pair<int, int>> pos19;
	pos19.push_back({ 0, 1 });
	pos19.push_back({ 1, 1 });
	pos19.push_back({ 1, 0 });
	pos19.push_back({ 2, 1 });

	tetPosition.push_back(pos1);
	tetPosition.push_back(pos2);
	tetPosition.push_back(pos3);
	tetPosition.push_back(pos4);
	tetPosition.push_back(pos5);
	tetPosition.push_back(pos6);
	tetPosition.push_back(pos7);
	tetPosition.push_back(pos8);
	tetPosition.push_back(pos9);
	tetPosition.push_back(pos10);
	tetPosition.push_back(pos11);
	tetPosition.push_back(pos12);
	tetPosition.push_back(pos13);
	tetPosition.push_back(pos14);
	tetPosition.push_back(pos15);
	tetPosition.push_back(pos16);
	tetPosition.push_back(pos17);
	tetPosition.push_back(pos18);
	tetPosition.push_back(pos19);

	solution();
}