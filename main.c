#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define TAX 0.13


float roundto4(float x){
	float y =  round(x * 100) / 100;
	return y;
}

void denumeratePrice(double price) {
    int cents = price * 100;  // Convert the price to cents

    // Calculate the number of each coin denomination
    int toonies = cents / 200;
    cents %= 200;
    int loonies = cents / 100;
    cents %= 100;
    int quarters = cents / 25;
    cents %= 25;
    int dimes = cents / 10;
    cents %= 10;
    int nickels = cents / 5;
    cents %= 5;
    int pennies = cents;
	
	//print headings
	printf("Coin     Qty Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", price);

    // Print the rows for each coin denomination
    printf("Toonies  %3d %9.4lf\n", toonies, price - toonies * 2.0);
    printf("Loonies  %3d %9.4lf\n", loonies, price - toonies * 2.0 - loonies * 1.0);
    printf("Quarters %3d %9.4lf\n", quarters, price - toonies * 2.0 - loonies * 1.0 - quarters * 0.25);
    printf("Dimes    %3d %9.4lf\n", dimes, price - toonies * 2.0 - loonies * 1.0 - quarters * 0.25 - dimes * 0.10);
    printf("Nickels  %3d %9.4lf\n", nickels, price - toonies * 2.0 - loonies * 1.0 - quarters * 0.25 - dimes * 0.10 - nickels * 0.05);
    printf("Pennies  %3d %9.4lf\n", pennies, price - toonies * 2.0 - loonies * 1.0 - quarters * 0.25 - dimes * 0.10 - nickels * 0.05 - pennies * 0.01);

}


int main(){
	const char patsize = 'S';
	const char tomsize='L';
	const char salsize='M';

	int sqty, mqty, lqty;
	float small, medium, large;
		
	//taking prices from user
	printf("Set Shirt Prices\n================\n");
	printf("Enter the price for SMALL shirt: $");
	scanf("%f", &small);
	printf("Enter the price for MEDIUM shirt: $");
	scanf("%f", &medium);
	printf("Enter the price for LARGE shirt: $");
	scanf("%f", &large);

	
	printf("\n\n");
	
	//displaying the prices of shirt
	printf("Shirt Store Price List \n======================\n");
	printf("SMALL: %.2f\n", small);
	printf("MEDIUM: %.2f\n", medium);
	printf("LARGE: %.2f\n\n", large);
	
	
	//getting quantity of shirts
	printf("\nPatty's shirt size is '%c'\n", patsize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &sqty);
	printf("\nTommy's shirt size is '%c'\n", tomsize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &lqty);
	printf("\nSally's shirt size is '%c'\n", salsize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &mqty);
	
	printf("\n\n");
	
	
	
	//variables for displaying in table format
	float 
		smSubtotal = roundto4(small*sqty),
		smTax = roundto4(smSubtotal * TAX),
		smTotal = roundto4(smSubtotal+smTax), 
		mdSubtotal = roundto4(medium*mqty),
		mdTax = roundto4(mdSubtotal * TAX),
		mdTotal = roundto4(mdSubtotal+mdTax), 
		lgSubtotal = roundto4(large*lqty),
		lgTax = roundto4(lgSubtotal * TAX), 
		lgTotal = roundto4(lgSubtotal+lgTax),
		totalSubtotal = smSubtotal+mdSubtotal+lgSubtotal,
		totalTax = smTax+mdTax+lgTax,
		totalTotal = smTotal+mdTotal+lgTotal;
	


//	displaying bill data 	
	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patsize, small, sqty, smSubtotal, smTax, smTotal);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salsize, medium, mqty, mdSubtotal, mdTax, mdTotal);
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomsize, large, lqty, lgSubtotal, lgTax, lgTotal);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("%33.4lf %9.4lf %9.4lf\n\n",totalSubtotal, totalTax, totalTotal );
	
	
	printf("Daily retail sales represented by coins\n=======================================\n\n");
	
	printf("Sales EXCLUDING tax\n");
	denumeratePrice(totalSubtotal);
	
	printf("\n Average cost/shirt: $%.4f \n", totalSubtotal / (sqty + mqty + lqty));
	
	printf("Sales INCLUDING tax\n");
	denumeratePrice(totalTotal);
	
	printf("\n Average cost/shirt: $%.4f \n", totalTotal / (sqty + mqty + lqty));
	return 0;
}

