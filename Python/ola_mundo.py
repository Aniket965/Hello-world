class OlaMundo():
    def __init__(self):
        self.message = "open source"

    def print_message(self):
        print("Olá mundão %s" % self.message)

if __name__ == "__main__":
    olaMundo = OlaMundo()
    olaMundo.print_message()