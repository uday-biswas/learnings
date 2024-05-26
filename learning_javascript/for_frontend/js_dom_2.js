//browser events and the DOM
  //syntax for event-target => event-target.addEventListener(event, function, useCapture)
    //event-target => the element to attach the event handler to
    //event => a string that specifies the name of the event. Note: Do not use the "on" prefix. For example, use "click" instead of "onclick".
    //function => specifies the function to run when the event occurs. Note: Do not add "()" to the function name.
    //useCapture => Optional. A Boolean value that specifies whether the event should be executed in the capturing or in the bubbling phase.
                    //Possible values: true - The event handler is executed in the capturing phase. false- Default. The event handler is executed in the bubbling phase.

    //1. add event listener
    let content = document.querySelector('.content')   //event-target
    function bgchanger() {
        content.style.backgroundColor = 'lightblue'
    }
    content.addEventListener('click', bgchanger) //changes the background color of the element having class="content" to blue when clicked

    //types of events
    //1. mouse events
    //1.1 click - occurs when the user clicks on an element
    //1.4 mouseover - occurs when the pointer is moved onto an element or one of its children
    //1.5 mouseout - occurs when the pointer is moved out of an element or one of its children
    //1.6 mousedown - occurs when the pointer is pressed down over an element
    //1.7 mouseup - occurs when the pointer is released over an element
    //1.8 mousemove - occurs when the pointer is moving while it is over an element
    //1.9 dblclick - occurs when the user double-clicks on an element
    //1.10 contextmenu - occurs when the user right-clicks on an element to open the context menu
    //1.11 wheel - occurs when the mouse wheel rolls up or down over an element
    //1.12 drag - occurs when an element is dragged
    //1.13 dragend - occurs when the user has finished dragging the element
    //1.14 dragenter - occurs when the dragged element enters the drop target
    //1.15 dragleave - occurs when the dragged element leaves the drop target
    //1.16 dragover - occurs when the dragged element is over the drop target
    //1.17 dragstart - occurs when the user starts to drag an element
    //1.18 drop - occurs when the dragged element is dropped on the drop target
    //1.19 scroll - occurs when an element's scrollbar is being scrolled
    //1.20 select - occurs after the user selects some text (for <input> and <textarea>)
    //1.21 resize - occurs when an element is resized
    
    //2. keyboard events - occurs mostly on <input> and <textarea> elements on form.

    //2.1 keydown - occurs when a keyboard key is pressed down
    //2.2 keyup - occurs when a keyboard key is released
    //2.3 keypress - occurs when a keyboard key is pressed down and then released
    //2.4 input - occurs when the value of an <input> or <textarea> element is changed
    //2.5 change - occurs when the value of an <input>, <select>, or <textarea> element is changed
    //2.6 select - occurs after the user selects some text (for <input> and <textarea>)
    //2.6 submit - occurs when a form is submitted
    //2.7 focus - occurs when an element gets focus
    //2.8 blur - occurs when an element loses focus
    //2.9 cut - occurs when the user cuts the content of an element
    //2.10 copy - occurs when the user copies the content of an element
    //2.11 paste - occurs when the user pastes some content in an element
    //2.12 contextmenu - occurs when the user right-clicks on an element to open the context menu
    //2.13 compositionstart - occurs when the user starts to enter text
    //2.14 compositionend - occurs when the user is done entering text

    //4. window events - occurs on the window object
    //4.1 load - occurs when a page has finished loading
    //4.2 resize - occurs when the browser window is resized
    //4.3 scroll - occurs when the user scrolls in the specified element
    //4.4 unload - occurs once a page has unloaded (for <body>)
    //4.5 beforeunload - occurs before a page is unloaded (for <body>)
    //4.6 error - occurs when an error occurs while loading an external file (like an image)

    //5. media events - occurs on <audio> and <video> elements
    //5.1 abort - occurs when the loading of an audio/video is aborted
    //5.2 canplay - occurs when the browser can start playing the audio/video
    //5.3 canplaythrough - occurs when the browser can play through the audio/video without stopping for buffering
    //5.4 durationchange - occurs when the duration of the audio/video is changed
    //5.5 emptied - occurs when the current playlist is empty
    //5.6 ended - occurs when the audio/video has ended
    //5.7 error - occurs when an error occurred during the loading of an audio/video
    //5.8 loadeddata - occurs when media data is loaded

    //6. progress events - occurs when the browser is in the process of getting the media data (downloading the media)
    //6.1 loadstart - occurs when the browser starts looking for the specified audio/video
    //6.2 progress - occurs when the browser is downloading the specified audio/video
    //6.3 suspend - occurs when the browser is intentionally not getting media data
    //6.4 stalled - occurs when the browser is trying to get media data, but data is not available
    //6.5 waiting - occurs when the video stops because it needs to buffer the next frame


    //7. storage events - occurs when a Web Storage area is updated
    //7.1 storage - occurs when a Web Storage area is updated

    //8. history events - occurs when the browser's history changes
    //8.1 hashchange - occurs when there has been changes to the anchor part of a URL
    //8.2 popstate - occurs when the window's history changes

    //9. animation events - occurs when CSS animations are used
    //9.1 animationstart - occurs when a CSS animation has started
    //9.2 animationend - occurs when a CSS animation has completed
    //9.3 animationiteration - occurs when a CSS animation is repeated

    //10. transition events - occurs when CSS transitions are used
    //10.1 transitionstart - occurs when a CSS transition has started
    //10.2 transitionend - occurs when a CSS transition has completed
    //10.3 transitionrun - occurs when a CSS transition has started, and the styles are being changed

    ///2. event object
    //event object - contains properties and methods related to the event that occurred, like which element was clicked, which key was pressed, etc.
    //event object is passed as a parameter to the event listener function
    //event.target - returns the element that triggered the event.
    //event.type - returns the type of the event.
    //event.currentTarget - returns the element that triggered the event (the event does not have to occur on the element itself,
                            //it can occur on a descendant).
    //event.preventDefault() - prevents the default action of the event
    //event.stopPropagation() - prevents further propagation of the current event in the capturing and bubbling phases
    //event.stopImmediatePropagation() - prevents other listeners of the same event from being called
    

    //2. remove event listener
    //this will remove if the event-target, event, and function are same as the one added in the addEventListener() method
    content.removeEventListener('click', bgchanger) //removes the event listener from the element having class="content"

    //3. phases of event propagation
    //3.1 capturing phase - the event goes down to the element from the root element
    //3.2 in target phase - the event reaches the target element   
    //3.3 bubbling phase - the event bubbles up from the element to the root element

