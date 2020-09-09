package com.mycompany.app;

/**
 * Hello world!
 */
public class App
{

    private final String message = "Hello World!";

    public App() {}

    public static void main(String[] args) {
    	String test = "Pass";
    	
    	
    	if(test.equals("Pass"))
    	{
    		/*test = "Pass";*/
    		System.out.println("Fail");
    	}
    	else    	
    	{
    		test = "Fail";
    	}
    	
        System.out.println(new App().getMessage()+test);
    }

    private final String getMessage() {
        return message;
    }

}
