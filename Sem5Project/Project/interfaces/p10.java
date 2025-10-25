// 10. Write a Java program to create an interface Encryptable with methods encrypt (String data) and decrypt (String encryptedData) that define encryption and decryption operations. Create two classes AES and RSA that implement the Encryptable interface and provide their own encryption and decryption algorithms.

interface Encryptable {
    String encrypt(String data);
    String decrypt(String encryptedData);
}

class AES implements Encryptable {
    public String encrypt(String data) {
        StringBuilder sb = new StringBuilder();
        for(char c : data.toCharArray()) sb.append((char)(c + 1)); // simple shift encryption
        return sb.toString();
    }

    public String decrypt(String encryptedData) {
        StringBuilder sb = new StringBuilder();
        for(char c : encryptedData.toCharArray()) sb.append((char)(c - 1));
        return sb.toString();
    }
}

class RSA implements Encryptable {
    public String encrypt(String data) {
        StringBuilder sb = new StringBuilder();
        for(char c : data.toCharArray()) sb.append((char)(c + 2)); // simple shift encryption
        return sb.toString();
    }

    public String decrypt(String encryptedData) {
        StringBuilder sb = new StringBuilder();
        for(char c : encryptedData.toCharArray()) sb.append((char)(c - 2));
        return sb.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Encryptable aes = new AES();
        Encryptable rsa = new RSA();

        String data = "Hello";
        String encryptedAES = aes.encrypt(data);
        String decryptedAES = aes.decrypt(encryptedAES);

        String encryptedRSA = rsa.encrypt(data);
        String decryptedRSA = rsa.decrypt(encryptedRSA);

        System.out.println("AES Encrypted: " + encryptedAES);
        System.out.println("AES Decrypted: " + decryptedAES);
        System.out.println("RSA Encrypted: " + encryptedRSA);
        System.out.println("RSA Decrypted: " + decryptedRSA);
    }
}

/*
Output:
AES Encrypted: Ifmmp
AES Decrypted: Hello
RSA Encrypted: Jgnnq
RSA Decrypted: Hello
*/
