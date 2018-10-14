## requires flask
## install by:
## pip install flask

from flask import Flask
from flask import request

app = Flask(__name__)

@app.route("/")
def get_agent():
    agent = request.user_agent.platform
    return f'hello {agent} user, ' \
           f'... a Flask WebServer, ' \
           f'made for Hacktoberfest'

if __name__ == "__main__":
    app.run(host='0.0.0.0', port='8080')
