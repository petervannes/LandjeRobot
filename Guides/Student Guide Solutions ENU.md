# Student Guide Solutions

## Lesson 3, variables

### Assignment 1

Create three variables and print the values

    /*
        */    void setup() {      Serial.begin(9600);      delay(2000);        String name = "Peter" ;      int value = 12;      boolean trueorfalse = false;      Serial.println(name);      Serial.println(value);      Serial.println(trueorfalse);    }    void loop() {        }## Lesson 4, comparing

### Assignment 1

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      String var1 = "abcd";          String var2 = "abcd";      String var3 = "efgh";      Serial.println(var1 == var2);      Serial.println(var1 == var3);    }    void loop() {    }
    
    
### Assignment 2  
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      String var1 = "abcd";          String var2 = "abcd";      String var3 = "efgh";      boolean outcome = var1 == var2;      Serial.println(var1 == var2);      Serial.println(var1 == var3);      Serial.println(outcome);    }    void loop() {    }
    ### Assignment 3  
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int large = 2313;          int small = 5;                Serial.println(small > large);      Serial.println(small < large);    }    void loop() {    }

### Assignment 4
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int large = 2313;          int small = 5;    
            Serial.println(small > large);      Serial.println(small < large);
      Serial.println(small >= small);
      Serial.println(large <= large);
      Serial.println(small >= large);
      Serial.println(large <= small);
    }    void loop() {    }### Assignment 5
    
    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int large = 2313;          int small = 5;    
            Serial.println(small > large);      Serial.println(small < large);
      Serial.println(small >= small);
      Serial.println(large <= large);
      Serial.println(small >= large);
      Serial.println(large <= small);
      Serial.println(small != small);    
      Serial.println(small != large);              }    void loop() {    }
    
    
## Lesson 5, conditional statements

### Assignment 1

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int large = 2313;          int small = 5;                if (small < large) {        Serial.println("small is smaller than large");            }     }    void loop() {    }
    
### Assignment 2

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);      int large = 2313;          int small = 5;                if (small < large) {        Serial.println("small is smaller than large");            } else {
        Serial.println("small is larger than large");      
      }    }    void loop() {    }    
    
## Lesson 6, Loops

### Assignment 1

The correct answer is 9x
    
    getal 1
    "I do repeat this" 
    getal 2
    "I do repeat this" 
    getal 3
    "I do repeat this" 
    getal 4
    "I do repeat this" 
    getal 5
    "I do repeat this" 
    getal 6
    "I do repeat this" 
    getal 7
    "I do repeat this" 
    getal 8
    "I do repeat this" 
    getal 9
    "I do repeat this" 
    getal 10


### Assignment 2

    /*    */    void setup() {      Serial.begin(9600);      delay(2000);        int base = 3;      int exponent = 5;      int outcome = base;        for (int x=1; x<exponent; x++) {        outcome = outcome * base;      }        Serial.println(outcome);        }    void loop() {        }
    
    
## Lesson 7, Debugging

### Assignment 1

### Assignment 2

    /*
    
    */
    
    void setup() {
      
      Serial.begin(9600);
      delay(2000);
      
      Serial.println("Is it going well?");
        
    }
    
    void loop() {
        
    }
    
    
### Assignment 3

#### Solution 1

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT);
      randomSeed(analogRead(A1)); 
  
      int getal = 10;
      Serial.println("start number");
      Serial.println(number);
  
      int counter = random(1, 10);
      Serial.println("start counter");
      Serial.println(counter);
      
      while (number != counter) {
        Serial.println("counter");
        Serial.println(counter);
        counter ++;
      }
  
      Serial.println("Finished !");
    
    }

    void loop() {
        
    }

#### Solution 2

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT);
      randomSeed(analogRead(A1)); 
  
      int number = 5;
      Serial.println("start number");
      Serial.println(number);
  
      int counter = random(1, 5);
      Serial.println("start counter");
      Serial.println(counter);
      
      while (number != counter) {
        Serial.println("counter");
        Serial.println(counter);
        counter ++;
      }
  
      Serial.println("Finished !");
    
    }

    void loop() {
        
    }
    
## Lesson 8, The Robot instructionset

### Assignment 1

    void setup() {        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10);        }    void loop() {        }
    
### Assignment 2

    void setup() {          landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);      landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      
    }    void loop() {        }
    
### Assignment 3

    void setup() {         ## Example 1      for (int k=1; k <=4; k++) {         landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);        landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);      }         ## Example 2      int k = 1;      while (k <= 4) {        landjerobot.move(LandjeRobot::DIRECTION::FORWARD,10,true);        landjerobot.turn(LandjeRobot::TURN::LEFT,90,true);        k++;     }       }    void loop() {        }
    
### Assignment 4

Hands on assignment, no specific solution

### Assignment 5

    void setup() {         landjerobot.move(LandjeRobot::DIRECTION::FORWARD);      }    void loop() {        if (landjerobot.detectLine() != LandjeRobot::LINE::NONE ) {        landjerobot.move(LandjeRobot::DIRECTION::STOP );      }      }
    
## Lesson 9, Line Following   
    
### Assignment 1

    void setup() {          landjerobot.move(LandjeRobot::DIRECTION::FORWARD);      }    void loop() {        if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {          landjerobot.turn(LandjeRobot::TURN::LEFT,10,true);              }            if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {          landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true);        }            landjerobot.move(LandjeRobot::DIRECTION::FORWARD);          }      }


    
