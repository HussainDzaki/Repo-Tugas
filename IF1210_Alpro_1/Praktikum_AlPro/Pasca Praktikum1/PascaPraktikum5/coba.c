#include "polynomial.c"
int main()
{
    Polynomial p;
    int coeff[] = {-1,0,-1,3,1};
    int N = (sizeof (coeff)) / (sizeof(int)) ;
    CreatePolynomialFromArray(&p, coeff, N);
    PrintPolynomial(&p);


    return 0;
}
