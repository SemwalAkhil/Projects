 class Main {
    public static void main(String[] args) {
        String str = "banana"; 
        str = str.toLowerCase(); 
        int[] freq = new int[256]; 

        
        for (char c : str.toCharArray()) {
            freq[c]++;
        }

        System.out.println("Character frequencies:");
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                System.out.println((char) i + " - " + freq[i]);
            }
        }
    }
}