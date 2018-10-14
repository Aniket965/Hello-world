#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include "gmp.h"



void generatePrimes(mpz_t* p, mpz_t* q);
void computeNandF(mpz_t* q, mpz_t* p, mpz_t *phi, mpz_t* n);
void generateE(mpz_t* phi, mpz_t* e);
void enc(mpz_t* e, mpz_t* n, mpz_t* d, mpz_t* c, char[]);
void dec(mpz_t* m, mpz_t* c, mpz_t* d, mpz_t* n);
void makeKeys(mpz_t n, mpz_t e, mpz_t d, mpz_t p, mpz_t q);
void encrFile(mpz_t e, mpz_t n, mpz_t d, mpz_t c);

gmp_randstate_t stat;

int main() {

  
    mpz_t p, q, phi, e, n, d, c, dc;
    char msg[40] = "welcome to cryptoworld";
    int *mes;
    int len = strlen(msg);
    mpz_init(p);
    mpz_init(q);
    mpz_init(phi);
    mpz_init(e);
    mpz_init(n);
    mpz_init(d);
    mpz_init(c);
    mpz_init(dc);

    // RSA algorithm
    generatePrimes(&p, &q);
    computeNandF(&q, &p, &phi, &n);
    generateE(&phi, &e);
    // extended Euclidean
    mpz_invert(d, e, phi);
    printf("d = ");
    mpz_out_str(stdout, 10, d);
    printf("\n------------------------------------------------------------------------------------------\n");


    enc(&e, &n, &d, &c, msg);

    dec(&dc, &c, &d, &n);

    printf("\n------------------------------------------------------------------------------------------\n");
    printf("encrypt message  = ");
    mpz_out_str(stdout, 10, c);
    printf("\n");
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("message as int after decr  = ");
    mpz_out_str(stdout, 10, dc);
    printf("\n");

   
    mpz_export(mes, (size_t*) malloc(sizeof (size_t)), 1, sizeof (mes[0]), 0, 0, dc);
    char r[40];
    printf("message as string after decr  = ");
    for (int i = 0; i < len; i++) {
        r[i] = (char) mes[i];
        printf("%c", r[i]);
    }
    printf("\n");

    encrFile(e, n, d, c);

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(phi);
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(c);
    mpz_clear(d);
    mpz_clear(dc);
    return 0;
}

void generatePrimes(mpz_t* p, mpz_t* q) {

    int primetest;
    long sd = 0;
    mpz_t seed;
    gmp_randinit(stat, GMP_RAND_ALG_LC, 120);
    mpz_init(seed);
    srand((unsigned) getpid());
    sd = rand();
    mpz_set_ui(seed, sd);
    gmp_randseed(stat, seed);


    mpz_urandomb(*p, stat, 512);
    primetest = mpz_probab_prime_p(*p, 10);
    if (primetest != 0) {
        printf("p is prime\n");
    } else {
        //printf("p wasnt prime,choose next prime\n");
        mpz_nextprime(*p, *p);
    }

    mpz_urandomb(*q, stat, 512);
    primetest = mpz_probab_prime_p(*q, 10);
    if (primetest != 0) {
        // printf("q is prime\n");
    } else {
        // printf("p wasnt prime,choose next prime\n");
        mpz_nextprime(*q, *q);
    }


    printf("p and q generated!!\n");
    printf("p = ");
    mpz_out_str(stdout, 10, *p);
    printf("q = ");
    mpz_out_str(stdout, 10, *q);
    printf("\n------------------------------------------------------------------------------------------\n");
    mpz_clear(seed);
    return;
}

void computeNandF(mpz_t* q, mpz_t* p, mpz_t *phi, mpz_t* n) {
    
    mpz_t temp1, temp2;
    mpz_init(temp1);
    mpz_init(temp2);
    //n=p*q
    mpz_mul(*n, *q, *p);
    mpz_sub_ui(temp1, *q, 1); //temp1=q-1
    mpz_sub_ui(temp2, *p, 1); //temp2=p-1
    //φ=(p-1)(q-1)
    mpz_mul(*phi, temp1, temp2);
    printf("phi and n generated!!\n");
    printf(" n= ");
    mpz_out_str(stdout, 10, *n);
    printf("phi = ");
    mpz_out_str(stdout, 10, *phi);
    printf("\n------------------------------------------------------------------------------------------\n");
}

void generateE(mpz_t* phi, mpz_t* e) {

   
    mpz_t temp, seed;
    mpz_init(seed);
    mpz_init(temp);
    long sd = 0;
    gmp_randinit(stat, GMP_RAND_ALG_LC, 120);
    srand((unsigned) getpid());
    sd = rand();
    mpz_set_ui(seed, sd);
    gmp_randseed(stat, seed);

    do {
        mpz_urandomm(*e, stat, *phi + 1);
        mpz_gcd(temp, *phi, *e); //temp=gcd(e,φ)
    } while (mpz_cmp_ui(temp, 1) != 0); //όσο το gcd δεν είναι 1
    printf("e generated \n e = ");
    mpz_out_str(stdout, 10, *e);
    printf("\n------------------------------------------------------------------------------------------\n");

}

void enc(mpz_t* e, mpz_t* n, mpz_t* d, mpz_t* c, char msg[]) {

 
    int r[40];
    for (int i = 0; i < strlen(msg); i++) {
        r[i] = (int) msg[i];
    }

    int *m = r;
    mpz_t M;
    mpz_init(M);
    mpz_import(M, strlen(msg), 1, sizeof (m[0]), 0, 0, m);
    printf("message as int before encryption  = ");
    mpz_out_str(stdout, 10, M);
    printf("\n");
    
    mpz_powm(*c, M, *e, *n);

}

void dec(mpz_t* m, mpz_t* c, mpz_t* d, mpz_t* n) {
  
    mpz_powm(*m, *c, *d, *n);

}

void encrFile(mpz_t e, mpz_t n, mpz_t d, mpz_t c) {
  
    char text[80];
    FILE *file;
    file = fopen("text.txt", "r");
    int i = 0;
    if (file) {
        while ((x = getc(file)) != EOF) {
            i++;
            putchar(x);
            text[i] = (char) x;
        }
       
        int r[40];
        for (int i = 0; i < strlen(text); i++) {
            r[i] = (int) text[i];
        }

        int *m = r;
        mpz_t M;
        mpz_init(M);
        mpz_import(M, strlen(text), 1, sizeof (m[0]), 0, 0, m);
        printf("message as int before encryption  = ");
        mpz_out_str(stdout, 10, M);
        printf("\n");
      
        mpz_powm(c, M, e, n);
        printf("encrypt txt  = ");
        mpz_out_str(stdout, 10, c);
        printf("\n");
     
        fclose(file);
        file = fopen("text.txt", "w");
      
        mpz_out_raw(file, c);
        fclose(file);

    }

}
