run: geometry.c geometry
		gcc -Wall -Werror -o run geometry && ./geometry && rm -f run