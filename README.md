# Robot Control Surface

in order to control this bad boy, you have to 

~~~
export LD_LIBRARY_PATH=/home/Qt/6.6.1/gcc_64/lib
~~~
because Qt isnt in /usr/local/lib  
i dont know why  
I'll figure it out.  
Note: you have to re source ROS again afterwards.  
  
Then theres this bullshit:  
~~~
uic mainWindow.ui -o mainWindow.cpp
~~~