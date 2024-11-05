// 11. ENTER THE 2 POLYNOMIAL EQUATIONS DYNAMICALLY, MULTIPLY THEM AND DISPLAY THE ANSWER.
#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
struct Term
{
    int coeff;
    int exp;
    struct Term *next;
};

// Function to create a new term
struct Term *createTerm(int coeff, int exp)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial in descending order of exponent
void insertTerm(struct Term **poly, int coeff, int exp)
{
    struct Term *newTerm = createTerm(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp)
    {
        newTerm->next = *poly;
        *poly = newTerm;
    }
    else
    {
        struct Term *temp = *poly;
        while (temp->next != NULL && temp->next->exp >= exp)
        {
            temp = temp->next;
        }
        if (temp->exp == exp)
        {
            temp->coeff += coeff;
        }
        else
        {
            newTerm->next = temp->next;
            temp->next = newTerm;
        }
    }
}

// Function to multiply two polynomials
struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;

    // Multiply each term of poly1 with each term of poly2
    for (struct Term *p1 = poly1; p1 != NULL; p1 = p1->next)
    {
        for (struct Term *p2 = poly2; p2 != NULL; p2 = p2->next)
        {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertTerm(&result, coeff, exp);
        }
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }

    int isFirst = 1; // Flag to check if it's the first term
    while (poly != NULL)
    {
        if (!isFirst && poly->coeff > 0)
        {
            printf(" + ");
        }
        else if (poly->coeff < 0)
        {
            printf(" - ");
        }

        if (poly->exp == 0)
        {
            printf("%d", abs(poly->coeff));
        }
        else if (poly->exp == 1)
        {
            printf("%dx", abs(poly->coeff));
        }
        else
        {
            printf("%dx^%d", abs(poly->coeff), poly->exp);
        }

        isFirst = 0; // Set flag to false after the first term
        poly = poly->next;
    }
    printf("\n");
}

// Function to free the polynomial linked list
void freePolynomial(struct Term *poly)
{
    struct Term *temp;
    while (poly != NULL)
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    struct Term *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int terms, coeff, exp;

    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &terms);
    printf("Enter terms for Polynomial 1 (coefficient and exponent):\n");
    for (int i = 0; i < terms; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("\nEnter number of terms for Polynomial 2: ");
    scanf("%d", &terms);
    printf("Enter terms for Polynomial 2 (coefficient and exponent):\n");
    for (int i = 0; i < terms; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Multiply the two polynomials
    result = multiplyPolynomials(poly1, poly2);

    // Display the polynomials and the result
    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("Result (Product): ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
