def solution(places):
    answer = [0,0,0,0,0]

    for place_num,place in enumerate(places):
        person_location = []
        flag =True
        for i,row in enumerate(place):
            for j in range(len(row)):
                if row[j]=="P":
                    person_location.append((i,j))
        
        for i in range(len(person_location)):
            for j in range(i+1,len(person_location)):
                if abs(person_location[i][0] - person_location[j][0]) + abs(person_location[i][1] - person_location[j][1]) <2:
                    flag=False
                if abs(person_location[i][0] - person_location[j][0]) + abs(person_location[i][1] - person_location[j][1]) == 2:
                    if person_location[i][0] == person_location[j][0]:
                        if place[person_location[i][0]][int((person_location[i][1]+person_location[j][1])/2)] =="O":
                            flag=False
                    if person_location[i][1] == person_location[j][1]:
                        if place[int((person_location[i][0]+person_location[j][0])/2)][person_location[i][1]] =="O":
                            flag=False
                    if place[person_location[i][0]][person_location[j][1]] =="O" or place[person_location[j][0]][person_location[i][1]] =="O":
                        flag= False
        if flag:
            answer[place_num] =1

    return answer

if __name__ =="__main__":
    s= [
        ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], 
        ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], 
        ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], 
        ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], 
        ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]
        ]
    print(solution(s))