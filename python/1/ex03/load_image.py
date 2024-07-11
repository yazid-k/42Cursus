from matplotlib.image import imread
import numpy as np


def ft_load(path: str) -> np.ndarray:
    """
    Load an image from the specified path and return it as a NumPy array.

    Args:
        path (str): The path to the image file.

    Returns:
        np.ndarray: The loaded image as a NumPy array.

    Raises:
        TypeError: If the `path` argument is not a string.
        ValueError: If the `path` argument is an empty string.
    """
    try:
        if (isinstance(path, str) is False):
            raise TypeError("path must be a string")
        if (path == ""):
            raise ValueError("path can't be empty")
    except TypeError as e:
        print(f"{TypeError.__name__} : {e}")
    except ValueError as e:
        print(f"{ValueError.__name__} : {e}")
    else:
        image = imread(path)
        print(f"Image shape: {image.shape}")
        print(image)
        return image
