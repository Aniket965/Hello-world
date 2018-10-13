'''Contains Helpful Decorators
List of Decorators In This File:
    -cache
    -log
    -accepts
    -returns
    -silent
    -retry
'''

from functools import wraps
from threading import Timer

from .functions import hash_object


def cache(function):
    '''Cache Any Calls To Improve Efficency
    Args:
        function: the function to apply the decorator to
    Returns:
        Original Un-Modified Return Value Provided By 'function'
    Raises:
        TypeError: If the object cannot be hashed using .functions.hash_object
    '''
    data = {}

    @wraps(function)
    def inner(*args, **kwargs):
        hash_ = hash_object((args, kwargs))
        payload = data.get(hash_, None)
        if payload is None:
            payload = function(*args, **kwargs)
            data[hash_] = payload
        return payload
    return inner


#TODO: add log for exceptions
def log(logger=print, format=True):
    '''Log All Calls And Return Values Of The Function Provided
    Args:
        logger: A function that will be called with either: the formatted string of the call if 'format' is True
                or a dict containing the keys ('args', 'kwargs', 'result') if 'format' is False
        format: Determines whether the log function will recieve a formatted string or a tuple
    Returns:
        Original Un-modified Return Value Provided By 'function'
    Raises: None
    '''
    def decorator(function):
        @wraps(function)
        def inner(*args, **kwargs):
            result = function(*args, **kwargs)
            if format is True:
                name = function.__name__
                args_str = ', '.join((str(i) for i in args))
                kwargs_str = ', '.join(('{}={}'.format(str(i), str(kwargs[i])) for i in kwargs))
                string = '{}({}{}{}) -> {}'.format(name, args_str, ', ' if (args and kwargs) else '', kwargs_str, str(result))
                logger(string)
            else:
                logger({'args': args, 'kwargs': kwargs, 'result': result})
            return result
        return inner
    return decorator


def accepts(*args, order='restrict'):
    '''Limits The Type Of Args Allowed
    Args:
        *args: the types allowed
        order: can be one of 'restrict', 'restrict_strict' Or 'any'.
               'restrict' makes the args match exactly and is default. The args do not have to be in order. For example function(1, 2, 'three') would need to have @accept(str, int, int)
               'restrict_strict' means the args must match exactly as in 'restrict' but also must have the same order. For example function(1, 2, 'three') would need to have @accept(int, int, str)
               'any' means that the args provided are passed as long as the type is provided at least once.
    Returns:
        Original un-modified return value provided by 'function'
    Raises:
        TypeError: If arguments passed do not have an accepted type
    '''
    if order not in ('restrict', 'restrict_strict', 'any'):
        raise TypeError('Invalid \'order\' Argument: {}'.format(order))
    limit = args

    def decorator(function):
        @wraps(function)
        def inner(*args, **kwargs):
            if order == 'any':
                for i in (args + tuple(kwargs.values())):
                    if type(i) not in limit:
                        raise TypeError('Argument Type ({}) is Not An Accepted Type'.format(type(i).__name__))
            elif order == 'restrict':
                local_limit = list(limit)[:]
                for i in (args + tuple(kwargs.values())):
                    if type(i) not in local_limit:
                        raise TypeError('Argument Type ({}) is Not An Accepted Type. This may be due to previous arguments exhausting the accepted list'.format(type(i).__name__))
                    else:
                        local_limit.remove(type(i))
            elif order == 'restrict_strict':
                for i in zip((args + tuple(kwargs.values())), limit):
                    if type(i[0]) is not i[1]:
                        raise TypeError('Argument Type ({}) is Not An Accepted Type. This may be due to incorrect order of arguments'.format(type(i[0]).__name__))
            return function(*args, **kwargs)
        return inner
    return decorator


def returns(*args):
    '''Limits The Type of Return Values Allowed
    Args:
        *args: The types allowed. If the return value is any of these types, it will be accepted.
    Returns:
        Original un-modified return value provided by 'function'
    Raises:
        TypeError: When the return value is not valid
    '''
    if len(args) <= 0:
        raise TypeError('Must Have At Least One Constraint')
    limit = args

    def decorator(function):
        @wraps(function)
        def inner(*args, **kwargs):
            return_value = function(*args, **kwargs)
            if not type(return_value) in limit:
                raise TypeError('Function Returned A Non-Valid Return Value: {}'.format(type(return_value).__name__))
            else:
                return return_value
        return inner
    return decorator


#TODO: Add blacklist and whitelist
def silent(default_return=None, on_exception=None):
    '''Silences Any Exceptions And Sends Them To 'on_exception'
    Probably Shouldn't Be Used At All Except For Debugging And Such
    Args:
        default_return: If the function raises an Exception, this gets returned instead. Defaults to None
        on_exception: A function which is called and should handle exceptions passed to it
    Returns:
        Original un-modified return value provided by 'function' unless Exception occours.
        If Exception occours, 'default_return' is returned instead
    Raises:
        None. Thats The Point. It Raises... Nothing.
    '''
    def decorator(function):
        @wraps(function)
        def inner(*args, **kwargs):
            try:
                return_value = function(*args, **kwargs)
            except Exception as error:
                if on_exception is not None:
                    on_exception(error)
                return default_return
            else:
                return return_value
        return inner
    return decorator


def retry(times=5, blacklist=None, whitelist=None):
    '''Retries A Function x Times Untill It Doesn't Raise An Exception
    Args:
        times: The ammount of times to retry on Exception
        blacklist: A list of Exceptions that will not be ignored
        whitelist: If whitelist is defined, only Exceptions listed in whitelist will be ignored
        blacklist and whitelist cannot be defined simultaneously
    Returns:
        Original un-modified return value provided by 'function'
    Raises:
        None
    '''
    if whitelist and blacklist:
        raise TypeError('whitelist And blacklist Cannot Be Simultaneously Defined')
    if times <= 0:
        raise TypeError('times Cannot <= 0')

    def decorator(function):
        @wraps(function)
        def inner(*args, **kwargs):
            for _ in range(times - 1):
                try:
                    return_value = function(*args, **kwargs)
                except Exception as error:
                    if whitelist and (not type(error) in whitelist):
                        raise error
                    elif blacklist and (type(error) in blacklist):
                        raise error
                else:
                    return return_value
            else:
                return function(*args, **kwargs)
        return inner
return decorator
