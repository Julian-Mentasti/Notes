
import java.lang.System;
import java.io.IOException;

//
// This is an implementation of a simplified version of a command 
// line ftp client. The program always takes two arguments
//
import java.util.Arrays;

public class CSftp
{
    static final int MAX_LEN = 255;
    static final int ARG_CNT = 2;
    static final int DEFAULT_PORT = 21;

    public static void main(String [] args)
    {
        byte cmdString[] = new byte[MAX_LEN];
        // Get command line arguments and connected to FTP
        // If the arguments are invalid or there aren't enough of them
        // then exit.

        if (args.length != ARG_CNT) {
            System.out.print("Usage: cmd ServerAddress ServerPort\n");
            System.exit(2);
        }

        try {
            for (int len = 1; len > 0;) {
                System.out.print("csftp> ");
                Arrays.fill(cmdString, (byte)0);
                len = System.in.read(cmdString);
                if (len <= 0)
                    break;
                // Send input to inputHandler
                try {
                    int portNumber = arg.length == ? Integer.parseInt(args[1]): DEFAULT_PORT;
                    InputHandler inputHandler = new InputHandler(cmdString, args[0], portNumber);
                    //ConnectionHandler connectionHandler = new ConnectionHandler(inputHandler);
                    //connectionHandler.execute();
                } catch (NonFatalException nfe) {
                    nfe.printStackTrace();
                } catch (FatalException fe) {
                    fe.printStackTrace();
                    System.exit(1);
                } catch (Throwable e) {
                    //do nothing
                }
            }
        } catch (IOException exception) {
        System.err.println("0xFFFE Input error while reading commands, terminating.");
        }
    }
}

