#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long k, n;
vector<long long> len;
long long result;

bool cmp(long long a, long long b)
{
	return a > b;
}

long long cut(long long length)
{
	if(length == 0)
	{
		return 0;
	}

	long long cutCnt = 0;
	for(auto l : len)
	{
		cutCnt += l / length;
	}
	return cutCnt;
}

void BS(long long l, long long r)
{
	if(l > r)
	{
		return;
	}

	long long mid = ceil((double)(l + r) / 2);

	long long cnt = cut(mid);

	if(cnt < n)
	{
		BS(l, mid-1);
	}
	else
	{
		result = max(result, mid);
		BS(mid+1, r);
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;

	for(int i = 0; i < k; i++)
	{
		long long num;
		cin >> num;
		len.push_back(num);
	}

	sort(len.begin(), len.end(), cmp);

	BS(0, len[0]);
	cout << result;
}