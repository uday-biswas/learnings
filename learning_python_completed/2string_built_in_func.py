name = "Tony Stark"
print(name.upper())   #converts to upper case
print(name.lower())   #converts to lower case
print(name.title())   #title case means first letter of each word is capitalized
print(name.capitalize())   #capitalizes the first letter
print(name.swapcase())   #swaps the case of each letter
print(name.count('o'))   #returns the number of occurrences of a character
print(name.find("ny"))   #returns the index of the first occurrence of the string
print(name.find('l'))   #returns -1 if the string is not found
print(name.replace("Tony", "Ironman"))   #replaces all occurrences of a string with another string
print(name.split(" "))   #splits the string into a list of strings based on the separator
print(name.startswith("T"))   #returns true if the string starts with the specified string
print(name.endswith("k"))   #returns true if the string ends with the specified string
print(name.islower())   #returns true if the string contains only lower case letters
print(name.isupper())   #returns true if the string contains only upper case letters
