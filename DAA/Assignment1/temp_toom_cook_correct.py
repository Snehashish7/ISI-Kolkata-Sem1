import random
import sys
import traceback

class LargeNumberMultiplication:
    MAX_DIGITS = 2187  # Maximum allowable digits (a power of 3)
    DIGITS = 2187  # Number of digits in the current computation (<= MAX_DIGITS)

    def _init_(self, num1, num2):
        self.num1 = [num1]
        self.num2 = [num2]

    def execute(self):
        """ Main method to perform the multiplication """
        try:
            for i in range(self.MAX_DIGITS - len(self.num1)):
                self.num1.append(0)
            for i in range(self.MAX_DIGITS - len(self.num2)):
                self.num2.append(0)
            result = self.toom_cook_multiplication(self.num1, self.num2)
            result = self.handle_carry(result)
            self.display_result(self.num1, self.num2, result)
        except Exception as error:
            raise

    def standard_multiply(self, num1, num2):
        """ Perform basic multiplication

        :param  list num1
        :param  list num2
        :return list result
        """
        try:
            len_num1, len_num2 = len(num1), len(num2)
            result = [0 for _ in range(len_num1 + len_num2)]
            for j in range(len_num2):
                for i in range(len_num1):
                    result[j + i] += num1[i] * num2[j]
            return result
        except Exception as error:
            raise

    def toom_cook_multiplication(self, num1, num2):
        """ Toom-Cook 3-way multiplication logic

        :param  list num1
        :param  list num2
        :return list result
        """
        num1_m1, num1_m2, num1_0, num1_1, num1_inf = [], [], [], [], []
        num2_m1, num2_m2, num2_0, num2_1, num2_inf = [], [], [], [], []
        result_m1, result_m2, result_0, result_1, result_inf = [], [], [], [], []
        partial0, partial1, partial2, partial3, partial4 = [], [], [], [], []
        try:
            length = len(num1)
            
            if length <= 9:
                return self.standard_multiply(num1, num2)

            # Split the numbers into three parts
            part_num1_0 = num1[:(length // 3)]
            part_num1_1 = num1[(length // 3):(length * 2 // 3)]
            part_num1_2 = num1[(length * 2 // 3):]
            part_num2_0 = num2[:(length // 3)]
            part_num2_1 = num2[(length // 3):(length * 2 // 3)]
            part_num2_2 = num2[(length * 2 // 3):]

            for i in range(length // 3):
                num1_m2.append((part_num1_2[i] << 2) - (part_num1_1[i] << 1) + part_num1_0[i])
                num2_m2.append((part_num2_2[i] << 2) - (part_num2_1[i] << 1) + part_num2_0[i])
            for i in range(length // 3):
                num1_m1.append(part_num1_2[i] - part_num1_1[i] + part_num1_0[i])
                num2_m1.append(part_num2_2[i] - part_num2_1[i] + part_num2_0[i])
            num1_0, num2_0 = part_num1_0, part_num2_0
            for i in range(length // 3):
                num1_1.append(part_num1_2[i] + part_num1_1[i] + part_num1_0[i])
                num2_1.append(part_num2_2[i] + part_num2_1[i] + part_num2_0[i])
            num1_inf, num2_inf = part_num1_2, part_num2_2

            # Recursive calls to Toom-Cook multiplication
            result_m2  = self.toom_cook_multiplication(num1_m2, num2_m2)
            result_m1  = self.toom_cook_multiplication(num1_m1, num2_m1)
            result_0   = self.toom_cook_multiplication(num1_0, num2_0)
            result_1   = self.toom_cook_multiplication(num1_1, num2_1)
            result_inf = self.toom_cook_multiplication(num1_inf, num2_inf)

            partial4 = result_inf
            for i in range((length // 3) * 2):
                temp = -result_m2[i]
                temp += (result_m1[i] << 1) + result_m1[i]
                temp -= (result_0[i] << 1) + result_0[i]
                temp += result_1[i]
                temp += (result_inf[i] << 3) + (result_inf[i] << 2)
                temp = temp // 6
                partial3.append(temp)
            for i in range((length // 3) * 2):
                temp = (result_m1[i] << 1) + result_m1[i]
                temp -= (result_0[i] << 2) + (result_0[i] << 1)
                temp += (result_1[i] << 1) + result_1[i]
                temp -= (result_inf[i] << 2) + (result_inf[i] << 1)
                temp = temp // 6
                partial2.append(temp)
            for i in range((length // 3) * 2):
                temp = result_m2[i]
                temp -= (result_m1[i] << 2) + (result_m1[i] << 1)
                temp += (result_0[i] << 1) + result_0[i]
                temp += (result_1[i] << 1)
                temp -= (result_inf[i] << 3) + (result_inf[i] << 2)
                temp = temp // 6
                partial1.append(temp)
            partial0 = result_0

            # Combine results
            result = partial0 + partial2 + partial4
            for i in range((length // 3) * 2):
                result[i + length // 3] += partial1[i]
            for i in range((length // 3) * 2):
                result[i + length] += partial3[i]
            return result
        except Exception as error:
            raise

    def handle_carry(self, result):
        """ Handle carryovers in the result

        :param  list result
        :return list result
        """
        carry = 0
        try:
            for i in range(len(result)):
                result[i] += carry
                carry = result[i] // 10
                result[i] -= carry * 10
            if carry != 0:
                print("[CARRY OVERFLOW] ", carry)
            return result
        except Exception as error:
            raise

    def display_result(self, num1, num2, result):
        """ Output the numbers and result

        :param list num1
        :param list num2
        :param list result
        """
        len_num1 = self.MAX_DIGITS
        len_num2 = self.MAX_DIGITS
        len_result = self.MAX_DIGITS * 2
        try:
            while num1[len_num1 - 1] == 0:
                len_num1 -= 1
            while num2[len_num2 - 1] == 0:
                len_num2 -= 1
            while result[len_result - 1] == 0:
                len_result -= 1

            print("Number 1 =")
            for i in reversed(range(len_num1)):
                print(num1[i], end="")
                if (len_num1 - i) % 10 == 0:
                    print(" ", end="")
                if (len_num1 - i) % 50 == 0:
                    print()
            print("\nNumber 2 =")
            for i in reversed(range(len_num2)):
                print(num2[i], end="")
                if (len_num2 - i) % 10 == 0:
                    print(" ", end="")
                if (len_num2 - i) % 50 == 0:
                    print()
            print("\nResult =")
            for i in reversed(range(len_result)):
                print(result[i], end="")
                if (len_result - i) % 10 == 0:
                    print(" ", end="")
                if (len_result - i) % 50 == 0:
                    print()
            print()
        except Exception as error:
            raise


# Input handling
num1 = int(input())
num2 = int(input())
len_num1 = len(str(num1))
len_num2 = len(str(num2))

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
multiplier = LargeNumberMultiplication()
result_list = multiplier.toom_cook_multiplication(digits_num1, digits_num2)

# Sum the final result
final_result = 0
for i in range(len(result_list)):
    final_result += result_list[i] * (10 ** (len(result_list) - i - 1))

print(int(final_result) // 10)
