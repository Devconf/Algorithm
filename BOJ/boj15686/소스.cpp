#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

void solution()
{
	vector<pair<int, int>> home;
	vector<pair<int, int>> chicken;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;

			if(num == 1)
			{
				home.push_back({ i,j });
			}
			if(num == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	// 0��1�� ���� �� ���� ����
	vector<int> ind;

	// k=4, 4���� �����ϱ�
	int k = m;

	// k���� 1 �߰�
	for(int i = 0; i < k; i++)
	{
		ind.push_back(1);
	}

	// 2��(6��-2��)�� 0 �߰�
	for(int i = 0; i < chicken.size() - k; i++)
	{
		ind.push_back(0);
	}

	// ����
	sort(ind.begin(), ind.end());

	int minSum = 987654321;
	do
	{
		vector<pair<int, int>> selectedChicken;
		// ���
		for(int i = 0; i < ind.size(); i++)
		{
			if(ind[i] == 1)
			{
				selectedChicken.push_back(chicken[i]);
			}
		}

		int sum = 0;
		for(int i = 0; i < home.size(); i++)
		{
			int minDis = 987654321;
			for(int j = 0; j < selectedChicken.size(); j++)
			{
				minDis = min(minDis, abs(home[i].first - selectedChicken[j].first) + abs(home[i].second - selectedChicken[j].second));
			}
			sum += minDis;
		}
		minSum = min(minSum, sum);
	} while(next_permutation(ind.begin(), ind.end()));
	cout << minSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	solution();
}