import os
import hashlib
import time
from sys import exit
dirName=os.path.dirname(os.path.realpath(__file__))
yesAnswers=['yes','Yes','YES','Y','y','']
noAnswers=['No','no','n','N','NO']
ENILfilePath=''

def getListOfFiles(dirName):
    # create a list of file and sub directories 
    # names in the given directory 
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory 
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
    #remove hashchecker.enil from allFiles as the hash for that will never match cached hash
    for entry in allFiles:
        if entry[-5:] == ".enil":
            proxy=allFiles.index(entry)
            ENILfilePath=allFiles.pop(proxy) 
                     
    return allFiles
    
def encrypterString(unencryptedString):
    #takes any string and converts it into an encrypted string based on cipherSource
    CSVstring=''
    cipherSource="abCDlm:nfcde)istuxyzv-UVWjkBghGYoEFpq+rw*1(2H89\\0.~53K LIMQ_T467RSNOP=/AZ;"
    length=len(unencryptedString)
    proxy=""
    for char in range(0,length):
        indexNum=cipherSource.index(str(unencryptedString[char]))+1
        proxy=proxy+cipherSource[indexNum]
    CSVstring=proxy+","
    correctedCSVstring=CSVstring[0:-1]
    return correctedCSVstring    
allFiles=getListOfFiles(dirName)
def encrypterList(unencryptedList):
    #Takes a list of strings and returns a comma separated string of encrypted strings from the list
    outputCSVstring=''
    for file_name in unencryptedList:
        proxy=encrypterString(file_name)
        outputCSVstring=outputCSVstring+','+proxy
    correctedOutputCSVstring=outputCSVstring[1:]
    return(correctedOutputCSVstring)

def decrypterString(CSVstring):
    #same as encrypter string but decrypts
    outputString=''
    cipherSource="abCDlm:nfcde)istuxyzv-UVWjkBghGYoEFpq+rw*1(2H89\\0.~53K LIMQ_T467RSNOP=/AZ;"
    length=len(CSVstring)
    proxy=""
    for char in range(0,length):
        if CSVstring[char]==",":
            proxy=proxy+","
        else:
            indexNum=cipherSource.index(str(CSVstring[char]))-1
            proxy=proxy+cipherSource[indexNum]
    outputString=proxy+","
    return outputString

def decrypterList(encryptedList):
    #same as encrypterList but decrypts
    outputString=''
    for encrypted_item in encryptedList:
        proxy=decrypterString(encrypted_item)
        outputString=outputString+','+proxy
    correctedOutputCSVstring=outputString[1:]
    return(correctedOutputCSVstring)


def storeCreator(hashesDict, masterHash):
    #creating the text for the enil file
    tempFiles=list(hashesDict.keys())
    
    tempHashes=list(hashesDict.values()) 
    #preparing the CSV string of files in a ciphered way
    files=""
    files=encrypterList(tempFiles)
    files=files+"\n"
    #preparing CSV string of hashes in a ciphered way
    hashes=""
    hashes=encrypterList(tempHashes)
    hashes=hashes+"\n"
    #preparing masterHash in a ciphered way
    masterHash=encrypterString(masterHash)
    
    return(files,hashes,masterHash)




def dictcreator(allFiles):
    #creates a dictionary of filePath:hash of file and a hash of the string made of the sum of all hashes(called the masterHash)
    hashesDict={}
    masterHash=""
    sha256_hash = hashlib.sha256()
    for filename in allFiles:
        with open(filename,"rb") as f:
             # Read and update hash string value in blocks of 4K
            for byte_block in iter(lambda: f.read(4096),b""):
                sha256_hash.update(byte_block)
                g=sha256_hash.hexdigest()
            hashesDict[filename]=g
            masterHash=masterHash+g   
            hash_object=hashlib.sha256(masterHash.encode())
            masterHash=hash_object.hexdigest()
            
    return(hashesDict,masterHash)
    #returns (files,hashes,masterHash) all of which are strings


def noENILfile():
    #should run when there is no ENIL file.
    #creates an ENIL file with the foll encyrpted entries:1)all file paths,2)all hashes of files,3)masterhash
    allFiles=getListOfFiles(dirName)
    hashesDict,masterHash=dictcreator(allFiles)
    files,hashes,masterHash=storeCreator(hashesDict,masterHash)
    
    with open("hashstore.enil","w") as f:
        f.write(files)
        f.write(hashes)
        f.write(masterHash)
        f.close()
    print("Hash checker 'ENIL' file did not exist previously so one has been created")
    time.sleep(2)
    exit()

def ENILfileFound():
    #should run when an ENIL file is found
    #reads the enil file and decrypts and returns files,hashes and masterHash
    with open('hashstore.enil','r') as f:
        sums=f.readlines()
        sums =[x.strip() for x in sums]
        f.close()
        files=sums[0]
        hashes=sums[1]
        masterHash=sums[2]
        files=str(decrypterString(files))[0:-1]
        files=files.split(',')
        hashes=str(decrypterString(hashes))[0:-1]
        hashes=hashes.split(',')
        masterHashFromENIL=decrypterString(masterHash)
        hashesDictFromENIL={}
        if len(files)==len(hashes):    
            for n in range(len(files)):
                hashesDictFromENIL[files[n]]=hashes[n]
        
                
        return(hashesDictFromENIL,masterHashFromENIL)

def ENILfileUpdate():
    #should run only after checking with the user
    #over writes previous ENIL file with updates values
    aF=getListOfFiles(dirName)
    has,mas=dictcreator(aF)
    fil,hashes,maste=storeCreator(has,mas)
    with open("hashstore.enil","w") as f:
        f.write(fil)
        f.write(hashes)
        f.write(maste)
        f.close()
    print("Hash checker 'ENIL' file has been updated")


  
