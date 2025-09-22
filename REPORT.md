# REPORT.md
**Project:** libmyutils — ROLL_NO-OS-A01  
**Name:** Hamna  
**Roll No:** BSDSF23M032  

---

## Part 1 — Project Scaffold
- Created repo with directories: `src/`, `include/`, `lib/`, `bin/`, `obj/`, `man/man3/`.
- Added `.gitignore` and initial commit.  
- No report questions for this feature.

---

## Part 2 — Multi-file build
- Implemented `.c` and `.h` files.  
- Used recursive Makefiles to compile multiple source files into `bin/client`.  
- Created annotated tag: **v0.1.1-multifile**.  

### Report Questions
**Q1. Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?**  
**A:** This rule means the executable depends on object files. When any object changes, `make` relinks to produce the target.  
When linking against a library, instead of listing all object files, we use flags `-L` and `-l`. Static libraries copy the code into the final binary; dynamic libraries only reference symbols, resolved later at runtime.  

**Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**  
**A:** A git tag marks a specific commit as important (e.g., a release). It’s useful for versioning and returning to stable states.  
- Simple (lightweight) tag = just a pointer to a commit.  
- Annotated tag = full object with author, date, and message. It’s better for official releases.  

**Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**  
**A:** GitHub Releases provide packaged, tested versions of code. Attaching binaries lets others run/test without rebuilding. It’s also proof that the project builds correctly at that tag.  

---

## Part 3 — Static library
- Built `lib/libmyutils.a` with `ar rcs`.  
- Linked `bin/client_static` using `-lmyutils`.  
- Created tag: **v0.2.1-static**.  

### Report Questions
**Q1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?**  
**A:** In Part 2, object files were linked directly into the executable. In Part 3, we introduced rules to build `libmyutils.a` using `ar` and `ranlib`. The client then links with `-L../lib -lmyutils`, instead of compiling all `.c` directly.  

**Q2. What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?**  
**A:** `ar` creates the archive `.a` from object files. `ranlib` indexes it, allowing faster symbol lookups during linking. Some systems require `ranlib` for the archive to be usable.  

**Q3. When you run `nm` on your client_static executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?**  
**A:** Yes, the symbols appear inside the executable. This shows that static linking copies the library code into the final binary, making it self-contained.  

---

## Part 4 — Dynamic library
- Built `lib/libmyutils.so` with `-fPIC -shared`.  
- Linked `bin/client_dynamic` using `-lmyutils`.  
- Ran program with `LD_LIBRARY_PATH`.  
- Created tag: **v0.3.1-dynamic**.  

### Report Questions
**Q1. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?**  
**A:** `-fPIC` ensures generated code can run at any memory address. Shared libraries may be loaded at different addresses, so they must not rely on absolute addresses.  

**Q2. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?**  
**A:** The static client is larger because it contains a copy of all library code. The dynamic client is smaller because the code stays in the `.so` file, loaded at runtime.  

**Q3. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?**  
**A:** `LD_LIBRARY_PATH` tells the dynamic loader where to look for shared libraries. We set it to `./lib` so the loader could find `libmyutils.so`. This shows that the OS loader is responsible for resolving library dependencies at runtime.  

---

## Part 5 — Man pages + Install
- Created `man/man3/mystrfunctions.3`.  
- Added `install` and `uninstall` rules in root Makefile.  
- Verified `man mystrfunctions` after installing.  
- Created tag: **v0.4.1-final**.  

---

## Commands I used to test
```bash
make clean
make multifile
./bin/client

make static
./bin/client_static
ar -t lib/libmyutils.a
nm -C bin/client_static | grep mystrlen

make dynamic
LD_LIBRARY_PATH=$(pwd)/lib ./bin/client_dynamic
ldd bin/client_dynamic

man -l man/man3/mystrfunctions.3

