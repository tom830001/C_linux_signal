all: Signal
Signal: Signal.o
	gcc Signal.o -o Signal
Signal.o: Signal.c
	gcc Signal.c -c
clean:
	rm Signal.o Signal
