#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> len;
ll result;

bool cmp(ll a, ll b)
{
	return a > b;
}

void BS(ll l, ll r)
{
	if(l > r)
	{
		return;
	}

	ll mid = ceil((double)(l + r) / 2);
	ll total = 0;
	for(int i = 0; i < n; i++)
	{
		if(mid <= len[i])
		{
			total += (len[i] - mid);
		}
	}

	if(total < m)
	{
		BS(l, mid - 1);
	}
	else
	{
		result = max(result, mid);
		BS(mid + 1, r);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		ll num;
		cin >> num;
		len.push_back(num);
	}

	sort(len.begin(), len.end(), cmp);

	BS(0, len[0]);

	cout << result;
}