enum Color {
    RED, GREEN, BLUE
}

class Main {
    public static void main(String[] args) {
      
        Color c1 = Color.RED;
        
      
        String str1 = c1.name();
        System.out.println("Using name(): " + str1);

        
        String str2 = c1.toString();
        System.out.println("Using toString(): " + str2);
    }
}

