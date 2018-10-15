import ballerina/http;

@http:ServiceConfig {
  basePath: "/"
}

//Bind a New Service for port 9090
service<http:Service> hello bind {port:9090} {

//Only accept POST Requests 
  @http:ResourceConfig {
      path: "/",
      methods: ["POST"]
  }
  //New Resource named hi
  hi (endpoint caller, http:Request request) {

      http:Response res;
      res.setPayload("Hello Ballerina Wold!");

      _ = caller->respond(res);
  }
}