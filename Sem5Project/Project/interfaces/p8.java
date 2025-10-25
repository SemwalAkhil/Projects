// 8. Write a Java program to create an interface Playable with a method play() that takes no arguments and returns void. Create three classes Football, Volleyball, and Basketball that implement the Playable interface and override the play() method to play the respective sports.

interface Playable {
    void play();
}

class Football implements Playable {
    public void play() {
        System.out.println("Playing Football");
    }
}

class Volleyball implements Playable {
    public void play() {
        System.out.println("Playing Volleyball");
    }
}

class Basketball implements Playable {
    public void play() {
        System.out.println("Playing Basketball");
    }
}

public class Main {
    public static void main(String[] args) {
        Playable f = new Football();
        Playable v = new Volleyball();
        Playable b = new Basketball();

        f.play();
        v.play();
        b.play();
    }
}

/*
Output:
Playing Football
Playing Volleyball
Playing Basketball
*/
