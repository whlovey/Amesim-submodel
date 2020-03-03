/* Submodel PM50 skeleton created by AME Submodel editing utility
   ?? 3? 2 22:17:37 2020 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ameutils.h"
/* *******************************************************************************
 
TITLE : PM000
------------------------------------------------------------------------------
DESCRIPTION :
	PM000 is a submodel of constant speed prime mover.  The speed is
	completely independent of the torque on the shaft.
------------------------------------------------------------------------------
USAGE :
------------------------------------------------------------------------------
PARAMETER SETTINGS :
------------------------------------------------------------------------------
DATE OF CREATION/AUTHOR : March 1999 by C.W.RICHARDS
------------------------------------------------------------------------------
INDEX OF REVISIONS :
------------------------------------------------------------------------------
LIST OF FUNCTIONS USED :
------------------------------------------------------------------------------
SOURCE :
   Siemens Industry Software SAS
   7 place des Minimes
   42300 Roanne - France
   tel: (33).04.77.23.60.30
   fax: (33).04.77.23.60.31
   www.siemens.com/plm

   Copyright 2015 Siemens Industry Software NV
******************************************************************************* */

#define _SUBMODELNAME_ "PM50"

/* >>>>>>>>>>>>Insert Private Code Here. */
/* <<<<<<<<<<<<End of Private Code. */

/* There are 3 real parameters:

   omegaf final speed   [rev/min]
   tau    time constant [s]
   tstart startup time  [s]
*/

void pm50in_(int *n, double rp[3])

{
    int loop, error;
    /* >>>>>>>>>>>>Extra Initialization Function Declarations Here. */
    /* <<<<<<<<<<<<End of Extra Initialization declarations. */
    double omegaf, tau, tstart;

    omegaf = rp[0];
    tau = rp[1];
    tstart = rp[2];
    loop = 0;
    error = 0;

    /*
   If necessary, check values of the following:

   rp[0..2]
*/

    /* >>>>>>>>>>>>Initialization Function Check Statements. */
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

    /* >>>>>>>>>>>>Initialization Function Executable Statements. */
    /* <<<<<<<<<<<<End of Initialization Executable Statements. */
}

/*  There is 1 port.

   Port 1 has 1 variable:

      1 omega     prime mover speed [rev/min] basic variable output
*/

/*  There are 0 internal variables.

*/


void pm50_(int *n, double *omega, double rp[3], double *t)

{
    int loop;
    /* >>>>>>>>>>>>Extra Calculation Function Declarations Here. */
    /* <<<<<<<<<<<<End of Extra Calculation declarations. */
    double omegaf, tau, tstart;

    omegaf = rp[0];
    tau = rp[1];
    tstart = rp[2];
    loop = 0;

    /*
   Set all submodel outputs below:

   *omega      = ??;
*/

    /* >>>>>>>>>>>>Calculation Function Executable Statements. */
    
    if (*t >= tstart)
    {
        *omega = omegaf * (1 - exp(-(*t - tstart) / tau));
    }
    else
    {
        *omega = 0.0;
    }

    /* <<<<<<<<<<<<End of Calculation Executable Statements. */
