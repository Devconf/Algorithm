#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include <string>
#include <vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int matchCloth[10001];

int solution(int m, vector<int> temperatures, vector<vector<int>> clothes)
{

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> match;

	for(int i = 0; i < temperatures.size() ; i++)
	{
		for(int j = 0; j < clothes.size(); j++)
		{
			if(temperatures[i] >= clothes[j][0] && temperatures[i] <= clothes[j][1])
			{
				match.push_back(j);
			}
		}
	}

	for(int i = 0; i <= temperatures.size() - m; i++)
	{
		memset(matchCloth, 0, sizeof(matchCloth));
		for(int j = i; j < i + m; j++)
		{
			matchCloth[match[j]]++;
		}

		int cnt = 0;
		for(int j = 0; j < 20; j++)
		{
			if(matchCloth[j] > 0)
			{
				cnt++;
			}
		}
		pq.push({ cnt,i });
	}

	return pq.top().second+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> t;
	t.push_back(-2);
	t.push_back(-1);
	t.push_back(0);
	t.push_back(1);
	t.push_back(2);
	t.push_back(3);
	t.push_back(4);
	t.push_back(5);
	t.push_back(6);
	t.push_back(7);
	vector<vector<int>> c;
	vector<int> a1, a2;
	a1.push_back(-100);
	a1.push_back(0);
	a2.push_back(0);
	a2.push_back(100);
	//a3.push_back(26);
	//a3.push_back(30);
	c.push_back(a1);
	c.push_back(a2);
	//c.push_back(a3);
	solution(4, t, c);
}