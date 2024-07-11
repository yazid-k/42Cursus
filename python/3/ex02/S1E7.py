from S1E9 import Character


class Baratheon(Character):
    '''A class representing a Baratheon character.'''
    def __init__(self, first_name, is_alive=True):
        '''
        Initializes a Baratheon character.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if
            the character is alive. Defaults to True.
        '''
        self.first_name = first_name
        self.is_alive = is_alive
        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hair = "dark"

    def __str__(self):
        '''
        Returns a string representation of the Baratheon character.

        Returns:
            str: The string representation of the character.
        '''
        return f"{self.first_name} Baratheon"

    def __repr__(self):
        '''
        Returns a string representation of the Baratheon character.

        Returns:
            str: The string representation of the character.
        '''
        return f"{self.first_name} Baratheon"

    def die(self):
        '''
        Updates the character's status to indicate that they have died.
        '''
        super().die()


class Lannister(Character):
    """
    A class representing a Lannister character.
    """

    def __init__(self, first_name, is_alive=True):
        """
        Initializes a Lannister character.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates
              if the character is alive. Defaults to True.
        """
        self.first_name = first_name
        self.is_alive = is_alive
        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hair = "light"

    def die(self):
        """
        Marks the character as dead.
        """
        super().die()

    def __str__(self):
        """
        Returns a string representation of the character.

        Returns:
            str: The string representation of the character.
        """
        return f"{self.first_name} Lannister"

    def __repr__(self):
        """
        Returns a string representation of the character.

        Returns:
            str: The string representation of the character.
        """
        return f"{self.first_name} Lannister"

    @staticmethod
    def create_lannister(name, is_alive=True):
        """
        Creates a new Lannister character.

        Args:
            name (str): The first name of the character.
            is_alive (bool, optional): Indicates if the
            character is alive. Defaults to True.

        Returns:
            Lannister: The created Lannister character.
        """
        return Lannister(name, is_alive)
