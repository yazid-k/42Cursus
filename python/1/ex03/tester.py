from zoom import zoom
from load_image import ft_load
import matplotlib.pyplot as plt


def main():
    image = ft_load("animal.jpeg")
    image = zoom(image)
    plt.imshow(image)
    plt.show()


if __name__ == "__main__":
    main()
