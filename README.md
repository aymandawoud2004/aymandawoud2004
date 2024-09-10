- 👋 Hi, I’m @aymandawoud2004
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...

<!---
aymandawoud2004/aymandawoud2004 is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
import random
import pandas as pd
import string
import matplotlib.pyplot as plt
#This defines a list with all lowercase letters
lowercase = list(string.ascii_lowercase) 
numbers = [0]*26
dic = {'Letters':lowercase,
       'Times Guessed':numbers}
df = pd.DataFrame(dic)









# Define a list of words for the game"
wordDictionary = ["home", "house","google","office","professional",
                  "night","mirror","orange","title","speed"]

# this part will choose a random word from wordDictionary
randomWord = random.choice(wordDictionary)

#--------------------------------------------------------------------------------------------
#this part will print underscore like the number of the random word ,(end=" " ) used to ensure 
#horizantal underscore

## Function to print the hangman based on the number of incorrect guesses
def print_hangman(wrong):
    if wrong == 1:
        print("\n+---+")
        print("O   |")
        print("    |")
        print("    |")
        print("   ===")
    elif wrong == 2:
        print("\n+---+")
        print("O   |")
        print("|   |")
        print("    |")
        print("   ===")
    elif wrong == 3:
        print("\n+---+")
        print(" O  |")
        print("/|  |")
        print("    |")
        print("   ===")
    elif wrong == 4:
        print("\n+---+")
        print(" O  |")
        print("/|\\ |")
        print("    |")
        print("   ===")
    elif wrong == 5:
        print("\n+---+")
        print(" O  |")
        print("/|\\ |")
        print("/   |")
        print("   ===")
    elif wrong == 6:
        print("\n+---+")
        print(" O  |")
        print("/|\\ |")
        print("/ \\ |")
        print("   ===")

## Function to print the current guessed letters in the word
def printWord(guessedLetters):
    for char in randomWord:
        if char in guessedLetters:
            print(char, end=" ")
        else:
            print("_", end=" ")
    print()

# This function will  get the user input for guessing a letter
# and ensure it's a small letter similiar to the words in the wordDictionary
def get_user_input():
    letter_guessed = input("\nGuess a letter: ").lower()
    return letter_guessed

# Get the length of the word to guess
length_of_word_to_guess = len(randomWord)

# Initialize variables for tracking incorrect guesses and guessed letters
#this is to help print the hangman 
amount_of_times_wrong = 0

#In Python, a set is an unordered collection of unique elements. It's a data structure similar to a list or a tuple.
#but unlike lists and tuples, a set does not allow duplicate elements as we want in our game .  
#Using a set is  useful in our game  because it automatically ensures that each letter is unique,
#and the order of letters doesn't matter.

current_letters_guessed = set()
total_letters_guessed = []
# Main game loop
print("Welcome to hangman")
print("-------------------------------------------")
while amount_of_times_wrong != 6 and set(randomWord) != current_letters_guessed:
    # Display letters guessed so far
    print("\nLetters guessed so far:", " ".join(total_letters_guessed))
    
    # This will display  the hangman based on the number of incorrect guesses.
    print_hangman(amount_of_times_wrong)

    #  This will display the current state of guessed letters in the word
    printWord(current_letters_guessed)

    # Get the  user input for guessing a letter
    letter_guessed = get_user_input()
    #This statement checks if the user input was already guessed
    if letter_guessed not in total_letters_guessed and letter_guessed in lowercase:
        total_letters_guessed.append(letter_guessed)
        df.loc[df['Letters'] == letter_guessed, 'Times Guessed'] += 1
    elif letter_guessed in total_letters_guessed:
        print("You already picked this letter.")
    
    # ensure that the user input is from the alphabet and is just one digit length
    if letter_guessed.isalpha() and len(letter_guessed) == 1:
        # Check if the guessed letter is in the random word ,we use (.add()) because it is a set()
        if letter_guessed in randomWord:
            current_letters_guessed.add(letter_guessed)
        else:
            amount_of_times_wrong += 1
    else:
        print("Please enter a valid single letter.")

#This statement checks whether the user won or lost and displays the appropriate message
if set(randomWord) != current_letters_guessed:
    print_hangman(amount_of_times_wrong)
    printWord(current_letters_guessed)
    print("You lost :(")
    print("The word was:",randomWord)
else:
    printWord(current_letters_guessed)
    print("You won!")

print("\nGame over! Thank you for playing :)")







df.plot(x='Letters', y='Times Guessed', kind='bar', ylabel='Number of Guesses')
plt.show()
