GCC = gcc
CFLAGS = -g wall -wshadow
VALGRIND = valgrind --tool=memcheck --verbose --log-file


prog: aredistinct.o main.o
		$(GCC) $(CFLAGS) aredistinct.o main.o -o distinct1 # no -c
		
aredistinct.o: aredistinct.c
		$(GCC) $(CFLAGS) -C aredistinct.c
		
main.o: main.c
		$(GCC) $(CFLAGS) -c main.c
		
		testall: test0 test1 test2
		
test0: distinct1
		./distinct1 inputs/input0.txt> outputs/output0
		diff excepted0/excepted0 outputs/outputs0
		
		
test1: distinct1
		./distinct1 inputs/inputs1.txt > outputs/outputs1
		diff expected0/expected1 outputs/output1
		
		
test2: distinct1
		./distinct1 inputs/input2.txt > outputs/output2
		diff expected0/excepted2 outputs/output2
		

clean:
		/bin/rm -f *. o distinct1 outputs/* log*