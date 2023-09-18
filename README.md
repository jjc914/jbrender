# JBrender
A terminal rasterizer written in C. 

<img src="/res/jbrender.gif" height="300"/>

## Description
JBrender is a simple rasterizer written for educational purposes. It includes a threaded keyboard listener to respond to input and an obj reader to import models. Due to the structure of the codebase, it is easy to edit the scene programmatically, adding, moving, or rotating objects, etc. 

For the time being, the rasterizer lacks significant optimization. Furthermore, the obj reader does not include an effective triangulator for unconventional models. 

## To Build
1. Clone this repo:
```
git clone https://github.com/jjc914/jbrender.git
```
```
mkdir build
```
2. Make a build folder within the project folder and change directory:
```
mkdir build
cd build
```
3. Build the project and run:
```
cmake ..
cmake --build .
bin/jbrender
```

## To Do
- [ ] Implement Phong shading model
- [ ] Improved triangulation algorithm for non-quad geometry
- [ ] Only check point-triangle intersection for triangles within the bounding box of the frustum
- [ ] Different materials for objects
- [ ] Read materials from obj
- [ ] Remove global variables and find a better way for the keyboard listener to interact with main code
