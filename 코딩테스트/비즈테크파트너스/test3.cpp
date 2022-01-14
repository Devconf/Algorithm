#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int> prices = { 13000,88000,10000 };
	vector<int> discounts = { 30, 20 };


	int answer = 0;

	sort(prices.begin(), prices.end(), compare);
	sort(discounts.begin(), discounts.end(), compare);

	for(int i = 0; i < prices.size(); i++)
	{
		if(i >= discounts.size())
		{
			answer += prices[i];
			continue;
		}
		answer += prices[i] * (100 - discounts[i]) / 100;

	}
	cout << answer;
		
	return 0;
		
}