#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef double (*function)(double);

double counterror (double original, double fact){
    return fabs((original-fact)/original)*100;
}

//task 2
double tsk2f (double x){
    return sin(x+1)-(x/2);
}
double dtsk2f (double x){
    return cos(x+1)-(1/2);
}
short sign (double a){
    if(a<0){
        return -1;
    }else if(a>0){
            return 1;
        } else {
                return 0;
            }
}
double iteration (function fx, double xk, double e, double xn){
    for(xk += e; xk < xn-e ; xk += e){
        if(sign(fx(xk))*sign(fx(xk+e)) < 0){
            printf("The root of this equation is in [%.8f,%.8f]...\n",xk,xk+e);
            if(fabs(fx(xk))<e){
                return xk;
            }else
                {
                    return xk+e;
                }
            }
            }
}

double bisection (function fx, double xk, double e, double xn){
            double dx, bisecx;
            do {
                dx = (xk-xn)/2;
                bisecx = xn + dx;
                //calculation
                if  (sign(fx(xn))!=sign(fx(bisecx))){
                    xk = bisecx;
                } else {
                        xn = bisecx;
                    }
            }   while((xk-xn)>e);
            return bisecx;
}

double newton (function fx, function dfx, double xk, double e, double xn) {
    double newtx  = xn - fx(xn)/dfx(xn);
    while (fabs(newtx-xn)>e) {
        xn = newtx;
        newtx = newtx - fx(newtx)/dfx(newtx);
        }
    return newtx;
}

double secant (function fx, double xk, double e, double xn){
    double secantx = 0,x0;
        do {
            x0=secantx;
            secantx = xk-fx(xk)*(xn-xk)/(fx(xn)-fx(xk));
            if(fx(xk)*fx(secantx)<0) xn = secantx;
            else xk = secantx;
        } while (fabs(secantx-x0)>e);
        return secantx;
}


//task 3
double fx (double a){
    return 1/(1+tan(a)*tan(a));
}


char menu() {
    char choo;
    printf("-------------------------\n");
    printf("Lab 05 Kim V(12)\n");
    printf("-------------------------\n");
    printf("[1] Palindrome\n");
    printf("[2] Equation root localization\n");
    printf("[3] Integrals\n");
    printf("[E] Exit\n");
    printf("-------------------------\n");
    printf("Your choice: ");
    while((choo = getchar()) == '\n');
    printf("\n");
    return choo;
}

int main()
{
    char answer;
    while((answer = toupper(menu())) != 'E') {
    if(answer=='1'){
        printf("Enter the string: ");
        fflush(stdin);
        char str1[101];
        char str2[101];
        gets(str1);
        strcpy(str2,str1);
        strrev(str2);
        printf("Original: %s\nReverse: %s\n",str1,str2);
        if(strcmp(str1,str2)==0){
            printf("Palindrome\n");
        } else printf("Not palindrome\n");
        }
    if(answer=='2'){
        printf("Lab 05 Kim V(12) Task 2\n");
        printf("finding the roots of sin(x+1)-(x/2)  ");
        //menu
        int pw;
        printf("\nEnter the power of the step: -");
        if(scanf("%d",&pw)!=1||pw>7||pw<1){
            printf("\nIncorrect input! Expected 1 int more then 1less then 8\n");
            return -21;
        }
        double e;
        e = pow(10,0-pw);       //min interval
        double original_res = 1.38006;//ORIGINAL RESULT
        printf("\n\nOriginal result is: %.8f...\n",original_res);
        printf ("-------------------------------------------------------\n");
        /*
        Simple iteration
        */
        double iterx = iteration(tsk2f, 0, e, 2);
        double iterr = counterror(original_res, iterx);
        printf("Iteration method:\n Root is %.8f with error = %.5f%%...\n",iterx, iterr);
        printf ("-------------------------------------------------------\n");
        /*
        Bisection method
        */
        double bisecx = bisection(tsk2f, 2-e,e,0+e);
        double biserr = counterror(original_res, bisecx);
        printf("Bisection method:\n Root is %.8f with error = %.5f%%...\n",bisecx,biserr);
        printf ("-------------------------------------------------------\n");
        /*
        Secant method:
        */
        double secantx = secant(tsk2f, 2-e, e, 0+e);
        double secerr = counterror(original_res, secantx);
        printf("Secant method:\n Root is %.8f with error = %.5f%%...\n",secantx,secerr);
        printf("-------------------------------------------------------\n");

/*
        Newton's method
        */
        double newtx = newton(tsk2f, dtsk2f, 2-e, e , 0+e);
        double newterr =counterror(original_res, newtx) ;
        printf("Newton's method:\n Root is %.8f with error = %.5f%%;",newtx,newterr);
        printf ("\n-------------------------------------------------------\n\n");

    }
    if(answer=='3'){
        printf("Lab 05 Kim V(12) Task 3");
        printf("\nIntegrate  (1- tan x^2)/(1+tan x^2)^2  from x=pi/4 to pi/3");
        double original_res = 0.097406;
        printf("\nTrue result is: %.5f\n",original_res);
        double a=M_PI_4,b = M_PI/3;//INTERVAL
        double distance = 0.000001;//for trap, rect rules
            /*
            Trapezoidal rule
            */
            double trres=0, treps;
            for(double i = a; i < b; i+=distance){
                trres += (distance/2)*(fx(i)+fx(i+distance));
            }
            treps = counterror(original_res, trres);
            printf("\nResult using trapezoidal rule:\t\t%.5f; Error is %.5f%%",trres,treps);
            /*
            Riemann sum (left)
            */
            double leftres=0,lefteps;
            for(double i = a; i < b; i+=distance){
                leftres += distance*fx(i);
            }
            lefteps = counterror(original_res, leftres);
            printf("\nResult using left Riemann sum:\t\t%.5f; Error is %.5f%%",leftres,lefteps);
            /*
            Riemann sum (right)
            */
            double rightres=0, righteps;
            for(double i = a; i < b; i+=distance){
                rightres += distance*fx(i+distance);
            }
            righteps = counterror(original_res, rightres);
            printf("\nResult using right Riemann sum:\t\t%.5f; Error is %.5f%%",rightres,righteps);
            /*
            Riemann sum (midpoints)
            */
            double midres=0, mideps;
            for(double i = a; i < b; i+=distance){
                midres += distance*fx(i+distance/2);
            }
            mideps = counterror(original_res, midres);
            printf("\nResult using midpoints Riemann sum:\t%.5f; Error is %.5f%%",midres,mideps);
            /*
            Simpson's rule
            */
            double simres = 0, simeps;
            simres = (b-a)/6*(fx(a)+4*fx((a+b)/2)+fx(b));
            simeps = counterror(original_res, simres);
            printf("\nResult using Simpson's rule:\t\t%.5f; Error is %.5f%%\n",simres,simeps);
    }
    }
    return 0;
}
