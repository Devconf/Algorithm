#include<iostream>
#include<string>
using namespace std;

string num[10] = { "zero","one","two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };

int searchNum(string s)
{
	for(int i = 0; i < 10; i++)
	{
		if(num[i] == s)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	string s="";
	string result = "";

	cin >> s;

	for(size_t j = 0; j < 10; j++)
	{
		if(s.find(num[j]) != string::npos)
		{
			//replace(시작index, 구간, 치환문자)
			s.replace(s.find(num[j]), num[j].length(), to_string(j));
			j--;
		}

	}

	cout << s;
}