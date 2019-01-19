import java.io.BufferedReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;

public class ConnectionHandler {

    private ArrayList<String> replyString;
    private String command;
    private String argument;

    
    Socket echoSocket;
    BufferedReader in;
    PrintWriter out;
    
    public ConnectionHandler(InputHandler inputHandler) throws FatalException, NonFatalException {
        replyString = new ArrayList<String>();
        try {
            echoSocket = createSocket(inputHandler.hostName, inputHandler.portNumber,20000,false);
            out = new PrintWriter(echoSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            getReply();
            printReply();
            pushToServer("TYPE I");
            printReply();
        } catch (IOException e) {
            throw new FatalException("0xFFFC Control connection to " +
                                     inputHandler.hostName + " on port " +
                                     inputHandler.portNumber +
                                     " failed to open." );

        }
        echoSocket.close();
    }
    /**
    Function: createSocket
    ----------------------
    Opens a new socket with the given IP, Port, timeout and if its passive FTP

    hostName: String address of socket to be connected to
    port: int port number
    timeout: int timeout in ms
    pasv: boolean flag

    Return: Socket

    Exceptions: NonFatalException - 0x3A2 Data transfer connection
    **/
    private socket createSocket(String hostName, int port, int timeout, boolean pasv) throws NonFatalException, IOException {
        Socket socket = new Socket():
        try {
            socket.connect(new InetSocketAddress(ip, port), timeout);
        } catch (IOException e) {
            if (pasv) {
                throw new NonFatalException("0x3A2 Data Transfer connection to " +
                                            hostname + " on port " + port +
                                            " failed to open.");
            } else {
                throw e // EEEEEEEEEEEEEEEEEEEEEEEEEEEEE
            }
        }
        return socket;
    }

    /**
    Function: getReply
    --------------------
    Gets the server reply after a command is sent. can handle multi line replies

    Return: void

    Exceptions: NonFatalException - 0xFFFD Control Connection I/0 Error
    **/
    private void getReply throws NonFatalException () {
        String readBuffer;
        String[] readBufferArray;
        try {
            while(!(readBuffer.readLine()).matches("\\d\\d\\d\\s.*") {
                 readBufferArray.add(readBuffer);
            }
            replyString = readBufferArray;
        } catch (IOException e) {
            in.close();
            out.close();
            echoSocket.close();
            throw new NonFatalException("0xFFFD Control connection I/O error, closing control connection");
        }
    }

    /**
    Function: printReply
    --------------------
    prints whatever is in readBufferArray and clears and variable

    Return: void
    **/
    private void printReply() {
        for (String reply : replyString) {
            System.out.println(" <--" + reply);
        }
        replyString.clear();
    }

    /**
    Function pushToServer
    ---------------------
    Pushes a command to the server, and prints the response

    command: String to send to the server

    return: void
    **/
    public void pushToServer(String command) {
        System.outprintln("--> " + command);
        out.println(command + "\r\n");
        out.flush();
    }

    /**
    Function pushToServer
    --------------------
    Pushes a command to the server, and prints the response,
    if its active ftp it will start a new socket

    command: Command to be execured

    Exceptions: IOException if there was an issue with the server
                FatalException: 0xFFFF Processing error
    **/
    public void pushToServer(Command command) throws IOException, FatalException {
        String reply;
        pushToServer(command.getCommand());
        getReply();
        printReply();
        if (command.argument == "") {
            DataConnection dataConnection = new DataConnection(response, command);
            dataConnection.
