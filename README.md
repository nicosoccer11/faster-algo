# faster-algo
This repo aims to enhance the performance of a simple algorithm through multiple iterations (learning project). 

## Problem Statement

Your device's communication system is correctly detecting packets but isn't fully operational. It needs to identify messages as well. A start-of-message marker consists of 14 distinct characters. Create an algorithm that finds the first marker after these 14 distinct characters to ensure proper message detection.

### Examples

```sh
# Test case 6
test6 = `mjqjpqmgbljsphdztnvjfqwrcgsmlb` // first marker after character 19

# Test case 7
test7 = `bvwbjplbgvbhsrlpgdmjqwftvncz` // first marker after character 23
```

## Performance Results

The following table summarizes the average execution time for each iteration of the algorithm:

| Iteration | Average Time (ms) |
|-----------|--------------------|
| 1         | 9.68704            |
| 2         | 1.21121            |
| 3         | 0.12921            |
| 4         | 0.02801            |
| 5         | 0.01635            |

### Improvement Percentages
The following improvements were observed in execution time:

- Improvement from Iteration 1 to Iteration 2: 87.50%
- Improvement from Iteration 1 to Iteration 3: 98.67%
- Improvement from Iteration 1 to Iteration 4: 99.71%
- Improvement from Iteration 1 to Iteration 5: 99.83%

## Source
All the credit for this goes to this video [link](https://www.youtube.com/watch?v=U16RnpV48KQ) by ThePrimeagen