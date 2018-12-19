# Modified based on the example in the make.tutorial.pdf provided on the course site
# 
# Clean "is used to remove all object code files (in order to have a clean start)."
 
proj07: proj07.driver.o proj07.support.o
	gcc proj07.driver.o proj07.support.o -o proj07
	
proj07.driver.o: proj07.driver.c /user/cse320/Projects/project07.support.h
	gcc -Wall -c proj07.driver.c
	
proj07.support.o: proj07.support.c /user/cse320/Projects/project07.support.h
	gcc -Wall -c proj07.support.c
