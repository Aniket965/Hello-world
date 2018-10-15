from googleapiclient.discovery import build
from httplib2 import Http
from oauth2client import file, client, tools
import PyPDF2
import parser

# If modifying these scopes, delete the file token.json.
SCOPES = 'https://www.googleapis.com/auth/spreadsheets.readonly'

# The ID and range of a sample spreadsheet.
SPREADSHEET_ID = <SPREADSHEET_ID>
RANGE = <RANGE>

def main():
  # Auth setup
  store = file.Storage('token.json')
  creds = store.get()
  if not creds or creds.invalid:
    flow = client.flow_from_clientsecrets('credentials.json', SCOPES)
    creds = tools.run_flow(flow, store)
  service = build('sheets', 'v4', http=creds.authorize(Http()))

  inputFile = input("Please enter file name...")
  values = parser(inputFile)

  # Input body with info
  updatedSheet = {
    'values': [values[0], values[1][1:]],
    'majorDimension': 'COLUMNS'
  }
  date = {
    'values': [values[1][0]]
  }

  # Call the Sheets API
  result = service.spreadsheets().values().update(spreadsheetId=SPREADSHEET_ID,range=RANGE,body=updatedSheet,valueInputOption='RAW').execute()


if __name__ == '__main__':
    main()