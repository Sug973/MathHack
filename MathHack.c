#include <stdio.h> 
#include <math.h> // For pow() & sqrt() & sin(), cos(), tan() & M_PI
#include <string.h> // for strcmp()
#define _USE_MATH_DEFINES // for M_PI in Visual Studio 
#define error printf("\nInvalid Input, Sorry.\n"); //macro template for std error message
#ifndef M_PI // for compilers that do not have M_PI in math.h 
#define M_PI (3.14159265358979323846264338327950288)
#endif
void factorial(int unsigned long long); 
long long hcf(long long ,long long); // for HCF & SMP
void trcalc(char func[6],double);
void eat(void);
int main()
{
	printf("\n\n| MathHack v2.1 | \n\nFunctions :\n----------------------------------------------\n| CAL | FACT | AVG | PRIME | PMFACT | TAB | \n----------------------------------------------\n| FCTRL | EQ | HCF | SMP | TCAL | TTAB |"); // non-looped once-printed message
	while (1) {
		char choice[8];
		printf("\n----------------------------------------------\n\nChoose Function : "); 
		scanf("%8s", choice); 
		eat();

		if (strcmp(choice, "CAL") == 0 || strcmp(choice, "cal")==0)
		{
			double num1, num2, result; 
			char op; // determines operation
			printf("\n+  -  x  /  ^  %% | are valid operators.\n\nInput expression : ");
			scanf("%lf %c %lf", &num1, &op, &num2);
			eat();
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
                    long long n1 = num1; 
                    long long n2 = num2; // only int values can be used for % ; so %f nums are converted to %d n1,n2,re
                    long long re = n1%n2;
                    printf("\n%s %lld\n","Result = ",re);
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
			int unsigned long long num;
			printf("\nInput whole number : ");
			scanf("%llu", &num); eat();
			printf("\nFactors of %llu are:\n", num);
			printf("1,"); // 1 is a factor of every number 
			register unsigned long long factor = 2; // counter , starts checking factors from 2
			while (factor <= num / 2) // looks for factors till counter reaches half of num
			{
				if (num%factor == 0)
				{
					printf(" %llu, ", factor); // prints whitespace + factor

				}

				factor++; // increment counter to try next number
			}

			printf("%llu", num); // number is factor of itself
			continue; 
		}
		else if (strcmp(choice, "AVG") == 0 || strcmp(choice, "avg") == 0 ) 
		{
			register int i = 0; // for printing 'Enter number i ' & for accessing array 
            int q; //  for controlling number of iterations of for loop asking for a number 
			register int count; 
            printf("\nEnter number of values to calculate avg of : ");
            scanf("%d", &q);eat();
			double sum = 0.0, average; 
			double x = 0.0; // variable to store entered number to 
			for (count = 1; count <= q; count++) {

				printf("\nEnter number %d : ", i + 1);
				scanf("%lf", &x);eat();
				sum += x; // increments sum by num 
				i++; 
			}
			average = sum / i;
			printf("\n\n The Average is %f", average);
			continue;
		}
		else if (strcmp(choice, "PRIME") == 0 || strcmp(choice,"prime") == 0 ) 
		{
			int unsigned long long n; // number to be checked 
			register unsigned long long i; // counter in for loop
			register int unsigned short flag = 0;
			printf("\n\nEnter whole number to check : ");
			scanf("%llu", &n);eat();

			for (i = 2; i <= (sqrt(n)); ++i) { // checks for factors from 2 to sqrt of number. 
				if (n % i == 0) {
					flag = 1; // flag made 1 , number is composite 
					break;
				}
			}
			if (n == 1) 
				printf("\n1 is neither prime nor composite.\n"); 
			else if (flag == 0) 
				printf("\n%llu is a prime number.\n", n);
			else
				printf("\n%llu is not a prime number.\n", n);
			continue;
		}
		else if (strcmp(choice, "PMFACT") == 0 || strcmp(choice, "pmfact") == 0 ) { 
			int unsigned long num; // variable that stores entered number 
			register int unsigned i, j; // counters with for loops
			int unsigned short isPrime; // for checking that factor is indeed prime 
			printf("\nEnter whole number : ");
			scanf("%lu", &num);eat();
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
			double num, result; 
			register int unsigned short i; // counter 
			printf("\nEnter number to generate multiplication table : ");
			scanf("%lf", &num);eat();
			for (i = 2; i<=19 ; ++i) { // loop runs from 2 to 19, generating multiplication table. 
				result = num*i;
				printf("\n %.3lf x %i = %.3lf", num, i, result);
			}
			continue;
		}
		else if (strcmp(choice, "FCTRL")== 0 || strcmp(choice, "fctrl")== 0 ) { 
			int unsigned long long num, result;
			printf("\nEnter number to obtain factorial : ");
			scanf("%llu", &num);eat();
			if (num <= 20){
				factorial(num); // calls function 
				continue;
			}
			else {
				printf("\nSorry, max range is 20! . This is being worked on.\n"); // to flag and inform of inaccuracy beyond 20! when not uing tricks
				continue; 
			}
		}		
		else if (strcmp(choice, "EQ")== 0 || strcmp(choice, "eq")== 0 ) {  
			printf("\nGeneral form of quadratic equation is ax2 + bx + c = 0\n");
			double a, b,c, r1, r2, r, dscrmnt, real, img; // variables are : co-efficients , constant , roots 1 & 2, discriminat 
			printf("\nValue of a : ");
			scanf("%lf", &a);eat();
			printf("\nValue of b : ");
			scanf("%lf", &b);eat();
			printf("\nValue of c : ");
			scanf("%lf", &c);eat();

			dscrmnt = (b*b) - (4*a*c);
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
			long long a,b; 
			printf("\nFirst Number: ");
			scanf("%lld",&a);eat();
			printf("\nSecond Number: ");
			scanf("%lld", &b);eat();
			printf("\n\nHCF of %lld and %lld = %lld ", a, b, hcf(a,b)); // hcf() is called within printf() 
		}
		else if (strcmp(choice,"SMP")==0 || strcmp(choice,"smp")==0 ) { 
			long long nu, den, gcd, newn,newd; // initial numerator & denominator , their hcf/gcd, the new n&d
			printf("\nNumerator is : ");
			scanf("%lld", &nu);eat();
			printf("\nDenominator is : ");
			scanf("%lld", &den);eat();
			gcd = hcf(nu,den); // hcf() is called and stored to gcd 
			newn = nu/gcd; // division by hcf/gcd for simplifying the fraction
			newd = den/gcd;
			printf("\n\nSimplified Fraction is %lld / %lld\n", newn,newd);
			continue;
		}
    	else if(strcmp(choice,"TCAL")==0 || strcmp(choice,"tcal")==0 ) {
        	char func[6]; // string that stores trigonometric function 
        	double rad; // variable for radian value 
			char unit; // variable that stores unit of angle 
        	printf("\nRadians (r) or Degrees (d) : "); 
        	scanf(" %c", &unit);eat();
        	if(unit == 'd' ) {
            	printf("\nEnter T.func. followed by angle : ");
            	double deg; //stores degree value 
            	scanf("%s %lf", func, &deg); eat();
            	rad = deg * M_PI/180; // converts angle to radians 
            	trcalc(func,rad); 
			}
        	else if(unit == 'r'){
            	printf("\nEnter T.func. followed by angle : ");
            	scanf("%s %lf", func, &rad);eat();
            	trcalc(func,rad); // function and rad angle passed to trcalc()
			}
			else 
				error
			continue;
        }
		else if(strcmp(choice,"TTAB")==0 || strcmp(choice,"ttab")==0) { 
			char what; // variable that stores unit of angle 
			double this,in; // this == rad value ; in == entered value. For rad angle, in==this. 
			printf("\nRadian (r) or Degree (d) : ");
			scanf(" %c",&what); eat();
			if(what=='d') {
				printf("\nEnter degree angle : ");
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
				printf("\nEnter radian angle : ");
				scanf("%lf",&in); eat();
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
		else if(strcmp(choice,"exit")==0){
			break; // breaks loop to terminate MathHack
		}	
		else { // in case none of the above inputs are selected
			error 
			continue;
		}
	}
	return 0;
}
void factorial (int unsigned long long x)
{
	register unsigned long long f = 1; // stores product
	register unsigned long long i; // counter 
	for (i=x;i>=1;i--) // loop decrements from number till 1
		f= f*i; 
	printf("\nFactorial of %llu = %llu\n",x,f);
}
long long hcf (long long p,long long q) { //recursive function based on Euclid's algorithm to calculate HCF/GCD of two nos. 
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
void eat()
{
    int eat;while ((eat = getchar()) != '\n' && eat != EOF);
}
/*_______________________________
MathHack & AnPyCalc & AnCalc by Anant Prem Joshi
_______________________________
AnPyCalc v0.1(+, -, *, /, **)
 v0.2(Fixed Auto-Termination on Windows Cmd)
 v0.3(Added Facorisation)
 v0.4(Added Average)
 v0.4.1(Made easier to enter list for AVERAGE with 'enter number'string)
 v0.4.2(Added ability to enter decimal numbers for AVERAGE)
_______________________________
AnCalc v1.0 (Re-written in C and distributed as .exe + shortened user input)
 v1.1 (used while(1) )
 v2.0 (removed extra " , " @ Ln20 Col81 Ch72, changed message from 'Enter to Restart' to Enter to Reset', removed intro text from loop, fixed bug: every alternate Reset causes invalid input, CALC added moduluo division %, added PRIME)
 v2.1 (added PMFACT)
 v2.2(used continue instead of enter to continue, changed intro text to reflect changed features, removed inessential string.h inclusion)
_______________________________
 AnCalc renamed MathHack

MathHack v1.0 (added TAB : multiplication tables from 2 to 19)
 v1.1 (CALC if staments-->switch table for readability + performance)
 v1.2 (Open-sourcing of code, Binaries for Linux, Streamlining CALC to take expression, '----' after each iteration of while loop)
 v1.3 (added FCTRL,CALC added ' | ' feature, ints to longs & floats to doubles)
 v1.4 (short ints and register variables for loop counters, added error msg when attempting to compute > than 20!)
 v1.5 (#define error, Added EQ & HCF & SMP, enabled selection of function with or without capitlisation)
 v1.5.1 (Spell-correction, whitespace adjustment, Allowing user-defined no. of values in AVG, Replacing * with x in CALC)
 v1.5.2 (Code commenting, code-corrections for minor duplicacy and word choice)
 v2 (Working beyond simple arithmetic -> added Trigonmetric capabilities with TCALC and TTAB, also expanded EQ to complex and non-real roots)
 v2.1 (PRIME loop condition n/2-->sqrt(n), made TAB num double,'degreees'-->'degrees',CALC-->CAL,CAL - % - unisgned int-->long long, ~ all ints-->long long,AVG removed unneccasry arr, Changed Functions display style to be clearer,  Release-Notes-Comments restyled for clarity, scanf(choice) given size limit, added eat() to clear stdin)
_______________________________*/
