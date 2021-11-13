# stonk
An unintentionally slightly confusing `stak` based language

For a rough idea for how it looks like here's some examples:
1. Hello, world!
```hs
@main {Hello, world!} puts;
```
or
```hs
@main 'Hello, .world puts;
```
2. Factorial
```hs
@main '5 factorial puts;

@factorial
 dup
 '1 =
 {pop}
 {
  pop dup '1 -n factorial
  *n
 }
 if
;
```
or the same thing golfed
```hs
@main '5 f puts;@f dup '1 = {pop} {pop dup '1 -n f *n} if;
```

## how to actually run stonk
1. Download all of the files in the repo (except the "r" executable, which is for testing)
2. Run this on your terminal (requires g++)
   ```sh
   g++ main.cpp -std=c++11 -o stonk
   ```
3. Now run the compiled executable:
    ```
    ./stonk yourfile.stonk
    ```
