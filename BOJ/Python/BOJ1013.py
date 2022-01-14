# 아래 풀이법은 정규표현식을 사용하여 푼 방법이다.
import re

def main():
    num=int(input())
    while num:
        data= str(input())
        regex = re.compile('(100+1+|01)+')
        match = regex.fullmatch(data)
        if match == None:
            print("NO")
        else:
            print("YES")
        
        num-=1



if __name__ =="__main__":
    main()


######################################################33
#아래 코드는 문제에서 주어진 문자열을 패턴에 맞게 나이브하게 푼 방법이다
def main():
    num=int(input())
    while num:
        match=""
        oneCnt=0
        zeroCnt=0
        data= str(input())
        for idx in range(0,len(data)):
            if data[idx] == "1":
                if match  == "":
                    oneCnt+=1
                    match += data[idx]
                    continue
                elif match == "0":
                    zeroCnt=0
                    oneCnt=0
                    match =""
                    continue
                else:
                    oneCnt+=1
                    match += data[idx]
                    continue

            if data[idx] == "0":
                if match == "" :
                    zeroCnt+=1
                    match+=data[idx]
                    continue
                elif oneCnt == 1:
                    zeroCnt+=1
                    match+=data[idx]
                    continue
                elif oneCnt >= 2 and zeroCnt >=2:
                    if data[idx-2] == "1":
                        if len(data[idx:-1])>=2:
                            if data[idx+1] == "0":
                                match=""
                                zeroCnt=1
                                oneCnt=1
                                match ="10"
                                continue
                            else:
                                match=""
                                zeroCnt=1
                                oneCnt=0
                                match ="0"
                                continue
                        else:
                            match=""
                            zeroCnt=1
                            oneCnt=0
                            match ="0"
                            continue
                    else:
                        match=""
                        zeroCnt=0
                        oneCnt=0
                        zeroCnt+=1
                        match+=data[idx]
                        continue
                    continue
                else:
                    break
        
        if len(match) == 0:
            print("YES")
        else:
            if zeroCnt >=2:
                if oneCnt >=2:
                    print("YES")
                else:
                    print("NO")
            else:
                print("NO")
        num-=1



if __name__ =="__main__":
    main()