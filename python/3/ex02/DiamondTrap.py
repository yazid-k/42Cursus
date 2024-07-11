from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    '''
    A class representing a King character.
    '''

    def __init__(self, first_name, is_alive=True):
        '''
        Initializes a King character.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if
              the character is alive. Defaults to True.
        '''
        Baratheon.__init__(self, first_name, is_alive)
        Lannister.__init__(self, first_name, is_alive)
        self.family_name = "Baratheon"
        self.eyes = "blue"
        self.hair = "black"

    def __str__(self):
        '''
        Returns a string representation of the King character.

        Returns:
            str: The string representation of the character.
        '''
        return f"{self.first_name} Baratheon, King of the Andals"

    def set_eyes(self, color):
        '''
        Sets the eye color of the King character.

        Args:
            color (str): The eye color of the character.
        '''
        self.eyes = color

    def set_hairs(self, color):
        '''
        Sets the hair color of the King character.

        Args:
            color (str): The hair color of the character.
        '''
        self.hair = color

    def get_eyes(self):
        '''
        Returns the eye color of the King character.

        Returns:
            str: The eye color of the character.
        '''
        return self.eyes

    def get_hairs(self):
        '''
        Returns the hair color of the King character.

        Returns:
            str: The hair color of the character.
        '''
        return self.hair
