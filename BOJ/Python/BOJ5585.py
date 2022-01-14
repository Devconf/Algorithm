# 아래 코드는 그리디알고리즘을 이용하여 푼 문제이다.

if __name__ == "__main__":
    indata=1000-int(input())
    n=[500,100,50,10,5,1]
    cnt=1
    sum=0
    for i in n:
        if (indata // i) >0:
            cnt=sum+(indata//i)
            sum=cnt
            indata-=(i*(indata//i))
            continue
    print(sum)
    #print(indata)