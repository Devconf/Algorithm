#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;

void solution()
{
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int idx = n;

	while(true)
	{
		bool isEnd = true;
		for(int i = 0; i < n - 1; i++)
		{
			if(v[i] + 1 == v[i + 1])
			{
				isEnd = false;
				bool isFind = false;
				for(int j = i + 2; j < v.size(); j++)
				{
					if(v[j] > v[i + 1])
					{
						int tmp = v[j];
						v[j] = v[i + 1];
						v[i + 1] = tmp;
						isFind = true;
						break;
					}
				}
				if(isFind)
				{
					break;
				}
				else
				{
					int tmp = v[i + 1];
					v[i+1] = v[i];
					v[i] = tmp;
					break;
				}

			}
		}

		if(isEnd)
		{
			break;
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