CC = g++
CFLAGS = -O 
LDFLAGS =
INCLUDES = 
LIBS =
DEBUG =
TARGET = main
SRC=$(wildcard *.cpp) 
OBJS = $(SRC:.cpp=.o)
.SUFFIXES:	.cpp
# 生成規則 
all: $(TARGET)

debug: DEBUG=-g -DDEBUG

debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(DEBUG) -o $@ $(OBJS) $(LIBS) 
run:
	./$(TARGET)
test:
	./$(TARGET) -T
clean:
	rm -f $(TARGET) $(OBJS) .nfs* *~ \#* core 
.cpp.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -c $< 