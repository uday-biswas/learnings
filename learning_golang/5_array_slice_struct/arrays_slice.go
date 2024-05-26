package main

import (
	"fmt"
	"sort"
)

func main() {
	//arrays are used to store multiple values of same type
	//declaration of arrays
	var a [5]int //array of size 5
	fmt.Println("the array is", a)
	//initialization of arrays
	a[0] = 10
	a[1] = 20
	a[2] = 30
	a[3] = 40
	a[4] = 50
	fmt.Println("the array is", a)
	//another way of declaring and initializing arrays
	var b = [5]int{10, 20, 30, 40, 50}
	fmt.Println("the array is", b)
	//another way of declaring and initializing arrays
	var c = [...]int{10, 20, 30, 40, 50}
	fmt.Println("the array is", c)
	//another way of declaring and initializing arrays
	var d = [...]int{1: 10, 2: 20, 3: 30, 4: 40, 5: 50}
	fmt.Println("the array is", d)
	//another way of declaring and initializing arrays
	var e = [...]int{0: 10, 4: 50}
	fmt.Println("the array is", e)

	elen := len(e) //length of array
	fmt.Println("the length of array e is", elen)

	//slices are used to store multiple values of same type
	//declaration of slices
	var f = []int{10, 20, 30, 40, 50} //slice of size 5
	fmt.Println("the slice is", f)
	f = append(f, 10) //adding an element at the end of slice
	fmt.Println("the slice is", f)
	f = append(f[1:]) //removing the first element of slice
	fmt.Println("the slice is", f)
	f = append(f[0 : len(f)-1]) //removing the last element of slice. the right index is exclusive
	fmt.Println("the slice is", f)

	//slices with make function
	var g = make([]int, 4) //slice of size 4
	g[0] = 64
	g[1] = 31
	g[2] = 58
	g[3] = 40
	fmt.Println("the slice is", g)
	g = append(g, 50) //adding an element at the end of slice

	//sorting the slice
	sort.Ints(g)
	fmt.Println("the slice is", g)

	//removing an element from slice
	index := 2
	g = append(g[:index], g[index+1:]...) //removing the element at index 2
	fmt.Println("the slice is", g)
}
