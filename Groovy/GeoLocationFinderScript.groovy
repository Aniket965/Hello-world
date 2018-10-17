/*
* This script will read ip address or website from console as user input and will show the Geo location of ip address
* For terminate the script please enter `EXIT`.
* */
final String api = "http://ip-api.com/json/"
final String exist = "EXIT"

println("Find Geo location based on Ip address or Website name.\n")

while (true) {
    println "Enter your ip address or website name. For exist app, please enter EXIT"
    String address  = System.in.newReader().readLine()
    if (!exist.equalsIgnoreCase(address)) {
        try {
            def connection = new URL("${api}${address}")
                    .openConnection() as HttpURLConnection

            println("Response:")
            println(connection.inputStream.text)
            println("\n")
        } catch (Exception e) {
            println("Error : ${e.message},  Please try again.")
        }

    } else {
        break
    }
}
