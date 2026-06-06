### How to compile 
```bash
 g++ -std=c++23 *.cpp -o main
 ```
 ### How to run 
 ```bash
 ./main
 ```
 ### Class diagram
 ```mermaid
classDiagram
    class Date {
        -int day
        -int month
        -int year
        -Date(d: int, m: int, y: int)
        +Date()
        +setDay(newDay: int) expected~void, string~
        +setMonth(newMonth: int) expected~void, string~
        +setYear(newYear: int) expected~void, string~
        +setDate(d: int, m: int, y: int) expected~void, string~
        +getDay() int
        +getMonth() int
        +getYear() int
        +toString() string
        +isValidDate(d: int, m: int, y: int) bool$
        +inputDate() void
    }
```
### Promt History
```bash
https://gemini.google.com/share/4a8beae981fd
```
