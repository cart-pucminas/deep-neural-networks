// #include <stdio.h>
// #include <omp.h>
// #include <time.h>
// #include <stdlib.h>



// long long num_passos = 10;
long long num_passos = 10000000000;
double passo;

int main(int argc, char** argv){
  
    

    long long i;
    double x, pi, soma=0.0;
    passo = 1.0/(double)num_passos;

    

    #pragma omp parallel for private(x, i) shared(passo) reduction(+:soma) num_threads(6)
    for(i=0; i < num_passos; i++){
        // printf("%lld", i);
        x = (i + 0.5)*passo;
        soma += 4.0/(1.0 + x*x);
    }



    pi = soma*passo;

    printf("O valor de PI é: %f\n", pi);

    

    return 0;
    
}
