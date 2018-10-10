from hashlib import sha3_512
import getpass
from pymongo import MongoClient

def generate_hash(password):
    sha = sha3_512()
    sha.update(bytes(password, "utf-8"))
    return sha.hexdigest()

def insert_to_mongo(username, email, hashed_password):
    username = username.strip()
    email = email.strip().lower()
    
    client = MongoClient("127.0.0.1", 27017)
    db = client.authentication
    user = db.user

    if user.find_one({ "$strcasecmp": {"username": username.lower()}}) != None:
        print("Username bereits vergeben!")
        client.close()
        return

    if user.find_one({"email": email}) != None:
        print("Email bereits vergeben!")
        client.close()
        return
    
    user.insert_one({"username": username, "email": email,"password": hashed_password})
    print("Added User:", username)
    client.close()
    print("Finish")
    
def main():
    username = input("Username: ")
    email = input("Email: ")
    password = getpass.getpass("Password: ")
    
    hashed_password = generate_hash(password)
    print("SHA3 512: ")
    print(hashed_password)
    print()
    
    insert_to_mongo(username, email, hashed_password)
        
    
if __name__ == "__main__":
    main()
