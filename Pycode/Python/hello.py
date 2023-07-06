#print('Hello World!31231')
# n = int(input())
# for i in range(1,n+1):
#     for j in range(1,i+1):
#         print("* ",end="")
#     print()

# str='123456789'
 
# print(str)                 # 输出字符串
# print(str[0:-1])           # 输出第一个到倒数第二个的所有字符
# print(str[0])              # 输出字符串第一个字符
# print(str[2:5])            # 输出从第三个开始到第五个的字符
# print(str[2:])             # 输出从第三个开始后的所有字符
# print(str[1:5:2])          # 输出从第二个开始到第五个且每隔一个的字符（步长为2）
# print(str * 2)             # 输出字符串两次
# print(str + '你好')         # 连接字符串
 
# print('------------------------------')
 
# print('hello\nrunoob')      # 使用反斜杠(\)+n转义特殊字符
# print(r'hello\nrunoob')
# print('\n')
# print(r'\n') 

# import time

# for i in range(101):
#     print("\r{:3}%".format(i),end=' ')
#     time.sleep(0.001)

def change(a):
    print(id(a))   # 指向的是同一个对象
    a=10
    print(id(a))   # 一个新对象
 
a=1
print(id(a))
change(a)
print(id(a))