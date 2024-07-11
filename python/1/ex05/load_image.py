from matplotlib.image import imread


def ft_load(path: str) -> list:
    """
    Load an image from the specified path.

    Args:
        path (str): The path to the image file.

    Returns:
        list: The loaded image.

    Raises:
        TypeError: If the path is not a string.
        ValueError: If the path is empty.
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
