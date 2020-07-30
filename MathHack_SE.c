#include <stdio.h> 
#include <math.h> // For pow() & sqrt() & sin(), cos(), tan() & M_PI
#include <string.h> // for strcmp()
#define _USE_MATH_DEFINES // for M_PI in Visual Studio 
#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message
#ifndef M_PI // for compilers that do not have M_PI in math.h 
#define M_PI (3.14159265358979323846264338327950288)
#endif
void factorial(int unsigned long); 
long hcf(long,long); // for HCF & SMP
void trcalc(char func[6],double);
int main()
{
	printf("\n\nCALC | FACT | AVG | PRIME | PMFACT | TAB | FCTRL | EQ |  HCF | SMP | TCAL | TTAB\n"); // non-looped once-printed message
	while (1) {
		char choice[8];
		printf("\n\nMathHack_SE-v2 $ ");
		scanf("%s", choice); 
		if (strcmp(choice, "CALC") == 0 || strcmp(choice, "calc") == 0) 
		{
			double num1, num2, result; 
			char op; // determines operation
			scanf("%lf %c %lf", &num1, &op, &num2);
			switch(op) 
            {
                case '+':
                    result = num1 + num2;
                    printf("\n%s %lf\n","Result = ",result);
                    continue; // 'resets' => causes fresh instance through new iteration of infinite while loop ; used after every function finishes execution
                case '-':
                    result = num1 - num2;
                    printf("\n%s %lf\n","Result = ",result);
                    continue;
                case 'x':
                    result = num1*num2;
                    printf("\n%s %lf\n","Result = ",result);
                    continue;
                case '/':
                    result = num1/num2;
                    printf("\n%s %lf\n","Result = ",result);
                    continue;
                case '^':
                    result = pow(num1,num2);
                    printf("\n%s %lf\n","Result = ",result);
                    continue;
                case '%':
                {
                    int unsigned long n1 = num1; 
                    int unsigned long n2 = num2; // only int values can be used for % ; so %f nums are converted to %d n1,n2,re
                    int unsigned long re = n1%n2;
                    printf("\n%s %lu\n","Result = ",re);
                    continue;
                }
				case '|':
					result = pow(num1, 1.0/num2);
					printf("\n%s %lf\n","Result = ",result);
					continue;
                default :
                    error // invokes the error macro 
                    continue; 
            }
        }

		else if (strcmp(choice, "FACT") == 0 || strcmp(choice, "fact") == 0) 
		{
			int unsigned long num;
			scanf("%lu", &num);
			printf("\nFactors of %lu are:\n", num);
			printf("1,"); // 1 is a factor of every number 
			register int unsigned factor = 2; // counter , starts checking factors from 2
			while (factor <= num / 2) // looks for factors till counter reaches half of num
			{
				if (num%factor == 0)
				{
					printf(" %d, ", factor); // prints whitespace + factor

				}

				factor++; // increment counter to try next number
			}

			printf("%lu", num); // number is factor of itself
			continue; 
		}
		else if (strcmp(choice, "AVG") == 0 || strcmp(choice, "avg") == 0 ) 
		{
			register int i = 0; // for printing 'Enter number i ' & for accessing array 
            int q; //  for controlling number of iterations of for loop asking for a number 
			register int count;
            scanf("%d", &q);
			double num[100], sum = 0.0, average; 
			double x = 0.0; // variable to store entered number to 
			for (count = 1; count <= q; count++) {
				scanf("%lf", &x);
				num[i] = x; // puts x in array 
				sum += num[i]; // increments sum by num 
				i++; 
			}
			average = sum / i;
			printf("\n\n Average = %f", average);
			continue;
		}
		else if (strcmp(choice, "PRIME") == 0 || strcmp(choice,"prime") == 0 ) 
		{
			int unsigned long n; // number to be checked 
			register int unsigned i; // counter in for loop
			register int unsigned short flag = 0;
			scanf("%lu", &n);

			for (i = 2; i <= n / 2; ++i) { // checks for factors from 2 to half od number. 
				if (n % i == 0) {
					flag = 1; // flag made 1 , number is composite 
					break;
				}
			}

			if (n == 1) 
				printf("\n1 is neither prime nor composite.\n"); 
			else if (flag == 0) 
				printf("\n%lu is prime.\n", n);
			else
				printf("\n%lu is not prime.\n", n);
			continue;
		}
		else if (strcmp(choice, "PMFACT") == 0 || strcmp(choice, "pmfact") == 0 ) { 
			int unsigned long num; // variable that stores entered number 
			register int unsigned i, j; // counters with for loops
			int unsigned short isPrime; // for checking that factor is indeed prime
			scanf("%lu", &num);
			printf("\nPrime factors of %lu are: \n", num); 
			for (i = 2; i <= num; i++) // factors checked for b/w 2 to value of number 
			{
				if (num%i == 0) // if factor i detected 
				{
					isPrime = 1;
					for (j = 2; j <= i / 2; j++) // factor i checked for prime
					{
						if (i%j == 0) 
						{
							isPrime = 0; // if number is number is evenly divisible with another number, it is not prime & is declared so. 
							break;
						}
					}
					if (isPrime == 1) // if number was not flagged as composite, it is printed 
					{
						printf("%u ", i);
					}
				}
			}
			continue;
		}
		else if (strcmp(choice, "TAB") == 0 || strcmp(choice, "tab") == 0 ) { 
			int unsigned long num, result; 
			register int unsigned short i; // counter
			scanf("%lu", &num);
			for (i = 2; i<=19 ; ++i) { // loop runs from 2 to 19, generating multiplication table. 
				result = num*i;
				printf("\n %lu x %i = %lu", num, i, result);
			}
			continue;
		}
		else if (strcmp(choice, "FCTRL")== 0 || strcmp(choice, "fctrl")== 0 ) { 
			int unsigned long num, result;
			scanf("%ld", &num);
			if (num <= 20){
				factorial(num); // calls function 
				continue;
			}
			else {
				printf("\nSorry,MathHack cannot yet accurately calculate beyond 20 factorial.This is being worked on.\n"); // to flag and inform of inaccuracy beyond 20! when not uing tricks
				continue; 
			}
		}		
		else if (strcmp(choice, "EQ")== 0 || strcmp(choice, "eq")== 0 ) {  
			double a, b,c, r1, r2, r, dscrmnt, real, img; // variables are : co-efficients , constant , roots 1 & 2, discriminat 
			scanf("%lf", &a);
			scanf("%lf", &b);
			scanf("%lf", &c);

			dscrmnt = b*b - 4*a*c;
			printf("\n\nDiscriminant evaluates to %lf\n", dscrmnt);

			if (dscrmnt > 0) {
				r1= (-b + sqrt(dscrmnt))/ (2*a);
				r2= (-b - sqrt(dscrmnt))/ (2*a);
				printf("\nRoot 1 = %lf", r1);
				printf("\nRoot 2 = %lf", r2);
				continue;
			}
			else if (dscrmnt == 0) {
				r = -b/(2*a);
				printf("\nRoot 1 = Root 2 = %lf", r);
				continue;
			}
			else {
				printf("\nThe roots are not real for the given values.\n");
				real = -b/(2*a);
				img = sqrt(-dscrmnt) / (2*a);
				printf("\nRoot 1 = %lf + %lfi", real, img);
				printf("\nRoot 2 = %lf - %lfi", real, img);
				continue;
			}
		}
		else if (strcmp(choice,"HCF")== 0 || strcmp(choice,"hcf")== 0 ) { 
			long a,b;
			scanf("%ld",&a);
			scanf("%ld", &b);
			printf("\n\nHCF of %ld and %ld = %ld ", a, b, hcf(a,b)); // hcf() is called within printf() 
		}
		else if (strcmp(choice,"SMP")==0 || strcmp(choice,"smp")==0 ) { 
            long nu, den, gcd, newn,newd; // initial numerator & denominator , their hcf/gcd, the new n&d
            scanf("%ld", &nu);
            scanf("%ld", &den);
            gcd = hcf(nu,den); // hcf() is called and stored to gcd
            newn = nu/gcd;// division by hcf/gcd for simplifying the fraction
            newd = den/gcd;
            printf("\n\nSimplified Fraction is %ld / %ld\n", newn,newd);
            continue;
		}
    	else if(strcmp(choice,"TCAL")==0 || strcmp(choice,"tcal")==0 ) {
        	char func[6]; // string that stores trigonometric function 
        	double rad; // variable for radian value 
			char unit; // variable that stores unit of angle  
        	scanf(" %c", &unit); 
        	if(unit == 'd' ) {
            	double deg; //stores degree value 
            	scanf("%s %lf", func, &deg); 
            	rad = deg * M_PI/180; // converts angle to radians 
            	trcalc(func,rad); 
			}
        	else if(unit == 'r'){
            	scanf("%s %lf", func, &rad);
            	trcalc(func,rad); // function and rad angle passed to trcalc()
			}
			else 
				error
			continue;
        }
		else if(strcmp(choice,"TTAB")==0 || strcmp(choice,"ttab")==0) { 
			char what; // variable that stores unit of angle 
			double this,in; // this == rad value ; in == entered value. For rad angle, in==this. 
			scanf(" %c",&what); 
			if(what=='d') {
				scanf("%lf",&in);
				this = in * (M_PI/180); // converts degree to rad 
				printf("\nAngle in Radian = %lf\n ", this);
				printf("\nSin of %.2lf = %lf ", in, sin(this));
				printf("\nCos of %.2lf = %lf ", in, cos(this));
				printf("\nTan of %.2lf = %lf ", in, tan(this));
				printf("\nCosec of %.2lf = %lf ", in, 1/ (sin(this)));
				printf("\nSec of %.2lf = %lf ", in, 1/ (cos(this)));
				printf("\nCot of %.2lf = %lf ", in, 1/ (tan(this)));
			}
			else if(what== 'r') {
				scanf("%lf",&in);
				this = in * (180.0 / M_PI); // converts rad to deg
				printf("\nAngle in degrees = %lf\n ", this);
				printf("\nSin of %.2lf = %lf ", in, sin(in));
				printf("\nCos of %.2lf = %lf ", in, cos(in));
				printf("\nTan of %.2lf = %lf ", in, tan(in));
				printf("\nCosec of %.2lf = %lf ", in, 1/ (sin(in)));
				printf("\nSec of %.2lf = %lf ", in, 1/ (cos(in)));
				printf("\nCot of %.2lf = %lf ", in, 1/ (tan(in)));
			}
			else 
				error
			continue;
		}
        else if(strcmp(choice,"exit")==0)
            break;
		else { // in case none of the above inputs are selected
			error 
			continue;
		}
	}
	return 0;
}
void factorial (int unsigned long x)
{
	register int unsigned long f = 1; // stores product
	register int unsigned long i; // counter 
	for (i=x;i>=1;i--) // loop decrements from number till 1
		f= f*i; 
	printf("\nFactorial of %lu = %lu\n",x,f);
}
long hcf (long p,long q) { //recursive function based on Euclid's algorithm to calculate HCF/GCD of two nos. 
	if(q==0) 
		return p; 
	else 
		return hcf(q, p%q); // recursion 
}
void trcalc (char func[6],double angle) {
    double ans;
    if(strcmp(func,"sin")==0)
        printf("\nResult = %lf",sin(angle)); 
    else if(strcmp(func,"cos")==0)
        printf("\nResult = %lf",cos(angle));
    else if (strcmp(func,"tan")==0)
        printf("\nResult = %lf",tan(angle));
    else if(strcmp(func,"cosec")==0)
        printf("\nResult = %lf",1/ (sin(angle)));
    else if(strcmp(func,"sec")==0)
        printf("\nResult = %lf",1/ (cos(angle)));
    else if(strcmp(func,"cot")==0)
        printf("\nResult = %lf",1/ (tan(angle)));
    else
        error
}
//Release Notes :
//MathHackSE-v1.0 => Based on MathHack-v1.5.2
//MathHackSE-v2.0 => Based on MathHac-v2