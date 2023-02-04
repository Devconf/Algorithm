#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

void solution()
{
	int k;
	cin >> k;

	multiset<int> ms;

	for(int i = 0; i < k; i++)
	{
		char c;
		int num;

		cin >> c >> num;

		if(c == 'I')
		{
			ms.insert(num);
		}

		if(c == 'D')
		{
			if(num == 1)
			{
				if(!ms.empty())
				{
					multiset<int>::iterator it = ms.find(*--ms.end());
					ms.erase(it);
				}	
			}
			else
			{
				if(!ms.empty())
				{
					multiset<int>::iterator it = ms.find(*ms.begin());
					ms.erase(it);
				}
			}
		}
	}

	if(ms.empty())
	{
		cout << "EMPTY";
	}
	else
	{
		cout << *--ms.end() << " " << *ms.begin();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t > 0)
	{
		solution();
		cout << "\n";
		t--;
	}
}