proj09: proj09.support.o proj09.driver.o
	gcc proj09.support.o proj09.driver.o -o proj09
	
proj09.driver.o: proj09.driver.c
	gcc -c proj09.driver.c
	
proj09.support.o: proj09.support.s /user/cse320/Projects/project09.support.h
	gcc -march=native -Wall -c proj09.support.s
