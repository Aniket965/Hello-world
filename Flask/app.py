from flask import Flask, Response, render_template, url_for
from flask_restful import Resource, Api

app = Flask(__name__)
api = Api(app)

class Index(Resource):

    def get(self):

        return Response(render_template('index.html'), mimetype='text/html')


api.add_resource(Index, '/')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)