#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, c, k;
int maxLength = (int)2e9;
vector<int> v;

//���̵��� ������ ���� mid�� �̺�Ž���� ���� ã�ư���. ���⼭ ������ �����ϰ� �ڸ� �볪�� ������ ���̰�
//mid�� ���̺��� �۾ƾ��Ѵ�. 
void BS(int left, int right)
{
	if(left > right)
	{
		return;
	}
	int mid = (left + right) / 2;
	int length = l;
	int cnt = 0;

	int diff = 0;
	//�볪���� �߶���� ���� ������ ���̰� mid���� Ŀ�������̴�.
	for(int i = k; i >=0; i--)
	{
		diff += (v[i+1] - v[i]);
		if(diff > mid)//�������� mid���� ���� v[i]���� �ڸ���.
		{
			cnt++;
			diff = v[i+1] - v[i]; //�������� �߰��� ���̰�
			if(diff > mid) //�������� �߰��� ���̰� mid���� ���� mid�� �������ؾ��Ѵ�.
			{
				cnt = c + 1;
				break;
			}
		}
	}

	if(cnt > c)//��� �볪���� mid�� ���̷� �ڸ��� ���⶧���� mid�� �÷��ش�.
	{
		return BS(mid+1, right);
	}
	else
	{
		maxLength = min(maxLength, mid);
		return BS(left, mid-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> k >> c;

	v.push_back(0);
	v.push_back(l);

	for(int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = (int)1e9+1;

	BS(0,l);

	int diff = 0, cnt = 0;
	int idx = k;

	for(int i = k; i >= 0; i--)
	{
		diff += (v[i + 1] - v[i]);
		if(diff > maxLength)//�� ���������� �볪�� �������� �ִ���̺��� ū ��� cut ������ ���Ѵ�. 
		{
			cnt++;
			diff = v[i + 1] - v[i];
			idx = i + 1;
		}
	}

	if(cnt < c)
	{
		idx = 1;
	}

	cout << maxLength << " " << v[idx];
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int L, K, C;
//int D[10002];
//int First;
//
//int BS(int left, int right)
//{
//	if(left >= right)
//	{
//		return right;
//	}
//	int mid = (left + right) / 2;
//	int temp = 0;
//	int cnt = C;
//
//	if(D[0] > mid)
//	{
//		cnt = -1;
//	}
//
//	//���� �� �볪�� ������ ������ mid
//	//�ڸ� �� �ִ� ��ġ ������ ��� �ϳ��� mid���� ũ�ٸ� ���ذ��� Ŀ���� �Ѵ�.
//	for(int i = 1; i <= K; i++)
//	{
//		if(D[i] - D[i - 1] > mid)
//		{
//			cnt = -1;
//			break;
//		}
//	}
//
//	//�볪���� �߶���� ���� ������ ���̰� mid���� Ŀ�������̴�.
//	for(int i = 0; i < K; i++)
//	{
//		if(D[i + 1] - temp > mid)
//		{
//			temp = D[i];
//			cnt--;
//		}
//		if(cnt < 0)break;
//	}
//
//	//�볪���� �ڸ� �� �ִ� Ƚ���� �ʰ��Ͽ��ٸ� ���ذ��� �۾������Ѵ�.
//	if(cnt >= 0)
//	{
//		return BS(left, mid);
//	}
//	//�볪���� C���ȿ� ��� �߶��ٸ� ������ ������ ���� �� �ٿ�������.
//	else
//	{
//		return BS(mid + 1, right);
//	}
//}
//
//
//int main()
//{
//	cin >> L >> K >> C;
//
//	if(C > K)
//	{
//		C = K;
//	}
//	int idx = 0;
//	int tempK = K;
//	while(tempK--)
//	{
//		cin >> D[idx];
//		idx++;
//	}
//	D[idx] = L;
//
//	sort(D, D + K + 1);
//
//	int ans = BS(0, L);
//
//	int cnt = C;
//	int temp = L;
//	//���� ���ϰ� ������ �������� �볪���� �ڸ���.
//
//	for(int i = K - 1; i >= 0; i--)
//	{
//		if(temp - D[i] > ans)
//		{
//			//		cout << "�ڸ� �볪�� ��ġ: " << D[i+1] << endl;
//			temp = D[i + 1];
//			cnt--;
//		}
//	}
//	//cout << cnt << endl;
//	if(cnt > 0)
//	{
//		First = D[0];
//	}
//	else
//	{
//		First = temp;
//	}
//
//	cout << ans << ' ' << First << endl;
//
//	return 0;
//}