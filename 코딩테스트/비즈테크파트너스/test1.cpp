#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}

int main()
{
	vector<string> movie = { "spy","ray","spy","room","once","ray","spy","once" };

	vector<pair<string, int>> answer;

	vector<string> result;

	for(int i = 0; i < movie.size(); i++)
	{
		bool isFind = false;

		for(int j = 0; j < answer.size(); j++)
		{
			if(answer[j].first == movie[i])
			{
				answer[j].second++;
				isFind = true;
				break;
			}
		}
		if(!isFind)
		{
			answer.push_back({ movie[i],1 });
		}
	}

	sort(answer.begin(), answer.end(), compare);

	for(int i = 0; i < answer.size(); i++)
	{
		result.push_back(answer[i].first);
	}

	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}