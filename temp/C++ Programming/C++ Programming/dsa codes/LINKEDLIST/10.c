#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

Term* poly1 = NULL;
Term* poly2 = NULL;

void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = *poly;
    *poly = newTerm;
}

Term* subtractPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 || poly2) {
        int coeff = 0, exp = 0;
        if (poly1 && (!poly2 || poly1->exp > poly2->exp)) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly2 && (!poly1 || poly2->exp > poly1->exp)) {
            coeff = -poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coeff - poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        insertTerm(&result, coeff, exp);
    }
    return result;
}

void displayPolynomial(Term* poly) {
    while (poly) {
        printf("%dx^%d ", poly->coeff, poly->exp);
        if (poly->next) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;

    printf("Enter number of terms for first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter number of terms for second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    Term* result = subtractPolynomials(poly1, poly2);

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
