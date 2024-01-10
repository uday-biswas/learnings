//document fragment - it is a node that contains a group of nodes, it is not part of the DOM tree, it is a lightweight version of the DOM tree
//to create a document fragment, we use document.createDocumentFragment() method
//we can append nodes to the document fragment , which takes very less time than appending nodes to the DOM tree,
//because the document fragment is not part of the DOM tree, so it is not rendered in the browser,
//and after appending the nodes to the document fragment, we can append the document fragment to the DOM tree, which is a best practise

let fragment = document.createDocumentFragment()
for(let i=1; i<10; i++){
    let element = document.createElement('p')
    element.textContent = `This is paragraph ${i}`
    fragment.appendChild(element)
}
document.body.appendChild(fragment)

// The call stack
    //call stack is a data structure that records where in the program we are, 
    //if we call a function, it is added to the call stack, and when the function returns, 
    //it is removed from the call stack

    //setTimeout() is a method that takes a function as an argument, and a time in milliseconds,
    //and it calls the function after the specified time, and it is added to the call stack
    //and after the function is executed, it is removed from the call stack
    setTimeout(function(){
        console.log('hello')
    }, 5000)                   //hello is printed after 5 seconds

    

