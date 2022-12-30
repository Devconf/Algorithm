//#include<iostream>
//#include<string>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//int alpa[26];
//
////각 자릿수의 합을 계산 하지 않음
////예를 들어 ABB, BC, BC, BC, BC, BC, BC, BC, BC, BC 일경우 A는 100, B는 10의자리 10개 1의자리 1개 로 총101이되어 B가 더 가중치가 있음
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	memset(alpa, -1, sizeof(alpa));
//
//	int n;
//
//	cin >> n;
//
//	priority_queue<pair<int,string>,vector<pair<int,string>>,less<pair<int,string>>> pq ;
//	vector<string> v;
//
//	for(int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//		v.push_back(s);
//		pq.push({ s.length(),s });
//	}
//
//	int num = 9;
//	while(!pq.empty())
//	{
//		
//		pair<int, string> top = pq.top();
//		pq.pop();
//
//		if(top.second == "")
//		{
//			continue;
//		}
//
//		string sub = top.second.substr(1, top.second.size()-1);
//		char front = top.second[0];
//
//		if(alpa[front - 'A'] == -1)
//		{
//			alpa[front - 'A'] = num;
//			pq.push({ sub.size(),sub });
//			num--;
//		}
//		else
//		{
//			pq.push({ sub.size(),sub });
//		}
//	}
//
//	int maxNum = 0;
//	for(int i = 0; i < v.size(); i++)
//	{
//		string result = "";
//		for(int j = 0; j < v[i].size(); j++)
//		{
//			result.append(to_string(alpa[v[i][j] - 'A']));
//		}
//		maxNum += stoi(result);
//	}
//
//	cout << maxNum;
//}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int alpa[26];
vector<pair<int, int>> weight;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

//각 자릿수의 합을 계산 하지 않음
//예를 들어 ABB, BC, BC, BC, BC, BC, BC, BC, BC, BC 일경우 A는 100, B는 10의자리 10개 1의자리 1개 로 총101이되어 B가 더 가중치가 있음
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(alpa, -1, sizeof(alpa));
	for(int i = 0; i < 26; i++)
	{
		weight.push_back({ 0,-1 });
	}

	int n;

	cin >> n;

	vector<string> v;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		for(int j = 0; j < s.size(); j++)
		{
			weight[s[j] - 'A'].first += pow(10, s.size() - j);
			weight[s[j] - 'A'].second = s[j] - 'A';
		}
	}

	sort(weight.begin(), weight.end(),cmp);

	int num = 9;
	for(int i = 0; i < 10; i++)
	{
		alpa[weight[i].second] = num;
		num--;
	}
	
	int maxNum = 0;
	for(int i = 0; i < v.size(); i++)
	{
		string result = "";
		for(int j = 0; j < v[i].size(); j++)
		{
			result.append(to_string(alpa[v[i][j] - 'A']));
		}
		maxNum += stoi(result);
	}

	cout << maxNum;
}
