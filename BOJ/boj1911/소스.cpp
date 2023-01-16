#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<pair<long long, long long>> v;

	
	for(int i = 0; i < n; i++)
	{
		long long s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}


	sort(v.begin(), v.end());

	long long cur = 0;
	int cnt = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(cur >= v[i].first && cur < v[i].second)
		{
			int quotient = (v[i].second - cur) / l;
			int remainder = (v[i].second - cur) % l;

			cnt += quotient;
			cur += quotient * l;
			if(remainder != 0)
			{
				cnt++;
				cur += l;
			}
		}
		else if(cur< v[i].first)
		{
			cur = v[i].first;
			i--;
		}
	}
	cout << cnt;
}