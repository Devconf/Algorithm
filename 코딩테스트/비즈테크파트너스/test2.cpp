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
	string rid = "981020-1074839"; //ÁÖ¹Î¹øÈ£  

	string answer = "";
	string year = "";
	string sex = "";

	if(rid[7] == '1')
	{
		year = "19";
		year.push_back(rid[0]);
		year.push_back(rid[1]);
		sex = "M";
	}
	if(rid[7] == '2')
	{
		year = "19";
		year.push_back(rid[0]);
		year.push_back(rid[1]);
		sex = "F";
	}
	if(rid[7] == '3')
	{
		year = "20";
		year.push_back(rid[0]);
		year.push_back(rid[1]);
		sex = "M";
	}
	if(rid[7] == '4')
	{
		year = "20";
		year.push_back(rid[0]);
		year.push_back(rid[1]);
		sex = "F";
	}

	answer = year + "/" + sex;

	cout << answer;

	return 0;
}