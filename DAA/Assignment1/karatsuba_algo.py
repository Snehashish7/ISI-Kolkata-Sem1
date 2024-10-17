def karatsuba(num1,num2):
    if num1 < 10 or num2 < 10:
        return num1*num2
    
    #convert to string to get number of digits easily
    str_num1 = str(num1)
    str_num2 = str(num2)
    num_digits = max(len(str_num1),len(str_num2))
    half_dig = (num_digits + 1)//2

    a1, a0 = num1//(10**half_dig), num1%(10**half_dig)
    b1, b0 = num2//(10**half_dig), num2%(10**half_dig)

    a1b1 = karatsuba(a1,b1)
    a0b0 = karatsuba(a0,b0)
    rest = karatsuba(a1+a0,b1+b0) #calculating (a1+a0)(b1+b0)

    return (10**(2*half_dig))*a1b1 +(10**((2*half_dig)//2))*(rest - (a1b1+a0b0)) + a0b0

num1 = int(input())
num2 = int(input())
print("karatsuba", karatsuba(num1, num2))