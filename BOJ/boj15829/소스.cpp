#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;

	cin >> n >> s;

	long long sum = 0;
	while(n > 0)
	{
		long long num = 1;
		for(int i = n - 1; i > 0; i--)
		{
			num *= 31;
			num %= 1234567891;
		}
		sum += (s[n - 1] - 'a' + 1) * num;
		sum %= 1234567891;
		n--;
	}
	cout << sum;
}