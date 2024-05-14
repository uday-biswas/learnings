#learning arrays - list, tuple, set, dictionary
#list - similar to array in c/c++
marks = [10, 20, 30, 40, 50] #list
print(marks[0])   #accessing the first element
print(marks[-1])  #negative index starts from the end
print(marks[1:3]) #slicing - returns a new list with elements from index 1 to 2

marks[0] = 100    #updating the first element
#we can apply for loop on a list
for mark in marks:
    print(mark)
for i in marks[1:3]:
    print(i)

print(len(marks)) #returns the length of the list
print(marks.count(10)) #returns the number of occurrences of an element
marks.append(60) #adds an element at the end of the list
marks.insert(1, 5) #adds an element 5 at the index 1
marks.remove(5) #removes the first occurrence of the element
marks.pop() #removes the last element
marks.pop(1) #removes the element at index 1
marks.sort() #sorts the list
marks.reverse() #reverses the list
marks.clear() #removes all the elements from the list

#tuple - similar to list, but immutable
#we cannot update a tuple
tuples = (10, 20, 30, 40, 50)
print(tuples[0])
print(tuples.count(10))  #returns the number of occurrences of an element
print(tuples.index(10))  #returns the index of the first occurrence of an element
print(len(tuples)) #returns the length of the tuple

#set - similar to list, but unordered and no duplicates
#we cannot access elements using index and we have to use curly braces
sets = {10, 20, 30, 30, 30}
for i in sets:
    print(i)    #prints only 10, 20, 30

sets.add(40)    #adds an element to the set
sets.remove(30) #removes an element from the set
sets.discard(30)    #removes an element from the set
sets.pop()  #removes the first element from the set
sets.clear()    #removes all the elements from the set

#dictionary - similar to map in c/c++
subjects = {"maths": 100, "physics": 90, "chemistry": 80}
print(subjects["maths"])    #accessing the value using key
print(subjects.get("physics"))  #accessing the value using key
subjects["maths"] = 95  #updating the value using key
subjects["english"] = 70    #adding a new key value pair
del subjects["chemistry"]   #deleting a key value pair
print(subjects.keys())  #returns all the keys
print(subjects.values())    #returns all the values
print(subjects.items()) #returns all the key value pairs
print(len(subjects))    #returns the number of key value pairs
subjects.clear()    #removes all the key value pairs

