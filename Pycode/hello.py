# /usr/bin/env python3
list = [34,6,7,0,0,0,9]
n = 0
for i in list:
    if i == 0:
        list.remove(i)
        n += 1
        print('#',end='')
        print(n)
print(n)
# print('hell0')