### Assignment 2

When the robot detects the a line with the left or right sensor. Then wait a short moment to see if the status of the line-detection sensor changes. When the robot arrives at the turn marker in a slightly slanting line the state of the sensor will change from `LandjeRobot::LINE::LEFT` or `LandjeRobot::LINE::RIGHT` to `
LandjeRobot::LINE::BOTH`. So when before taking action on the sensors output is waited for a fraction of a second, the turn marker will be detected correctly.

How this will be implemented is part of the next assignment. 


### Assignment 3

    void setup() {       // Start moving when the robot is switched on,       // do not wait       landjerobot.move(LandjeRobot::DIRECTION::FORWARD);      }    void loop() {      // If there is not nothing (!) detected by the
      // reflection sensors, then do something      if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            // wait 30 milliseconds (0,03 second)        delay(30);    
        // When both reflection sensors do detect a line        if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {          // turn the robot around and wait for completion          landjerobot.turn(LandjeRobot::TURN::LEFT,180,true);        }    
        // When the reflection sensors do detect a line on the left        if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {          // Turn 10 degrees to the left and wait for completion
          landjerobot.turn(LandjeRobot::TURN::LEFT,10,true);        }    
        // When the reflection sensors do detect a line on the right        if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {          // Turn 10 degrees to the right and wait for completion
          landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true);        }            // Let the robot continue moving forward        landjerobot.move(LandjeRobot::DIRECTION::FORWARD);          } // end if      }


### Assignment 4

```
int mode = 0;void setup() {  // read the mode-switch state  mode = landjerobot.mode();  // If the switch has state "1"   if (mode == 1) {
    // Start moving forward when the robot is switched on
    // and do not wait for completion of the instruction    landjerobot.move(LandjeRobot::DIRECTION::FORWARD);  }  }void loop() {  // If the switch has state "1"   if (mode == 1) {    // If there is not nothing (!) detected by the
    // reflection sensors, then do something    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            // wait 30 milliseconds (0,03 second)      delay(30);            // When both reflection sensors do detect a line      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {        // turn the robot around and wait for completion
          landjerobot.turn(LandjeRobot::TURN::LEFT,180,true);      }            // When the reflection sensors do detect a line on the left      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {        // Turn 10 degrees to the left and wait for completion        landjerobot.turn(LandjeRobot::TURN::LEFT,10,true);      }            // When the reflection sensors do detect a line on the right      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {        // Turn 10 degrees to the right and wait for completion        landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true);      }            // Let the robot continue moving forward      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);          } // end if  } else { // If the switch has state "2"   }  }
```


## Lesson 10, more sensors and motors

### Assignment 1


```
void setup() {    landjerobot.look(LandjeRobot::LOOK::FORWARD);}void loop() {    }
```

```
void setup() {    landjerobot.look(LandjeRobot::LOOK::FAR_LEFT);
    delay(2000);    landjerobot.look(LandjeRobot::LOOK::FORWARD);
    delay(2000);    landjerobot.look(LandjeRobot::LOOK::FAR_RIGHT);
}void loop() {    }
```

### Assignment 2

```
void setup() {     landjerobot.mouthOpen();   delay(5000);   landjerobot.mouthClosed();   delay(5000);      landjerobot.talk(10);    }
```

### Assignment 3

Sound travels at the speed of 343 m/sec. So when it takes 12 seconds to hear the echo, the sound has travelled 343 * 12 or 4116 meters. But the sound has to travel from you to the mountain and back again. Therefore the actual distance to the mountain is 4116 meters divided by 2. So the distance is 2058 meters or approximately 2 km.

### Assignment 4


```void setup() {

    int distance = 400;      Serial.begin(9600);    delay(2000);    
    // Print de measured distance as long as
    // the distance is larger than 5cm.    while (distance > 5) {      distance = landjerobot.measureDistance();      Serial.println(distance);    }        // Make the robot talk for 10 seconds
    landjerobot.talk(10);    }
```



## Lesson 11, A new program

### Assignment 1

Solution is;

* If the left sensor detects a line move 10cm backward, then turn 45 degrees right. Continue driving forward.
* If the right sensor detects a line move 10cm backward, then turn 45 degrees left. Continue driving forward.
* If the both sensors detect a line move 10cm backward, then turn 180 degrees left. Continue driving forward.

### Assignment 2

The robot must start moving forward when the mode switch is set to mode "2" and switched on. So in the function ```setup()``` and instruction has to be added to make the robot moving forward.

This can be accomplished in two ways. First by adding an if statement which will make the robot move forward in mode 2.

