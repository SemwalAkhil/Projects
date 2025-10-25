 class Main {
    public static void main(String[] args) {
        // Create StringBuffer object
        StringBuffer sb = new StringBuffer("Hello");

        System.out.println("Original StringBuffer: " + sb);

        // 1. Append - add text at the end
        sb.append(" World");
        System.out.println("After append: " + sb);

        // 2. Insert - add text at a specific position
        sb.insert(6, "Java ");
        System.out.println("After insert: " + sb);

        // 3. Delete - remove characters from start index to end index (exclusive)
        sb.delete(6, 11); // removes "Java "
        System.out.println("After delete: " + sb);

        // 4. Replace - replace characters from start index to end index with new text
        sb.replace(0, 5, "Hi");
        System.out.println("After replace: " + sb);
    }
}
