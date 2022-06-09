randwalk: randwalk.c
	gcc -o randwalk randwalk.c common.c

clean:
	rm -f randwalk *.o
