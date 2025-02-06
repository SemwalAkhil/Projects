#include <stdio.h>

void printPostOrder(int preorder[], int start, int end) {
    if (start > end) return;

    int root = preorder[start];
    int rightStart = start + 1;

    while (rightStart <= end && preorder[rightStart] < root) {
        rightStart++;
    }

    printPostOrder(preorder, start + 1, rightStart - 1);
    printPostOrder(preorder, rightStart, end);
    
    printf("%d ", root);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int preorder[n];

    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Postorder traversal: ");
    printPostOrder(preorder, 0, n - 1);
    printf("\n");
    return 0;
}
