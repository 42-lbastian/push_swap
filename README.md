<h1 align="center"> push_swap </h1>
<h4 align="center"> Because Swap_push isn’t as natural </h4>

<h5 align="center">
  <a href="#description_id">Description</a> - 
  <a href="#algo_id">Sorting algorithm</a> - 
  <a href="#usage_id">Usage</a> - 
  <a href="#ressource_id">Ressource</a>
</h5>


---

<h2 id="description_id"> Description of the project: </h2>

The goal of this project is to sort a list of numbers using a set of instructions ans two stacks

We can use these instructions:

| Code  | Instruction                         | Action                                                                           |
| ----- | ----------------------------------- | ---------------------------------------------------------------------------------|
| `sa`  | swap a                              | Swap the first 2 elements at the top of stack a                                  |
| `sb`  | swap b                              | Swap the first 2 elements at the top of stack b                                  |
| `ss`  | swap a + swap b                     | `sa` & `sb`                                                                      |
| `pa`  | push a                              | Take the first element at the top of b and put it at the top of a                |
| `pb`  | push b                              | Take the first element at the top of a and put it at the top of b                |
| `ra`  | rotate a                            | Shift up all elements of stack a by 1; The first element becomes the last one    |
| `rb`  | rotate b                            | Shift up all elements of stack b by 1; The first element becomes the last one    |
| `rr`  | rotate a + rotate b                 | `ra` & `rb`                                                                      |
| `rra` | reverse rotate a                    | Shift down all elements of stack a by 1; The last element becomes the first one. |
| `rrb` | reverse rotate b                    | Shift down all elements of stack b by 1; The last element becomes the first one. |
| `rrr` | reverse rotate a + reverse rotate b | `rra` & `rrb`                                                                    |

The list to be sorted cannot contain duplicate numbers.

This programm print all intruction's code needed to sort the list

---

<h2 id="algo_id"> Sorting algorithm: </h2>

I used a **quicksort algorithm**, but I had to customize it to fit with the instructions provided in the subject.

---

<h2 id="usage_id"> Usage: </h2>

#### Compilation: (in the folder that contain the makefile)
```shell
make
```

#### How to run it:

```shell
./push_swap (list of numbers to sort)
```

You can generate a list of 100 numbers with this command (you can edit it to print more numbers):
```shell
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ') ; echo $ARG
```
and the copy the list of numbers printed by the command

```shell
./push_swap (paste the numbers)
```

You can also use the checker provided for this subject (it will tell you if the list is sorted):
```shell
./push_swap (paste the numbers) | checker_yourOS $ARG
```

---

<h2 id="ressource_id"> Ressource: </h2>

I use this video to understand how quicksort is working: <a href="https://www.youtube.com/watch?v=e_l77X9P1H4">Quicksort Demonstration With a Stack of Comics</a>
