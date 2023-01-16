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
	vector<pair<long long, long long>> p;

	
	for(int i = 0; i < n; i++)
	{
		long long s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	v.push_back({ 0,0 });

	sort(v.begin(), v.end());


	//v.push_back({ v[v.size()-1].second,v[v.size() - 1].second });

	long long start = 0;
	long long end = 0;
	int cnt = 0;
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i].second - v[i].first <=l){
			cnt++;
			end= v[i].second;
			continue;
		}
		else
		{
			if((v[i].first - v[i-1].second) > l/2)
			{
				cnt += ceil((end - start) / l);
				start = v[i].first;
				end = v[i].first;
			}
			else
			{
				end = v[i].second;
			}
		}
	}
	cnt += ceil((end - start) / l);

	cout << cnt;
	for(int i = 0; i < p.size();i++)
	{
		cout << p[i].first << " " << p[i].second;
	}
}