def grade_school_multiplication(A, B):   
    # Result --> store intermediate sums, initially all zeros
    res_arr = [0] * (len(A) + len(B))
    
    # Iterate through A in reverse
    for i in reversed(range(len(A))):
        a = int(A[i]) #current digit of A
        carry = 0

        # Iterate through B in reverse
        for j in reversed(range(len(B))):
            b = int(B[j]) #current digit of A
            # Multiply digits and add to the corresponding position in the result array
            sum = a * b + res_arr[i + j + 1] + carry
            carry = sum // 10
            res_arr[i + j + 1] = sum % 10
        
        # Add any leftover carry to the next position
        res_arr[i + j] += carry
    # Remove leading zeros from the result
    res_str = ""
    rflag = 0 #once the leading 0's are removed, dont remove any 0's after that
    for i in res_arr:
        if i == 0 and rflag == 0:
            continue
        else:
            rflag = 1
            res_str += str(i)
    if res_str:
        return int(res_str)
    return 0


# # Example usage:
# A = int(input())
# B = int(input())
# print(grade_school_multiplication(str(A), str(B)))  
