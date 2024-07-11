def NULL_not_found(object: any) -> int:
    type = object.__class__
    if (object is None):
        print("Nothing", end="")
    elif (object != object):
        print("Cheese", end="")
    elif (object is False):
        print("Fake", end="")
    elif (object == 0):
        print("Zero", end="")
    elif (object == ''):
        print("Empty", end="")
    else:
        print("Type not Found")
        return 1
    print(f": {object} {type}")
    return 0
