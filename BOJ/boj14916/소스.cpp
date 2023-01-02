#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int result = 99999999;

	for(int i = 0; i <= (int)floor(n / 5); i++)
	{
		int money = n - (i * 5);
		if(money % 2 == 0)
		{
			result = min(result, i + (money / 2));
		}
	}

	if(result > n)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
	
}