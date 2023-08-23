### Using no reference (in parameter, function return or receiving variable in the caller)
* A) No compile or run time error
* B) If the object is heavy: takes more time and memory

---

### Using & saves time and memory BUT

* A) **As a function parameter**: if used & without const: you can't send temporary object => Compile error

* B) **As a return**: Never return & (or const &) for a local variable as it will be destroyed. This will cause RTE. The is the most   dangerous case, as others cause compile error.

* C) You can return & to data member as it won't be destroyed before the receiving variable. But better use const & to follow OO concepts as possible.

* D) **As a receiving variable**: You can't receive & for temporary object. Compile error.

* E) **As a receiving variable**: You can always receive const &, even for temporary object. No problem.
