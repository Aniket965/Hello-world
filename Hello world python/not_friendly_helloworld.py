import base64
import subprocess
 
subprocess.Popen("base64 --decode".split() ,stdin=subprocess.Popen("echo SGVsbG8gV29ybGQ=".split(), stdout=subprocess.PIPE).stdout).communicate()[0]
