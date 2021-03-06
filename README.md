# Landje Robot

![cover](https://raw.githubusercontent.com/petervannes/LandjeRobot/master/docs/Student%20guide/cover.png)

Welcome to the Landje Robot repository. Landje Robot is an fully open source STEM robot and named after the elementary school of my kids where i started teaching programming using this robot. It is a common object avoidance and line following robot like many others. Landje Robot deviates in two aspects from many other builds.

First, Landje Robot is fully documented. There is a [Preparation guide](https://petervannes.github.io/LandjeRobot/Landje%20robot%20Kit%20preparation.html) which describes the bill of material, assembly of wire looms and other main parts and designs of the 3D printed parts. Next to the [Preparation guide](https://petervannes.github.io/LandjeRobot/Landje%20robot%20Kit%20preparation.html) there is a [Student guide](https://petervannes.github.io/LandjeRobot/Student%20guide%20ENU.html) with programming lessons in [English](https://petervannes.github.io/LandjeRobot/Student%20guide%20ENU.html) and [Dutch](https://petervannes.github.io/LandjeRobot/Student%20guide%20NLD.html).

Secondly, Landje Robot has its own instruction set. The instruction set is also documented in [Dutch](https://petervannes.github.io/LandjeRobot/instructionset%20NLD.html) and [English](https://petervannes.github.io/LandjeRobot/instructionset%20ENU.html). This instructionset simplifies the control of the sensors, motors, led and switch. With this instruction set and robot i made an attempt to create instruction material for kids who have overgrown the level of programming in Scratch or similar languages like Blockly and Alice. Programming in Scratch is a good starting point to grab the concepts of programming, but it has it's limitiations. (as this robot has it's own)

Switching from the safe Scratch language to C is challenging with it syntax and runtime errors. Therefore the complexity of controlling the I/O ports to read sensor data or control the servo- and stepper motors is delegated to the provide instructionset. Moving the robot forward is now reduced to a `move ( direction )` instruction.

For documentation and components there has been made use of open source components and products as much as possible. Documentation is written in MarkDown or HTML format. Graphical content is made using [GIMP](https://www.gimp.org) for bitmaps and [Inkscape](https://inkscape.org/en/) for vector oriented images.

All documentation is clearly published [here](https://petervannes.github.io/LandjeRobot/)
