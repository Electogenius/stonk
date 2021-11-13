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