# Generic Algorithms

**The library containers define a surprisingly small set of operations.**
**Rather than adding lots of functionality to each container, the library provides a set of algorithms**.
**most of which are independent of any particular container type. These algorithms are generic:**
> They operate on different types of containers and on elements of various types.

**Rather than define each of these operations as members of each container type, the standard library defines a set of generic algorithms:**
> “algorithms” because they implement common classical algorithms such as sorting and searching.

> “generic” because they operate on elements of differing type and across multiple container types—not only library types such as vector or list, but also the built-in array type —and, as we shall see, over other kinds of sequences as well.

### Iterators Make the Algorithms Container Independent

### Algorithms Never Execute Container Operations
**The generic [algorithms](algorithms.md) do not themselves execute container operations. They operate solely in terms of iterators and iterator operations.**
**Because of that, algorithms never change the size of the underlying container.**

**It is up to us to ensure that the algorithm will not attempt to access a nonexistent element in the second sequence when passing the iterators to algorithms**
