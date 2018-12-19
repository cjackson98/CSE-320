# Modified based on the example in the make.tutorial.pdf provided on the course site
# 
# Clean "is used to remove all object code files (in order to have a clean start)."
 
proj06: proj06.driver.o proj06.support.o
	gcc proj06.driver.o proj06.support.o -o proj06
	
proj06.driver.o: proj06.driver.c project06.support.h
	gcc -Wall -c proj06.driver.c
	
proj06.support.o: proj06.support.c project06.support.h
	gcc -Wall -c proj06.support.c

clean:
	rm -f run proj06.driver.o proj06.support.o
