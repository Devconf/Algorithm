#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
struct Bus
{
	int s, e, idx;
};

bool cmp(Bus x, Bus y)
{
	if(x.s != y.s)
	{
		return x.s < y.s;
	}
	return x.e > y.e;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Bus> v;

	cin >> n >> m;

	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int len = 0;
		if(a < b)//정노선
		{
			v.push_back({ a,b,i });
		}
		else
		{//역노선일경우 
			v.push_back({ a - n,b,i });
			v.push_back({ a,b + n,i });
		}
	}

	sort(v.begin(), v.end(), cmp);

	vector<int> result = { v.front().idx };//첫번째 노선은 반드시 유요하다
	int here = 0;
	for(int i = 1; i < v.size(); i++)
	{
		if(v[here].e < v[i].e)
		{
			result.push_back(v[i].idx);
			here = i;
		}
	}

	sort(result.begin(), result.end());

	result.erase(unique(result.begin(), result.end()), result.end());

	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}