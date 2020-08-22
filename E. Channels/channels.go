package main

import (
	"runtime"
	"sync"
)

/*
import (
	"fmt"
	"math/rand"
	"runtime"
	"sync"
	"time"
)
*/

//Glock global lock
var Glock sync.Mutex

//Merge2Channels sums the f-processed values from the in-channels and puts this sum into the out channel
func Merge2Channels(f func(int) int, in1 <-chan int, in2 <-chan int, out chan<- int, n int) {
	go func() {
		Glock.Lock()
		//fmt.Println("Lock")

		fx1 := make([]*int, n+1)
		go func() {
			for i := 0; i != n; i++ {
				x1 := <-in1
				//fmt.Println("x1 = ", x1)
				go func(i int) {
					tmpf1 := f(x1)
					fx1[i] = &tmpf1
					//fmt.Printf("fx1[%d] = %d\n", i, *fx1[i])
				}(i)
			}
		}()

		fx2 := make([]*int, n+1)
		go func() {
			for i := 0; i != n; i++ {
				x2 := <-in2
				//fmt.Println("x2 = ", x2)
				go func(i int) {
					tmpf2 := f(x2)
					fx2[i] = &tmpf2
					//fmt.Printf("fx2[%d] = %d\n", i, *fx2[i])
				}(i)
			}
		}()

		for i := 0; i != n; {
			if fx1[i] != nil && fx2[i] != nil {
				out <- (*fx1[i] + *fx2[i])
				i++
			}
			runtime.Gosched()
		}

		//fmt.Println("Unlock")
		Glock.Unlock()
	}()
}

/*
var s1 = rand.NewSource(time.Now().UnixNano())
var r1 = rand.New(s1)

func f(i int) int { // time consuming function
	time.Sleep(time.Duration(r1.Intn(i+1)) * time.Millisecond)
	return i

}

func main() {
	in1 := make(chan int)
	in2 := make(chan int)

	n := 200

	// Gatheing data
	results := []int{}
	go func() {
		for i := 0; i != 2*n; i += 2 {
			in1 <- i
			in2 <- i + 1
			results = append(results, i+i+1)
		}
	}()
	fmt.Println("Start")

	// Run test function
	out := make(chan int)

	Merge2Channels(f, in1, in2, out, n)
	Merge2Channels(f, in1, in2, out, n)
	Merge2Channels(f, in1, in2, out, n)
	Merge2Channels(f, in1, in2, out, n)
	Merge2Channels(f, in1, in2, out, n)

	// Check results
	var i int
	for v := range out {
		//fmt.Print(i, ": ")
		if v != results[i] {
			fmt.Print(v, "!=", results[i], " !!!!!!!!!!!!!!!!!!!!\n")
			//} else {
			//	fmt.Print(v, "==", results[i], "\n")
		}
		i++

		if i == n {
			break
		}
	}
	fmt.Println("Finish")

	close(in1)
	close(in2)
	close(out)
}
*/
