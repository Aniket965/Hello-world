#include <stdio.h>
#include <math.h>

void newton_divided() {
    printf("\t\tNewton's Divided Difference\n\n");
    int n,i,n1,j;
    printf("Enter n : ");
    scanf("%d",&n);
    float x[n],y[n],x1,p,ans=0;
    printf("Enter Values of X : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&x[i]);
    }
    printf("Enter Values of Y : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&y[i]);
    }
    printf("Enter Value of X1 : ");
    scanf("%f",&x1);
    n1 = n-1;
    float req[n-1],del[n];
    for(i = 0; i < n; i++)
        del[i] = y[i];
    for(j = 0; j < n1; j++) {
        printf("\n----- %d divided difference -----\n\n",j+1);
        for(i = 0; i < n1-j; i++) {
            del[i] = del[i+1] - del[i];
            del[i] /= (x[i+j+1] - x[i]);
            printf("Diff[%d] : %.4f\n",j,del[i]);
        }
        req[j] = del[0];

    }
    printf("\n------------------------------\n");
    ans = y[0];
    for(i = 0; i < n1; i++) {
        float m = 1;
        for(j = i; j >= 0; j--) {
            m *= (x1-x[j]);
        }
        ans += (m*req[i]);
    }

    printf("f(%.2f) = %.4f\n",x1,ans);
}

void newton_forward() {
printf("\t\tNewton's Forward Difference\n\n");
    int n,i,n1,j;
    printf("Enter n : ");
    scanf("%d",&n);
    float x[n],y[n],x1,p,ans=0;
    printf("Enter Values of X : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&x[i]);
    }
    printf("Enter Values of Y : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&y[i]);
    }
    printf("Enter Value of X1 : ");
    scanf("%f",&x1);
    n1 = n-1;
    float req[n-1],del[n];
    for(i = 0; i < n; i++)
        del[i] = y[i];
    for(j = 0; j < n1; j++) {
        printf("\n----- %d Forward difference -----\n\n",j+1);
        for(i = 0; i < n1-j; i++) {
            del[i] = del[i+1] - del[i];
            printf("Diff[%d] : %.4f\n",j,del[i]);
        }
        req[j] = del[0];

    }
    printf("\n------------------------------\n");
    p = (x1-x[0])/(x[1]-x[0]);
    printf("p  = %f\n",p);
    ans = y[0];
    for(i = 0; i < n1; i++) {
        j = i+1;
        float m = 1;
        m /= fact(j);
        while(j) {
            m *= (p-j+1);
            j--;
        }
        ans += (m*req[i]);
    }
    printf("\ny(%f) = %f\n",x1,ans);
}


void newton_backward() {
printf("\t\tNewton's Backward Difference\n\n");
    int n,i,n1,j;
    printf("Enter n : ");
    scanf("%d",&n);
    float x[n],y[n],x1,p,ans=0;
    printf("Enter Values of X : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&x[i]);
    }
    printf("Enter Values of Y : ");
    for(i = 0; i < n; i++) {
        scanf("%f",&y[i]);
    }
    printf("Enter Value of X1 : ");
    scanf("%f",&x1);
    n1 = n-1;
    float req[n-1],del[n];
    for(i = 0; i < n; i++)
        del[i] = y[i];
    for(j = 0; j < n1; j++) {
        printf("\n----- %d Backward difference -----\n\n",j+1);
        for(i = 0; i < n1-j; i++) {
            del[i] = del[i+1] - del[i];
            printf("Diff[%d] : %.4f\n",j,del[i]);
        }
        req[j] = del[i-1];

    }
    printf("\n------------------------------\n");
    p = (x1-x[n-1])/(x[1]-x[0]);
    printf("p  = %f\n",p);
    ans = y[n-1];
    for(i = 0; i < n1; i++) {
        j = i+1;
        float m = 1;
        m /= fact(j);
        while(j) {
            m *= (p+j-1);
            j--;
        }
        ans += (m*req[i]);
    }
    printf("\ny(%.4f) = %.4f\n",x1,ans);
}

int fact(int n) {
    if(n == 0 || n == 1)
        return 1;
    return n*fact(n-1);
}

int main() {
    printf("1.Newton Forward Difference\n");
    printf("2.Newton Backward Difference\n");
    printf("3.Newton Divided Difference\n");
    printf("Enter Your Choice : ");
    int ch;
    scanf("%d",&ch);
    switch(ch) {
        case 1: newton_forward();
                break;
        case 2: newton_backward();
                break;
        case 3: newton_divided();
                break;
    }
}
