package main

import (
	"fmt"
)

func main() {
	//pointers are used to store the address of a variable
	//declaration of pointers
	var a int = 10
	var b *int = &a //&a means address of a
	fmt.Println("the value of a is", a)
	fmt.Println("the address of a is", &a)
	fmt.Println("the value of b is", b)
	fmt.Println("the value at address b is", *b) //*b means value at address b
	//changing the value of a using b
	*b = 20
	fmt.Println("the value of a is", a)
	fmt.Println("the value at address b is", *b)
}
