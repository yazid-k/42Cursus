def ft_tqdm(lst: range) -> None:
    """
    Prints a progress bar while iterating over a given range.

    Args:
        lst (range): The range to iterate over.

    Yields:
        The elements of the given range.

    """
    total = len(lst)
    for i, elem in enumerate(lst):
        percentage = (i + 1) / total * 100
        bar_length = 50
        filled_length = int(bar_length * percentage // 100)
        bar = '█' * filled_length + ' ' * (bar_length - filled_length)
        print(f"\r {percentage:.0f}%|{bar}| {i + 1}/{total}", end="\r")
        yield elem
    print()
