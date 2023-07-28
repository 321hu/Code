# /usr/bin/env python3
# list = [34,6,7,0,0,0,9]
# n = 0
# for i in list:
#     if i == 0:
#         list.remove(i)
#         n += 1
#         print('#',end='')
#         print(n)
# print(n)
# print('hell0')
names = ['Alice', 'Bob', 'Charlie']
ages = [25, 30, 22]
countries = ['USA', 'Canada', 'Australia']

# 使用zip函数将对应位置的元素打包成元组
zipped_data = zip(names, ages, countries)
# 将迭代器转换为列表
zipped_list = list(zipped_data)

# print(zipped_list)
# print(zipped_data)

from itertools import zip_longest
odd = [1,3,5,7]
even = [2,4,6,8,10]
for i in zip(odd, even):
    print(i, end=',')
print()
for i in zip_longest(odd, even):
    print(i, end=',')