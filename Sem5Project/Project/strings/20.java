class Main {
    public static void main(String[] args) {
        String str = "ABC";
        int n = str.length();

        System.out.println("All subsets of " + str + ":");

        // Loop over 0 to 2^n - 1
        for (int i = 0; i < (1 << n); i++) {  // 1 << n = 2^n
            String subset = "";
            for (int j = 0; j < n; j++) {
                // Check if j-th bit in i is set
                if ((i & (1 << j)) != 0) {
                    subset += str.charAt(j);
                }
            }
            System.out.println(subset);
        }
    }
}

