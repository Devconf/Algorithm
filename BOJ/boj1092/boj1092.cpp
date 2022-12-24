#include<iostream>
#include<algorithm>
#include<functional>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int n, m;
vector<int> carrier, weight;

void greedy()
{
	int time = 0;
	if(carrier[0] < weight[0])
	{
		cout << -1;
		return;
	}
	else
	{
		while(!weight.empty())
		{
			int index = 0;

			for(int i = 0; i < weight.size(); i++)
			{
				if(index == carrier.size())
				{
					break;
				}
				if(carrier[index] >= weight[i])
				{
					index++;
					weight.erase(weight.begin() + i);
					i = i - 1;
				}
			}
			time++;
		}
	}
	cout << time;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, tmp;

	cin >> n;
	cin.clear();
	cin.ignore();

	getline(cin, s);
	stringstream ss(s);
	while(getline(ss, tmp, ' '))
	{
		carrier.push_back(stoi(tmp));
	}

	cin >> m;
	cin.clear();
	cin.ignore();

	getline(cin, s);
	stringstream ss1(s);
	while(getline(ss1, tmp, ' '))
	{
		weight.push_back(stoi(tmp));
	}
	sort(carrier.begin(), carrier.end(), greater<int>());
	sort(weight.begin(), weight.end(), greater<int>());
	greedy();

}