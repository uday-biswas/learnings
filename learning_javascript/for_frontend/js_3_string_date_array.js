//learning in built math functions
console.log(Math.random()); // gives a random number between 0 and 1
console.log(Math.round(1.9)); // rounds off to the nearest integer
console.log(Math.ceil(1.1)); // rounds off to the next integer
console.log(Math.floor(1.9)); // rounds off to the previous integer
console.log(Math.min(1, 2, 3, 4, 5)); // gives the minimum value
console.log(Math.max(1, 2, 3, 4, 5)); // gives the maximum value
console.log(Math.abs(-1)); // gives the absolute value
console.log(Math.pow(2, 3)); // gives the power of the number
console.log(Math.sqrt(4)); // gives the square root of the number
console.log(Math.log(2)); // gives the natural log of the number
console.log(Math.log10(2)); // gives the log to the base 10 of the number

//string methods
let str = "Hello World , you are beautiful";
console.log(str.length); // gives the length of the string
console.log(str.indexOf("World")); // gives the index of the first occurence of the substring
console.log(str.lastIndexOf("World")); // gives the index of the last occurence of the substring
console.log(str.slice(0, 7)); // gives the substring from the start index to the end-1 index
console.log(str.substring(0, 7)); // gives the substring from the start index to the end-1 index , same as slice
console.log(str.startsWith("Hello")); // checks if the string starts with the given substring
console.log(str.endsWith("ful")); // checks if the string ends with the given substring
console.log(str.includes("you")); // checks if the string contains the given substring
console.log(str.replace("World", "Universe")); // replaces the first occurence of the substring with the given substring
console.log(str.trim()); // removes the leading and trailing spaces
let arr = str.split(" "); // splits the string into an array of substrings based on the given separator
console.log(arr);
console.log(str.concat(" , ", "you", " are", " beautiful")); // concatenates the given strings to the original string

//backtick(`) operator - used to create template literals, it will be shown as it is 
let fname = "Rishabh";
let message =
`Hello ${fname},
 Thanks for the opportunity.
 
 Regards,
 Babbar`;
console.log(message);

//understanding date object
//there are 5 ways to declare the date object
//1. new Date()
let date1 = new Date();
console.log(date1);

//2. new Date(milliseconds)
let date2 = new Date(5789);    // 1 Jan 1970 + 5789 milliseconds
console.log(date2);

//3. new Date(dateString)
let date3 = new Date("2020-01-01");   // 1 Jan 2020

//4. new Date(year, month, day, hours, minutes, seconds, milliseconds)
let date4 = new Date(2020, 0, 1, 12, 30, 45, 100); // 1 Jan 2020 12:30:45:100

//5. new Date(year, month, day)
let date5 = new Date(2020, 0, 1); // 1 Jan 2020 00:00:00:000   , month is 0 based

//getting the date and time from the date object
console.log(date1.getDate()); // gives the date
console.log(date1.getDay()); // gives the day of the week
console.log(date1.getFullYear()); // gives the year
console.log(date1.getHours()); // gives the hours
console.log(date1.getMinutes()); // gives the minutes
console.log(date1.getSeconds()); // gives the seconds
console.log(date1.getMilliseconds()); // gives the milliseconds
console.log(date1.getMonth()); // gives the month

//setting the date and time from the date object
date1.setDate(10); // sets the date
date1.setFullYear(2020); // sets the year
date1.setHours(12); // sets the hours
date1.setMinutes(30); // sets the minutes
date1.setSeconds(45); // sets the seconds
date1.setMilliseconds(100); // sets the milliseconds
date1.setMonth(0); // sets the month

//understanding the array object - it is a collection of elements of any type
//there are 2 ways to declare the array object
//1. using the array literal
let arr1 = [1, 2, 3, 4, 5];

//2. using the array constructor
let arr2 = new Array(1, 2, 3, 4, 5);

//there are following operations that can be performed on the array

//1. insertion of the elements in the array
arr1.push(6); // inserts the element at the end of the array - [1, 2, 3, 4, 5, 6]
arr1.unshift(0); // inserts the element at the start of the array - [0, 1, 2, 3, 4, 5, 6]

arr1.splice(3, 0, 3.5, 'yellow'); // inserts the element at the given index - [0, 1, 2, 3.5, 'yellow', 3, 4, 5, 6]
//syntax of splice method - arr.splice(index, no. of elements to be deleted, elements to be inserted)

