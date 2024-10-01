all: ./test.asm
	nasm -f elf64 ./test.asm -i ./common
	gcc -no-pie raw_mode.c test.o -e _start	
	./a.out
	rm -rf ./test.o ./a.out 


