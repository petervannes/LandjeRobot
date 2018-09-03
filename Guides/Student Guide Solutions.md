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
    
## Lesson 9, Line Following   
    
### Assignment 1

    void setup() {          landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;      }    void loop() {        if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {          landjerobot.turn(LandjeRobot::TURN::LEFT,10,true) ;              }            if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {          landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true) ;        }            landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;          }      }


    
### Assignment 2

When the robot detects the a line with the left or right sensor. Then wait a short moment to see if the status of the line-detection sensor changes. When the robot arrives at the turn marker in a slightly slanting line the state of the sensor will change from `LandjeRobot::LINE::LEFT` or `LandjeRobot::LINE::RIGHT` to `
LandjeRobot::LINE::BOTH`. So when before taking action on the sensors output is waited for a fraction of a second, the turn marker will be detected correctly.

How this will be implemented is part of the next assignment. 


### Assignment 3

    void setup() {       // Start met rijden als de robot aangezet wordt en       // wacht niet       landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;      }    void loop() {      // Als er niet niets (!) gedetecteerd wordt door de       // reflectie sensors doe dan iets      if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            // wacht 30 milliseconden (0,03 seconde)        delay(30) ;            // Als beide reflectie sensors een lijn detecteren        if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {          // keer de robot om en wacht          landjerobot.turn(LandjeRobot::TURN::LEFT,180,true) ;        }            // Als de reflectie sensors links een lijn detecteren        if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {          // Draai 10 graden naar links en wacht          landjerobot.turn(LandjeRobot::TURN::LEFT,10,true) ;        }            // Als de reflectie sensors rechts een lijn detecteren        if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {          // Draai 10 graden naar rechts en wacht          landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true) ;        }            // Laat de robot weer verder rijden        landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;          } // einde if      }


### Assignment 4

```
int mode = 0 ;void setup() {  // "Lees" de stand van de mode schakelaar  mode = landjerobot.mode() ;  // Als schakelaar op "1" staat  if (mode == 1) {    // Start met rijden als de robot aangezet wordt en    // wacht niet    landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;  }  }void loop() {  // Als de schakelaar op "1" staat.  if (mode == 1) {    // Als er niet niets (!) gedetecteerd wordt door de     // reflectie sensors doe dan iets    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            // wacht 30 milliseconden (0,03 seconde)      delay(30) ;            // Als beide reflectie sensors een lijn detecteren      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {        // keer de robot om en wacht        landjerobot.turn(LandjeRobot::TURN::LEFT,180,true) ;      }            // Als de reflectie sensors links een lijn detecteren      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {        // Draai 10 graden naar links en wacht        landjerobot.turn(LandjeRobot::TURN::LEFT,10,true) ;      }            // Als de reflectie sensors rechts een lijn detecteren      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {        // Draai 10 graden naar rechts en wacht        landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true) ;      }            // Laat de robot weer verder rijden      landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;          } // einde if  } else {    // nieuwe programma  }  }
```


## Lesson 10, more sensors and motors

### Assignment 1


```
void setup() {    landjerobot.look(LandjeRobot::LOOK::FORWARD) ;}void loop() {    }
```

```
void setup() {    landjerobot.look(LandjeRobot::LOOK::FAR_LEFT) ;
    delay(2000);    landjerobot.look(LandjeRobot::LOOK::FORWARD) ;
    delay(2000);    landjerobot.look(LandjeRobot::LOOK::FAR_RIGHT) ;
}void loop() {    }
```

### Assignment 2

```
void setup() {     landjerobot.mouthOpen() ;   delay(5000);   landjerobot.mouthClosed();   delay(5000) ;      landjerobot.talk(10) ;    }
```

### Assignment 3

Sound travels at the speed of 343 m/sec. So when it takes 12 seconds to hear the echo, the sound has travelled 343 * 12 or 4116 meters. But the sound has to travel from you to the mountain and back again. Therefore the actual distance to the mountain is 4116 meters divided by 2. So the distance is 2058 meters or approximately 2 km.

### Assignment 4



```
void setup() {

    int afstand = 400 ;      Serial.begin(9600);    delay(2000);        // druk de gemeten afstand af zolang    // de afstand groter is dan 5 cm.    while (afstand > 5) {      afstand = landjerobot.measureDistance() ;      Serial.println(afstand) ;    }        // Laat de robot 10 seconden praten    landjerobot.talk(10) ;    }
```