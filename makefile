.PHONY: run
run: main
	./main

main: main.o
	ld --entry=__main $< -o $@

main.o: main.c
	gcc -Os -fno-builtin -fomit-frame-pointer -fno-ident -c $< -o $@

