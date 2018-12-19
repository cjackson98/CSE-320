# Modified based on the example in the make.tutorial.pdf provided on the course site
# 
# Clean "is used to remove all object code files (in order to have a clean start)."
 
proj12: proj12.driver.o proj12.support.o
	gcc proj12.driver.o proj12.support.o -o proj12
	
proj12.driver.o: proj12.driver.c /user/cse320/Projects/project12.support.h
	gcc -Wall -c proj12.driver.c
	
proj12.support.o: proj12.support.c /user/cse320/Projects/project12.support.h
	gcc -Wall -c proj12.support.c
