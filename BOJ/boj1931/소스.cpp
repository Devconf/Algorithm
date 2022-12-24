#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool orderByFinish(pair<int, int> a, pair<int, int> b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> meeeting;

	for(int i = 0; i < n; i++)
	{
		int start, finish;
		cin >> start >>finish;
		meeeting.push_back({ start,finish });
	}

	sort(meeeting.begin(), meeeting.end(), orderByFinish);

	int cnt = 1;
	int finish = meeeting[0].second;
	int nextStart = 0;

	for(int i = 1; i < n; i++)
	{
		if(meeeting[i].first < finish)
		{
			continue;
		}
		finish = meeeting[i].second;
		cnt++;
	}

	cout << cnt;
}