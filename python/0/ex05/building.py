import sys


def building(s):
    """
    Counts the character occurences in a strings

    args :
        s : string to process
    """
    if (len(s) == 0):
        s = input("What is the text to count ?\n")
        while (s == ''):
            s = input("What is the text to count ?\n")
    else:
        s = s[0]
    print(f"The text contains {len(s)} characters:")
    print(f"{sum(1 for c in s if c.isupper())} upper letters")
    print(f"{sum(1 for c in s if c.islower())} lower letters")
    pcount = sum(1 for c in s if c in [',', '?', ';', '.', ':', '/', '!', '-'])
    print(f"{pcount} punctuation marks")
    print(f"{sum(1 for c in s if c.isspace())} spaces")
    print(f"{sum(1 for c in s if c.isdigit())} digits")


def main():
    args = sys.argv[1:]
    try:
        if (len(args) > 1):
            raise AssertionError("wrong number of arguments")
    except AssertionError as e:
        print(f"{AssertionError.__name__} : {e}")
    else:
        building(args)


if __name__ == "__main__":
    main()
