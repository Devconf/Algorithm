#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 1;

	while(n)
	{
		cin >> n;
		
		int sum = 0;
		for(int i = n; i > 0; i--)
		{
			sum += i;
		}
		if(n != 0)
		{
			cout << sum << "\n";
		}
	}
}