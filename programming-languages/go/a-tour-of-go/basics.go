// 1. Packages: Programs start running in package main.
package main

// 2. Imports: Use factored import statements.
import (
	"fmt"
	"math"
	"math/rand"
	"runtime"
	"time"
)

// 3. Functions: Types come after the variable name.
func random(x int) float64 {
	return math.Sqrt(float64(rand.Intn(x)))
}

// 3-1. Syntactic sugar: Two or more consecutive type names can be shortened into one.
func add(x, y int) int {
	return x + y
}

// 3-2. Returning muliple results
func swap(x, y string) (string, string) {
	return y, x
}

// 3-3. Named return values. Should only be used in short functions.
func split(sum float64) (x, y float64) {
	x = sum * 4 / 9
	y = sum - x
	return
}

// 4. Variables: Variables can be declared at the package level or function level.
var i, j, k int = 3, 4, 5

func variables() {
	var a int

	// 4-1. Short variable declaration: Only inside a function, the var keyword can be shortened.
	b := 10

	// Constants: Abbreviated syntax cannot be used with constants.
	const c = 20

	fmt.Println(a, b, c, i, j, k)
}

// 5. For loop
func for_loop(num_iterations int) int {
	sum := 0
	for i := 0; i < num_iterations; i++ {
		sum += i
	}

	// 5-1. While loops don't exist in Go.
	for sum < 1000 {
		sum += sum
	}

	for {
		// 6. If statements in Go
		if sum >= 0 {
			break
		}

		// 6-1: If statements can declare variables
		if value := int(math.Pow(2, 3)); sum > value {
			break
		} else if sum < value {
			continue
		} else {
			continue
		}
	}

	return sum
}

// 7. Switch statements: Break calls are not needed.
func switch_statement() {
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X")
	case "linux":
		fmt.Println("Linux")
	default:
		fmt.Println("Other")
	}

	fmt.Println("When's Saturday?")
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow.")
	case today + 2:
		fmt.Println("In two days.")
	default:
		fmt.Println("Too far away.")
	}

	// 7-1: Switch without a condition is just a cleaner if-else statement
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
}

// 8. Defer: Execution waits until the surrounding function returns.
func defer_statement() {
	defer fmt.Println("again")
	fmt.Println("Hello")

	// 8-1. Defer statements are executed in LIFO order.
	for i := 0; i < 4; i++ {
		defer fmt.Printf("%d", i)
	}
	defer fmt.Println("")
}

// 9. Pointers
func pointers() {
	var pointer *int

	i := 42
	pointer = &i

	fmt.Printf("%p points to %d\n", pointer, *pointer)
}

// 10. Structs
type Point struct {
	X int
	Y int
}

func structs() {
	point := Point{1, 2}
	fmt.Print(point)
	fmt.Printf(": %d %d", point.X, point.Y)

	// 10-1. Pointers have syntactic sugar for field access.
	point = Point{X: 1}
	pointer := &point
	fmt.Printf(" = %d %d", pointer.X, pointer.Y)
}

// 11. Arrays
func arrays() {
	var array [2]string
	array[0] = "Hello"
	array[1] = "World"
	fmt.Println(array[0], array[1])

	// 11-1. Slices are references to arrays that share data with arrays.
	primes := [6]int{2, 3, 5, 7, 11, 13}
	var slice []int = primes[1:4]
	fmt.Println(slice)
}

func main() {
	a, b := swap("world", "Hello")
	fmt.Println(a, b)

	fmt.Printf("Random numbers: ")
	fmt.Println(split(random(10) + random(20)))

	variables()
	for_loop(100)
	switch_statement()
	defer_statement()
	pointers()
	arrays()
}
