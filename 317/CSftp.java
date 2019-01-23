
import java.lang.System;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedStreamReader;
import java.io.BufferedInputStream;
import java.io.InputStreamReader;

//
// This is an implementation of a simplified version of a command
// line ftp client. The program always takes two arguments
//


public class CSftp
{
    // Constants
    static final int MAX_LEN = 255;
    static final int ARG_CNT = 2;
    static final int DFT_PRT = 21;
    static final int DFT_TMO = 20000;

    // Global Vars
    Socket socket;
    Socket dataSocket;
    BufferedReader fromServer;
    BufferedWriter toServer;
    BufferedReader fromDataServer;
    UserCommand userCommand;

    public static void main(String [] args)
    {
        byte cmdString[] = new byte[MAX_LEN];
        // Get command line arguments and connected to FTP
        // If the arguments are invalid or there aren't enough of them
        // then exit.

        if (args.length == 0) {
            System.out.print("Usage: cmd ServerAddress ServerPort\n");
            return;
        }

        String hostName = arg[0];
        int portNumber = arg.length == ? Integer.parseInt(args[1]): DFT_PRT;
        try {
            socket = new Socket();
            fromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            toSever = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            try {
                socket.connect(new InetSocketAddress(hostName, portNumber), DFT_TMO);
                String[] response = getReply("passive"); // 191
                System.out.println("<-- " + Arrays.toString(response));
            } catch (IOException e) {
                System.out.println("0xFFFC Control connection to " + hostName +
                                   " on port " + portNumber + " failed to open.");
            }
            for (int len = 1; len > 0;) {
                System.out.print("csftp> ");
                Arrays.fill(cmdString, (byte) 0);
                len = System.in.read(cmdString);
                if (len <= 0)
                    break;
                command = deLint(cmdString);
                command = convertInputToArray(command);
                try {
                    userCommand = new UserCommand(command);
                } catch (NonFatalException nfe) {
                    System.out.println(nfe.getMessage());
                }

                switch(userCommand.getCommand) {
                    case ("quit"):
                        quit();
                        break;
                    case ("cd"):
                        cd(userCommand.getArgument());
                        break;
                    case ("get"):
                        get(userCommand.getArgument());
                        break;
                    case ("features"):
                        features();
                        break;
                    case ("dir"):
                        dir()
                        break;
                    case ("user"):
                        login(userCommand.getArgument());
                        break;
                    case ("pw"):
                        password(userCommand.getArgument());
                        break;
                }
            }
         } catch (IOException e) {
            System.err.println("0xFFFE Input error while reading commands, terminating.");
         }
         ragequit();
    }

    /**
    Helper Class to hold the data of a command
    **/
    private class UserCommand {
        private final String command;
        private final String argument = "";

        /**
        Function UserCommand
        --------------------
        Constructs a UserCommand by parsing the commands from the given string array,
            saves the instructions in the objects and checks to see if the command is valid
        Returns: object
        **/
        public UserCommand(String[] userInputArray)
        {
            switch(userInputArray[0]) {
                case("user"):
                    this.command = "USER";
                    this.argument = userInputArray[1];
                    break;
                case("pw"):
                    this.command = "PASS";
                    this.argument = userInputArray[1];
                    break;
                case("quit"):
                    this.command = "QUIT";
                    break;
                case("get"):
                    this.command = "RETR";
                    this.argument = userInputArray[1];
                    break;
                case("features"):
                    this.command = "FEAT";
                    break;
                case("cd"):
                    this.command = "CWD";
                    this.argument = userInputArray[1];
                    break;
                case("dir"):
                    this.command = "RETR"
                    this.argument = userInputArray[1];
                    break;
                default:
                    throw new NonFatalException("0x001 Invalid Command");
            }
        }

        public String getCommand() {
            return command;
        }

        public String getArgument() {
            return argument;
        }
    }

