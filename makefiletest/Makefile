
CC = g++
CFLAGS = -Wall -c
TARGET = main

$(TARGET): $(TARGET).o calculator.o
	$(CC) -Wall $(TARGET).o calculator.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).cpp

calculator.o: calculator.cpp calculator.h
	$(CC) $(CFLAGS) calculator.cpp

# .PHONY evita que make trate clean como un target
.PHONY: clean
# Borra los ficheros resultado de manera recursiva y sin confirmación
clean:
	rm -rf *.o $(TARGET)
