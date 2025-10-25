class Main{
   public static void main(String[] args) {
    String str ="surya";
    String rev = "";
    
    for (int i = str.length() - 1; i >= 0; i--) {
     rev = rev + str.charAt(i);
        }

        System.out.println("Original string: " + str);
        System.out.println("Reversed string: " + rev);
    
    
    }
}
