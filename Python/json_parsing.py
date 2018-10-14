import json

data = '''
[
  { "id" : "1",
    "email" : "abc@gmail.com",
    "name" : "Tarun"
  } ,
  { "id" : "2",
    "email" : "xyz@gmail.com",
    "name" : "Shivam"
  }
]'''

info = json.loads(data)

for item in info:
    print('Id : ', item['id'], end=",  ")
    print('Name : ', item['name'], end=",  ")
    print('Email : ', item['email'])
