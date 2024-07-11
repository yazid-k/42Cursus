import numpy as np


def zoom(image: np.ndarray) -> np.ndarray:
    """
    Zooms in on an image by cutting a square part of 400px width.

    Args:
        image (np.ndarray): The input image to be zoomed.

    Returns:
        np.ndarray: The zoomed image.

    Raises:
        TypeError: If the input image is not of type np.ndarray.
        ValueError: If the input image does not have 3 dimensions.
    """
    try:
        if not isinstance(image, np.ndarray):
            raise TypeError("image must be a numpy array")
        if len(image.shape) != 3:
            raise ValueError("image must have 3 dimensions")
    except TypeError as e:
        print(f"{type(e).__name__}: {e}")
    except ValueError as e:
        print(f"{type(e).__name__}: {e}")
    else:
        height, width, _ = image.shape
        start_row = height // 2 - 200
        end_row = start_row + 400
        start_col = width // 2 - 200
        end_col = start_col + 400
        zoomed = image[start_row:end_row, start_col:end_col]
        return zoomed


def rotate(image: np.ndarray) -> np.ndarray:
    """
    Rotates an image by 90 degrees clockwise.

    Args:
        image (np.ndarray): The input image to be rotated.

    Returns:
        np.ndarray: The rotated image.

    Raises:
        TypeError: If the input image is not of type np.ndarray.
        ValueError: If the input image does not have 3 dimensions.
    """
    try:
        if (isinstance(image, np.ndarray) is False):
            raise TypeError("image must be a list")
        if (len(image.shape) != 3):
            raise ValueError("image must contain 3 dimensions")
    except TypeError as e:
        print(f"{TypeError.__name__} : {e}")
    except ValueError as e:
        print(f"{ValueError.__name__} : {e}")
    else:
        rotated = np.rot90(image, k=1)
        return rotated
