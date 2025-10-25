class Main {
    public static void main(String[] args) {
        String str = "Hello world Java";

      
        String arr[] = str.split(" ");

     
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
