import hashlib

def hash_file(filename):
   """"This function returns the SHA-1 hash
   of the file passed into it"""

   
   h = hashlib.sha1()


   with open(filename,'rb') as file:

       
       chunk = 0
       while chunk != b'':
         
           chunk = file.read(1024)
           h.update(chunk)

   
   return h.hexdigest()

message = hash_file("track1.mp3")
print(message)
