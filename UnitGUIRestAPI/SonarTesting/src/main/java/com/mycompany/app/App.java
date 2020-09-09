package com.mycompany.app;

import java.util.logging.Level; 
import java.util.logging.Logger; 

/**
 * Hello world!
 */
public class App
{

    private final String message = "Hello World!";

    public App() {}

    public static void main(String[] args) 
    {
    	String test = "test";
    	if(test.equals("Pass"))
    	{
    		test = "Pass";
    	}
    	else
    	{
    		test = "Fail";
    	}
    	
    	Logger logger = Logger.getLogger(App.class.getName());
    	logger.log(Level.INFO, new App().getMessage()+test);
    }

    private final String getMessage() {
        return message;
    }

}
