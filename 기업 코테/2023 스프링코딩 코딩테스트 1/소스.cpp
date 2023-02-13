#include<iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue<pair<pair<double, int>, int>, vector<pair<pair<double, int>, int>>, less<pair<pair<double, int>, int>>> pq;

int solution(vector<vector<int>> lotteries)
{
	int answer = 0;

	for(int i = 1; i <= lotteries.size(); i++)
	{
		if(lotteries[i-1][0] <= lotteries[i-1][1])
		{

			pq.push({ {((double)lotteries[i - 1][0] / (double)(lotteries[i - 1][1] + 1)) ,lotteries[i - 1][2]},i });
		}
		else
		{
			pq.push({ {(double)1/(double)1,lotteries[i - 1][2]},i });
		}
	}

	answer = pq.top().second;
	cout << answer;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> v;
	vector<int> v1,v2;
	v1.push_back(100);
	v1.push_back(100);
	v1.push_back(500);
	v.push_back(v1);
	v2.push_back(1000);
	v2.push_back(1000);
	v2.push_back(100);
	v.push_back(v2);

	solution(v);

}