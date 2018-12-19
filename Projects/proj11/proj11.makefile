proj11: proj11.support.o project11.driver.o
	gcc proj11.support.o project11.driver.o -o proj11

proj11.support.o: proj11.support.s /user/cse320/Projects/project11.support.h
	gcc -march=native -Wall -c proj11.support.s

proj11.driver.o: proj11.driver.o
	gcc -c proj09.driver.o
