# 아래 코드는 그리디알고리즘과 우선순위 큐를 이용하여 푼 문제이다.

from sys import stdin
import heapq
import queue

n, k = map(int,stdin.readline().split())
max_sum =0;
jewelries = []
for _ in range(n):
    heapq.heappush(jewelries, list(map(int,stdin.readline().split())))

bags = [ int(stdin.readline().rstrip()) for _ in range(k)]
bags.sort()

tmp_jewelry=[]
for bag in bags:
    while jewelries and bag >= jewelries[0][0]:
        heapq.heappush(tmp_jewelry, -heapq.heappop(jewelries)[1])
    if tmp_jewelry:
        max_sum-=heapq.heappop(tmp_jewelry)
    elif not jewelries:
        break

print(max_sum)

