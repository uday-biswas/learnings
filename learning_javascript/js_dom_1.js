 //Understanding the DOM
    //The DOM is a tree of nodes and objects that expose properties and methods. 
      //The Document object is the root of the DOM tree.

//1. Accessing the elements of the DOM

    //1.1 getElementById() is a method of the document object which returns the element 
    //with the specified ID.
   console.log(document.getElementById('para1').innerHTML)   //returns the content of the element with id="para1"

   //1.2 getElementsByClassName() is a method of the document object which returns a 
   //collection of all elements in the document with the specified class name, 
   //as a NodeList object called HTMLCollection.
   //there can be multiple class names specifies in the parameter separated by space
   console.log(document.getElementsByClassName('test red')) //only selects the elements that have both given class names
   console.log(document.getElementById('parent-id').getElementsByClassName('test'))  //get all elements with class="test" inside the element with id="parent-id"
   /*
   <!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <div id="parent-id">
        <p>hello world 1</p>
        <p class="test">hello world 2</p>
        <p class="test">hello world 3</p>
        <p>hello world 4</p>
    </div>

    <script>
        const parentDOM = document.getElementById("parent-id");
        console.log(parentDOM.innerHTML); // <p>hello world 1</p><p class="test">hello world 2</p><p class="test">hello world 3</p><p>hello world 4</p>

        const test = parentDOM.getElementsByClassName("test"); // a list of matching elements as an object, *not* the element itself
        console.log(test); // HTMLCollection object

        const testTarget = parentDOM.getElementsByClassName("test")[0]; // the first element, as we wanted
        console.log(testTarget.innerHTML); // hello world 2
    </script>
</body>

</html>
   */

   //1.3 getElementsByTagName() is a method of the document object which returns a
   //collection of all elements in the document with the specified tag name,
   //as a NodeList object called HTMLCollection.
   console.log(document.getElementsByTagName('p')) //returns a collection of all <p> elements in the document
   console.log(document.getElementById('parent-id').getElementsByTagName('p')) //get all <p> elements inside the element with id="parent-id"

   //1.4 querySelector() is a method of the document object which returns the first element
   //that matches a specified CSS selector(s) in the document.
   console.log(document.querySelector('p')) //returns the first <p> element in the document
   console.log(document.querySelector('.test')) //returns the first element with class="test" in the document
   console.log(document.querySelector('#para1')) //returns the element with id="para1"
   console.log(document.querySelector('div p')) //returns the first <p> element that is a descendant of a <div> element

   //1.5 querySelectorAll() is a method of the document object which returns a static (not live)
   //NodeList representing a list of the document's elements that match the specified group of selectors.
   console.log(document.querySelectorAll('p')) //returns all <p> elements in the document
   console.log(document.querySelectorAll('.test')) //returns all elements with class="test" in the document
   console.log(document.querySelectorAll('#para1')) //returns the element with id="para1"
   console.log(document.querySelectorAll('div p')) //returns all <p> elements that are descendants of a <div> element

//2. Get or Set the content of HTML elements

   //<p id="para1">This is a <b style="display:none">paragraph</b>.</p>   

   //2.1 innerHTML is a property of the document object which sets or returns the HTML content (inner HTML) of an element.
   console.log(document.querySelector('#para1').innerHTML) //returns the content of the element having id="para1" including the HTML tags
                                                           //output on console: This is a <b style="display:none">paragraph</b>.
   document.querySelector('#para1').innerHTML = 'Hello World' //sets the content of the element with id="para1"

   //2.2 innerText is a property of the document object which sets or returns the text content of the specified node,
   //and all its descendants.
   console.log(document.querySelector('#para1').innerText) //returns the text content of the element having id="para1" avoiding the HTML tags and also the text content of the hidden elements
                                                           //output on console: This is a
   document.querySelector('#para1').innerText = 'Hello World' //sets the text content of the element with id="para1"
 
   //2.3 textContent is a property of the document object which sets or returns the text content of the specified node,
   //and all its descendants.
   console.log(document.querySelector('#para1').textContent) //returns the text content of the element having id="para1" avoiding the HTML tags but including the text content of the hidden elements
                                                             //output on console: This is a paragraph
   document.querySelector('#para1').textContent = 'Hello World' //sets the text content of the element with id="para1"

   //2.4 outerHTML is a property of the document object which sets or returns the HTML content (inner HTML) of an element.
   console.log(document.querySelector('#para1').outerHTML) //returns the content of the element having id="para1" including the HTML tags
                                                             //output on console: <p id="para1">This is a <b style="display:none">paragraph</b>.</p>
   document.querySelector('#para1').outerHTML = '<p id="para1">Hello World</p>' //sets the content of the element with id="para1"
   
//3. creating, adding, and removing elements to the DOM

   //createTextNode() is a method of the document object which creates a Text Node with the specified text.
   const node = document.createTextNode('Hello World') //creates a text node

   //createElement() is a method of the document object which creates an Element Node with the specified name.
   const para = document.createElement('p') //creates a <p> element
   para.textContent = 'Hello World' //sets the text content of the <p> element
   document.body.appendChild(para) //appends the <p> element to the document body

   //insertAdjacentHTML() is a method of the document object which parses the specified text as HTML or XML and inserts the resulting nodes into the DOM tree at a specified position.
   //position can be: "beforebegin", "afterbegin", "beforeend", or "afterend"
   const cont = document.querySelectorAll('.content')
   let node1 = document.createElement('p')
   node1.textContent = 'Beginning of the new me';
   cont.insertAdjacentHTML('beforebegin', node1); //inserts a <p> element before the element having class="content"
   document.querySelector('#para1').insertAdjacentHTML('afterbegin', node1) //inserts a <p> element after the start of the element having id="para1"

   //removeChild() is a method of the document object which removes a specified child node of the specified element.
   //we need to specify the parent node and the child node both
   const parentElement = document.querySelector('#parent-id')
   const childElement = document.querySelector('#para1')
   parentElement.removeChild(childElement) //removes the <p> element having id="para1" from the <div> element having id="parent-id"

   //remove() is a method of the document object which removes the element from the DOM.
   childElement.remove(); //removes the <p> element having id="para1" from the DOM

//4. Adding, removing and modifying css styles of elements

   //4.1 style is a property of the document object which sets or returns the value of the style attribute of an element.
   //we can set or return the value of one or more style properties of an element.
   const content = document.querySelectorAll('.content')
   content.style.cssText = 'color: red; font-size: 20px; background-color: light-blue' //sets the value of the style attribute of the element having class="content"
   content.style.color = 'red' //sets the color of the element having class="content"

   content.style.cssText = '' //removes all the styles of the element having class="content"

   //4.2 classList is a property of the document object which returns the class name(s) of an element, as a DOMTokenList object.
   //we can add, remove, toggle, or check if an element contains a specified class name.
   content.classList.add('red') //adds the class name "red" to the element having class="content"
   content.classList.remove('red') //removes the class name "red" from the element having class="content"
   content.classList.toggle('red') //toggles between adding and removing the class name "red" from the element having class="content"
   let x = content.classList.contains('red') //returns true if the element having class="content" contains the class name "red", otherwise false

   //4.3 className is DOM property that returns the class names of an element as string. 
   //we can add, remove, or toggle classes with className.
   let arr = content.className.trim().split();

   







