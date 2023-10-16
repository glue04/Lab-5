#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const char* getMonthName(int index){
	return months[index];
	}
	
void monthlyreport(double sales[]);
void summary(double sales[]);
void movingaverages(double sales[]);
void sorted(double sales[]);

int main(){
	FILE *file = fopen("input.txt", "r");
	if(file==NULL){
		printf("Error opening file");
		return 1;
		}
	
	double sales[MONTHS];
	for(int i = 0; i<MONTHS; i++){
		fscanf(file, "%lf", &sales[i]);
	}
	fclose(file);
	
	monthlyreport(sales);
	summary(sales);
	movingaverages(sales);
	sorted(sales);
	return 0;
}

void monthlyreport(double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]);
    }
    printf("\n");
}


void summary(double sales[]) {
	double min = sales[0];
	double max = sales[0];
	double total = 0;
	int minMonth = 0;
	int maxMonth = 0;
	
	for(int i = 0; i < MONTHS; i++) {
		if(sales[i]<min) {
			min = sales[i];
			minMonth = i;
			}
		if (sales[i] > max) {
            		max = sales[i];
            		maxMonth = i;
        		}
        	total += sales[i];
        	}
        printf("Sales summary:\n");
    	printf("Minimum sales: $%.2lf (%s)\n", min, getMonthName(minMonth));
    	printf("Maximum sales: $%.2lf (%s)\n", max, getMonthName(maxMonth));
    	printf("Average sales: $%.2lf\n\n", total / MONTHS);
	}

void movingaverages(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2lf\n", getMonthName(i), getMonthName(i+5), sum / 6.0);
    }
    printf("\n");
}

void sorted(double sales[]) {
    typedef struct {
        double value;
        int index;
    } SaleData;

    
    SaleData sortedSales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i].value = sales[i];
        sortedSales[i].index = i;
    }

    
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sortedSales[j].value < sortedSales[j + 1].value) {
                SaleData temp = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;
            }
        }
    }
    
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", getMonthName(sortedSales[i].index), sortedSales[i].value);
    }
    printf("\n");
}

