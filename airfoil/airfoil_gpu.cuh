#ifndef _AIRFOIL_GPU_
#define _AIRFOIL_GPU_

void call_gputest(double **x_old, double **x_mid, double **x_new, double **v_old, double **v_mid, double **v_new, double **f_mid, double dt, int size);

void call_gpu_dummy();

#endif

