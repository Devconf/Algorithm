#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> hash;
	for(int i = 0; i < n; i++)
	{
		string add, pass;
		cin >> add >> pass;

		hash[add] = pass;
	}

	for(int i = 0; i < m; i++)
	{
		string search;
		cin >> search;
		cout << hash[search] << "\n";
	}
}