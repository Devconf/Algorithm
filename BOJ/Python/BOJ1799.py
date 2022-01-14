from sys import stdin

n = 0
cnt_black = 0
cnt_white = 0
bord = []
max_black=0
max_white=0
left_down_check = []
left_up_check = []


def promissing(x,y):
    global n, bord, left_down_check, left_up_check
    flag =True
    if bord[x][y] ==1 and 0<= x <n and 0<= y <n:
        if left_down_check[y+x] or left_up_check[(n-1) + (y-x)]:
                flag =False
        return flag
    return False 


def black(x,y):
    global n, left_down_check, left_up_check, cnt_black,max_black
    
    for ny in range(y,x-1,-1):
        nx = y - ny
        if nx >= 2*n - 1 or ny >=2*n - 1:
            max_black = max(max_black,cnt_black)
            return

        if promissing(nx, ny):
            cnt_black+=1
            left_down_check[ny+nx] = True
            left_up_check[(n-1) + (ny-nx)] =True
            black(0,nx+ny+2)
            left_down_check[ny+nx] = False
            left_up_check[(n-1) + (ny-nx)] = False
            cnt_black-=1
    return black(0,x+y+2)


def white(x,y):
    global n, left_down_check, left_up_check, cnt_white,max_white
    
    for ny in range(y,x-1,-1):
        nx = y - ny
        if nx >= 2*n - 1 or ny >=2*n - 1:
            max_white = max(max_white,cnt_white)
            return

        if promissing(nx, ny):
            cnt_white+=1
            left_down_check[ny+nx] = True
            left_up_check[(n-1) + (ny-nx)] =True
            white(0,nx+ny+2)
            left_down_check[ny+nx] = False
            left_up_check[(n-1) + (ny-nx)] = False
            cnt_white-=1
    return white(0,x+y+2)
    
def main():
    global n , bord, left_down_check, left_up_check, cnt_black,cnt_white,max_black
    n= int(stdin.readline().split()[0])

    tmp_bord =[]
    for _ in range(n):
        row = [num for num in map(int,stdin.readline().rstrip().split())]
        tmp_bord.append(row)

    
    for i in range(2*n-1):
        bord.append([0 for j in range(2*n-1)])
        
    for i in range(n):
        for j in range(n):
            if tmp_bord[i][j] == 1:
                bord[i][j] = 1

    for idx in range(0,2*n-1):
        left_down_check.append(False)
        left_up_check.append(False)
    

    for y in range(n):
        black(0, y*2)
        white(0, y*2+1)

    print(max_black+ max_white)
    return 0

if __name__ == "__main__":
    main()