#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321;
using namespace std;

int n, m, b;
vector<int> v;
vector<pair<int, int>> compact_v; //{높이, 갯수}

void solution()
{
	int minWeight = INF;
	int height = 0;
	for(int i = 0; i <= 256; i++) // 높이 기준
	{
		int weight = 0;
		int block = b;
		for(int j = 0; j < compact_v.size(); j++)
		{
			if(i > compact_v[j].first)
			{
				int needBlock = (i - compact_v[j].first) * compact_v[j].second;
				block -= needBlock;
				weight += needBlock;
			}
			else if(i < compact_v[j].first)
			{
				int removeBlock = (compact_v[j].first - i) * compact_v[j].second;
				block += removeBlock;
				weight += (2 * removeBlock);
			}
		}
		if(block >= 0)
		{
			if(weight <= minWeight)
			{
				minWeight = weight;
				height = i;
			}
		}
	}
	cout << minWeight << " " << height;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> b;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
	}

	sort(v.begin(), v.end());

	for(auto value : v)
	{
		if(compact_v.empty() || compact_v.back().first != value)
		{
			compact_v.push_back({ value,1 });
		}
		else
		{
			compact_v.back().second += 1;
		}
	}

	solution();
}