//below program will print the text content of the element that is clicked, by using the event target property
//event.target - returns the element that triggered the event.
//in the below program, the event listener is added to the article element, 
//but when we click on the paragraph element inside the article element, the event is triggered and its text content is printed
    
    /*
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>

    <body>
        <article id="wrapper">
            <p>this is inside para 1</p>
            <p>this is inside para 2</p>
            <p>this is inside para 3</p>
            <p>this is inside para 4</p>
        </article>
    
        <script>
            let content = document.querySelector('#wrapper')
            content.addEventListener('click', (event) => {
                console.log(event.target.textContent)
            })
        </script>
    </body>

    </html>
    */

//below program will print the text content of the span element 
//that is clicked inside the para element of article element, we will use target and nodeName property.
//event.target.nodeName - returns the name of the element that triggered the event.
//here only when we click on the span element inside the article element, the event is triggered and its text content is printed
    
    /*
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>

    <body>
        <article id="wrapper">
            <p>this is <span>span 1</span> inside para 1</p>
            <p>this is <span>span 2</span> inside para 2</p>
            <p>this is <span>span 3</span> inside para 3</p>
            <p>this is <span>span 4</span> inside para 4</p>
            <span>this is span 5</span>
        </article>

        <script>
            let content = document.querySelector('#wrapper')
            content.addEventListener('click', (event) => {
                if (event.target.nodeName === 'SPAN')
                    console.log(event.target.textContent)
            })
        </script>
    </body>

    </html>
    */

    //4. event prevent default
    //4.1 preventDefault() - prevents the default action of the event
    let link = document.querySelector('.link')
    link.addEventListener('click', function(event) {
        event.preventDefault()
    }) //prevents the default action of the link element - does not redirect to the link
     
    //4.2 stopPropagation() - prevents further propagation of the current event in the capturing and bubbling phases

