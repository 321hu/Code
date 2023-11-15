class Student:
    __name = "" # 私有实例变量
    def __init__(self, name):
        self.__name = name
    
    def getName(self):
        return self.__name

# stu = Student("John")
# print(stu.getName())

if __name__ == "__main__":
    stu = Student("John")
    print(stu.getName())