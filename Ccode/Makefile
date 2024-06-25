CC := g++
OBJS := Polymorphism_test.o
# OBJS := test.o
# OBJS := test.o header.o
TARGET := program

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm *.exe
	rm *.o