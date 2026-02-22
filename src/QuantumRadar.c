#include "Status.h"
#include <math.h>
#include <stdio.h>
#include <cblas.h>

//Placeholder values
double r = 1.0;
double phi = 0.0; 

Status create_tmvs(double* tmsv_state)
{
   /*
    Two-mode squeezed vacuum state expands to:
    Σ_tmsv = 
        [ cosh(2r),           0,                      sinh(2r)cos(phi),           sinh(2r)sin(phi),
        0,                    cosh(2r),               sinh(2r)sin(phi),           -sinh(2r)cos(phi),
        sinh(2r)cos(phi),     sinh(2r)sin(phi),       cosh(2r),                   0,
        sinh(2r)sin(phi),     -sinh(2r)cos(phi),      0,                          cosh(2r)
        ]

    We will be modeling it as the following:
    */
    double a = cosh(2*r);
    double b = sinh(2*r);

    tmsv_state[0] = a;
    tmsv_state[5] = a;
    tmsv_state[10]= a;
    tmsv_state[15]= a;

    tmsv_state[2] = b*cos(phi);
    tmsv_state[8] = b*cos(phi);

    tmsv_state[3] = b*sin(phi);
    tmsv_state[6] = b*sin(phi);
    tmsv_state[9] = b*sin(phi);
    tmsv_state[12]= b*sin(phi);

    tmsv_state[7]  = -b*cos(phi);
    tmsv_state[13] = -b*cos(phi);

    return SUCCESS;
}

Status print_matrix(double* matrix, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%5.2f   ", matrix[i*col+j]);
        }
        printf("\n");
    }
    return SUCCESS;
}

int main()
{
    double tmsv_state[16] = {0};
    create_tmvs(tmsv_state);
    print_matrix(tmsv_state, 4, 4);
}




