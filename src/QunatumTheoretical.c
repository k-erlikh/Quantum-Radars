#include <Status.h>

double sigma_1 = 0; // σ₁ → recieve signal power
double sigma_2 = 0; //σ₂ → reference signal power
double rho = 0; // ρ → correlation coefficient ( 0 <= rho <= 1)
double phi = 0; //φ → phase between recive and reference signals

Status createTmvsTheoretical(double* state)
{
    /*
    The tmvs can be represented by:
    Σ(σ₁, σ₂, ρ, φ) = 
        [ σ₁²⋅I₂,          ρ⋅σ₁⋅σ₂⋅R'(φ),
          ρ⋅σ₁⋅σ₂⋅R'(φ)ᵀ,   σ₂²⋅I₂        ]

    Where: 
    R'(φ) = 
    [ cos(φ), sin(φ),
      sin(φ), -cos(φ)]

    Which expands to:
    Σ(σ₁, σ₂, ρ, φ) = 
    [ σ₁², 0, ρ⋅σ₁⋅σ₂⋅cos(φ), ρ⋅σ₁⋅σ₂⋅sin(φ)
      0, σ₁², ρ⋅σ₁⋅σ₂⋅sin(φ), -ρ⋅σ₁⋅σ₂⋅cos(φ)
      ρ⋅σ₁⋅σ₂⋅cos(φ), ρ⋅σ₁⋅σ₂⋅sin(φ), σ₂², 0,
      ρ⋅σ₁⋅σ₂⋅sin(φ), -ρ⋅σ₁⋅σ₂⋅cos(φ), 0, σ₂²]
    */

    double m = rho*sigma_1*sigma_2;

    state[0] = sigma_1*sigma_1;
    state[5] = sigma_1*sigma_1;
    state[10] = sigma_2*sigma_2;
    state[15] = sigma_2*sigma_2;

    state[2] = m*cos(phi);
    state[8] = m*cos(phi);

    state[3] = m*sin(phi);
    state[6] = m*sin(phi);
    state[9] = m*sin(phi);
    state[12] = m*sin(phi);

    state[7] = -m*cos(phi);
    state[13] = -m*cos(phi);

    return SUCCESS;
}

Status printState(double *state, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%5.2f   ", state[i*col+j]);
        }
        printf("\n");
    }
    return SUCCESS;
}
