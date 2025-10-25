/*25. Create a class, entering the command line arguments from the user 
    and show all the arguments as output.*/

class p25 {
    public static void main(String args[]) {

        // Check if any command line arguments are provided
        if(args.length == 0) {
            System.out.println("No command line arguments provided.");
            return;
        }

        // Display all command line arguments
        System.out.println("Command Line Arguments:");
        for(int i = 0; i < args.length; i++) {
            System.out.println("Argument " + (i + 1) + ": " + args[i]);
        }
    }
}
