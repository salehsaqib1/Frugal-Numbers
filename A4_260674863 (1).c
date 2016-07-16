/*
 * A4_260674863.c
 *
 *  Created on: Mar 14, 2016
 *      Author: Saleh Saqib Fazal
 */

#include <stdio.h>
#include <math.h>

//The check_for_digits function counts and returns the number of digits of any integer input

int check_for_digits(int x){
	int digits=0;

	while(x!=0){
		x/=10;
		++digits;
	}

	return digits;
}

/*The frugal_checker function returns 1 if the number is frugal and returns 0 otherwise.
 Hence it is being used as a boolean true or false. */

int frugal_checker(int x){
	  int i, y;
	  int factorization_digits = 0;	//number of digits after prime factorization
	  int repeats=0;	//number of repeats of a factors
	  int digits_repeats=0;  //number of digits of repeats
	  int different_factors=0; //number of different factors
	  int original_digits;  //number of original digits

	  original_digits = check_for_digits(x);

	  y=sqrt(x);	/*to check for primes, it is only required to test factors less than
	  	  	  	  	or equal to the square root of the tested number*/

	  while (x%2 == 0){		//this while loop checks number for factor 2

		  if (repeats>0){
			  x = x/2;		//if repeats>0, i.e the factor 2 repeats then counter increases
			  repeats++;
			  continue;
		  }

		  x = x/2;
		  different_factors++;	//to account for the different factor 2
		  repeats++;
	  }


	  if(repeats>1) {		//check the digits of factor 2 if repeats is greater than 1.
	       digits_repeats += check_for_digits(repeats);
	  }

/*a for loop runs from the next prime number after 2 i.e 3 till the square root of the
 number. Since 2 is the only prime number that is even. So I took 2 as a separate case
 above and now I will check for odd prime factors.
 */
	  for (i = 3; i <= y; i = i+2){
		  repeats=0;

	  	  while (x%i == 0){

	  		  if (repeats>=1){
	  			  x = x/i;
	  			  repeats++;
	  			  continue;
	    	  }

	  		  x = x/i;
	       	  different_factors+= check_for_digits(i);
	    	  repeats++;
	     }

	     if (repeats>1){
	    	 digits_repeats += check_for_digits(repeats);
	     }
	  }

	    /* This if loop occurs if the test value after prime factorization is still
	        a prime number greater than 2.*/
	  if(x>2){
		  different_factors += check_for_digits(x);
	  }

	  factorization_digits= different_factors + digits_repeats;

	    /*the final if statement checks for frugal numbers by comparing the number of
	      digits in the original number and the result after prime factorization. For
	      number to be frugal factorization digits have to be less than the original. */

	  if(factorization_digits < original_digits){
		  return 1;
	  }

	return 0;
}


int main(){
	    int n, i;

	    scanf("%d", &n);           //reads user's input-value

	    /*frugal numbers can only exist for numbers which have prime factors. Since
	      '1' does not have any, the program processes for values greater than '1'*/

	    if(n>1){
	       /*Every number from 2 to the limit (n) is checked for its frugal nature.
	         The 'frugal_finder' function is called to check each value. If a value
	         is frugal it is printed to the screen. */
	       for(i=2; i<=n; i++){
	           if(frugal_checker(i)==1){
	               printf("%d ", i);
	           }
	       }
	    }

	    else if(n==1){
	        printf("Prime Factorization of '1' is not possible mathematically.");
	    }

	    else if(n<1){
	        printf("Please enter a positive integer value greater than 1.");
	    }

	    return 0;
}


