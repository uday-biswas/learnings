package main

import (
	"fmt"
	"time"
)

func main() {
	presentTime := time.Now()
	fmt.Println("The time is", presentTime)
	//formatting the time
	fmt.Println("The time is", presentTime.Format("01-02-2006 15:04:05 Monday"))
	//adding 10 hours to the present time
	futureTime := presentTime.Add(time.Hour * 10)
	fmt.Println("The time after 10 hours will be", futureTime)
	//creating a custom time
	customTime := time.Date(2024, time.January, 1, 12, 0, 0, 0, time.UTC) //year, month, day, hour, minute, second, nanosecond, timezone
	fmt.Println("The custom time is", customTime.Format("01-02-2006 15:04:05 Monday"))
}
