#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int n, m;
string poketmonName[100002];
map<string,int> poketmonList;

struct compare
{
	bool operator()(const pair<int, int>& value,
		const int& key)
	{
		return (value.first < key);
	}
	bool operator()(const int& key,
		const pair<int, int>& value)
	{
		return (key < value.first);
	}
};

void solution()
{
	for(int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if(s[0] < 65)
		{
			int num = stoi(s);
			cout << poketmonName[num] << "\n";
		}
		else
		{
			cout << poketmonList[s] << "\n";
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		poketmonName[i] = s;//숫자로 물어봤을경우

		int hash = 0;
		for(int j = 0; j < s.size(); j++)
		{
			hash += s[j];
		}
		poketmonList.insert({ s,i });
	}

	solution();

}