src	:=$(wildcard *.c)
obj	:=$(src:.c=.o)
CC	:=gcc
CFLAGS	:=-Wall -g -c
all:print kmp
kmp:$(obj)
	$(CC) $^ -o $@
$(obj):%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
print:
	@echo $(src)
	@echo $(obj)
clean:
	rm -rf a.out kmp *~ *.o
.PHONY:
	all
	clean
	print
