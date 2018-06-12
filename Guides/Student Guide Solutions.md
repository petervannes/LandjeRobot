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
    
## Lesson 8, The Robot instructionset

### Assignment 1

    void setup() {        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10) ;        }    void loop() {        }
    
### Assignment 2

    void setup() {          landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);  
    }    void loop() {        }
    
### Assignment 3

    void setup() {         ## Voorbeeld 1      for (int k=1 ; k <=4 ; k++) {         landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;        landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      }         ## Voorbeeld 2      int k = 1 ;      while (k <= 4) {        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true) ;        landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);        k++ ;     }       }    void loop() {        }
    
### Assignment 4

hands on assignment, no specific solution

### Assignment 5

    void setup() {         landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;      }    void loop() {        if (landjerobot.detectLine() != LandjeRobot::LINE::NONE ) {        landjerobot.move(LandjeRobot::DIRECTION::STOP ) ;      }      }
    
### Assignment 6

    void setup() {          landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;      }    void loop() {        if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {          landjerobot.turn(LandjeRobot::TURN::LEFT,10,true) ;              }            if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {          landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true) ;        }            landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;          }      }


    
### Assignment 7

When the robot detects the a line with the left or right sensor. Then wait a short moment to see if the status of the line-detection sensor changes. When the robot arrives at the turn marker in a slightly slanting line the state of the sensor will change from `LandjeRobot::LINE::LEFT` or `LandjeRobot::LINE::RIGHT` to `
LandjeRobot::LINE::BOTH`. So when before taking action on the sensors output is waited for a fraction of a second, the turn marker will be detected correctly.

How this will be implemented is part of the next assignment. 




