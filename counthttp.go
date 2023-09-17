package main

import (
	"fmt"
	"net/http"
	"sync"
)

var (
	count      int
	mu sync.Mutex
	done       = make(chan bool)
)

func main() {
	http.HandleFunc("/", handleRequest)
	go Server()
	<-done // Wait for counting to finish
	fmt.Printf("Total Requests: %d\n", count)
}

func Server() {
	fmt.Println("Server is running on :8080")
	http.ListenAndServe(":8080", nil)
}

func handleRequest(w http.ResponseWriter, r *http.Request) {
	go requestInc()
	fmt.Fprintf(w, "Hello, World!")
}

func requestInc() {
	mu.Lock()
	count++
	mu.Unlock()
}

func init() {
	go func() {
		for {

			mu.Lock()
			if count > 2{
				done <- true
				mu.Unlock()
				return
			}else{
				fmt.Println("Total requests: ", count)
			}
			mu.Unlock()
			//time.Sleep(3 * time.Second)
		}
	}()
}
