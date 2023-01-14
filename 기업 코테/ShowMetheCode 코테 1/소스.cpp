#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int sum = 0;

	int one = 0, two = 0;
	
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if(num == 1)
		{
			one++;
		}
		else
		{
			two++;
		}
		sum = max(sum, abs(one - two));
	}

	cout << sum;

}