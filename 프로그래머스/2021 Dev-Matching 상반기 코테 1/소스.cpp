#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	int match = 0;
	int zeroCnt = 0;

	for(int i = 0; i < lottos.size(); i++)
	{
		if(lottos[i] == 0)
		{
			zeroCnt++;
			continue;
		}
		for(int j = 0; j < win_nums.size(); j++)
		{
			if(lottos[i] == win_nums[j])
			{
				match++;
			}
			
		}
	}

	if(match + zeroCnt >= 2)
	{
		answer.push_back(7 - (match + zeroCnt));
	}
	else
	{
		answer.push_back(6);
	}

	if(match >= 2)
	{
		answer.push_back(7 - match);
	}
	else
	{
		answer.push_back(6);
	}

	return answer;
}

int main()
{
	vector<int> lottos;
	lottos.push_back(44);
	lottos.push_back(11);
	lottos.push_back(0);
	lottos.push_back(0);
	lottos.push_back(31);
	lottos.push_back(25);

	vector<int> win_nums;
	win_nums.push_back(31);
	win_nums.push_back(10);
	win_nums.push_back(45);
	win_nums.push_back(1);
	win_nums.push_back(6);
	win_nums.push_back(19);

	solution(lottos, win_nums);
}