.PHONY: clean

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

LIBPATH = obj/src/lib

all: bin/geometry

bin/geometry: obj/src/geometry/geometry.o obj/src/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/lib/lib.a: obj/src/lib/square.o
	ar rcs $@ $^

obj/src/geometry/geometry.o: src/geometry/geometry.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
obj/src/lib/square.o: src/lib/square.c src/lib/square.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
clean: 
	rm bin/geometry
	rm obj/src/geometry/*.d
	rm obj/src/geometry/*.o
	rm obj/src/lib/*.d
	rm obj/src/lib/*.o
	rm obj/src/lib/*.a

-include obj/src/geometry/geometry.d obj/src/lib/square.d
