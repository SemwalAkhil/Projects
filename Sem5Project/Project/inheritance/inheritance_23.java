// CODE:-

abstract class Instrument {
    abstract void play();
    abstract void tune();
}

class Glockenspiel extends Instrument {
    void play() {
        System.out.println("Playing the Glockenspiel with soft, melodic tones.");
    }

    void tune() {
        System.out.println("Tuning the Glockenspiel bars to perfect pitch.");
    }
}

class Violin extends Instrument {
    void play() {
        System.out.println("Playing the Violin with smooth bow movements.");
    }

    void tune() {
        System.out.println("Tuning the Violin strings to the correct frequency.");
    }
}

class Main {
    public static void main(String[] args) {
        Glockenspiel g = new Glockenspiel();
        Violin v = new Violin();

        System.out.println("----- Glockenspiel -----");
        g.tune();
        g.play();

        System.out.println("\n----- Violin -----");
        v.tune();
        v.play();
    }
}
