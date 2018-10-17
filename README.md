For Bourne shell programming, we shall stick to #!/bin/sh.

The third line runs a command: 'echo', with two parameters, or arguments - the first is "Hello"; the 

second is "World".  Note that echo will automatically put a single space between its parameters.

now run chmod 755 first.sh to make the text file executable, and run ./first.sh. 

Note:  The value for this is 755 (readable by User, Group and World, writable by User, executable by User,         Group and World). It is set automatically when you create a folder.
       
       permission : -rwxr-xr-x


Your screen should then look like this:

            $ chmod 755 first.sh
            $ ./first.sh
            Hello World
            $