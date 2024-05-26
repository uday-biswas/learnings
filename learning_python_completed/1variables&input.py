#learning python

#variables - no need to declare the type of variable
#types of variables - int, float, string, boolean
age = 20 #int
name = "John" #string
salary = 20000.00 #float
isEmployed = True #boolean

print("My name is " + name + " ,age and salary is " , age , salary , "and my employment status is" , isEmployed)
#strings can be concatenated using + operator

#taking input from user
#input() - returns a string
#int(input()) - returns an integer
#float(input()) - returns a float
#bool(input()) - returns a boolean, if the input is empty, it returns false, else true
#eval(input()) - returns the type of the input

name = input("Enter your name: ")
age = int(input("Enter your age: "))
salary = float(input("Enter your salary: "))
isEmployed = bool(input("Are you employed? "))
print(name, age, salary, isEmployed)

#type casting
#int(), float(), str(), bool()
#bool() - returns false for 0, 0.0, "", None, False, else returns true
num = int("10")
marks = float("10.5")
isEmployed = bool(False)
print(num, marks, isEmployed)