# koh_skola
Knight's of Honor copy with SFML used for GUI and C++ used for engine. 

## Prerequisites
##### SFML
The project already contains all the dll's you need. But you will have to link SFML with your env.
If you plan on using just the .exe you don't need to do anything else than pulling the repo.
I had to use Code::Blocks as my env and there's really good site to help you out with linking here: https://www.sfml-dev.org/tutorials/2.5/start-cb.php
Or you can just find help for your env/IDE here: https://www.sfml-dev.org/download/sfml/2.5.1/ .
## Installing

A step by step series of examples that tell you how to get a development env running.

```
pull the repo.
make new project in the "koh_skola" project folder.
Link Util and Resources folders with your project.
Try compiling the code.
```
If you end up with "missing dlls' error" that's because you linked sfml dynamicaly. What you need to do is copy the dlls' from /Util/dll/
and paste them in project folder ("koh_skola"). And if your .exe won't run you will have to do the same, copy the dlls' into the same location as your exe file.

## Deployment

To be written.

## Built With

* [SFML](https://www.sfml-dev.org/index.php) - The graphics and network framework used

## Acknowledgments

* Hat tip to anyone whose code was used
* Huge thanks to my roomate for buying me internet
* Thank you if you are reading this.



