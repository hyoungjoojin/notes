package main

import (
	"fmt"
	"time"
)

func say(s string) {
	for i := 0; i < 3; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func sum(array []int, channel chan int) {
	sum := 0
	for _, value := range array {
		sum += value
	}

	channel <- sum
}

func fibonacci(n int, channel chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		channel <- x
		x, y = y, x+y
	}
	close(channel)
}

func main() {
	// 1. Goroutines: Lightweight threads managed by the Go runtime.
	go say("Hello")
	say("World")

	// 2. Channels: Channels are typed conduits for sharing information.
	channel := make(chan int) // Channels are typed by chan
	array := []int{1, 2, 3, 4, 5, 6, 7, 8}
	go sum(array[:len(array)/2], channel) // Channels block by default, so locks aren't needed.
	go sum(array[len(array)/2:], channel)
	x, y := <-channel, <-channel // Channel sending and recieving are done by <-
	fmt.Println(x, y, x+y)

	// 3. Buffered Channels: Channels can be buffered. Overflow will cause the program to panic.
	channel = make(chan int, 2)
	channel <- 1
	channel <- 2
	fmt.Println(<-channel, <-channel)

	// 4. Closing Channels
	channel = make(chan int, 10)
	go fibonacci(cap(channel), channel)
	for i := range channel {
		fmt.Println(i)
	}
}
