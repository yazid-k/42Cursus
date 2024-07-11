import numpy as np


def zoom(image: np.ndarray) -> np.ndarray:
    """
    Zooms in on an image by reducing its dimensions by half.

    Args:
        image (np.ndarray): The input image to be zoomed.

    Returns:
        np.ndarray: The zoomed image.

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
        height, width, _ = image.shape
        start_row = height // 4
        end_row = start_row + height // 2
        start_col = width // 4
        end_col = start_col + width // 2
        zoomed = image[start_row:end_row, start_col:end_col]
        print(f"Zoomed image shape: {zoomed.shape}")
        print(zoomed)
        return zoomed
