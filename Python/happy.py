import falcon
import json

api = application = falcon.API()


class HappyDev(object):
    def on_get(self, req, resp):
        resp.status = falcon.HTTP_200
        resp.body = json.dumps({'Message': 'hey bro , HAPPY PROGRAMMER\'s DAY :)'})


api.add_route('/dev', HappyDev())
