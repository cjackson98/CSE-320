
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  Pulser ((SD("2a"), "Initial (i) "),  Init, 'i', 1000);
  Pulser ((SD("3a"), "Clock (c)"), Clock, 'c', 1000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  Probe ( (SD("1c"), "W"), w );
  Probe ( (SD("2c"), "X"), x );
  Probe ( (SD("3c"), "Y"), y );
  Probe ( (SD("4c"), "Z"), z );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  Signal notw, notx, noty, notz, and1, and2, W, X, Y, Z;

  // DFF
  Dff (SD(sd,"1a"), (Init, W, Clock, Zero), w);
  Dff (SD(sd,"2a"), (Zero, X, Clock, Init), x);
  Dff (SD(sd,"3a"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd,"4a"), (Zero, Z, Clock, Init), z);

  // NOT
  Not ( SD(sd, "1b"), w, notw );
  Not ( SD(sd, "2b"), x, notx );
  Not ( SD(sd, "3b"), y, noty );
  Not ( SD(sd, "4b"), z, notz );

  // AND
  And ( SD(sd, "1c"), (notw, notz), W );	// W
  And ( SD(sd, "2c"), (noty, z), and1 );	// X and1
  And ( SD(sd, "3c"), (y, notz), and2 );	// X and2
  And ( SD(sd, "4c"), (notx, noty), Y );	// Y

  // OR
  Or ( SD(sd, "1d"), (and1, and2), X );		// X
  Or ( SD(sd, "2d"), (w, w), Z );			// Z
}

