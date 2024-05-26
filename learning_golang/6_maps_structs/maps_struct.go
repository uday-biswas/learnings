package main

import (
	"fmt"
)

// structs are used to store multiple values of different types
type User struct { //declaration of struct
	name   string
	age    int
	status bool
}

func main() {
	//declaration of structs objects
	uday := User{"uday", 20, true}
	fmt.Println("the struct is", uday)

	//maps are used to store key value pairs
	//declaration of maps
	var a map[string]int //map of string keys and int values
	fmt.Println("the map is", a)
	//initialization of maps
	a = map[string]int{"a": 1, "b": 2, "c": 3}
	fmt.Println("the map is", a)
	//another way of declaring and initializing maps
	b := map[string]int{"a": 1, "b": 2, "c": 3}
	fmt.Println("the map is", b)
	//adding a key value pair to map
	b["d"] = 4
	fmt.Println("the map is", b)
	//deleting a key value pair from map
	delete(b, "d")
	fmt.Println("the map is", b)
	//checking if a key is present in map
	val, ok := b["d"]
	fmt.Println("the value is", val, "and the key is", ok)
	//checking if a key is present in map
	val1, ok1 := b["c"]
	fmt.Println("the value is", val1, "and the key is", ok1)
	//iterating over maps
	for key, value := range b {
		fmt.Println("the key is", key, "and the value is", value)
	}
}
