Introduction
============

This repo is part of the tutorial found in
the repo https://github.com/ActivisionGameScience/ags_conda_recipes.git

It builds a single C++ library, ``ags_blosc_wrapper``, that
is a dumb wrapper around the popular ``blosc`` compression
library (https://github.com/Blosc/c-blosc).

The purpose is to demonstrate several techniques:

- How to depend on external libraries (using ``conda``)
  and how to build against them (using ``cmake``)

- How to build both static and dynamic binaries 

- How to expose both a ``C++`` and ``C`` API using
  the *opaque pointers* technique

In turn, this project is used as a dependency for 
two other projects:

- https://github.com/ActivisionGameScience/ags_example_py_wrapper.git
  (a ``python`` wrapper around this library)

- https://github.com/ActivisionGameScience/ags_example_cpp_app.git
  (a ``C++`` application that uses this library)

The purpose of the ``C`` API (which is a simple wrapper around
the ``C++`` API) is to allow easy bindings to other languages
like the ``python`` wrapper listed above.
