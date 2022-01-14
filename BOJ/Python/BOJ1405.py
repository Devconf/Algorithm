# 아래 코드는 로봇이 움직일때 이동결로가 단순한 확률을 DFS를 이용하여 푼 문제이다.

from sys import stdin

dx = [1,0,-1,0]
dy =[0,1,0,-1] 
p =[]
visit =[]
n = 0
result = 0

def dfs(x,y,hop_cnt, sum_p):
    global result
    if visit[x][y] == 1:
        return

    if hop_cnt == n:
        result += sum_p
        return

    visit[x][y] = 1

    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        new_p = sum_p * p[i]
        if visit[nx][ny] == 0:
            dfs(nx,ny,hop_cnt+1 ,new_p)
            visit[nx][ny] = 0
            


def main():
    global n
    n, pe ,pw ,ps ,pn = map(int, stdin.readline().split())
    
    for _ in range(n*2):
        tmp = []
        for _ in range(n*2):
            tmp.append(0)
        visit.append(tmp)
    
    global p
    p = [(pe*0.01),(ps*0.01),(pw*0.01),(pn*0.01)]
    
    dfs(n-1,n-1,0,1)
    print(result)

if __name__ == "__main__":
    main()
