# :warning: under construction ...! :warning:

# Just some code challenges... O(n^n) >>>> O(1)

# Some requirements
To compile (choose at will):
- gcc 9.4
- clang

Just a suggestion to ease it up:
- Cmake 2.23
- Make 4.2

# Practical terms

For Makefile friendly people
```shell
make compile build run RUNNER_ARGS="--ch <challange_name> --sv <solver_name>"
```

(Recommended) Developing flow
1. Branch it out (or fork it up)
2. Do your stuff and open a PR
3. Await peer review and you've reached main!

If you want to add a new challenge
1. Create a new folder under src and add the challenge (similar cmakelists to the existing)
2. Link it to main in the cmakelists
3. Make it runnable from main (picking up the challenge_name)

If you want to add a new solver to an existing challenge
1. Create a new file and a function inside with the SAME NAME (will be important for ci)
2. Add your solver to the cmakelists
3. Add it to the function mappign at the beginning of the challenge and increment counter

# Current to do list
- [x] block commits to main and make branch PRs the only way to advance main
- [x] create the base main to run the challenges and time them
- [x] add the `anagram` challenge
- [ ] and solve it in many weird ways of course!
- [ ] improve a bit on cmake // make // and possibly adapt it to other builds
- [ ] make a github action to run a challenge on PR (we have free VM minutes!)
- [ ] add the "legacy" `sentence_word_inversion` challenge
- [ ] make super unsafe main that executes functions with user input
 