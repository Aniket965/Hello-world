/* Creating a Simple HTTP Server

 */

import java.net.InetSocketAddress;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import com.sun.net.httpserver.HttpServer;

public class SimpleHTTPServer {

    public static void main(String[] args) throws Exception {
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

        int port = 8000;
        HttpServer server = HttpServer.create(new InetSocketAddress(port), 0);
        server.createContext("/ping", new PingHandler());
        server.createContext("/Get", new GetHandler());
        server.setExecutor(null); // creates a default executor
        server.start();

        System.out.println(dateTimeFormatter.format(LocalDateTime.now()) + ": Server Started at port : " + port );
    }
}

/*
test with
http://localhost:8000/ping

we can't open a port below 1024, without root privileges
the port should be  higher than 1024, if  running the code under a non-root user.
*/

