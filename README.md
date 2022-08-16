# rayTracyingInWeekend
Learning notes from book "Ray Tracing in one weekend"

## Run Program (ubuntu 20.04)
1.Obtain the update code from the official website
```
https://github.com/RayTracing/raytracing.github.io
```
2.Install cmake if not available 
```
$sudo apt install cmake
```
3.Go to the top level repo, set up the build folder
```
$cmake -B  build
```
4.Then, compile all the code
```
$cmake --build build
```
5.Go to the build/inOneWeekend folder, update the **main.cc** file if needed

6.Go back to build folder, recompile
```
$make
```
7.Generate the image.ppm 
```
$/inOneWeekend  > image.ppm
```
8.View the results
```
$xdg-open  image.ppm
```
