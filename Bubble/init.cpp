#include "gpluto.hpp"

void Init (double *v, double x1, double x2, double x3, RunConfig &run_config)
{
  double *inputParam = run_config.inputParam;
  double r, theta, phi, B0;
  
  r = DIM_EXPAND(x1*x1, + x2*x2, + x3*x3);
  r = sqrt(r);

  // set unit length to 1 pc
  run_config.unit_length = 3.086e18;

  v[RHO] = 1.0;
  v[VX1] = 0.0;
  v[VX2] = 0.0;
  v[VX3] = 0.0;
  v[PRS] = 1.0/run_config.gamma;
  B0     = sqrt(2.0*v[PRS]/inputParam[BETA]);

  if (r <= 5.0) v[PRS] = inputParam[P_IN]; // Change pressure internally   
 
  // v[BX1] = B0;
  // v[BX2] = 0.0;
  // v[BX3] = 0.0;
  
  // v[AX1] = 0.0;
  // v[AX2] =  v[BX3]*x1;
  // v[AX3] = -v[BX2]*x1 + v[BX1]*x2;
}

////////////////////////////////////////////////////////////////////////
void InitDomain (Data *data, Grid *grid)
/*! 
  Assign initial condition by looping over the computational domain.
  Called after the usual Init() function to assign initial conditions
  on primitive variables.
  Value assigned here will overwrite those prescribed during Init().
*/
////////////////////////////////////////////////////////////////////////
{
}

////////////////////////////////////////////////////////////////////////
void Analysis (Data *data, Grid *grid)
/*!
*/
////////////////////////////////////////////////////////////////////////
{
}
////////////////////////////////////////////////////////////////////////
void UserDefBoundary (const Data *data, RBox *box, int side, Grid *grid) 
/*!
*/
////////////////////////////////////////////////////////////////////////
{
}
