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
moc mainWindow.cpp -o mainWindow.moc
~~~
maybe not anymore ^ (Set RPATH in cmake)

https://www.youtube.com/watch?v=KugPAznC4Yo
https://stackoverflow.com/questions/54464488/ros-qt-gui-how-to-distribute-the-threads
https://answers.ros.org/question/335364/ros2-rclcpp-linking-error-and-correct-way-to-handle-dependencies/