/* Submodel RACK50 skeleton created by AME Submodel editing utility */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ameutils.h"
/* *******************************************************************************
 
TITLE : RACK00
------------------------------------------------------------------------------
DESCRIPTION :
 
   This submodel of a rack and pinion converts a linear velocity v1
   in m/s (port 1) into an angular velocity w2 in rev/min (port2) and
   a torque t2 in Nm (port 2) into a linear force in N (port 1) f1.
 
        w2 = v1 / radius        (S.I. units)
        f1 = t2 / radius        (S.I. units)
 
   where radius is the transformation ratio set by the user which corresponds 
   to the primitive radius of the pinion.
 
   A rack displacement in mm (x) is calculated by integrating the linear
   velocity (v1).
 
------------------------------------------------------------------------------
USAGE :
------------------------------------------------------------------------------
PARAMETER SETTINGS :
 
   The transformation ratio (radius) must be different from zero! However,
   a negative value will be accepted. This can be used to reverse the
   sign of the rotary motion.
 
------------------------------------------------------------------------------
DATE OF CREATION/AUTHOR : 26/02/1999 R.RHOTE-VANEY
------------------------------------------------------------------------------
INDEX OF REVISIONS :
 
   26/03/2002 STC Automatic SI unit conversion is introduced.
 
------------------------------------------------------------------------------

******************************************************************************* */

#define _SUBMODELNAME_ "RACK50"

/* >>>>>>>>>>>>Insert Private Code Here. */
/* <<<<<<<<<<<<End of Private Code. */

/* There is 1 real parameter:

   radius radius of the pinion [mm -> m]
*/

void rack50in_(int *n, double rp[1], double *x)

{
   int loop, error;
   /* >>>>>>>>>>>>Extra Initialization Function Declarations Here. */
   /* <<<<<<<<<<<<End of Extra Initialization declarations. */
   double radius;

   radius = rp[0];
   loop = 0;
   error = 0;

   /*
   If necessary, check values of the following:

   rp[0..0]
   *x
*/

   /* >>>>>>>>>>>>Initialization Function Check Statements. */

   if (radius == 0.0)
   {
      amefprintf(stderr, "/nPinion radius cannot be = 0./n");
      error = 2;
   }

   /* If you want the program to be stopped when an unacceptable value is found, 
   you must setthe local variable error to 2
   If it is just a warning, set error to 1 */

   /* <<<<<<<<<<<<End of Initialization Check Statements. */

   if (error == 1)
   {
      amefprintf(stderr, "\nWarning in %s instance %d.\n", _SUBMODELNAME_, *n);
   }
   else if (error == 2)
   {
      amefprintf(stderr, "\nFatal error in %s instance %d.\n", _SUBMODELNAME_, *n);
      amefprintf(stderr, "Terminating the program.\n");
      AmeExit(1);
   }

   /* Common -> SI units conversions. */

   rp[0] *= 1.00000000000000e-003;
   radius = rp[0];

   /* >>>>>>>>>>>>Initialization Function Executable Statements. */

   /* <<<<<<<<<<<<End of Initialization Executable Statements. */
}

/*  There are 2 ports.

   Port 1 has 2 variables:

      1 f1     force at port 1           [N]   one line macro 't2/radius'
      2 v1     linear velocity at port 1 [m/s] basic variable input

   Port 2 has 2 variables:

      1 w2     rotary velocity at port 2 [rev/min] one line macro 'v1/radius'
      2 t2     torque at port 2          [Nm]      basic variable input
*/

/*  There are 2 internal variables.

      1 x         displacement of the rack [mm -> m]       explicit state (derivative `dx')
      2 theta     angular position         [degree -> rad] basic variable
*/


/* THE CALCULATION FUNCTION WILL NOT BE CALLED. */

void rack50_(int *n, double *v1, double *t2, double *x, double *dx
      , double *theta, double rp[1])

{
   int logi;
/* >>>>>>>>>>>>Extra Calculation Function Declarations Here. */
/* <<<<<<<<<<<<End of Extra Calculation declarations. */
   double radius;
   int loop;
   radius     = rp[0];

/* Common -> SI units conversions. */

   *x        *= 1.00000000000000e-003;

/*
   Set all submodel outputs below:

   *dx         = ??;
   *theta      = ??;
*/



/* >>>>>>>>>>>>Calculation Function Executable Statements. */

   *dx = *v1;
   *theta = *x/radius;
/* <<<<<<<<<<<<End of Calculation Executable Statements. */

/* SI -> Common units conversions. */

   *x        /= 1.00000000000000e-003;
   *dx       /= 1.00000000000000e-003;
   *theta    /= 1.74532925199433e-002;
}
