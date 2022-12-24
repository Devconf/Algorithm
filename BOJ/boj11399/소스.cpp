#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> p;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		p.push_back(a);
	}

	sort(p.begin(), p.end());

	int result = 0;

	for(int i = n; i > 0; i--)
	{
		result += i * p[n-i];
	}

	cout << result;
}