#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string s)
{
	vector<string> result;
	stringstream ss(s);
	string tmp;

	while(getline(ss, tmp, ' '))
	{
		result.push_back(tmp);
	}
	return result;
}

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	vector<pair<string, string>> v;
	map<string, string> m;

	for(auto data : record)
	{
		vector<string> parse = split(data);

		if(parse[0] == "Enter")
		{
			m.insert_or_assign(parse[1], parse[2]);
			v.push_back({ parse[1],"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." });
		}
		if(parse[0] == "Leave")
		{
			v.push_back({ parse[1],"´ÔÀÌ ³ª°¬½À´Ï´Ù." });
		}
		if(parse[0] == "Change")
		{
			m.insert_or_assign(parse[1], parse[2]);
		}
	}

	for(auto p : v)
	{
		answer.push_back(m.at(p.first) + p.second);
	}


	return answer;
}