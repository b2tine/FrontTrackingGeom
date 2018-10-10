/***************************************************************
FronTier is a set of libraries that implements different types of 
Front Traking algorithms. Front Tracking is a numerical method for 
the solution of partial differential equations whose solutions have 
discontinuities.  

Copyright (C) 1999 by The University at Stony Brook. 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
****************************************************************/


/*
*				example12.c:
*
*		User initialization example for Front Package:
*
*	Copyright 1999 by The University at Stony Brook, All rights reserved.
*
*/

#include <FronTier.h>

char *in_name;
int main(int argc, char **argv)
{
	static Front front;
	static F_BASIC_DATA f_basic;
	static LEVEL_FUNC_PACK level_func_pack;
	SURFACE *surf;
	double r1,r2,h,center[3];
	int idir;

	f_basic.dim = 3;	
	FT_Init(argc,argv,&f_basic);

	/* Initialize basic computational data */

	f_basic.L[0] = 0.0;	f_basic.L[1] = 0.0; 	f_basic.L[2] = 0.0;
	f_basic.U[0] = 2.0;	f_basic.U[1] = 1.0; 	f_basic.U[2] = 1.0;
	f_basic.gmax[0] = 200;	f_basic.gmax[1] = 100; f_basic.gmax[2] = 100;
	f_basic.boundary[0][0] = f_basic.boundary[0][1] = DIRICHLET_BOUNDARY;
	f_basic.boundary[1][0] = f_basic.boundary[1][1] = DIRICHLET_BOUNDARY;
	f_basic.boundary[2][0] = f_basic.boundary[2][1] = DIRICHLET_BOUNDARY;
	f_basic.size_of_intfc_state = 0;

        in_name                 = f_basic.in_name;

	FT_StartUp(&front,&f_basic);

	/* Initialize domain */
	level_func_pack.pos_component = 2;
	FT_InitIntfc(&front,&level_func_pack);

	/* Initialize interior surface */
	center[1] = center[2] = 0.5;
	center[0] = 0.0;
	r1 = 0.3;
	r2 = 0.1;
	h = 0.25; 
	idir = 0;
	FT_MakeAnnularCylinderSurf(&front,
			center,
			r1,		// outer radius
			r2,		// inner radius
			h,		// height
			1,2,		// negative and positive components
			idir,		// direction of axis
			FIRST_PHYSICS_WAVE_TYPE, // wave type
			1,		// refinement level
			NO,		// not extend to buffer zone
			&surf);
	   
	/* Draw the interface */
	FT_Draw(&front);

	clean_up(0);
}
