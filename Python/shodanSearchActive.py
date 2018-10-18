#uses shodan's default search query then scans all hosts found

# Author: Scotizo

import shodan
import sys

# Configuration
API_KEY = ""

# Input validation
#if len(sys.argv) == 1:
#        print('Usage: %s <search query>' % sys.argv[0])
#        sys.exit(1)

try:
        # Setup the api
        api = shodan.Shodan(API_KEY)

        # Perform the search
        query = ' '.join(sys.argv[1:])
        result = api.search(query)
        count = int(6)
        # Loop through the matches and print each IP
        for service in result['matches']:
                
                
                host = api.host(service['ip_str'])

                #result['matches']:
                print("""
                IP: {}
                Organization: {}
                Operating System: {}
                Ports: {}
                Vuln: {}
                """.format(host['ip_str'], host.get('org', 'n/a'), host.get('os', 'n/a'),host.get('ports','n/a'),host.get('vulns','n/a') ))
                for item in host['data']:
                        print("""
                        Port: {}
                        Banner: {}

                        """.format(item['port'], item['data']))
                wait = input('------------------------------\nHIT ENTER TO CONTINUE\n------------------------------')    
            
except Exception as e:
        print('Error: %s' % e)
        sys.exit(1)

