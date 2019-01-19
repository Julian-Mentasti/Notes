import java.io.IOException;

public class NonFatalException extends IOException {

    public NonFatalException(String str) {
        super(str);
    }
}
