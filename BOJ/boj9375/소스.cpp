#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

void solution()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		map<string,int> m;

		for(int i = 0; i < n; i++)
		{
			
			string name, category;

			cin >> name >> category;

			if(m.find(category) == m.end())
			{
				m.insert({ category, 1 });
			}
			else
			{
				m[category]++;
			}
		}

		int ans = 1;
		for(auto iter = m.begin(); iter != m.end(); iter++)
		{
			ans *= (iter->second + 1);
		}
		cout << ans-1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution();
}