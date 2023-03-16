CFLAGS = -O2 -Wall -Wextra -Werror
TARGETS = lab1balN32451

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -rf *.o $(TARGETS) 

lab1balN32451: lab1balN32451.c
	gcc $(CFLAGS) -o lab1balN32451 lab1balN32451.c -ldl
