import sys
from ft_filter import ft_filter


def main():
    args = sys.argv[1:]
    try:
        if (len(args) != 2):
            raise AssertionError("wrong number of arguments")
        if (args[1].isnumeric() is False):
            raise AssertionError("second argument needs to be a number")
    except AssertionError as e:
        print(f"{AssertionError.__name__} : {e}")
    else:
        length_check = lambda x: len(x) > int(args[1])
        print(length_check("World"))
        print(ft_filter(length_check, args[0].split()))


if __name__ == "__main__":
    main()
