from abc import ABC, abstractmethod


class Character(ABC):
    """Your docstring for Class"""
    @abstractmethod
    def __init__(self, first_name, is_alive=True):
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        """Kill the character.

        Sets the 'is_alive' attribute to False.
        """
        self.is_alive = False


class Stark(Character):
    """A class representing a Stark character.

    Attributes:
        first_name (str): The first name of the Stark character.
        is_alive (bool): Indicates whether the Stark character is alive or not.
    """

    def __init__(self, first_name, is_alive=True):
        """Initialize a Stark character.

        Args:
            first_name (str, optional): The first name of the Stark
            character. Defaults to None.
            is_alive (bool, optional): Indicates whether
            the Stark character is alive or not. Defaults to True.
        """
        super().__init__(first_name, is_alive)

    def die(self):
        """Kill the Stark character.

        Sets the 'is_alive' attribute to False.
        """
        super().die()
