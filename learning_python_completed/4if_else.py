#if else conditions
#we have to give colon, and then we have to give tab space

age = int(input("Enter your age: "))
if age >= 18:
    print("You are eligible to vote")
    print("Thank you for voting")
elif age >= 13:
    print("You are a teenager")
else:
    print("You are not eligible to vote")
    print("Please try again after", 18 - age, "years")