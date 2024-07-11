import pandas as pd
import numpy as np


def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """
    Calculate the Body Mass Index (BMI) for a given height and weight.

    Args:
        height (list[int | float]): A list of heights in meters.
        weight (list[int | float]): A list of weights in kilograms.

    Returns:
        list[int | float]: A list of calculated BMI values.
    """
    h = pd.Series(height)
    w = pd.Series(weight)
    try:
        if h.size != w.size:
            raise AssertionError("lists of different size")
        for i in range(len(height)):
            if ((w.dtype != np.dtype('float64') and w.dtype != np.dtype('int'))
                    or (h.dtype != np.dtype('float64')
                        and h.dtype != np.dtype('int'))):
                raise AssertionError("type is not int or float")
        for i in height:
            if (i == 0):
                raise AssertionError("height can't be equal to 0")

    except AssertionError as e:
        print(f"{AssertionError.__name__} : {e}")
    else:
        return [weight[i] / height[i] ** 2 for i in range(len(height))]


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    Apply a limit to a list of BMI values and return a list of booleans
    indicating whether each BMI value is within the limit.

    Args:
        bmi (list[int | float]): A list of BMI values.
        limit (int): The limit to apply to the BMI values.

    Returns:
        list[bool]: A list of booleans indicating whether each BMI
        value is within the limit.
    """
    if (bmi is None):
        return None
    return [i > limit for i in bmi]
