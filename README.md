# SimpleCPU
Learning about C++ CPU emulation.

### Introduction
Hello, this is yet another experiment of mine!
<br>
In this project, I attempted to emulate a really, really simple processor.
<br>
As of right now, the processor does not support signed bytes, nor does it detect overflow and underflow.
But that is fine, as I was not even planning on adding it in the first place.
Perhaps I will add some more functions to this code in the future, but I doubt it.
I have learned a lot about CPUs in general, so I think that I have achieved the goal for this project.

### Sample program
```cpp
// Simple assembly program that computes 10 + 9 = 19:
ram.setInstruction(OpCode::STO, 10);	// Store the value 10 in register zero
ram.setInstruction(OpCode::MOV);        // Move the value of register zero to register one
ram.setInstruction(OpCode::STO, 9);     // Store the value 9 in register zero
ram.setInstruction(OpCode::ADD, 0);	// Add register zero to register one and store the result in register zero
ram.setInstruction(OpCode::PRT, 0);	// Print the contents of register zero
ram.setInstruction(OpCode::HLT);        // Exit the program
```
### Usage
You can use this code however you would like it to use. Credits would be nice, but I created this small project in a couple hours,
so I highly doubt any of this will be of any use to you. As I said, go ahead, use this code as you see fit!
