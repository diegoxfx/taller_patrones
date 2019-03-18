
###############################################################################
# Needed include dir
INCLUDE = $(PWD)/include
SRC = $(PWD)/src
CC = g++
CCFLAGS = -I $(INCLUDE) -std=c++11 -lmysqlcppconn
LDFLAGS =  -I $(INCLUDE) -std=c++11 -lmysqlcppconn
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(SOURCES:.c=.o)
TARGET = test

# Go into src/ and run target motion-vector
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $< -o $@

###############################################################################

clean:
	rm -f *.o $(TARGET)
	rm -f $(SRC)/*.o
