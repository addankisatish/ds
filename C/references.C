REFERENCES:
----------

/*
 * References are less powerful than pointers.
 *
 * 1) Once a reference is created, it cannot be later made to reference another object.
 * 2) References cannot be NULL.
 * 3) A reference must be initialized when declared.
 *
 * Due to the above limitations, references in C++ cannot be used for implementing
 * data structures like linked list, tree etc.
 *
 * When we do pass arguments by reference or pointer ?
 *
 * 1) To modify local variables of the caller function.
 * 2) For passing large size arguments
 * 3) To avoid Object Slicing.
 * 4) To acheive run-time polymorphism ina function.
