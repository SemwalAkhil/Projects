public class SumFirstTen {
    static int sumNaturalNumbers() {
        int sum = 0;
        for (int i=1; i<=10; i++) {
            sum += i;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("Sum of first 10 natural numbers: " + sumNaturalNumbers());
    }
}
output:-
        Sum of first 10 natural numbers: 55