```
void setup() {  // read the mode-switch state  mode = landjerobot.mode();  // If the switch has state "1"   if (mode == 1) {    // Start moving forward when the robot is switched on
    // and do not wait for completion of the instruction    landjerobot.move(LandjeRobot::DIRECTION::FORWARD);  } else {
    // If the switch has state "2" 
    // Start moving forward when the robot is switched on
    // and do not wait for completion of the instruction
    landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
  }  }
```

The same result can be accomplished by removing some lines of code from the existing code. Regardless of the state of the mode switch the robot has to start moving forward. There is no specific reason 

```
void setup() {  // read the mode-switch state  mode = landjerobot.mode();  // Start moving forward when the robot is switched on
  // and do not wait for completion of the instruction  landjerobot.move(LandjeRobot::DIRECTION::FORWARD);  }
```

### Assignment 3

This is a basic working example to make the robot stay within the lines. 

```
    // If there is not nothing (!) detected by the
    // reflection sensors, then do something    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {            // wait 30 milliseconds (0,03 second)      delay(30);            // When both reflection sensors do detect a line      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {        // turn the robot around and wait for completion
          landjerobot.turn(LandjeRobot::TURN::LEFT,180,true);      }            // When the reflection sensors do detect a line on the left      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {        // Turn 10 degrees to the left and wait for completion        landjerobot.turn(LandjeRobot::TURN::LEFT,10,true);      }            // When the reflection sensors do detect a line on the right      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {        // Turn 10 degrees to the right and wait for completion        landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true);      }            // Let the robot continue moving forward      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);          } // end if
```

Using the basic code, the robot may end in an endless loop, repeating the same movements over and over again. Most certainly this will occur when the robot ends up in a corner of the drawn rectangle. Adding some randomness whill resolve this issue.

```
    // If there is not nothing (!) detected by the
    // reflection sensors, then do something
    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {
    
      // wait 30 milliseconds (0,03 second)
      delay(30);
    
      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, random(20,90), true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, random(20,90), true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, random(160,200), true);
      }
      
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    }
```

### Assignment 4

```
void setup() {

  // read the mode-switch state
  mode = landjerobot.mode();

  // Make the robot look forward
  landjerobot.look(LandjeRobot::LOOK::FORWARD);
  
  // Start moving forward when the robot is switched on
  // and do not wait for completion of the instruction
  landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
  
}
```

### Assignment 5

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
    }
```

### Assignment 6

To which direction would you send the robot; To the left

Based on distance; The longest measured distance.

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Measure the distance to the left
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int left = landjerobot.measureDistance();

      // Measure the distance to the right
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int right = landjerobot.measureDistance();
      
      // Look forward again
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      if (left > right) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // move forward again
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    }
  }
```
    
    
#Lesson 12, improvements

##Assignment 1

When the robot needs to turn, just move a bit backward first to get some space to turn.

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
    
      // Stop moving
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Measure the distance to the left
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int left = landjerobot.measureDistance();

      // Measure the distance to the right
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int right = landjerobot.measureDistance();
      
      // Look forward again
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Move a bit backward and turn to the left or right
      if (left > right) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Move forward again
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    }
  }
```

Or more efficient

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
      // Stop moving
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Measure the distance to the left
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int left = landjerobot.measureDistance();

      // Measure the distance to the right
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int right = landjerobot.measureDistance();
      
      // Look forward again
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Move a bit backward
      landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
      
      // Turn to the left or right
      if (left > right) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Move forward again
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    }
  }
```

## Assignment 2

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
    
      // Stop moving
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
   
      // Grumble
      landjerobot.talk(5);
              
      // Measure the distance to the left
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int left = landjerobot.measureDistance();

      // Measure the distance to the right
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int right = landjerobot.measureDistance();
      
      // Look forward again
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Move a bit backward
      landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
      
      // Turn to the left or right
      if (left > right) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Move forward again
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    }
  }
```
    
    
## Assignment 3

```
    // Measure the distance
    int distance = landjerobot.measureDistance();

    // Stop when the distance is less than 10cm
    if (distance < 10) {
      
      // Verifiy the measured distance
      int totaldistance = 0;
      for (int x=1; x<=5;x++) {
        totaldistance = totaldistance + landjerobot.measureDistance(); 
      }
      
      if (totaldistance < 50) {
      
        // Stop moving
        landjerobot.move(LandjeRobot::DIRECTION::STOP);
        
        // Grumble
        landjerobot.talk(5);
      
        // Measure the distance to the left
        landjerobot.look(LandjeRobot::LOOK::LEFT);
        delay(1000);
        int left = landjerobot.measureDistance();
  
        // Measure the distance to the right
        landjerobot.look(LandjeRobot::LOOK::RIGHT);
        delay(1000);
        int right = landjerobot.measureDistance();
        
        // Look forward again
        landjerobot.look(LandjeRobot::LOOK::FORWARD);
        
        // Move a bit backward
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
      
        // Turn to the left or right
        if (left > right) {
          landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
        } else {
          landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
        }
        
         // Move forward again
         landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
      }
    }
```