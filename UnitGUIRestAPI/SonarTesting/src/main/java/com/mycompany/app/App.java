import java.util.logging.Level; 
import java.util.logging.Logger; 

package com.mycompany.app;

/**
 * Hello world!
 */
public class App
{

    private final String message = "Hello World!";

    public App() {}

    public static void main(String[] args) {
    	Logger logger = Logger.getLogger(App.class.getName());
    	logger.log(Level.INFO, new App().getMessage());
    }

    private final String getMessage() {
        return message;
    }

}
