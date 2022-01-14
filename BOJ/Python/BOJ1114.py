from sys import stdin

spot = []
stick_len =[]

def cut(start, end):
    global spot
    max_val= (0,0,0)
    for idx in spot:
        left = (start,idx,idx)
        right =(idx+1,end,idx)
        tmp = left if abs(left[1]- left[0]+1) >= abs(right[1]-right[0] +1) else right
        max_val =  max_val if abs(max_val[1]-max_val[0]+1) >= abs(tmp[1]-tmp[0]+1) else tmp
        
    return max_val

def main():
    global spot, stick_len
    l,k,c = map(int, stdin.readline().split())
    start = 1
    end =l
    spot = sorted(list(map(int,stdin.readline().split())))
    stick_len = [0 for _ in range(len(spot)+1)]
    print(stick_len)
    stick_len[0] = (spot[0],spot[0])
    for idx in range(1,len(spot)):
        stick_len[idx]= (spot[idx],spot[idx]-spot[idx-1])
    stick_len[k] = (l,l-stick_len[k-1][0])
    print(stick_len)
    cnt =0
    while True:
        if c == 0:
            print(returned_spot[1]-returned_spot[0]+1, returned_spot[2])
            break
        returned_spot = cut(start,end)
        spot.remove(returned_spot[2])
        
        start = returned_spot[0]
        end = returned_spot[1]
        c-=1


if __name__=="__main__":
    main()