lst = [int(item) for item in input().split()]
days = int(input())

lengt = len(lst)
newArr = [0]*(lengt+2)
for i in range(1,lengt+1):
    newArr[i] = lst[i-1]

prev_arr = newArr
next_arr = [0]*(lengt+2)

while(days):
    for i in range(1,lengt+1):
        if prev_arr[i-1] == prev_arr[i+1]:
            next_arr[i] = 0
        else:
            next_arr[i] = 1
    prev_arr = next_arr.copy()
    days-=1

print(next_arr[1:lengt+1])