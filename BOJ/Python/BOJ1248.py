# 아래 코드는 부호에 맞는 적절한 수를 찾는 문제로 백트랙킹을 이용하여 해결하였다.

from sys import stdin
n = 0
answer = []
result=[]
def possible(idx):
    sum_val =0
    for i in range(idx,-1,-1):
        sum_val+=result[i]
        if answer[i][idx] == '+' and sum_val <= 0:
            return False
        if answer[i][idx] == '-' and sum_val >= 0:
            return False
        if answer[i][idx] == '0' and sum_val != 0:
            return False
    return True

def find_match(idx):
    if idx == n:
        tmp= ''
        for _, val in enumerate(result):
            tmp +=(str(val) +' ')
        print(tmp.rstrip())
        exit(0)

    for i in range(-10, 11):
        result.append(i)
        
        if possible(idx):
            find_match(idx+1)
        del result[idx]


def main():
    global n
    n = int(stdin.readline())

    str_input = stdin.readline().rstrip()

    global answer
    
    for _ in range(n):
        tmp = []
        for _ in range(n):
            tmp.append(' ')
        answer.append(tmp)
    
    cnt = 0
    for i in range(n):
        for j in range(i,n):
            answer[i][j] = str_input[cnt]
            cnt+=1 
    
    find_match(0)

if __name__ == "__main__":
    main()