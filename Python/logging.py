import datetime

# Log parm(File_name)
class logging_class:
    def __init__(self, log_file_name, verbose):
        self.log_file_name = log_file_name
        self.stream = open(log_file_name, "a")
        self.verbose = verbose

    # Write a line in the log file
    def create_log(self, to_add):
        if (to_add != "\n"):
            self.stream.write(str(datetime.datetime.now().replace(microsecond=0)))
            if (self.verbose is True):
                print (str(datetime.datetime.now().replace(microsecond=0)), end = " ")
        if (self.verbose is True):
            print("  ", end = " ")
            print(to_add)
        self.stream.write("  ")
        self.stream.write(to_add)
        self.stream.write("\n")

    #add log lines, change behevior if tab or str
    def add_logging(self, to_add):
        if (type(to_add) == str):
            self.create_log(to_add)
        else:
            for ii in to_add:
                self.create_log(ii)

