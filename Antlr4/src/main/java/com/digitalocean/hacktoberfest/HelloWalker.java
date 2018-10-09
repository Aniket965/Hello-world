package com.digitalocean.hacktoberfest;

public class HelloWalker extends HelloWorldBaseListener {
    public void enterHelloWorld(HelloWorldParser.HelloWorldContext ctx) {
        System.out.println("Who says hello? " + ctx.NAME().getText() + " does.");
    }
}