
/******************************************************************************
  Project #3 - Chris Jackson
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/
/*
a. 
	Start with four switches to generate the four 1-bit input signals (w, x, y, z) and eight probes to display
		the eight 1-bit output signals. Don’t worry about the layout of the probes at this point. 
	In function "circuits", use "signal renaming" (discussed above) to generate arbitrary values for the eight output signals.

b. 
	Revise function "circuits" to actually handle the eight required functions (perhaps in several steps). 

c. 
	Revise function "simnet" so that the eight probes are in the right places:
		The eight probes will be placed near the right edge of the "sim" window.
		The "Present" probe will be placed at the top of the "sim" window, while the probes for the other seven functions ("a", "b", and so on) will be placed
			below the "Present" probe in the "Figure 8" pattern used by a seven-segment display.

d. 
	Revise function "simnet" to use a 4-bit counter instead of four switches:
		Function "simnet" will serve as a test fixture which allows the user to produce hexadecimal digits and observe the resulting outputs. The input
			will be generated using a four-bit counter (controlled by pulsers), and the results will be displayed using eight probes.
		The pulsers used in conjunction with the four-bit counter will be placed vertically on the left edge of the "sim" window.
*/
void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;
  Signal Strobe(1);
  Signal ResetA(1);
  Signal ResetB(1);
  
  Counter ((SD("4c"), "4-bit Counter"), (ResetB, Strobe), (w,x,y,z));
  
  circuits( SD("3d-5d"), w, x, y, z, Present, a, b, c, d, e, f, g);

  Pulser ( (SD("3a"), "Reset"),  ResetA, 'r', 0000);
  Pulser ( (SD("5a"), "Strobe"), Strobe, 's', 1);
  
  Not (SD("3b"), ResetA, ResetB);

  Probe ( (SD("1f-1h"), "P"), Present );
  Probe ( (SD("2f-2h"), "A"), a );
  Probe ( (SD("2h-4h"), "B"), b );
  Probe ( (SD("4h-6h"), "C"), c );
  Probe ( (SD("6f-6h"), "D"), d );
  Probe ( (SD("4f-6f"), "E"), e );
  Probe ( (SD("2f-4f"), "F"), f );
  Probe ( (SD("4f-4h"), "G"), g );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
	Module( (sd, "Circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

	Signal notw, notx, noty, notz;
	Signal and1, and2, and3, and4, and5, and6, and7;
	
	Not ( SD(sd, "1b"), w, notw);
	Not ( SD(sd, "2b"), x, notx);
	Not ( SD(sd, "3b"), y, noty);
	Not ( SD(sd, "4b"), z, notz);
	
	And ( SD(sd,"1c"), (notw, x, noty), and1 );				//Present
	And ( SD(sd,"2c"), (w, notx, notz), and2 );				//Present
	And ( SD(sd,"3c"), (notw, noty, notz), and3 );			//Present
	And ( SD(sd,"4c"), (notw, notx, y, z), and4 );			//Present
	And ( SD(sd,"6c"), (notw, notx), and5 );				//D
	And ( SD(sd,"7c"), (w, noty), and6 );					//D
	And ( SD(sd,"9c"), (notx, noty), and7 );				//E
	
	Or ( SD(sd,"1d"), (and1, and2, and3, and4), Present );	//Present
	Or ( SD(sd,"2d"), (notx, z), a);						//A
	Or ( SD(sd,"3d"), (y, notz), b);						//B
	Or ( SD(sd,"4d"), (One, One), c);						//C
	Or ( SD(sd,"5d"), (z, and5, and6), d);					//D
	Or ( SD(sd,"6d"), (w, and7), e);						//E
	Or ( SD(sd,"7d"), (noty, notz), f);						//F
	Or ( SD(sd,"8d"), (w, x, y), g);						//G
}

