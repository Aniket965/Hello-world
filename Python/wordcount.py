def stringCount(name:str,string:str)->int:
    infile = open(name,'r')
    content = infile.read()
    infile.close()
    count = 0
    content = content.split()
    for i in content:
        if string in i:
            count += 1
    return count
