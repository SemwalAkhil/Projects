 class Main {
    public static void main(String[] args) {
        String str = "ABCDEFGHIJ"; // example string
        int N = 5;                 // number of parts

        int partSize = str.length() / N;

        for (int i = 0; i < N; i++) {
            int start = i * partSize;
            int end = start + partSize;
            System.out.println(str.substring(start, end));
        }
    }
}
