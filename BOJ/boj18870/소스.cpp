#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first < b.second.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int,pair<int, int>>> v; //{num, {idx,cnt}}
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back({ num,{i,0} });
	}
	sort(v.begin(), v.end());


	for(int i = 1; i < n; i++)
	{
		if(v[i].first > v[i - 1].first)
		{
			v[i].second.second = v[i - 1].second.second + 1;
		}
		else
		{
			v[i].second.second = v[i - 1].second.second;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < n; i++)
	{
		cout << v[i].second.second << " ";
	}
}