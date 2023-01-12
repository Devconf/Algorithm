#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, c, k;
int maxLength = (int)2e9;
vector<int> v;

//아이디어는 적절한 길이 mid를 이분탐색을 통해 찾아간다. 여기서 정답은 적절하게 자른 통나무 각각의 길이가
//mid의 길이보다 작아야한다. 
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
	//통나무를 잘라야할 경우는 구간의 길이가 mid보다 커졌을때이다.
	for(int i = k; i >=0; i--)
	{
		diff += (v[i+1] - v[i]);
		if(diff > mid)//누적합이 mid보다 긴경우 v[i]에서 자른다.
		{
			cnt++;
			diff = v[i+1] - v[i]; //마지막에 추가한 길이가
			if(diff > mid) //마지막에 추가한 길이가 mid보다 길경우 mid를 재조정해야한다.
			{
				cnt = c + 1;
				break;
			}
		}
	}

	if(cnt > c)//모든 통나무를 mid의 길이로 자를수 없기때문에 mid를 늘려준다.
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
		if(diff > maxLength)//맨 마지막부터 통나무 누적합이 최대길이보다 큰 경우 cut 갯수를 더한다. 
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
//	//가장 긴 통나무 길이의 기준은 mid
//	//자를 수 있는 위치 사이중 어느 하나라도 mid보다 크다면 기준값은 커져야 한다.
//	for(int i = 1; i <= K; i++)
//	{
//		if(D[i] - D[i - 1] > mid)
//		{
//			cnt = -1;
//			break;
//		}
//	}
//
//	//통나무를 잘라야할 경우는 구간의 길이가 mid보다 커졌을때이다.
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
//	//통나무를 자를 수 있는 횟수를 초과하였다면 기준값은 작아져야한다.
//	if(cnt >= 0)
//	{
//		return BS(left, mid);
//	}
//	//통나무를 C번안에 모두 잘랐다면 기준의 범위를 조금 더 줄여나간다.
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
//	//답을 구하고 나서는 끝점부터 통나무를 자른다.
//
//	for(int i = K - 1; i >= 0; i--)
//	{
//		if(temp - D[i] > ans)
//		{
//			//		cout << "자를 통나무 위치: " << D[i+1] << endl;
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