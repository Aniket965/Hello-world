import xml.etree.ElementTree as ET

xml_data = '''
<data>
    <users>
        <user>
            <id>1</id>
            <name>Tarun</name>
        </user>
        <user>
            <id>2</id>
            <name>Shivam</name>
        </user>
    </users>
</data>'''

stuff = ET.fromstring(xml_data)
lst = stuff.findall('users/user')

for item in lst:
    print('Id: ', item.find('id').text)
    print('Name: ', item.find('name').text)
    
