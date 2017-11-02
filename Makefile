CC= gcc
.PHONY: clean

tassert: tassert.o xassert.o
	$(CC) $? -o tassert
clean:
	rm -rf *.o *~ *.s

