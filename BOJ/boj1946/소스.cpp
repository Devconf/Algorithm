#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}

int  main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		int n;
		vector<pair<int, int>> test;

		cin >> n;

		for(int j = 0; j < n; j++)
		{
			int a, b; // a= 서류, b= 면접
			cin >> a >> b;
			test.push_back({ a,b });
		}

		sort(test.begin(), test.end(), compare);
		
		int cnt = 0;
		int max = 100001;
		for(int j=0;j<test.size();j++)
		{
			if(test[j].second < max)
			{
				max = test[j].second;
				cnt++;
			}
		}
		cout << cnt<<"\n";
	}
}