proj10: proj10.support.o project10.driver.o
	gcc proj10.support.o project10.driver.o -o proj10

proj10.support.o: proj10.support.s /user/cse320/Projects/project10.support.h
	gcc -march=native -Wall -c proj10.support.s
