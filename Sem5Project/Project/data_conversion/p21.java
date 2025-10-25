// 21. How to convert String to boolean

class StringToBoolean  {
    public static void main(String[] args) {
        String trueStr = "true";
        String falseStr = "false";
        String otherStr = "yes";

        boolean b1 = Boolean.parseBoolean(trueStr);
        boolean b2 = Boolean.parseBoolean(falseStr);
        boolean b3 = Boolean.parseBoolean(otherStr);

        System.out.println(trueStr + " -> " + b1);
        System.out.println(falseStr + " -> " + b2);
        System.out.println(otherStr + " -> " + b3);
    }
}

/*
Output:
true -> true
false -> false
yes -> false
 */