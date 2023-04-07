CFLAGS = -Wall -Wextra -Werror

geometry: geometry.o square.o
	$(CC) $(CFLAGS) -o $@ $^

geometry.o: geometry.c
	$(CC) -c $(CFLAGS) -o $@ $<

square.o: square.c square.h
	$(CC) -c $(CFLAGS) -o $@ $<