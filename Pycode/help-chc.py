
# 1. 
# n = int(input())

# print('*' * (2*n - 1))
# for i in range(1, n):
#     print('*' * (n-i) + ' '*(2*i-1) + '*' * (n-i))

# for i in range(n-2, 0, -1):
#     print('*' * (n-i) + ' '*(2*i-1) + '*' * (n-i))

# print('*' * (2*n - 1))

# 2.
# decimal =eval(input("Enter an integer:"))
# hexString = ""
# value = decimal
# while value != 0:
#     single =value %16
#     if single == 15:
#         hexString ="F"+ hexString
#     elif single == 14:
#         hexString ="E"+ hexString
#     elif single == 13:
#         hexString ="D"+ hexString
#     elif single == 12:
#         hexString ="C"+ hexString
#     elif single == 11:
#         hexString ="B" + hexString
#     elif single == 10:
#         hexString ="A"+ hexString
#     else:
#         hexString= str(single) + hexString
#     value = value // 16
# print(str(decimal)+"'s hex representation is "+ hexString)

# 3.
# 3.1, 先将数据存储在矩阵中，继而进行计算
# n = int(input())
# matrix = []
# for _ in range(n):
#     nums = input()
#     row = [float(num) for num in nums.split()]
#     matrix.append(row)

# a, b = 0, 0
# for i in range(n):
#     a += matrix[i][i]
#     b += matrix[i][n-1-i]

# print(f"{a+b:.2f}")

# 3.2, 直接对每一行输入进行计算
# n = int(input())
# res = 0
# for i in range(n):
#     nums = [float(num) for num in input().split()]
#     res += nums[i] + nums[n-1-i]
# print(f"{res:.2f}")

# matrix = []
# for _ in range(4):
#     a = list(map(int, input().split()))
#     print(a)
#     matrix.append(a)
# print(matrix)
# total = 0
# rows = len(matrix)
# cols = len(matrix[0])
# for j in range(cols):
#     total += matrix[0][j]+matrix[rows-1][j]
# for i in range(1,rows-1):
#     total += matrix[i][0] + matrix[i][cols-1]
# print(total)

print(input().split())