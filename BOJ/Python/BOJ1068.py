# 아래 코드는 DFS를 이용하여 특정 노드의 자식노드를 지워 새로운 트리를 만드는 방법이다.

def findChild(arr,killnode):
    tempArr= arr
    if len(killnode) == 0:  
        return arr
    
    for nodeNum in killnode:
        newArr = []
        killchild =[]
        for idx, node in enumerate(tempArr):
            if list(tempArr[idx].keys())[0] == nodeNum:
                killchild.append(list(tempArr[idx].values())[0])
            else:
                newArr.append(tempArr[idx])

        tempArr = findChild(newArr,killchild)
    return tempArr
    


def findLeaf(node):
    leaf = 0
    for i in node:
        parent = list(i.values())[0]
        sum =0
        for j in node:
            if list(j.keys())[0] == parent:
                sum+=1
        if sum == 0:
            leaf +=1
    print(leaf)


def main():
    node = int(input())
    arr = [{int(e):i} for i,e in enumerate(input().split(' '))]
    killnode =int(input())

    for idx , node in enumerate(arr):
        if list(arr[idx].values())[0] ==killnode:
            if list(arr[idx].keys())[0] == -1:
                print(0)
                return
            else:
                arr.pop(idx)
    findLeaf(findChild(arr, [killnode]))

if __name__ == "__main__":
    main()