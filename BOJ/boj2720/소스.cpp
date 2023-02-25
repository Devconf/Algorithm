#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int change[4] = { 25,10,5,1 };
	for(int i = 0; i < n; i++)
	{
		vector<int> v(4, 0);
		int num;
		cin >> num;

		for(int j = 0; j < 4; j++)
		{
			if(num < change[j])
			{
				continue;
			}

			int quotient = num / change[j];
			num -= quotient * change[j];
			v[j] = quotient;
		}

		for(auto result : v)
		{
			cout << result << " ";
		}
		cout << "\n";
	}
}