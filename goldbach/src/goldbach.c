//Αυτό είναι το τρίτο μέρος του HW0.

#include <stdio.h>
#include <math.h>

long long primes(long long num) {   //Συνάρτηση που υπολογίζει αν ένας αριθμός είναι πρώτος.

    long long divisor, root, isprime = 1;
    root = sqrt(num);               //Αποθηκεύω σε μια μεταβλητή, τη ρίζα του αριθμού, για διευκόλυνση.

    if (num == 0 || num == 1) {     //Ελέγχω ακραίες περιπτώσεις.
        isprime = 0;
    }
    else {
        for (divisor = 2 ; divisor <= root ; divisor++) {
            if (num % divisor == 0) {
                isprime = 0;
                break;
            }
        }
    }
    return isprime;
}

long long goldbach(long long num) {     //Συνάρτηση που εκτελεί τη διαδικασία του Goldbach.

    long long a, b, isprime;    //Το a είναι ο πρώτος αριθμός και το b ο δεύτερος.
        
    while (1) {
        
        for (a = 2 ; a <= num / 2 ; a++) {
            if (primes(a) == 1) {
                b = num - a;
                if (primes(b) == 1) {
                    printf("%lld = %lld + %lld\n", num, a, b);
                    return 1;
                }
            }
        }
        break;
    }
    return 0;
}

int main() {

    long long number, isprime;
    char choice;
    int scanresult;

    while(1) {
        
        printf("PLease give me a number, between 0 and 10000000000:\n");
        
        scanresult = scanf("%lld", &number);

        if (scanresult == EOF) {
            printf("EOF detected, exiting.\n");
            return 0;
        }

        if (scanresult != 1) {
            printf("Invalid input: expected an integer.\n");
            return 1;
        }
        else {
            if (number < 0 || number > 10000000000LL) {
                printf("Number should be in the range [0, 10000000000].\n");
                return 1;
            }
        }
            
        printf("Now, choose how to test ('p' for prime, 'g' for goldbach):\n");
        
        if (scanf(" %c", &choice) == EOF) {
            printf("EOF detected, exiting.\n");
            return 0;
        }

        if (choice != 'p' && choice != 'g') {
            printf("Invalid choice: expected 'p' or 'g'.\n");
            return 1;
        }
        else {
            if (choice == 'p') {
            isprime =  primes(number);
                if (isprime == 1) {
                    printf("%lld is prime.\n", number);
                }
                else {
                printf("%lld is not prime.\n", number);
                }
                
            }
        
            else {
                if (((number % 2) != 0) || number <= 2) {
                    printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
                    continue;
                }
                else {
                    goldbach(number);
                    continue;
                }
            }
        }
        continue;
    }
    return 0;
}