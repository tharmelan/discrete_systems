#include "IIR_filter.h"

// constructors
IIR_filter::IIR_filter(float tau,float Ts)
{
    this->a0 = -tau / (tau+Ts);
    this->b0 = Ts/(Ts+tau);

    /*
    this->A[0] = -tau / (tau+Ts);
    this->B[0] = Ts/(Ts+tau);
    */

}
IIR_filter::IIR_filter(float wb, float D, float Ts, float K)
{
    this->b0 = (wb*wb)*(Ts*Ts)*K;
    this->a0 = 1+(wb*wb)*(Ts*Ts)-2*D*wb*Ts;
    this->a1 = 2*D*wb*Ts-2;

    /*
    this->A[0] = 1+(wb*wb)*(Ts*Ts)-2*D*wb*Ts;
    this->A[1] = 2*D*wb*Ts-2;
    this->B[0] = (wb*wb)*(Ts*Ts)*K;*/
}

// Methods:

float IIR_filter::eval(float u)
{
    float y = -a0 * y_old + -a1 * y_old_old + b0*u_old_old;
    this->u_old_old = u_old;
    this->u_old = u;
    this->y_old_old = y_old;
    this->y_old = y;
    return y;
}


float IIR_filter::eval2(float u)
{
    float y = B[0]*u;
    for(int i = 0; i < /*A.length*/ 0 ; i++) {
        y += A[i] * Y[i];
    }
    Y[0] = y;
    /*Y[1] = Y[0:N-1]*/
    for(int i = 0/*Y.length -2 zweit hinterster wert*/; i >= 0 ; i--) {
        Y[i+1] = Y[i];
    }
    return y;
}

// Deconstructor
IIR_filter::~IIR_filter() {} 