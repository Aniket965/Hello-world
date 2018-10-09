package com.digitalocean.hacktoberfest;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class HelloWorld {
	public static void main(String[] args) throws Exception {

		// Input stream + lexing
		ANTLRInputStream antlrInputStream = new ANTLRInputStream("hello hacktoberfest");
		HelloWorldLexer helloWorldLexer = new HelloWorldLexer(antlrInputStream);
		CommonTokenStream tokens = new CommonTokenStream(helloWorldLexer);

		// Parsing
		HelloWorldParser helloWorldParser = new HelloWorldParser(tokens);
		ParseTree tree = helloWorldParser.helloWorld();
		
		ParseTreeWalker walker = new ParseTreeWalker();
		walker.walk(new HelloWalker(), tree);
	}
}