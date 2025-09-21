


## 1. Linking Rule in Makefile

The line:

```makefile
$(TARGET): $(OBJECTS)
````

means that the final program (`$(TARGET)`) is made by combining all the object files (`$(OBJECTS)`) that were compiled from the source code.

**Difference from linking a library:** If we link a library, we also include pre-made code from outside (like `-lmylib`). Linking just object files uses only our own code.

---

## 2. Git Tags

A **git tag** is a name we give to a specific commit, usually to mark a version like `v1.0`.

**Why it is useful:**

* Shows a stable version of the project.
* Makes it easy to go back to that version.
* Helps others know which commit is an official release.

**Simple tag vs Annotated tag:**

* **Simple tag:** Just a name, no extra info.
* **Annotated tag:** Has extra info like author, date, and a message. Annotated tags are better for releases.

---

## 3. GitHub Releases

**Purpose:**

* Marks a stable version of the project.
* Makes it easy for others to find and download.

**Why attach binaries:**

* Users can download the program and run it without compiling.
* Makes sure everyone uses the same version.
* Good for people who are not developers.

```
