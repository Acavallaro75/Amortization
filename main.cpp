#include <cstdio>

int main() {
    double interestRate, interestPaid, principle, principlePaid, initialPrinciple, payment, paymentBalance,
            endingPayment, totalPayments, totalInterest = 0;
    printf("How much was the loan for:");
    scanf("%lf", &initialPrinciple); //Sets the variable "initialPrinciple" to the user's input//
    printf("What was the interest rate:");
    scanf("%lf", &interestRate); //Sets the variable "interestRate" to the user's input//
    printf("How much is your monthly payment:");
    scanf("%lf", &payment); //Sets the variable "payment" to the user's input//
    if (interestRate < 1) { //This is used if the user enters a decimal for the interest rate//
        interestRate = (interestRate * 100);
    }
    principle = initialPrinciple; //This is put here to recall the initial principle later//
    printf("Principle:\t$%.2lf\n", principle);
    printf("Interest:\t  %.0lf%%\n", interestRate);
    printf("Payment:\t  $%.2lf\n", payment);
    printf("         \tInt.\tPrinciple\tEnding \t    Payment\n");
    printf("Principle\tPaid\t  Paid   \tPayment\t    Balance\tMade On\n");
    printf("---------\t----\t---------\t-------\t    -------\t-------\n");
    while (principle > 0) {
        printf("%9.2lf", principle);
        interestPaid = principle * ((interestRate / 12) / 100);
        printf("%12.2lf", interestPaid);
        principlePaid = (payment - interestPaid);
        printf("\t%9.2lf", principlePaid);
        endingPayment = payment;
        printf("\t%7.2lf", endingPayment);
        paymentBalance = principle - principlePaid;
        printf("\t%11.2lf", paymentBalance);
        principle = (principle - principlePaid);
        printf("\t_______\n");
        totalInterest += interestPaid;
        if (endingPayment > paymentBalance) {
            totalPayments = totalInterest + initialPrinciple;
            printf("%9.2lf", principle);
            interestPaid = principle * ((interestRate / 12) / 100);
            printf("%12.2lf", interestPaid);
            principlePaid = principle;
            printf("\t%9.2lf", principlePaid);
            endingPayment = principle;
            printf("\t%7.2lf", endingPayment);
            paymentBalance = principle - principlePaid;
            printf("\t    %7.2lf", paymentBalance);
            printf("\t_______\n");
            printf("The total amount of payments is $%.2lf.\n", totalPayments);
            printf("The total interest paid is $%.2lf.", totalInterest);
            break;
        }
    }
    return 0;
}