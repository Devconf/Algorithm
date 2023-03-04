#include<iostream>
#include<vector>
using namespace std;

int n, s;
vector<int> v;

void solution()
{
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> s;

	for(int i = 0; i < n && s > 0; i++)
	{
		int idx = i, m = v[i];
		for(int j = i + 1; j < n && j - i <= s; j++)
		{
			if(v[j] > m)
			{
				m = v[j];
				idx = j;
			}
		}

		if(idx != i)
		{
			s -= (idx - i);
			for(int j = idx; j > i; j--)
			{
				v[j] = v[j - 1];
			}
			v[i] = m;
		}
	}
	for(int i = 0; i < n; i++) cout << v[i] << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solution();
}