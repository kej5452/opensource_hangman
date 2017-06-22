CFLAG = -g -Wall
CC = gcc
TARGET = hangman
SRCS = hangman.c draw.c choose_problem.c
HEADER = draw.h choose_problem.h
.PHONY = clean

$(TARGET) : $(SRCS)
	$(CC) $(CFLAG) -o $(TARGET) $(SRCS)
clean: 
	rm -f $(TARGET)

