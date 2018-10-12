# Tomcat memory settings
# -Xms<size> set initial Java heap size
# -Xmx<size> set maximum Java heap size
# -Xss<size> set java thread stack size
# -XX:MaxPermSize sets the java PermGen size

# Default memory settings if not specified in $LUCEE_JAVA_OPTS
: ${LUCEE_JAVA_OPTS:="-Xms256m -Xmx512m"}

# Use /dev/urandom for EGD (http://wiki.apache.org/tomcat/HowTo/FasterStartUp)
JAVA_OPTS="${LUCEE_JAVA_OPTS} -Djava.security.egd=file:/dev/./urandom";

# additional JVM arguments can be added to the above line as needed, such as
# custom Garbage Collection arguments.

export JAVA_OPTS;

# Add location of Apache Tomcat native library to the library path
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/lib/x86_64-linux-gnu";
export LD_LIBRARY_PATH;
