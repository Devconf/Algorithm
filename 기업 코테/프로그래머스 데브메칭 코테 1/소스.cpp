#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> cnt;

bool cmp(int a, int b)
{
	return a < b;
}

void check()
{
	int s = 0;
	int count = 0;

	do
	{
		cnt.push_back(s);

		for(int k = 0; k < v.size() - 1; k++)
		{
			int sum = v[k] + v[k + 1];
			if(sqrt(sum) == (int)sqrt(sum))
			{
				cnt[count]++;
			}
		}
		count++;
	} while(next_permutation(v.begin() + 1, v.end() - 1));
}

int main()
{
	int  t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{

		int n = 0;
		cin >> n;

		int start = 0;
		for(int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if(j == 0)
			{
				start = num;
			}
			v.push_back(num);
		}

		v.push_back(start);

		sort(v.begin()+1, v.end()-1,cmp);

		check();
		
		int maxCount = cnt[0];

		for(int l = 0; l < cnt.size(); l++)
		{
			if(maxCount < cnt[l])
			{
				maxCount = cnt[l];
			}
		}

		cout << "#" << i << " " << maxCount <<"\n";

		vector<int>().swap(v);
		vector<int>().swap(cnt);

	}
}

//523 53 143 394 231 445 999
