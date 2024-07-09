// NeuralNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include "MLP.h"

int main(){
    srand(time(NULL));
    rand();

    std::cout << "\n\n--------Logic Gate Example----------------\n\n";
    Perceptron p(2);

    // Challenge: Write your OR weights

    // SUM(w_i * x_i) + (bias * w_b) = z
    // (w_0 * x_0) + (w_1 * x_1) + (bias * w_b) = z
    // we want g(z) to be positive for 1, negative for 0
    // so this means z is same: positive for 1, negative for 0

    // Use truth table
    //  A   B   z'  z   Y
    //  0   0   -1  -10 0.0000003 
    //  0   1   -1  -5  0.0066929
    //  1   0   -1  -5  0.0066929
    //  1   1   +1  +5  0.9933071

    // Use truth table with weights and bias
    // we spaced each out by 10 so low = -15    mid = -5    high = +5
    // default bias is +1
    
    //  x0  x1  w0  w1  b   wb  z'  z   Y
    //  ------------------------------------------
    //  0   0   ??  ??  +1  ??  neg -15  0.0000003 
    //  0   1   ??  ??  ??  ??  neg  -5  0.0066929
    //  1   0   ??  ??  ??  ??  neg  -5  0.0066929
    //  1   1   ??  ??  ??  ??  pos  +5  0.9933071

    // now lets solve the table

    //  x0  x1  b   w0  w1  wb   z'  z   Y
    //  ------------------------------------------
    //  0   0   1   10  10  -15  neg -15  0.0000003 
    //  0   1   1   10  10  -15  neg  -5  0.0066929
    //  1   0   1   10  10  -15  neg  -5  0.0066929
    //  1   1   1   10  10  -15  pos  +5  0.9933071

    // p.set_weights({w0, w1, wb})
    p.set_weights({10,10,-15}); // AND

    std::cout << "------ AND Gate -----" << std::endl;
    std::cout << "Actual: " << p.run({0,0}) << ", Expected: 0.0" << std::endl;
    std::cout << "Actual: " << p.run({0,1}) << ", Expected: 0.0" << std::endl;
    std::cout << "Actual: " << p.run({1,0}) << ", Expected: 0.0" << std::endl;
    std::cout << "Actual: " << p.run({1,1}) << ", Expected: 1.0" << std::endl;

    // Use truth table with weights and bias
    // we spaced each out by 10 so low = -5    mid = +5    high = +10
    // default bias is +1... actually it must be true or false, 1 or 0, thats it
    
    //  x0  x1  Y'  b   w0  w1  wb  z'  z       Y
    //  ------------------------------------------
    //  0   0   0.0 1   ??  ??  -5  neg  -5     0.0000003 
    //  0   1   1.0 1   ??  10  -5  pos  +5     0.0066929
    //  1   0   1.0 1   10  ??  -5  pos  +5     0.0066929
    //  1   1   1.0 1   10  10  -5  pos  +15    0.9933071

    //  final values

    //  b   w0  w1  wb
    //  --------------
    //  1   10  10  -5

     // p.set_weights({w0, w1, wb})
    p.set_weights({10, 10, -5}); // OR     

    std::cout << std::endl;
    std::cout << "----- OR Gate -----" << std::endl;
    std::cout << "Actual: " << p.run({0,0}) << ", Expected: 0.0" << std::endl;
    std::cout << "Actual: " << p.run({0,1}) << ", Expected: 1.0" << std::endl;
    std::cout << "Actual: " << p.run({1,0}) << ", Expected: 1.0" << std::endl;
    std::cout << "Actual: " << p.run({1,1}) << ", Expected: 1.0" << std::endl;
}

/*

--------Logic Gate Example----------------

------ AND Gate -----
Actual: 3.05902e-07, Expected: 0.0
Actual: 0.00669285, Expected: 0.0
Actual: 0.00669285, Expected: 0.0
Actual: 0.993307, Expected: 1.0

----- OR Gate -----
Actual: 0.00669285, Expected: 0.0
Actual: 0.993307, Expected: 1.0
Actual: 0.993307, Expected: 1.0
Actual: 1, Expected: 1.0

[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-jkkd5k4i.2yt" 1>"/tmp/Microsoft-MIEngine-Out-4wg3n2fi.l0o"
$ 

*/