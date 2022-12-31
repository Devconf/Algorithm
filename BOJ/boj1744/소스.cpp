#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	bool zero = false;
	vector<int> plus;
	vector<int> minus;
	deque<int> q;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if(num > 0)
		{
			plus.push_back(num);
		}
		else 
		{
			minus.push_back(num);
		}
	}

	sort(plus.begin(), plus.end(), cmp);

	for(int i = 0; i < plus.size(); i++)
	{
		q.push_back(plus[i]);
	}

	int plusSum = 0;
	while(!q.empty())
	{
		if(q.size() == 1)
		{
			int first = q.front();
			q.pop_front();
			plusSum += first;
		}
		else
		{
			int first = q.front();
			q.pop_front();
			int second = q.front();
			q.pop_front();

			if(first + second <= first * second)
			{
				plusSum += first * second;
			}
			else
			{
				plusSum += first + second;
			}
		}
	}


	sort(minus.begin(), minus.end());

	

	for(int i = 0; i < minus.size(); i++)
	{
		if(minus[i] == 0)
		{
			zero = true;
			continue;
		}
		q.push_back(minus[i]);
	}

	if(q.size() > 0)
	{
		if(q.size() % 2 == 1) //음수가 홀수 일경우
		{
			if(zero)
			{
				q.pop_back();
			}

		}
	}
	

	int minusSum = 0;
	while(!q.empty())
	{
		if(q.size() == 1)
		{
			int first = q.front();
			q.pop_front();
			minusSum += first;
		}
		else
		{
			int first = q.front();
			q.pop_front();
			int second = q.front();
			q.pop_front();

			if(first + second <= first * second)
			{
				minusSum += first * second;
			}
			else
			{
				minusSum += first + second;
			}
		}
	}
	cout << plusSum + minusSum;
}