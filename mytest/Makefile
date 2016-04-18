CC = g++
INC = -I ~/usr/include
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) $(INC)
LFLAGS = -Wall $(DEBUG) -L ~/usr/lib -lquickfix

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = quickfix_test

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -f *.o *~ $(EXEC)
