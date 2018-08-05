CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
unittestresults: dominion.o
	gcc -o unittest1 unittest1.c dominion.o  rngs.o $(CFLAGS)
	gcc -o unittest2 unittest2.c dominion.o  rngs.o $(CFLAGS)
	gcc -o unittest3 unittest3.c dominion.o  rngs.o $(CFLAGS)
	gcc -o unittest4 unittest4.c dominion.o  rngs.o $(CFLAGS)
	gcc -o cardtest1 cardtest1.c dominion.o  rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c dominion.o  rngs.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c dominion.o  rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c dominion.o  rngs.o $(CFLAGS)
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "\n\n*****Code coverage*****" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
randomtestadventurer.out: dominion.o
	gcc -o randtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randtestadventurer > randomtestadventurer.out
	echo "\n\n*****Code coverage*****" >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out
	
randomtestcard1.out: dominion.o
	gcc -o randtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randtestcard1 > randomtestcard1.out
	echo "\n\n*****Code coverage*****" >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out
	
randomtestcard2.out: dominion.o
	gcc -o randtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randtestcard2 > randomtestcard2.out
	echo "\n\n*****Code coverage*****" >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	gcov -f -b dominion.c >> randomtestcard2.out
	
randomtests: randomtestadventurer.out randomtestcard1.out randomtestcard2.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 randtestadventurer randtest1 randtest2
