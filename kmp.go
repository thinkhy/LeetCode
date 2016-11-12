package main
import (
   "fmt"
   "testing"
)

func strStr(str string, t string) int {
  if len(t) == 0 {
    return -1
  }

  step := make([]int, len(t))
  step[0] = -1
  for i := 1; i < len(t); i++ {
    j := i-1
    for j != -1 {
       if t[step[j]+1] == t[i] {
	  break
       }
       j = step[j]
    }
    if j == -1 {
	 step[i] = -1
    } else {
         step[i] = step[j]+1
    }
  }
  fmt.Println(step)

  var i, j int
  for i,j = 0, 0; i < len(str); {
    for i < len(str) && j < len(t) {
       fmt.Printf("[i: %d, j: %d]\n", i, j)
       if str[i] == t[j] {
          i++
	  j++
       } else if j > 0 {
          j = step[j-1]+1
       } else {
          break
       }
    }
    fmt.Printf(">>[i: %d, j: %d]\n", i, j)

    // not matched at current position
    if j == 0 {
       i++
    } else if j == len(t) {
      return i-len(t)
    } else {
      return -1
    }
  }

  return -1
}

func TestMain(t *testing.T) {
  testData := []struct {
                 s      string
		 target string
		 expect int
              }{ 
	       { s: "abccss", target: "css", expect: 3  },
	       { s: "abccsscscscscs", target: "cscscscs", expect: 6  },
	       { s: "abccss", target: "",    expect: -1  },
	       { s: "",       target: "abc", expect: -1  },
	       { s: "a",      target: "abc2", expect: -1  },
	       { s: "",       target: "", expect: -1  },
	       { s: "mississippi", target: "issipi", expect: -1  },
	      }

  for _, d := range testData {
	  result := strStr(d.s, d.target)
          fmt.Printf("Expected %d, got %d\n", d.expect, result)
	  if result != d.expect {
	     t.Fatalf("Expected %d, got %d\n", d.expect, result)
	  }
  }
}

func main() {
  tt := new(testing.T)
  TestMain(tt)


}
