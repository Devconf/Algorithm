#include<iostream>
#include<string>
#include<deque>
using namespace std;

void parse(deque<int> &dq, string arr)
{
	string s = "";
	for(int i = 0; i < arr.size(); i++)
	{
		if(arr[i] == ']' || arr[i] == '[' || arr[i] == ',')
		{
			if(!s.empty())
			{
				dq.push_back(stoi(s));
				s = "";
			}
		}
		else
		{
			s.push_back(arr[i]);
		}
	}
}

void solution()
{
	deque<int> dq;
	string p;
	int n;
	string arr;
	bool isFront = true;

	cin >> p >> n >> arr;

	parse(dq, arr);

	for(int i = 0; i < p.size(); i++)
	{
		if(p[i] == 'D')
		{
			if(dq.empty())
			{
				cout << "error\n";
				return;
			}
			else
			{
				if(isFront)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}
		if(p[i] == 'R')
		{
			if(isFront)
			{
				isFront = false;
			}
			else
			{
				isFront = true;
			}
			
		}
	}

	if(dq.empty())
	{
		cout << "[]\n";
	}
	else
	{
		string result = "[";
		if(isFront)
		{
			while(!dq.empty())
			{
				result += to_string(dq.front()) + ",";
				dq.pop_front();
			}
			result[result.size()-1] = ']';
		}
		else
		{
			while(!dq.empty())
			{
				result += to_string(dq.back()) + ",";
				dq.pop_back();
			}
			result[result.size()-1] = ']';
		}

		cout << result<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		solution();
	}

}