#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s, rs;

	while(true){
		cin >> n;
		if(n == 0)
		{
			break;
		}

		s = to_string(n);
		rs = to_string(n);
		reverse(rs.begin(), rs.end());

		bool palindrome = true;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] != rs[i])
			{
				palindrome = false;
				break;
			}
		}

		if(palindrome)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
	return 0;
}