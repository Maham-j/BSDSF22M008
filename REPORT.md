# Report for Static Library Build

## 1. Differences Between Makefile in Part 2 and Part 3
- **Part 2 (Multifile Build):**
  - Compiled all `.c` files directly into object files and linked them together to make the executable.
  - No static library was used.
  - Simpler Makefile.

- **Part 3 (Static Library Build):**
  - Utility `.c` files are first compiled into `.o` files.
  - These `.o` files are bundled into a static library `libmyutils.a` using `ar`.
  - The main program links with this library using the `-lmyutils` flag.
  - Makefile now has extra rules for creating and linking the static library.

---

## 2. Purpose of `ar` and `ranlib`
- **`ar`**:
  - Combines multiple `.o` files into a single static library `.a`.
  - Example:  
    ```
    ar rcs lib/libmyutils.a obj/myfilefunctions.o obj/mystrfunctions.o
    ```
  - Flags:
    - `r` → Replace or add files
    - `c` → Create library if it doesn't exist
    - `s` → Create index for fast symbol lookup

- **`ranlib`**:
  - Creates an index in the library to help the linker find symbols quickly.
  - Modern `ar rcs` already includes this step, so `ranlib` is optional.

---

## 3. Static Linking with `nm`
- Running `nm bin/client_static` shows functions like `mystrlen` inside the executable.
- This proves **static linking**, where:
  - Code from the library is **copied into the final executable**.
  - The program **does not need the `.a` file** at runtime because everything is included at compile time.
