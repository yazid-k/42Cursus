import numpy as np
import matplotlib.pyplot as plt


def ft_invert(array: np.ndarray) -> np.ndarray:
    """
    Inverts the pixel values of an image array.

    Parameters:
    array (np.ndarray): The input image array.

    Returns:
    np.ndarray: The inverted image array.
    """
    inverted = 255 - array
    plt.imshow(inverted)
    plt.show()
    return inverted


def ft_red(array: np.ndarray) -> np.ndarray:
    """
    Extracts the red channel from an image array.

    Parameters:
    array (np.ndarray): The input image array.

    Returns:
    np.ndarray: The red channel of the image array.
    """
    red = array.copy()
    red[:, :, 1] = 0
    red[:, :, 2] = 0
    plt.imshow(red)
    plt.show()
    return red


def ft_green(array: np.ndarray) -> np.ndarray:
    """
    Extracts the green channel from an image array.

    Parameters:
    array (np.ndarray): The input image array.

    Returns:
    np.ndarray: The green channel of the image array.
    """
    green = array.copy()
    green[:, :, 0] = 0
    green[:, :, 2] = 0
    plt.imshow(green)
    plt.show()
    return green


def ft_blue(array: np.ndarray) -> np.ndarray:
    """
    Extracts the blue channel from an image array.

    Parameters:
    array (np.ndarray): The input image array.

    Returns:
    np.ndarray: The blue channel of the image array.
    """
    blue = array.copy()
    blue[:, :, 0] = 0
    blue[:, :, 1] = 0
    plt.imshow(blue)
    plt.show()
    return blue


def ft_grey(array: np.ndarray) -> np.ndarray:
    """
    Converts an image array to grayscale.

    Parameters:
    array (np.ndarray): The input image array.

    Returns:
    np.ndarray: The grayscale image array.
    """
    grey = np.sum(array, axis=2) // 3
    grey = np.dstack((grey, grey, grey))
    plt.imshow(grey)
    plt.show()
    return grey
