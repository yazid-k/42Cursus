def all_thing_is_obj(object: any) -> int:
    type = object.__class__
    type_list = [list, tuple, set, dict]
    if (type in type_list):
        print(f"{type.__name__.capitalize()} : {type}")
    elif (type == str):
        print(f"{object} is in the kitchen : {type}")
    else:
        print("Type not found")

    return (42)