    /**
    Function: deLint
    ----------------
    Converts comdString to String delinting it by removing spaces and tabs

    cmdString: byteArray

    Returns: a string containing only commands in lower case
    **/
    private String delint(byte[] cmdString)
    {
        String buffer = new StringBuffer();
        for (int i=0; i<cmdString.length;++i) {
            buffer.append((char) cmdString[i]);
        }
        String output = buffer.toString().toLowerCase();
        return output.replaceAll("", "\t").trim();
    }

    /**
    Function: getReply
    ------------------
    Gets the response from the connection and returns an array string of the return

    connection: type of command, can be passive or active :3

    Return: String[]
    **/
    public static String[] getReply(String connection)
    {
        BufferedReader replyReader;
        String error;

        if (connection == "passive") {
            replyReader = fromDataServer;
            error = "0x3A7 Data transfer connection I/O error, closing data connection";
        } else if (connection == "active") {
            replyReader = fromDataServer;
            error = "0xFFFD Control connecton I/O error, closing control connection";
        } else {
            System.out.println("0xFFF Processing error. Invalid type of connection");
            ragequit();
        }

        try {
            ArrayList<String> reply = new ArrayList<String>();
            String line = null;
            if (connection == "active") {
                while (!(line.matches("\\d\\d\\d\\s.*"))) {
                    line = reader.readLine();
                    response.add(line);
                }
            } else {
                line = ""
                while (line != null) {
                    line = reader.readLine();
                    response.add(line);
                }
            }

            String[] result = new String[response.size()];
            int i = 0;
            for (String singleLine : response) {
                result[i] = responseLine; ++i;
            }
            return result
        } catch (IOException e) {
            System.out.println(error);
            ragequit();
        }
    }

    /**
    Function: convertInputToArray
    -----------------------------
    Splits the user input into an array of strings, sparated by each space
        and removing the leading spaces. It checks if the input has too many arguments.

    command: command string

    Returns: String[]
    **/
    private String[] convertInputToArray(String command)
    {
        String[] segments = uesrInput.split(" +");
        ArrayList<String> userInputArray = new ArrayList<String>();
        for (String segment: segments) {
            userInputArray.add(segment.replaceAll("\\s+",""));
        }
        if (userInputArray.size() > 2)
            System.out.println("0x002 incorrect number of arguments");

        return userInputArray.toArray(new String[0]);
    }

    /**
    Function: ragequit()
    --------------------
    Closes everything

    Return void
    **/
    public static void ragequit()
    {
        try {
            if (fromDataServer != null)
                fromDataServer.close();
            if (fromServer != null)
                fromServer.close();
            if (toServer != null)
                toServer.close();
            if (socket != null)
                socket.close();
            if (dataSocket != null)
                dataSocket.close();
        } catch (IOException e) {
            System.err.println("0xFFF Processing error. Unable to close");
        }
    }

    /**
    Function: toServer
    ------------------
    Sends the instruction to the passive server

    connection: String can be active or passive
    command: String command

    Returns String[] with the reply
    Exceptions: IOException
    **/
    public static String[] toServer(String connection, String command) throws IOException
    {
        System.out.println("--> " + command);
        pushServer(command);
        String[] response = getReply(connection);
        System.out.println(Arrays.toString(response) + " <--");
        if (connection == "passive") {
            String[] dataResponse = getReply("passive");
            System.out.println(Arrays.toString(dataResponse));
            response = getReply("passive");
            System.out.println(Arrays.toString(response) + " <--");
        }
        return response;
    }

    /**
    Function pushServer
    -----------------
    Sends the command directly to the passive server

    String message
    Returns void
    Exceptions: IOException
    **/
    public static void pushServer(String command) throws IOException
    {
        try {
            socket.write(command + "\r\n");
            socket.flush();
        } catch (IOException e) {
            System.out.println("0xFFFD Control connection I/O error, closing control connection");
            ragequit();
            System.exit(1);
        }
    }
        
    



}
