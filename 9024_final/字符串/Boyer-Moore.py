
def string_match_boyer_moore(T,P):
    n = len(T)
    m = len(P)
    i = m - 1
    j = m - 1
    num = 1
    while i < n:
        print('---第',num,'次---')
        num+=1
        count = i - j
        print(T)
        print(' '*count+P)
        if T[i] == P[j]:
            if j == 0:
                return i
            else:
                i -=1
                j -=1
        else:
            i = i+m-min(j,1+L(T[i],P))
            j = m-1
    return -1





    
def L(c,P):
    for i in range(len(P)-1,-1,-1):
        if c == P[i]:
            return i
    return -1


string_match = input('长字符:')
sub = input('短字符:')
if string_match_boyer_moore(string_match,sub) == -1:
    print('失败')
else:
    print('成功')