//2. searching the elements in the array
  //using the inbuilt methods
console.log(arr1.indexOf(3)); // gives the index of the first occurence of the element if present, else -1
console.log(arr1.indexOf(7,2)); //searches the element after the given index
console.log(arr1.lastIndexOf(3)); // gives the index of the last occurence of the element if present, else -1
console.log(arr1.includes(3)); // checks if the element is present in the array, prints true or false

  //using callback functions with find and findIndex methods
console.log(arr1.find( (element) => element > 3) ); // gives the first element that satisfies the condition
console.log(arr1.findIndex( (element) => element > 3) ); // gives the index of the first element that satisfies the condition

//searching the objects in the array of objects
let courses = [
    {no: 1, name: 'DSA', price: 199},
    {no: 2, name: 'Web Dev', price: 299},
    {no: 3, name: 'React', price: 399},
];

  //using the inbuilt methods (indexOf, lastIndexOf, includes) wont work with objects as they are reference types
  //so we can will use the callback functions with find and findIndex methods
console.log(courses.find( function(course){
    return course.price > 200;
} ).name ); // prints the 'name' property of the first object that satisfies the condition

console.log(courses.findIndex((course) => course.name === 'React')); // gives the index of the first object that satisfies the condition

//3. Removing the elements from the array
let number = [1, 2, 3, 4, 5, 6, 7, 8, 9];
number.pop(); // removes the last element from the array - [1, 2, 3, 4, 5, 6, 7, 8]
number.shift(); // removes the first element from the array - [2, 3, 4, 5, 6, 7, 8]
number.splice(3, 1); // removes the element at the given index - [2, 3, 4, 6, 7, 8]

//4. emptying the array
number.length = 0; // removes all the elements from the array
number.splice(0, number.length); // removes all the elements from the array

//5. combining the arrays
let arr3 = [1, 2, 3];
let arr4 = [4, 5, 6];
let arr5 = arr3.concat(arr4); // combines the arrays - [1, 2, 3, 4, 5, 6]
let arr6 = [...arr3, 'a', false, ...arr4]; // combines the arrays - [1, 2, 3, 'a', false, 4, 5, 6]

//6. Iterating the array using the for of loop
for(let element of arr5){
    console.log(element);
}

  //using the forEach method
arr5.forEach((element) => console.log(element));

//7. joining and splitting the elements of the array
let arr7 = ['a', 'b', 'c', 'd'];
let str1 = arr7.join(' '); // joins the elements of the array with the given separator - 'a b c d'
let arr8 = str1.split(' '); // splits the string into an array of substrings based on the given separator - ['a', 'b', 'c', 'd']

//8. sorting the array
let arr9 = [40, 26, 9, 1, 5, 3, 7, 2,];
arr9.sort(); // sorts the array in ascending order - [1, 2, 3, 5, 7, 9, 26, 40]
arr9.reverse(); // sorts the array in descending order - [40, 26, 9, 7, 5, 3, 2, 1]

 //sorting the array of objects
let courses1 = [
    {no: 1, name: 'DSA', price: 199},
    {no: 2, name: 'Web Dev', price: 399},
    {no: 3, name: 'React', price: 99}
];

courses1.sort( (a, b) => a.price - b.price )   //if it is positive then a will come after b, if it is negative then a will come before b
                                               // sorts the array in ascending order of the price property
console.log(courses1);

//9. filtering the array
let arr10 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let filtered = arr10.filter( (element) => element > 5); // filters the array based on the given condition - [6, 7, 8, 9]
console.log(filtered);

//10. mapping the array
let arr11 = [1, 2, 3, 4];
let mapped1 = arr11.map( (element) => 'student No ' + element); // maps the array based on the given condition - ['student No 1', 'student No 2', 'student No 3', 'student No 4']
let mapped2 = arr11.map( (element) => element * 2 ); // [2, 4, 6, 8]
let mapped3 = arr11.map( (element) => ({value: element}) ); // mapping used to create objects - [{value: 1}, {value: 2}, {value: 3}, {value: 4}]

//11. reducing the array
let arr12 = [1, 2, 3, 4];
let reduced1 = arr12.reduce( (accumulator, currentValue) => accumulator + currentValue); // reduces the array to a single value based on the given condition - 10
console.log(reduced1);
