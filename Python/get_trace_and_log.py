# Haktoberfest @ 10/13/2018 :D!
import traceback, sys

def get_trace_and_log(error):
    """(str: error) -> str

    Returns a distinct traceback with the offending line and logs the error with the time and date."""
    logf = open("errors.log", "a")
    trace = traceback.extract_tb(sys.exc_info()[-1], limit=1)[-1][1]
    logging.error(error)
    print(f'Offending line: {trace}')
    logf.write(f'Error: {str(error)}\n'
               f'Asc time: {time.asctime()}\n')
