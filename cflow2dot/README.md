# cflow3dot
This tool is intended to be used on c sources to give a graphical representations of the program's flow.

This is at a very embrional state

# Dependencies:
[cflow](https://www.gnu.org/software/cflow/)

[dot](http://www.graphviz.org/)

# Example usage:
Tris.c is one of the first programs I ever wrote, so i took it as an example of hard-to-read code
```sh
bash plot.sh Tris.c 
xdg-open Tris.c.dot.png
```

# Sample output:

![Just a sample](./Tris.dot.png)

