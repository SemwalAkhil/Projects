 class Main {
    public static void main(String[] args) {
        String str = "ABC";
        System.out.println("All permutations of " + str + " are:");
        permute(str, "");
    }

    static void permute(String str, String prefix) {
        if (str.isEmpty()) {
            System.out.println(prefix);
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            permute(str.substring(0, i) + str.substring(i + 1), prefix + str.charAt(i));
        }
    }
}

