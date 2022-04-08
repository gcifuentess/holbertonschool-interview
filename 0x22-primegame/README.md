# 0x22. Prime Game

## Resources :books:
Read or watch:

---
## Learning Objectives :bulb:
What you should learn from this project:

---

## Links to Files :file_folder:

### [0. Prime Game](./0-prime_game.py)
* Maria and Ben are playing a game. Given a set of consecutive integers starting from 1 up to and including n, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

---

## Author
* **Gabriel Cifuentes** - [gcifuentess](https://github.com/gcifuentess)


---
---

# *HBTN PROJECT:*


Requirements
------------


### General


* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly `#!/usr/bin/python3`
* A `README.md` file, at the root of the folder of the project, is mandatory
* Your code should use the `PEP 8` style (version 1.7.x)
* All your files must be executable



Tasks
-----

###  0. Prime Game

Maria and Ben are playing a game. Given a set of consecutive integers starting from `1` up to and including `n`, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

* Prototype: `def isWinner(x, nums)`
* where `x` is the number of rounds and `nums` is an array of `n`
* Return: name of the player that won the most rounds
* If the winner cannot be determined, return `None`
* You can assume `n` and `x` will not be larger than 10000
* You cannot import any packages in this task


```
carrie@ubuntu:~/0x22-primegame$ cat main_0.py
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

carrie@ubuntu:~/0x22-primegame$

```
---