def checkForDeletions(CurrentFiles,CacheFiles):
    #chceks the 2 files list to see if any file from old list was deleted ie not there in current list
    deletedFiles=[]
    for file in CacheFiles:
        if file in CurrentFiles:
            nono=0
        else:
            deletedFiles.append(file)
    return(deletedFiles)

def checkForAdditions(CurrentFiles,CacheFiles):
    #checks to see if any file was added ie file was not there in old list but is there in new list
    addedFiles=[]
    for file in CurrentFiles:
        if file in CacheFiles:
            continue
        else:
            addedFiles.append(file)
    return(addedFiles)

def deleteFiles(addedFiles):
    #allows user to manually delete files he/she hasnt added or modified directly through command line
    filePath=input('Copy the path of the file you want to delete from the list above and paste it here(one at a time):')
    if filePath in addedFiles:
        os.remove(filePath)
    else:
        print(filePath+' isnt a file path that was recently added. ',end="")
        time.sleep(4)
        retryResponse=input('Would you like to try again?(y/n)')
        if retryResponse in yesAnswers:
            deleteFiles(addedFiles)
    anotherOne=input('Would you like to add another file?(y/n)')
    if anotherOne in yesAnswers:
        deleteFiles(addedFiles)
        return
def UserCheckAdded(addedFiles):
    #allows user to go through each addedFile to see if theres a file that they didnt add
    confirmation=input('Were some of the added files not added by you? Would you like to remove one or more of the added files?(y/n)\n')
    if confirmation in yesAnswers:
        print('The following is a list of all files that have been added since last run time:')
        time.sleep(2)
        for file in addedFiles:
            print(file)
            time.sleep(1.5)
        print("If any of these files was not added by you and you suspect the file of being malicious you should delete the file immediately.")
        time.sleep(2.5)
        maliciousFileChecker=input('Would you like to delete files not added by you?(y/n)')
        if maliciousFileChecker in yesAnswers:
            deleteFiles(addedFiles)
        else: return(0)

def antiModChecker(hashesDictFromENIL,masterHashFromENIL):
    allFiles=getListOfFiles(dirName)
    hashesDict,masterHash=dictcreator(allFiles)
    masterHashFromENIL=masterHashFromENIL[:-1]
    #check that masterHash is same
    if masterHash==masterHashFromENIL:
        print('Files have not been modified.')
        time.sleep(1)
        print('Integrity of all files is maintained. Virus checker will now close')
        time.sleep(4)
        #exits program
        exit()        
    else:
        CurrentFiles=list(hashesDict.keys())
        CacheFiles=list(hashesDictFromENIL.keys())
        #check for file additions and deletions
        addedFiles=checkForAdditions(CurrentFiles,CacheFiles)
        deletedFiles=checkForDeletions(CurrentFiles,CacheFiles)
        if len(addedFiles)==0 and len(deletedFiles)==0:
            print("No files have been added or deleted")
            time.sleep(3)
        else:
            if len(deletedFiles)!=0:
                print("The following files have been deleted:")
                time.sleep(2)
                for file in deletedFiles:
                    print(file)
                    time.sleep(0.5)
                garbage=input('press enter to continue')            
            if len(addedFiles)!=0:
                print("\nThe following files have been added:")
                time.sleep(2)
                for file in addedFiles:
                    print(file)
                    time.sleep(0.5)
                garbage=input('press enter to continue')
            
            #Make sure that the added files were added by the user:
            UserCheckAdded(addedFiles)
        #check the hashes
        #only need to check hash of files that are currently in folders
        verified=[]
        modifie=[]

        print('\nVerifying file integrity of old files',end='')
        time.sleep(1.5)
        print('.',end='')
        time.sleep(1.5)
        print('.',end='')
        time.sleep(1.5)
        print('.')
        time.sleep(2)
        
        for file in CurrentFiles:
            if file in addedFiles:
                print(file)
            else:
                if hashesDict[file]==hashesDictFromENIL[file]:
                    verified.append(file)
                    continue
                else:
                    modifie.append(file)
        
        print('\nFollowing files have not been modified and their integrity is guranteed:')
        time.sleep(1)
        for file in verified:
            print(file)
        garbage=input('press enter to continue')
        print('\nFollowing files have been modified so they may have been infected with a virus:')
        time.sleep(1)
        for file in modifie:
            print(file)
        garbage=input('press enter to continue')
        print('Note: Only update the cache if you are confident that integrity of all files are intact.')
        time.sleep(4)
        updateConfirmation=input('Would you like to update the cache of file integrity keys?(y/n)')            
        if updateConfirmation in yesAnswers:
            print('Virus check will close soon after updating',end='')
            time.sleep(0.5)
            print('.',end='')
            time.sleep(0.5)
            print('.',end='')
            time.sleep(0.5)
            print('.',end='')
            time.sleep(2.5)
            ENILfileUpdate()
            time.sleep(4)
            exit()
        else:
            print('not updating the cache file means the integrity of recently added or modified files cannot not be verified the next time you run this file.')
            time.sleep(2)
            reconfirmation=input('Are you sure you dont want to update files?')
            if reconfirmation in yesAnswers:
                print('Virus checker will now close' )
                time.sleep(2)
                exit()

###Logics Start here
ENILtester=os.listdir(dirName)
ENILpresent=False
for entry in ENILtester:
    if entry[-5:] == ".enil":
        ENILpresent=True
if ENILpresent:
    hashesDictFromENIL,masterHashFromENIL= ENILfileFound()
    antiModChecker(hashesDictFromENIL,masterHashFromENIL)
else:
    noENILfile()
