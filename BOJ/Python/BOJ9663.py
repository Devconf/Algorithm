'''
아래 코드는 n-queen문제를 백트랙킹을 이용하여 푼 문제이다.
queen은 가로 세로 대각선을 움직일수 있으므로 한 줄에는 최대 한개의 queen만 존재할 수 있다.
따라서 i,j부터 j++ 하면서 queen을 놓아간다. 만약 queen을 좋았을경우 i를 증가시켜
다음번 queen이 들어갈 수 있는 자리를 탐색한다.
'''
from sys import stdin

n=0
cnt=0 
chess =[]

def promising(x):
    global chess
    flag =True
    idx =0
    while idx<x and flag:
        if chess[idx] == chess[x] or abs(chess[x] - chess[idx]) == (x - idx):
            flag =False
            break
        idx+=1
    return flag

def queens(x,cnt):
    global n, chess
    
    if promising(x):
        if x == n-1:
            cnt+=1
            return cnt
        else:
            for y in range(n): # 특정 행에 몇번째 열에 queen이 들어갔는지 저장한다
                chess[x+1]= y
                cnt = queens(x+1, cnt)
            chess[x+1] = 0
            return cnt
    return cnt


def main():
    global n , chess, cnt
    n = int(stdin.readline().split()[0])
    
    for _ in range(n):
        chess.append(0)
    print(queens(-1, 0))

if __name__ =="__main__":
    main()
