#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n, l;

	cin >> n >> l;

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	if(l == 1)
	{
		cout << v.size();
		return 0;
	}
	else
	{
		sort(v.begin(), v.end());
		int cnt = 0;
		int start = v[0];
		int length = 0;

		for(int i = 1; i < v.size(); i++)
		{
			if(l<=v[i] - start)
			{
				cnt++;
				start =v[i];
			}
		}
		
		cout << cnt+1;
	}
}