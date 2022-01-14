#아래 풀이법은 감소하는 수를 브루트포스를 이용하여 해결하였다.

lst =['0','1','2','3','4','5','6','7','8','9']

def getDecreaseNum(current):
    nextList=[]
    for i in current:
        for j in lst:
            if i[len(i)-1] > j[len(j)-1]:
                nextList.append(i+j)
    return nextList

def main():
    decreaseNum =['0','1','2','3','4','5','6','7','8','9']
    currentDecreaseNum =[]
    nextDecreaseNum =[]
    n= int(input())

    currentDecreaseNum = lst
    #print(currentDecreaseNum)
    while len(decreaseNum) <= n:
        nextDecreaseNum = getDecreaseNum(currentDecreaseNum)
        if len(nextDecreaseNum) == 0:
            print(-1)
            return
        currentDecreaseNum = nextDecreaseNum
        decreaseNum += nextDecreaseNum

    if n==0:
        print(0)
    else:
        print(decreaseNum[n])    
            

if __name__ == "__main__":
    main()