This class solves Lorenz equations in R3 using the Runge-Kutta method (4th order), which typically is more accurate than Euler's method for solving ODE.

For more info:

http://introcs.cs.princeton.edu/java/94diffeq/

To use the class in your code, it's pretty straightforward- just include the header.

Note that you'll need an implementation of the Vec3f class. In the current code, we use Cinder's implementation (lines 29 & 30)- replace it with whatever you like.

Typically, you will use the class in a way similar to this:

``
LorenzSolver lorenzSolver= LorenzSolver(); //initialize the class
Vec3f p = Vec3f(0,10,0); //define the point's position at time t
lorenzSolver.setDelta(0.01f); //set the delta
lorenzSolver.computePoint(p); //compute the position of the point at time t+delta
``
