# for row in range(1, 10):
#     for col in range(1, 10):
#         if row*col < 10:
#             print(' ', end='')
#         print(row*col, ' ', end='')
#     print()

# s = input("Enter a number: ")
# total = 0
# while s != 'done':
#     total += int(s)
#     s = input("Enter a number: ")
# print("The sum is " + str(total))


# x, y = 2, 4
# def add(a, b):
#     a = a + 1
#     return a+b

# print(x, '+', y, '=', add(x, y))


# def func():
#     x = 1
#     y = 2
#     a = 3
#     b = 4
#     def sum(a, b):
#         return a + b
#     def sub(a, b):
#         return a - b
#     return sum(x, y) * sub(a, b)

# print(func())

# def func():
#     x = 1
#     y = 2
#     a = 3
#     b = 4
#     sum = lambda x, y : x+y
#     print(sum)
#     sub = lambda x, y : x-y
#     print(sub)
#     return sum(x, y) * sub(a, b)

# print(func())

# def fab(max):
#     cnt, a, b = 0, 0, 1
#     while cnt < max:
#         yield b
#         a, b = b, a+b
#         cnt += 1

# a = fab(5)
# print(next(a))

# def iterPower(base, exp):
#     res = 1
#     cnt = 0
#     while cnt < exp:
#         res *= base
#         cnt += 1
#     return res
# print(iterPower(2, 3))

def recurPower(base, exp):
    if exp == 0:
        return base
    return recurPower(base, exp-1)*base

print(recurPower(3, 4))