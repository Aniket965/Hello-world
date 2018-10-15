import sqlite3
import urllib.request
import ssl

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

conn = sqlite3.connect('emaildb.sqlite')
cur = conn.cursor()

# delete any table named Counts beforehand from the database
conn.execute('''DROP TABLE IF EXISTS Counts''')

# creating new table
cur.execute('''CREATE TABLE Counts (org TEXT, count INTEGER)''')
# getting the file from web
url = 'https://raw.githubusercontent.com/csev/py4e/master/code/mbox.txt'
fhand = urllib.request.urlopen(url, context=ctx)
# reading each line from the file using handle and also decoding it
for line in fhand:
    if not line.decode().startswith('From: '):
        continue
    pieces = line.decode().split()
    email = pieces[1]
    (emailname, domain) = email.split("@")
    # domain = email[email.index('@')+1:]
    cur.execute('SELECT count FROM Counts WHERE org= ? ', (domain,))
    row = cur.fetchone()
    if row is None:
        cur.execute('''INSERT INTO Counts (org, count)
                VALUES ( ?, 1 )''', (domain, ))
    else:
        cur.execute('UPDATE Counts SET count=count+1 WHERE org = ?',
                    (domain, ))
conn.commit()

sqlstr = 'SELECT org, count FROM Counts ORDER BY count DESC LIMIT 10'
print
print("Counts:")
for row in cur.execute(sqlstr):
    print(str(row[0]), row[1])

# Closing the DB
cur.close()
