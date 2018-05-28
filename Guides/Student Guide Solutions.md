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
    ### Assignment 3  
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int groot = 2313 ;          int klein = 5 ;                Serial.println(klein > groot);      Serial.println(klein < groot);    }    void loop() {    }

### Assignment 4
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int groot = 2313 ;          int klein = 5 ;    
            Serial.println(klein > groot);      Serial.println(klein < groot);
      Serial.println(klein >= klein);
      Serial.println(groot <= groot);
      Serial.println(klein >= groot);
      Serial.println(groot <= klein);
    }    void loop() {    }### Assignment 5
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int groot = 2313 ;          int klein = 5 ;    
            Serial.println(klein > groot);      Serial.println(klein < groot);
      Serial.println(klein >= klein);
      Serial.println(groot <= groot);
      Serial.println(klein >= groot);
      Serial.println(groot <= klein);
      Serial.println(klein != klein);    
      Serial.println(klein != groot);              }    void loop() {    }
    
    
## Lesson 5, conditional statements

### Assignment 1

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int groot = 2313 ;          int klein = 5 ;                if (klein < groot) {        Serial.println("klein is kleiner dan groot") ;            }     }    void loop() {    }
    
### Assignment 2

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int groot = 2313 ;          int klein = 5 ;                if (klein < groot) {        Serial.println("klein is kleiner dan groot") ;            } else {
        Serial.println("klein is groter dan groot") ;      
      }    }    void loop() {    }    
    
## Lesson 6, Loops

### Assignment 1

Het juiste antwoord is 9x
    
    getal 1
    "Dit herhaal ik" 
    getal 2
    "Dit herhaal ik" 
    getal 3
    "Dit herhaal ik" 
    getal 4
    "Dit herhaal ik" 
    getal 5
    "Dit herhaal ik" 
    getal 6
    "Dit herhaal ik" 
    getal 7
    "Dit herhaal ik" 
    getal 8
    "Dit herhaal ik" 
    getal 9
    "Dit herhaal ik" 
    getal 10


### Assignment 2

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);        int grondtal = 3 ;      int exponent = 5 ;      int uitkomst = grondtal ;        for (int x=1 ; x<exponent ; x++) {        uitkomst = uitkomst * grondtal ;      }        Serial.println(uitkomst);        }    void loop() {        }
    
    
## Lesson 7, Debugging

### Assignment 1

### Assignment 2

    /*
    
    */
    
    void setup() {
      
      Serial.begin(9600);
      delay(2000);
      
      Serial.println("Gaat het wel goed?");
        
    }
    
    void loop() {
        
    }
    
    
### Assignment 3

#### Solution 1

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT) ;
      randomSeed(analogRead(A1)); 
  
      int getal = 10;
      Serial.println("start getal");
      Serial.println(getal);
  
      int teller = random(1, 10);
      Serial.println("start teller");
      Serial.println(teller);
      
      while (getal != teller) {
        Serial.println("teller");
        Serial.println(teller);
        teller++ ;
      }
  
      Serial.println("Klaar!");
    
    }

    void loop() {
        
    }

#### Solution 2

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT) ;
      randomSeed(analogRead(A1)); 
  
      int getal = 5;
      Serial.println("start getal");
      Serial.println(getal);
  
      int teller = random(1, 5);
      Serial.println("start teller");
      Serial.println(teller);
      
      while (getal != teller) {
        Serial.println("teller");
        Serial.println(teller);
        teller++ ;
      }
  
      Serial.println("Klaar!");
    
    }

    void loop() {
        
    }