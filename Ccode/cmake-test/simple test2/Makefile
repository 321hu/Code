# hello: hello.o header.o
# 	g++ hello.o header.o -o hello

# hello.o: header.h
# hello.o: header.h（仅代表依赖关系，只有当header.h发生改变的时候，hello.o才会重新编译）

CC := g++
CFLAG := -O3 -Wall -g -MMD
OBJS := hello.o header.o
TARGET := hello #生成的可执行文件的名称（目标）
OTHERTARGET := other #另外的目标
DEPS := $(OBJS:.o=.d)

all: $(TARGET) #$(OTHERTARGET) #clean

$(TARGET): $(OBJS)
#	@echo $^
#	@echo $@
	$(CC) $^ -o $@ 
# 	./$(TARGET) $(ARGS)

# 上述语句中：$(CC) $^ -o $@  == $(CC) $(OBJS) -o $(TARGET)

# $(OTHERTARGET): $(OBJS)
# 	$(CC) $(CFLAG) $^ -o $@

-include $(DEPS)

%.o: %.cpp
	$(CC) $(CFLAG) -c $^ -o $@

clean:
	del $(OBJS)

cleanall:
	del *.exe
	del *.d
