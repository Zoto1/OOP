### How to compile 
```bash
g++ -std=c++23 *.cpp ../DateInput/Date.cpp -o main
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
        +Date(int, int, int)
        +isValidDate(int, int, int) bool$
        +setDay(int) expected<void, string>
        +setMonth(int) expected<void, string>
        +setYear(int) expected<void, string>
        +toString() string
    }

    class Student {
        -string ID
        -string Fullname
        -string Address
        -string Email
        -Date DOB
        +setName(string) expected<void, string>
        +setID(string) expected<void, string>
        +setAddress(string) expected<void, string>
        +setEmail(string) expected<void, string>
        +setDOB(Date) expected<void, string>
        +toString() string
        +inputStudent() void
    }

    Student *-- Date : has
    
```
### Promt History
```bash
https://gemini.google.com/share/2390a51eab80
```
