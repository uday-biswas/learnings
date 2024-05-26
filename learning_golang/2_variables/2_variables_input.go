package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	//variable types in go - int, float, string, bool
	//declaration of variables - var <variable_name> <variable_type> = <value>
	//var means variable can be modified , but const variable cannot be modified.
	var age int = 20
	var weight float32 = 65.5
	var name string = "John Doe"
	var isMarried bool = false
	fmt.Print("my name is ", name, " and my age is ", age, " and my weight is ", weight, " and my marital status is ", isMarried, "\n")

	//implicit type declaration
	var age1 = 20 //go will automatically detect the type of variable
	fmt.Print("my age is ", age1, "\n")

	//taking input from user
	reader := bufio.NewReader(os.Stdin) //creating a reader object
	fmt.Print("Enter your name: ")
	name1, _ := reader.ReadString('\n') //reading the input from user
	fmt.Print("Enter your age: ")
	age2, _ := reader.ReadString('\n') //reading the input from user
	fmt.Print("my name is ", name1, " and my age is ", age2, "\n")

	//conversion of variables from string to int, float, bool
	rating, err := strconv.ParseFloat(strings.TrimSpace(age2), 64) //converting string to float
	if err != nil {
		fmt.Println("the error is: ", err)
	} else {
		rating += 1.5
		fmt.Print("my name is ", name1, " and my age is ", rating, "\n")
	}

	//similarly we can convert string to int and bool using strconv.ParseInt and strconv.ParseBool
}
