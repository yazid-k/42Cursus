def ft_statistics(*args: any, **kwargs: any) -> None:
    if (len(args) == 0):
        print("ERROR")
        return
    for kwarg in kwargs.values():
        if (kwarg == 'mean'):
            print(f"mean: {sum(args) / len(args)}")
        elif (kwarg == 'median'):
            args = sorted(args)
            if len(args) % 2 == 0:
                print(f"median: {(args[len(args) // 2 - 1]
                                  + args[len(args) // 2]) / 2}")
            else:
                print(f"median: {args[len(args) // 2]}")
        elif (kwarg == 'quartile'):
            args = sorted(args)
            quartile = []
            quartile.append(args[len(args) // 4])
            quartile.append(args[len(args) // 4 * 3])
            print(f'quartile: {quartile}')
        elif (kwarg == 'std'):
            mean = sum(args) / len(args)
            variance = sum((x - mean) ** 2 for x in args) / len(args)
            print(f"std: {variance ** 0.5}")
        elif (kwarg == 'var'):
            mean = sum(args) / len(args)
            variance = sum((x - mean) ** 2 for x in args) / len(args)
            print(f"var: {variance}")
