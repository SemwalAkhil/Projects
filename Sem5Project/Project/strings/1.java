import java.util.Scanner;

 class main {
    public static void Main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        boolean onlyDigits = true;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch < '0' || ch > '9') {
                onlyDigits = false;
                break;
            }
        }

        if (onlyDigits) {
            System.out.println("Only digits");
        } else {
            System.out.println("Not only digits");
        }

        sc.close();
    }
}