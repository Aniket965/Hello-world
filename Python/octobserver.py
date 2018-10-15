class Subscriber:
    def __init__(self, name):
        self.name = name
    def update(self, event, message):
        print('#{}: {} got message "{}"'.format(event, self.name, message))


class Publisher:

    def __init__(self, events):
        self.subscribers = { event : dict() for event in events }

    def get_subscribers(self, event):
        return self.subscribers[event]

    def register(self, event, who, callback=None):
        if callback is None:
            callback = getattr(who, 'update')
        self.get_subscribers(event)[who] = callback

    def unregister(self, event, who):
        del self.get_subscribers(event)[who]

    def dispatch(self, event, message):
        for subscriber, callback in self.get_subscribers(event).items():
            callback(event, message)



digitalocean = Publisher(['hacktoberfest2018', 'hacktoberfest2019'])

daniel = Subscriber('Daniel Stoinov')
# Add yourself here as subscriber

digitalocean.register("hacktoberfest2018", daniel)
digitalocean.register("hacktoberfest2019", daniel)
# Register yourself here for the event


digitalocean.dispatch("hacktoberfest2018", "It is open. Go for it!")
digitalocean.dispatch("hacktoberfest2019", "Hold your horses. Next year!")



