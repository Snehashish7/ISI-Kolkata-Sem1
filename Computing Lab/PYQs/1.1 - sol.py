def large_sum(s1,s2):
    max_len = max(len(s1),len(s2))
    sum_arr = [0]*(max_len+1)
    i = max_len
    end_s1, end_s2 = len(s1)-1, len(s2)-1
    carry = 0
    while(1):
        summ = 0
        if end_s1 >= 0 and end_s2 >= 0:
            summ = int(s1[end_s1]) + int(s2[end_s2]) + carry
            if summ > 9:
                carry = summ//10
                summ %= 10
            else:
                carry = 0
            sum_arr[i] = summ
            end_s1 -= 1
            end_s2 -= 1

        elif end_s1 >= 0:
            summ = int(s1[end_s1]) + carry
            sum_arr[i] = summ
            end_s1 -= 1

        elif end_s2 >= 0:
            summ = int(s2[end_s2]) + carry
            sum_arr[i] = summ
            end_s2 -= 1
        
        else:
            break

        i -= 1
    
    cnt = 0
    for j in range(len(sum_arr)):
        if sum_arr[j] == 0:
            cnt += 1
        else:
            break

    res = "".join(map(str,sum_arr[cnt:]))
    return res if len(res) > 0 else '0'

def large_diff(s1,s2):
    max_len = max(len(s1),len(s2))
    sum_arr = [0]*(max_len+1)
    i = max_len
    end_s1, end_s2 = len(s1)-1, len(s2)-1
    carry = 0
    while(1):
        summ = 0
        if end_s1 >= 0 and end_s2 >= 0:
            summ = int(s1[end_s1]) - int(s2[end_s2]) + carry
            if summ < 0:
                carry = -1
                summ += 10
            else:
                carry = 0
            sum_arr[i] = summ
            end_s1 -= 1
            end_s2 -= 1

        elif end_s1 >= 0:
            summ = int(s1[end_s1])+carry
            if summ < 0:
                carry = -1
                summ += 10
            else:
                carry = 0
            sum_arr[i] = summ
            end_s1 -= 1

        elif end_s2 >= 0:
            summ = int(s2[end_s2])+carry
            if summ < 0:
                carry = -1
                summ += 10
            else:
                carry = 0
            sum_arr[i] = summ
            end_s2 -= 1
        
        else:
            break

        i -= 1
    
    cnt = 0
    for j in range(len(sum_arr)):
        if sum_arr[j] == 0:
            cnt += 1
        else:
            break

    res = "".join(map(str,sum_arr[cnt:]))
    return res if len(res) > 0 else '0'


s1 = input()
s2 = input()
sign = input()

if sign == '+':
    print(large_sum(s1,s2))
elif sign == '-':
    print(large_diff(s1,s2))
else:
    print("Please check the inputs")