//learning objects , objects are key value pairs, they are used to store data in a structured way
//declaring an object
const person = {         //here the person is the reference variable that is pointing to the object
    firstName: 'Asabeneh',
    lastName: 'Yetayeh',
    age: 250,
    country: 'Finland',
    city: 'Helsinki',
    skills: [
      'HTML',
      'CSS',
      'JavaScript',
      'React',
      'Node',
      'MongoDB',
      'Python',
      'D3.js'
    ],
    isMarried: true
  }

  //accessing values using dot notation
  console.log(person.firstName)
  console.log(person.lastName)

  //accessing values using bracket notation
  console.log(person['firstName'])
  console.log(person['lastName']) 

  //accessing an object using for in loop
  for (const key in person) {
    if (person.hasOwnProperty(key)) {
      const element = person[key]
      console.log(key +" : " +element)
    }
  }

  //decaring objects inside object, with an example of user object
const users = {
    Alex: {
      email: 'alex@alex.com',
      skills: ['HTML', 'CSS', 'JavaScript'],
      age: 20,
      isLoggedIn: false,
      points: 30
    },
    Asab: {
      email: 'asab@asab.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'Redux', 'MongoDB', 'Express', 'React', 'Node'],
      age: 25,
      isLoggedIn: false,
      points: 50
    },
    Brook: {
      email: 'daniel@daniel.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React', 'Redux'],
      age: 30,
      isLoggedIn: true,
      points: 50
    },
    Daniel: {
      email: 'daniel@alex.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'Python'],
      age: 20,
      isLoggedIn: false,
      points: 40
    },
    John: {
      email: 'john@john.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React', 'Redux', 'Node.js'],
      age: 20,
      isLoggedIn: true,
      points: 50
    },
    Thomas: {
      email: 'thomas@thomas.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React'],
      age: 20,
      isLoggedIn: false,
      points: 40
    },
    Paul: {
      email: 'paul@paul.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'MongoDB', 'Express', 'React', 'Node'],
      age: 20,
      isLoggedIn: false,
      points: 40
    }
  }

  for(const keys in users){
    if(keys === 'Daniel'){
      console.log(users[keys])
    }
  }

  //function inside object,  we can't use arrow function as object method
  const rectangle = {
    length : 20,
    breadth : 20,
    getArea: function() {
      return this.length * this.breadth
    },
    getPerimeter: function() {
      return 2 * (this.length + this.breadth)
    },
  }

  console.log(rectangle.getArea())
  console.log(rectangle.getPerimeter())

  //object creation using factory function
  function createRectangle(length, breadth) {
    return {
      length: length,
      breadth: breadth,
      getArea: function() {
        return this.length * this.breadth
      },
      getPerimeter: function() {
        return 2 * (this.length + this.breadth)
      }
    }
  }

  const rectangle1 = createRectangle(10, 5)   // Created the rectangle object using the createRectangle function
  console.log(rectangle1.length)              // => 10
  console.log(rectangle1.getArea())             // => 50
  
  //object creation using constructor function - it is similar to class in cpp , we create a structure and then create objects of that structure
  //it uses pascal notation to define the name of the function -> first letter of every word is capital -> NumberOfStudents
  //it just defines and initializes the properties and methods of an object
  function Rectangle(length, breadth) {
    this.length = length
    this.breadth = breadth
    this.getArea = function() {
      return this.length * this.breadth
    }
    this.getPerimeter = function() {
      return 2 * (this.length + this.breadth)
    }
  }

  const rectangle2 = new Rectangle(10, 5)   // Created the rectangle object using the Rectangle constructor function
  console.log(rectangle2.getArea())            // => 50

  rectangle2.color = 'yellow'             //adding a new property to this object only, not to the constructor class
  console.log(rectangle2.color)               // => yellow

  delete rectangle2.color          //deleting a property from this object

  //understanding the reference of an object
  let a = {value : 10}     //here a is a reference variable that is pointing to the object
  let b = a               //so now b is also pointing to the same object
  a.value++               //so if we change the value at a, it will also change the value at b
  console.log(a.value)    //11
  console.log(b.value)    //11

  //versus primitive types
  let x = 10
  let y = x
  x++
  console.log(x)    //11  
  console.log(y)    //10

  //loops - for in loop, for of loop
  //for in loop - used to iterate over the properties of an object
  for (const key in rectangle2) {
    if (rectangle2.hasOwnProperty(key)) {
      console.log(key)    //prints the properties of the object
      console.log(rectangle2[key])    //prints the values of the properties
    }
  }

  //for of loop - used to iterate over the elements of an array
  const numbers = [1, 2, 3, 4, 5]
  for (const number of numbers) {
    console.log(number)
  }

  // => cloning the object :
  let src = {            //source object
    a: 1,
    b: 2,
    func : function() {
      return 1
    }
  }

  //1. Iterating over the properties of the object and copying them to the new object

  let dest1 = {}               //destination object
  for (const key in src) {
    dest1[key] = src[key]
  }

  //2. Using Object.assign() method

  let src2 = { value:4 }

  let dest2 = Object.assign({}, src)   //here the first argument is the destination object and the second argument is the source object
                                      //then the destination object is returned which is stored in dest2
  let dest3 = Object.assign({}, src, src2)   //multiple source objects can be passed to be cloned to the destination object

  //3. Using the spread operator

  let dest4 = {...src}    //here the source object is spreaded and stored in the destination object






