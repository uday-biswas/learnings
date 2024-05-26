#learning functions 
#def - keyword to define a function

def add(a, b):
    return a + b

c = add(10, 20) #calling a function
print(c)

#built-in modules in python
#firstly we have to import the module, then we can use the functions
#math module
import math
print(math.sqrt(16))   #returns the square root of a number
print(math.pow(2, 3))  #returns the power of a number
print(math.pi) #returns the value of pi

#random module
import random
print(random.random())  #returns a random number between 0 and 1
print(random.randint(1, 10))    #returns a random integer between 1 and 10

#datetime module
import datetime
print(datetime.datetime.now())  #returns the current date and time

#os module
import os
print(os.getcwd())  #returns the current working directory
print(os.listdir()) #returns the list of files and directories in the current working directory
print(os.listdir("C:/Users"))   #returns the list of files and directories in the given directory
print(os.path.exists("C:/Users/HP/Desktop"))   #returns true if the given path exists
print(os.path.isfile("C:/Users/HP/Desktop"))   #returns true if the given path is a file
print(os.path.isdir("C:/Users/HP/Desktop"))    #returns true if the given path is a directory
print(os.path.split("C:/Users/HP/Desktop/abc.txt"))   #splits the path and returns the path
