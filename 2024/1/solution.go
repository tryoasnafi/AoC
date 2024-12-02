package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
	"strconv"
	"strings"
)

func abs(n int) int {
	if n < 0 {
		return n * -1
	}
	return n
}

const INPUT_1_PATH = "input.txt"
const INPUT_2_PATH = "input2.txt"

func distance() {
	file, err := os.Open(INPUT_1_PATH)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	left := []int{}
	right := []int{}
	for scanner.Scan() {
		d := strings.SplitN(scanner.Text(), " ", 4)
		l, _ := strconv.Atoi(d[0])
		r, _ := strconv.Atoi(d[len(d)-1])
		left = append(left, l)
		right = append(right, r)
	}
	slices.Sort(left)
	slices.Sort(right)
	result := 0
	for i := range left {
		result += abs(left[i] - right[i])
	}
	fmt.Println("solution 1:", result)
}

func similarity() {
	file, err := os.Open(INPUT_2_PATH)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	left := []int{}
	right := map[int]int{}
	for scanner.Scan() {
		d := strings.SplitN(scanner.Text(), " ", 4)
		l, _ := strconv.Atoi(d[0])
		r, _ := strconv.Atoi(d[len(d)-1])
		left = append(left, l)
		if _, ok := right[r]; !ok {
			right[r] = 1
		} else {
			right[r] += 1
		}
	}
	result := 0
	for i := range left {
		result += (left[i] * right[left[i]])
	}
	fmt.Println("solution 2:", result)
}

func main() {
	distance()
	similarity()
}
