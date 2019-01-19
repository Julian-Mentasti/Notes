/**
Handles the User inpur by parsing so other classes may use them
**/
import java.lang.Throwable;
import java.lang.Enum;
import java.util.ArrayList;
public class InputHandler {

    public String hostName;
    public Integer portNumber;
    public String argument;

    public String command;
    private String userInput;

    public InputHandler(byte[] cmdString, String hostName, Integer portNumber) throws Exception, NonFatalException {
        this.hostName = hostName;
        this.portNumber = portNumber;
        this.userInput = delintArray(cmdString);
        this.argument = "";
        // Checks to see if the input is empty or if its commented out
        if (userInput.length() == 0 || userInput.charAt(0) == '#') {
            throw new Exception();
        }
        try {
            String[] userInputArray = convertInputToArray();
            obtainCommands(userInputArray);
            return;
        } catch (NonFatalException nfe) {
            throw nfe;
        }

        
    }

    /**
    Function: obtainCommands
    -----------------------
    Parses the command from the string array, saves the instruction in the object
        also checks to see if the command is valid

    userInputArray: String array where the commands will be read from
    returns: NULL
    
    exceptions: NonFatalException - 0x001 Invalid Command
    **/
    private void obtainCommands(String[] userInputArray) throws NonFatalException {

        switch (userInputArray[0]) {
            case ("user"):
                this.command = "USER";
                this.argument = userInputArray[1];
                break;
            case ("pw"):
                this.command = "PASS";
                this.argument = userInputArray[1];
                break;
            case ("quit"):
                this.command = "QUIT";
                break;
            case ("get"):
                this.command = "RETR";
                this.argument = userInputArray[1];
                break;
            case ("features"):
                this.command = "FEAT";
                break;
            case("cd"):
                this.command = "CWD";
                this.argument = userInputArray[1];
                break;
            case("dir"):
                this.command = "RETR";
                this.argument = userInputArray[1];
                break;
            default:
                throw new NonFatalException("Error: 0x001 Invalid Command, Recieved: [" +
                                            userInputArray[0] + "]");
        }
    }
                
                


    /**
    Function: delintArray
    ---------------------
    Converts cmdString to String, delinting it by removing spaces and tabs

    cmdString: byteArray to be delinted

    returns: a string containing only commands in lower case
    **/
    private String delintArray(byte[] cmdString) {
        StringBuffer buffer = new StringBuffer();
        for (int i=0;i<cmdString.length;++i) {

            //Should I test for nl?
            buffer.append((char) cmdString[i]);
        }
        // Set buffer to String all in lower case
        String output = buffer.toString().toLowerCase();
        // remove random spaces and tab characters in the front or back
        return output.replaceAll("","\t").trim();
    }

    /**
    Function: convertInputToArray
    -----------------------------
    Splits the userInput into an array of strings, separated by each space
        and removing the leading space. It checks if the input has too many arguments.

    returns: String array of each word in the userInput

    Exception: throws NonFatalException - too many arguments
    **/
    private String[] convertInputToArray() throws NonFatalException {

        String[] segments = userInput.split(" +");
        ArrayList<String> userInputArray = new ArrayList<String>();
        for (String segment: segments) {
            userInputArray.add(segment.replaceAll("\\s+",""));
        }

        if (userInputArray.size() > 2) {
            NonFatalException nfe = new NonFatalException(
                "Too many arguments, expected at most 2 recieved: " +
                Integer.toString(userInputArray.size()));
            throw nfe;
        }
        return userInputArray.toArray(new String[0]);
    }

    /**
    Function: getCommand
    --------------------
    returns the command, if an argument is needed for the command it is appended

    return: String command
    **/
    public String getCommand() {
        if(argument == "")
            return command;
        else
            return command + " " + argument;
    }

        
}
        


