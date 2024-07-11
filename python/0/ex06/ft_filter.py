def ft_filter(check, list):
    """
    Recoding of the built-in function filter

    Args :
        Check : function that returns a boolean
        List :  List to filter

    Return :
        Sub-list of list with the elements that pass the check function
    """
    return [i for i in list if check(i)]
