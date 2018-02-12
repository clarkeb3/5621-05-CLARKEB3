CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm

targets 	= round    my_seq    my_grep    my_hexdump 
objects		= round.o  my_seq.o  my_grep.o  my_hexdump.o

default: $(targets)

round: round.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
my_seq: my_seq.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
my_grep: my_grep.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
my_hexdump: my_hexdump.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	$(RM) $(targets) $(objects)

test: round-test my_seq-test my_hexdump-test my_grep-test

round-test: round
	./round -K 1000
	./round -K 1024
	./round -K 1600
	./round -M 10484360
	./round -G 1073741124
	./round -h 1145921504

my_seq-test: my_seq
	./my_seq 7
	./my_seq 7 5 20

my_grep-test: my_grep 
	./my_grep include round.c -n

my_hexdump-test: my_hexdump
	./my_hexdump round.c