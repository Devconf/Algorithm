change_data =[]
delete_data = []
def update(location,cmd):
    global change_data ,delete_data
    if len(cmd)>1:
        command, num = map(str, cmd.split())
        if command =="D":
            return location + int(num)
        elif command == "U":
            return location - int(num)
    else:
        command =cmd    
        if command == "C":
            print(delete_data)
            delete_data.append((location,change_data[location]))
            del change_data[location]
            return location
        elif command == "Z":
            print(delete_data)
            print(list(delete_data[-1:][0])[1])
            change_data.insert(int(list(delete_data[-1:][0])[1]), int(list(delete_data[-1:][0])[1]))
            delete_data.pop()
            return location

def solution(n, k, cmd):
    global change_data
    data = [i for i in range(n)]
    change_data = data
    for command in cmd:
        k = update(k, command)
    
    print(data)
    print(change_data)
    answer = ''
    return answer

if __name__ =="__main__":
    n=8
    k=2
    cmd = ["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]

    print(solution(n,k,cmd))