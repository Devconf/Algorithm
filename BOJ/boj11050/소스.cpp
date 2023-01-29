#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	int a = 1, b = 1;
	for(int i = 0; i < k; i++)
	{
		a *= n;
		n--;
	}

	for(int i = k; i >0; i--)
	{
		b *= i;
	}
	cout << a / b;
}