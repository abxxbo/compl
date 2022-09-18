# Compl
COMPL is a graphing tool for the complex plane.

# Compilation
COMPL requires the following dependencies to be installed:
- raylib (see [Working on GNU Linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux))
- GNU GCC
- GNU Make

Once dependencies have been met, `make` will compile the program, and `make run`
will run.


# What is the Complex Plane?
Before we understand what the complex plane is, we must first
understand what a complex number is.

## Complex Numbers
Try to take the square root of -1. You can't. However, mathematicians
decided to call the result `i`, or `imaginary number`.


## Complex Plane
The complex plane is just like a graph, however the X axis is
known as the `Real` axis, and the Y axis is known as the `Imaginary`
axis.

<p align="center"><img src="https://www.mathsisfun.com/algebra/images/complex-plane.svg"></p>


<br>
<br>

# Basic COMPL Usage

## Plotting Points
To plot a point on the grid, you left click on the space you want to
place it on.
In the top right corner, you should see a list of all your points.

## Removing Points
To remove a point, hover the mouse over the point, and left-click the point.
It will be removed from the list of points as well as being unrendered.