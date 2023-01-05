#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(),v.end(), cmp);

	int cnt = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(k == 0)
		{
			break;
		}
		if(v[i] > k)
		{
			continue;
		}
		k -= v[i];
		cnt++;
		i--;
	}

	cout << cnt;
}