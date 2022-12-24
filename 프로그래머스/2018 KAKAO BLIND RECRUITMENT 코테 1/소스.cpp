#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> map1(n, 0);
	vector<int> map2(n, 0);
	vector<int> result(n, 0);
	vector<string> answer;

	for(int i = 0; i < map1.size(); i++)
	{
		int num;
		cin >> num;
		map1[i] = num;
	}

	for(int i = 0; i < map2.size(); i++)
	{
		int num;
		cin >> num;
		map2[i] = num;
	}

	for(int i = 0; i < result.size(); i++)
	{

		result[i] = map1[i]|map2[i];
	}

	for(int i = 0; i < result.size(); i++)
	{
		string bitString = bitset<16>(result[i]).to_string();
		string temp = "";
		for(int j = 16 - n; j < 16; j++)
		{
			if(bitString[j] == '1')
			{
				temp.push_back('#');
			}
			else
			{
				temp.push_back(' ');
			}
		}
		answer.push_back(temp);
	}

	for(int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

}