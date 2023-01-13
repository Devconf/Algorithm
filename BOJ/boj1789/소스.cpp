#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long s;

	cin >> s;

	long long sum = 0;
	long long answer = 0;
	for(long long i = 1; ; i++)
	{
		if(sum + i <= s)
		{
			sum += i;
			answer = i;
		}
		else
		{
			break;
		}
	}
	cout << answer;
}