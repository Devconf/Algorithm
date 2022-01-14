#include<iostream>
#include<vector>
using namespace std;

vector<int> coin(100001);
vector<long long> resultCase(100001);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		coin[i] = cost;
	}
	resultCase[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int sum = 0; sum <= k; sum++)
		{
			if(sum - coin[i] >= 0)
			{
				resultCase[sum] += resultCase[sum - coin[i]];
			}
		}
	}
	cout << resultCase[k];
}