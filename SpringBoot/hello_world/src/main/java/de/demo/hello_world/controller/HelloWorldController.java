package de.demo.hello_world.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloWorldController {

    @GetMapping("")
    @ResponseBody
    public String index(){
        return "HELLO WORLD!";
    }

    @GetMapping("/{name}")
    @ResponseBody
    public String helloName(@PathVariable String name){
        return "HELLO " + name.toUpperCase() + "!";
    }

}
