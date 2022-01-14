def solution(s):
    answer = ""
    end_idx=0
    data = ["zero","one","two","three","four","five",
            "six","seven","eight","nine"]
    
    find_idx = 0
    while True:
        if find_idx >= len(s):
            break

        if s[find_idx].isdigit():
            answer+=s[find_idx]
        else:
            for idx, val in enumerate(data):
                tmp_idx = s[find_idx:].find(val)
                if tmp_idx == 0:
                    answer+=str(idx)
                    find_idx+=len(val) -1
                    break

        find_idx+=1

    return answer

if __name__ =="__main__":
    s= input()
    solution(s)