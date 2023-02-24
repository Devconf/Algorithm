#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, m;
string s;

//void solution()
//{
//	int cnt = 0;
//
//	for(int i = 0; i < m; i++)
//	{
//		if(s[i] == 'O')
//		{
//			continue;
//		}
//		
//		int k = 0;//IOI 갯수
//		while(s[i + 1] == 'O' && s[i + 2] == 'I')
//		{
//			k++;
//			if(k == n)
//			{
//				cnt++;
//				k--; // 오른쪽으로 +2만큼 이동했을때 k값 유지
//			}
//			i += 2;
//		}
//	}
//	cout << cnt;
//}

vector<int> getSkipTable(string pattern)
{
	int p = pattern.size();
	vector<int> skipTable(p, 0);

	int begin = 1, matched = 0; // matched는 몇개가 맞는지 length를 나타낸다.

	while(begin + matched < p)
	{
		if(pattern[matched] == pattern[begin + matched]) // matched는 접두부,begin+matched는 접미부를 나타낸다.
		{ 
			matched++;
			skipTable[begin + matched - 1] = matched;
		}
		else
		{
			if(matched == 0)
			{
				begin++;
			}
			else
			{
				// KMP 문자열 탐색 알고리즘 과 동일하게 불일치 발생 시
				// 매칭을 진행하면서 구했던 접두 접미사 길이 만큼 탐색을 건너뛸 수 있다
				begin += matched - skipTable[matched - 1];
				matched = skipTable[matched - 1];
			}
		}
	}
	return skipTable;
}


vector<int> kmpSearch()
{
	string pattern;
	vector<int> ret;
	vector<int> skip_table;

	for(int i = 0; i < 2 * n + 1; i++)
	{
		if(i % 2 == 0)
		{
			pattern.push_back('I');
		}
		else
		{
			pattern.push_back('O');
		}
	}

	int originLength = s.size(), patternLength = pattern.size();
	int begin = 0, matched = 0;

	skip_table = getSkipTable(pattern);

	while(begin <= originLength - patternLength)
	{
		if(matched < patternLength && s[begin + matched] == pattern[matched])
		{
			matched++;

			if(matched == patternLength)
			{
				ret.push_back(begin);
			}
		}
		else
		{
			if(matched == 0)
			{
				begin++;
			}
			else
			{
				begin += matched - skip_table[matched - 1];
				matched = skip_table[matched - 1];
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> s;
	vector<int> result;

	result = kmpSearch();

	cout << result.size();
}