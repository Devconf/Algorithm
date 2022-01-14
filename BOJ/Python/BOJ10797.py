if __name__ == "__main__":
    day=input()
    data=input()
    car=[int(x) for x in input.split()]
    car=data.split(" ")
    cnt=0
    for i in range(len(car)):
        if day in car:
            cnt+=1
            car.remove(day)
    print(cnt)