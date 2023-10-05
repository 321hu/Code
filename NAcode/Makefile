CC := g++ #不要修改

OBJS := test.o header.o
TARGET := test
CFLAG := -O3 -Wall -g -MMD #MMD可以生成.d文件 #不要修改
DEPS := $(OBJS:.o=.d) #不要修改

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@
	./$(TARGET)

-include $(DEPS)

%.o: %.cpp
	$(CC) $(CFLAG) -c $^ -o $@

clean:
	del *.exe
	del *.d
	del $(OBJS)