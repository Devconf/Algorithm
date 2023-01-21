#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;

	for(int i = 0; i < n; i++)
	{
		string method;
		cin >> method;

		if(method == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if(method == "size")
		{
			cout << q.size() << "\n";
		}
		else if(method == "empty")
		{
			if(q.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			if(q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				if(method == "pop")
				{
					cout << q.front() << "\n";
					q.pop();
				}
				else if(method == "front")
				{
					cout << q.front() << "\n";
				}
				else if(method == "back")
				{
					cout << q.back()<<"\n";
				}
			}
		}
	}
}