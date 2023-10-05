CC := g++
OBJS := main.o Solve.o
TARGET := project1

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del *.exe
	del *.o