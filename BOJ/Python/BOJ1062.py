#아래 문제는 브루트포스와 비트마스킹을 이용하여 푼 문제이다.

from sys import stdin
from itertools import combinations

bin_dic = {
    'b':20,'d':19,'e':18,'f':17,'g':16,'h':15,'j':14,'k':13,'l':12,'m':11,'o':10,
    'p':9,'q':8,'r':7,'s':6,'u':5,'v':4,'w':3,'x':2,'y':1,'z':0
}

def word_to_bin(word):
    result=0b0
    for x in word:
        result = result | (1<<bin_dic[x])
    
    return result


n,k=map(int,stdin.readline().split(' '))
words=[]
max_cnt =0
for _ in range(n):
    words.append(set(stdin.readline().rstrip()[4:-4]).difference('a','n','t','i','c'))

if k < 5:
    print(0)
else:
    bin_list = [word_to_bin(x) for x in words]
    
    power_of_2 = [(2**i) for i in range(21)]
    
    for combi in combinations(power_of_2,k-5):
        current= sum(combi)
        cnt=0
        for bin_word in bin_list:
            if bin_word & current == bin_word:
                cnt+=1
        max_cnt = max(max_cnt,cnt)
    print(max_cnt)
        
    
