//understanding the functions 
//1. function declaration

 //1.1 direct function declaration
function greet(name) {
    console.log('Hello ' + name);
}
greet('John'); // prints Hello John

  //1.2 function assigned to the variable
let stand = function() {
    console.log('Stand up');
}
stand(); // prints Stand up

  //1.3 arrow function 
let sit = () => {
    console.log('Sit down');
}
sit(); // prints Sit down

//2.1 use of arguments object
function sum1() {
    let total = 0;
    for(let value of arguments)  //here all the parameters are passed as in properties of the 'arguments' object
        total += value;
    return total;
}
console.log(sum1(1, 2, 3, 4, 5)); // prints 15

 //2.2 use of rest operator
function sum2(...args) {
    let total = 0;
    for(let value in args)     //here all the parameters are passed as elements of the args array
        total += args[value];
    return total
}
console.log(sum2(1, 2, 3, 4, 5)); // prints 15
 
function sum3(discount, ...prices) {    //rest parameter must be the last parameter, first parameter is passed to discount and remaining are passed to prices
    let total = 0;
    for(let value in prices)
        total += prices[value];
    return total * (1 - discount);
}
console.log(sum3(0.1, 20, 30)); // prints 45

//3. getters and setters
let person = {
    firstName: 'John',
    lastName: 'Doe',
    get fullName() {
        return this.firstName + ' ' + this.lastName;
    },
    set fullName(value) {
        let parts = value.split(' ');
        this.firstName = parts[0];
        this.lastName = parts[1];
    }
};
console.log(person.fullName); // prints John Doe using getter
person.fullName = 'Jane Foster';   // uses setter
console.log(person.fullName); // prints Jane Foster 

//4. try and catch blocks
let person1 = {
    firstName: 'John',
    lastName: 'Doe',
    get fullName() {
        return this.firstName + ' ' + this.lastName;
    },
    set fullName(value) {
        if(typeof value !== 'string')
            throw new Error('Value is not a string');   //this throw error message will be passed to the catch block if there is an error
        let parts = value.split(' ');
        if(parts.length !== 2)
            throw new Error('Enter a first and last name');
        this.firstName = parts[0];
        this.lastName = parts[1];
    }
};
try {      //try block is used to test the code inside it for errors
    person1.fullName = 1;    //if there is an error in the try block then the catch block is executed
}
catch(e) {    //catch block is used to handle the errors
    console.log(e)   //prints the error message 
}

try {
    person1.fullName = 'jane doe';
}
catch(e) {    //e is the error object
    console.log(e);
}
finally {     //finally block is executed whether there is an error or not
    console.log('Finally block executed');
}









