package com.monotonic.generics._1_what_and_why_of_generics;

public class GenericExample
{
    public static void main(String[] args)
    {
        GenericCircularBuffer<String> buffer = new GenericCircularBuffer<String>(10);

        buffer.offer("a");
        buffer.offer("bc");
        buffer.offer("d");

        //buffer.offer(1);

        //System.out.println(buffer.poll());
        
        // Printing buffer
        String value = concatenate(buffer);
        System.out.println(value);
    }

    private static String concatenate(GenericCircularBuffer<String> buffer)
    {
        StringBuilder result = new StringBuilder();

        String value;
        while ((value = buffer.poll()) != null)
        {
            result.append(value);
        }

        return result.toString();
    }
}
