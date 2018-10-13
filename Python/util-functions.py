import copy


def hash_object(obj):
    '''Attempts To Hash A Given Object
    Source: http://stackoverflow.com/questions/5884066/hashing-a-python-dictionary
    Args:
        obj: The object to hash
    Returns:
        The hash of 'obj'
    Raises:
        TypeError: If 'obj' cannot be hashed
    '''
    if hasattr(obj, '__dict__'):
        return hash_object(obj.__dict__)
    elif isinstance(obj, (set, tuple, list)):
        return hash(tuple([hash_object(e) for e in obj]))
    elif isinstance(obj, dict):
        new_o = copy.deepcopy(obj)
        for k, v in new_o.items():
            new_o[k] = hash_object(v)
        return hash(tuple(frozenset(sorted(new_o.items()))))
    else:
        try:
            return_value = hash(obj)
        except TypeError:
            raise TypeError('Unable To Hash Object ()'.format(obj))
        else:
            return return_value


def flatten(obj, types=[tuple, list, set]):
    '''Flattens A List Type Object With Unknown Depth
    Source: https://www.reddit.com/r/Python/comments/6axvw1/how_to_unpack_a_nested_list_of_unknown_depth/
    Args:
        obj: The list to flatten
    Returns:
        A flattened list. e.g. [1, 2, [3,4], 5, [6, [7, 8, [9, [10]]]]] becomes [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    Raises: None
    '''
    flat_list = []
    for i in list(obj):
        if type(i) in types:
            print('flatten')
            flat_list.extend(flatten(i, types=types))
        else:
            flat_list.append(i)
    return list(flat_list)


def read(file, binary=False):
    '''Convenience Function To Quickly Return The Contents of A File
    Args:
        file: str containing a path to a file
        binary: if True, file will read in binary mode
    Returns:
        Contents Of 'file'
    Raises: None
    '''
    with open(file, 'rb' if binary else 'r') as file:
        data = file.read()
    return data


def write(file, text, binary=False):
    '''Convenience Function To Quickly Write To A File
    Args:
        file: str containing a path to a file
        text: The data to write to the file
        binary: if True, file will be written to in binary mode
    Returns: None
    Raises: None
    '''
    with open(file, 'wb' if binary else 'w') as file:
        file.write(text)


def convert(data, type_, default=None):
    '''Attempt To Convert 'data' To 'type_'
    Args:
        data: The data to convert to type_
        type_: A function which must take one argument and attemptto return a converted object.
               The function should raise a ValueError if it cannot convert the data
        default: If 'data' cannot be converted, 'default' is returned
    Returns:
        'type_(data)' Or 'default'
    Raises: None
    '''
    try:
        return type_(data)
    except ValueError:
return default
