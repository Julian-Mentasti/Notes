public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        if ((args.length == 0) || (args.length > 1)) {
            System.out.println("Input 1 argument");
            return;
        }
        int arg_integer = 0;
        try {               
        arg_integer = Integer.valueOf(args[0]);
        } catch (Exception e) {
            System.out.println("Invalid Input\n");
            return;
        }
        String hex_number = Integer.toHexString(arg_integer);
        String binary_number = Integer.toBinaryString(arg_integer);
        System.out.println("decimal representation:     " + arg_integer);
        System.out.println("hexadecimal representation: 0x" + hex_number);
        System.out.println("binary representation:      " + binary_number);
        
    
    }
}
