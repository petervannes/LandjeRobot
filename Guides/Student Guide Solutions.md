# Student Guide Solutions

## Lesson 3, variables

### Assignment 1

Create three variables and print the output

    /*
        */    void setup() {      Serial.begin(9600);      delay(2000);        String naam = "Peter"  ;      int waarde = 12 ;      boolean waarofniet = false ;      Serial.println(naam);      Serial.println(waarde);      Serial.println(waarofniet);    }    void loop() {        }## Lesson 4, comparing

### Assignment 1

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      String var1 = "abcd" ;          String var2 = "abcd" ;      String var3 = "efgh" ;      Serial.println(var1 == var2);      Serial.println(var1 == var3);    }    void loop() {    }
    
    
### Assignment 2  
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      String var1 = "abcd" ;          String var2 = "abcd" ;      String var3 = "efgh" ;      boolean uitkomst = var1 == var2 ;      Serial.println(var1 == var2);      Serial.println(var1 == var3);      Serial.println(uitkomst);    }    void loop() {    }