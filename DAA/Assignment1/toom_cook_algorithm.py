class PolynomialMultiplication:
    def __init__(self, base_limit = 6561):
        self.base_limit = base_limit
    
    def naive_multiply(self, poly1, poly2):
        """ Simple polynomial multiplication by distributing terms. """
        try:
            len1, len2 = len(poly1), len(poly2)
            result = [0 for _ in range(len1 + len2)]
          
            for j in range(len2):
                for i in range(len1):
                    result[j + i] += poly1[i] * poly2[j]

            return result
        except Exception as e:
            raise

    def toom_cook_multiply(self, poly1, poly2):
        """ Efficient Toom-Cook Polynomial Multiplication. """
        
        a_at_0, a_at_1, a_at_neg1, a_at_neg2, a_at_inf = [], [], [], [], []
        b_at_0, b_at_1, b_at_neg1, b_at_neg2, b_at_inf = [], [], [], [], []
        result_at_0, result_at_1, result_at_neg1, result_at_neg2, result_at_inf = [], [], [], [], []
        
        try:
            length = len(poly1)
            if length <= 9: return self.naive_multiply(poly1, poly2)
            
            # Divide polynomials into three segments: low, mid, and high.
            seg_size = length // 3
            a_high, a_mid, a_low = poly1[seg_size*2:], poly1[seg_size:seg_size*2], poly1[:seg_size]
            b_high, b_mid, b_low = poly2[seg_size*2:], poly2[seg_size:seg_size*2], poly2[:seg_size]
            
            # Polynomial evaluations
            a_at_0, b_at_0 = a_low, b_low
            a_at_1 = [a_low[i] + a_mid[i] + a_high[i] for i in range(seg_size)]
            b_at_1 = [b_low[i] + b_mid[i] + b_high[i] for i in range(seg_size)]
            a_at_neg1 = [a_low[i] - a_mid[i] + a_high[i] for i in range(seg_size)]
            b_at_neg1 = [b_low[i] - b_mid[i] + b_high[i] for i in range(seg_size)]
            a_at_neg2 = [a_low[i] - 2*a_mid[i] + 4*a_high[i] for i in range(seg_size)]
            b_at_neg2 = [b_low[i] - 2*b_mid[i] + 4*b_high[i] for i in range(seg_size)]
            a_at_inf, b_at_inf = a_high, b_high
            
            # Recursive pointwise multiplications
            result_at_0 = self.toom_cook_multiply(a_at_0, b_at_0)
            result_at_1 = self.toom_cook_multiply(a_at_1, b_at_1)
            result_at_neg1 = self.toom_cook_multiply(a_at_neg1, b_at_neg1)
            result_at_neg2 = self.toom_cook_multiply(a_at_neg2, b_at_neg2)
            result_at_inf = self.toom_cook_multiply(a_at_inf, b_at_inf)
                        
            # Interpolation to calculate the coefficients
            r3, r2, r1, r0, r4 = [], [], [], result_at_0, result_at_inf
            
            # r3 = (-result_at_neg2 + 3*result_at_neg1 - 3*result_at_0 + result_at_1 + 12*result_at_inf) / 6
            for i in range(2*seg_size):
                temp = (-result_at_neg2[i] + 3*result_at_neg1[i] - 3*result_at_0[i] + result_at_1[i] + 12*result_at_inf[i]) // 6
                r3.append(temp)
                
            # r2 = (3*result_at_neg1 - 6*result_at_0 + 3*result_at_1 - 6*result_at_inf) / 6
            for i in range(2*seg_size):
                temp = (3*result_at_neg1[i] - 6*result_at_0[i] + 3*result_at_1[i] - 6*result_at_inf[i]) // 6
                r2.append(temp)
                
            # r1 = (result_at_neg2 - 6*result_at_neg1 + 3*result_at_0 + 2*result_at_1 - 12*result_at_inf) / 6
            for i in range(2*seg_size):
                temp = (result_at_neg2[i] - 6*result_at_neg1[i] + 3*result_at_0[i] + 2*result_at_1[i] - 12*result_at_inf[i]) // 6
                r1.append(temp)

            # Assemble final result
            final_result = r0 + r2 + r4
            for i in range(2*seg_size): final_result[i + seg_size] += r1[i]
            for i in range(2*seg_size): final_result[i + 3*seg_size] += r3[i]
                
            return final_result
            
        except Exception as e:
            raise

# Input handling
num1 = int(input())
num2 = int(input())
len_num1 = len(str(num1))
len_num2 = len(str(num2))

#padding smaller digits with 0.
if len_num1 % 3:
    len_num1 = len_num1 - len_num1 % 3 + 3
if len_num2 % 3:
    len_num2 = len_num2 - len_num2 % 3 + 3

digits_num1, digits_num2 = [], []
rem, temp = 0, num1

while len_num1:
    len_num1 -= 1
    if temp == 0:
        digits_num1.append(0)
        continue
    rem = temp % 10
    digits_num1.append(rem)
    temp = temp // 10
digits_num1.reverse()

rem, temp = 0, num2
while len_num2:
    len_num2 -= 1
    if temp == 0:
        digits_num2.append(0)
        continue
    rem = temp % 10
    digits_num2.append(rem)
    temp = temp // 10
digits_num2.reverse()

# Execute the multiplication
multiplier = PolynomialMultiplication()
result_list = multiplier.toom_cook_multiply(digits_num1, digits_num2)

# Sum the final result
final_result = 0
for i in range(len(result_list)):
    final_result += result_list[i] * (10 ** (len(result_list) - i - 1))

print(int(final_result) // 10)

'''
1234567895142
123457896541
'''