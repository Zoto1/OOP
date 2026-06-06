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
    class Product {
        -string ID
        -string Name
        -Date ExpiryDate
        -float Price
        +Product()
        +setID(string) expected<void, string>
        +setName(string) expected<void, string>
        +setExpiryDate(Date) expected<void, string>
        +setPrice(float) expected<void, string>
        +getID() string
        +getName() string
        +getExpiryDate() Date
        +getPrice() float
        +toString() string
        +inputProduct() void
    }
    Product *-- Date : has a
```
### Promt History
```bash
https://gemini.google.com/share/1f74537b9dbd
```
