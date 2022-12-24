#include<iostream>
#include<string>
#include<vector>
using namespace std;

int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };

int main()
{
	vector<vector<string>> places(5,vector<string> (5));

	for(int i = 0; i < 5; i++)
	{
		vector<string> temp;
		for(int j = 0; j < 5; j++)
		{
			string s;
			cin >> s;
			temp.push_back(s);
		}
		places[i]=temp;
	}


	//solution
	//빈자리를 기준으로 상하좌우에 학생이 한명만 있어야 한다.

	vector<int> result;

	for(int i = 0; i < places.size(); i++)
	{
		vector<vector<char>> p(5,vector<char>(5));
		vector<pair<int, int>> empty;
		vector<pair<int, int>> pSit;

		for(int j=0; j< places[i].size();j++)
		{
			for(int k = 0; k < places[i][j].length(); k++)
			{
				p[j][k] = places[i][j][k];
				if(p[j][k] == 'O')
				{
					empty.push_back({ j,k });
				}
				if(p[j][k] == 'P')
				{
					pSit.push_back({ j,k });
				}
			}
		}

		bool emptyPossible = true;
		bool sitPossible = true;

		for(int j = 0; j < empty.size(); j++)
		{
			int cnt = 0;
			for(int k = 0; k < 4; k++)
			{
				int nx = empty[j].first + x[k];
				int ny = empty[j].second + y[k];
				if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && p[nx][ny] == 'P')
				{
					cnt++;				
				}
			}
			if(cnt > 1)
			{
				emptyPossible = false;
				break;
			}
		}

		for(int j = 0; j < pSit.size(); j++)
		{
			int cnt = 0;
			for(int k = 0; k < 4; k++)
			{
				int nx = pSit[j].first + x[k];
				int ny = pSit[j].second + y[k];
				if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && p[nx][ny] == 'P')
				{
					cnt++;
				}
			}
			if(cnt > 0)
			{
				sitPossible = false;
				break;
			}
		}


		if((emptyPossible && sitPossible) ==false)
		{
			result.push_back(0);
		}
		else
		{
			result.push_back(1);
		}
	}

	for(auto answer : result)
	{
		cout << answer << " ";
	}
}