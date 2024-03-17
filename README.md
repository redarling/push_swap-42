# 🚀 Push Swap

## Project Description
Push Swap is a project that implements a stack sorting algorithm. The main task of the project is to sort an array of integers using a limited set of operations on two stacks.

## 🛠️ Installation Instructions
1. Clone the repository using the command:
   
      https://github.com/redarling/Push_Swap-42.git

2. Navigate to the project directory:

      cd Push_Swap-42 

3. Compile the project:

      make

## 💻 Usage
1. Run the program using the command:

      ./push_swap num1 num2 num3 ...

2. Example usage:

      ./push_swap 4 2 7 1 3 -1 -5 10 0

3. The program will output the sequence of operations required to sort the numbers.

## 📄 Operations Explanation
| Operation | Explanation                                 |
|-----------|---------------------------------------------|
| sa        | Swap the first two elements at the top of stack a. |
| sb        | Swap the first two elements at the top of stack b. |
| ss        | sa and sb at the same time.                  |
| pa        | Push the first element at the top of stack a to stack b. |
| pb        | Push the first element at the top of stack b to stack a. |
| ra        | Rotate stack a towards the top. The first element becomes the last one. |
| rb        | Rotate stack b towards the top. The first element becomes the last one. |
| rr        | ra and rb at the same time.                  |
| rra       | Reverse rotate stack a. The last element becomes the first one. |
| rrb       | Reverse rotate stack b. The last element becomes the first one. |
| rrr       | rra and rrb at the same time.                |

## 📝 Author
- [asyvash](https://github.com/redarling)
