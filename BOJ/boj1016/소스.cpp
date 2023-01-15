#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long arr[1000002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 0, sizeof(arr));

	long long small, large;
	cin >> small >> large;

	long long cnt = 0;
	long long i = 2;

	while(i*i <= large){
		long long sNum = small / (i*i);
		if(small % (i * i) != 0)
		{
			sNum += 1;
		}
		while(i*i*sNum <= large)
		{
			arr[i*i*sNum - small] = 1;
			sNum++;
		}
		i++;
	}
	
	for(long long i = 0; i <= 1000002; i++)
	{
		if(arr[i] == 1)
		{
			cnt++;
		}
	}

	cout << large - small +1 - cnt;
}