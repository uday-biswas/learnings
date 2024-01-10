//Asynchronous javascript

//asynchronous code uses event loop to handle asynchrnous function calls.
//event loop is a loop that checks the call stack and the task queue, 
//if the call stack is empty, it takes the first function from the task 
//queue and pushes it to the call stack.
//and the call stack gets emptied after the synchronous code is executed.
//and the event loop keeps on checking the call stack and the task queue.

//promises are used to handle asynchronous code, 
//a promise is an object that may produce a single value some time in the future,
//either a resolved value, or a reason that it is not resolved(rejected).

    //understanding the promise working

    let waadaa1 = new Promise(function (resolve, reject) {    //the promise is declared
        setTimeout(() => {                                  //the set timeout is added to the task queue, at t=2000ms it will be pushed to the call stack
            console.log("waadaa1 settimeout started");
        }, 2000);
        resolve("waadaa1 resolved");      //the promise is resolved ,and the value is passed to the then() method, which is called after the promise is resolved
    });

    let output = waadaa1.then((value) => {      //the then() method fot waadaa1 is called, and the value ("waadaa1 resolved") is passed to the function
        console.log(value);                     //the value is printed at t = 0 ms after the call stack is empty (after the synchronous code is executed)
        let waadaa2 = new Promise(function (resolve, reject) {   //the second promise is declared
            setTimeout(() => {                                 //the set timeout is added to the task queue, at t=3000ms it will be pushed to the call stack
                console.log("waadaa2 settimeout started");
            }, 3000);
            resolve("waadaa2 resolved");          //the second promise is also resolved ,and the value is passed to the then() method
        });
        return waadaa2;                      //output variable is assigned the value of waadaa2, which is a promise
    })

    output.then((value) => console.log(value));   //the then() method for output(waadaa2) is called, and the value ("waadaa2 resolved") is printed at t= 0 ms

    //the output of the above code is:
    //waadaa1 resolved                     //this is printed at t=0ms
    //waadaa2 resolved                    //this is printed at t=0ms
    //waadaa1 settimeout started         //this is printed at t=2000ms
    //waadaa2 settimeout started        //this is printed at t=3000ms

    //we can use catch() method to handle the rejected promise, working is same as then() method
    //catch() is a method that takes a function as an argument, and it is called when the promise is rejected
    let meraPromise2 = new Promise(function(resolve, reject){  //promise is declared
        setTimeout(function(){                      //set timeout is added to the task queue, at t=3000ms it will be pushed to the call stack
            reject('hello')                        
        }, 3000)
    })

    meraPromise2.catch(function(value){       //at t = 3000ms , the promise is rejected, and the catch() method is called with the value passed to it
        console.log(value)                    //the value is printed at t = 3000 ms
    })

    //the output of the above code is:
    //hello                               //this is printed at t=3000ms

    //we can use finally() method to execute a piece of code after the promise is resolved or rejected
    //finally() method is called after the then() or catch() method is called

    //for 50 promises , we cant use then() method 50 times, so we will use async await method
    //promises are basically used to stop the other asynchronous code from executing before the promise is resolved or rejected
    //so we can achieve the same thing using async await method in a more efficient way

    async function myFunction() {       //async function is declared
        console.log("hello A")
        console.log("hello B")
        const response = await fetch("./student_data.json")   //await keyword is used to wait for the promise to resolve or reject, until then the synchronous code is executed
        const students = await response.json();              //the response is converted to json format
        console.log(students[0].name)
        console.log("hello C")
    }

    console.log("hello D")
    myFunction();       //the async function is called
    console.log("hello E")

    //the output of the above code is:
    //hello D            //as part of the synchronous code
    //hello A            //inside the async function
    //hello B         
    //hello E            //as there is a await keyword, the synchronous code is executed before the promise is resolved
    //Kumar Sanu         //again inside the async function the promise is resolved, and the value is printed
    //hello C            inside the async function after the promise is resolved


       