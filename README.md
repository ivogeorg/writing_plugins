### writing_plugins

Exercise in writing Gazebo plugins, the brains behind simulated robot behavior :)

### Notes

1. Create plugin catkin package with the following requirements:
   ```
   catkin_create_pkg writing_plugins gazebo gazebo_ros gazebo_plugins roscpp
   ```  
2. After compilation, add the path to the plugin library (in this case `~/catkin_ws/devel/lib`) to the Gazebo plugin path:
   ```
   export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/catkin_ws/devel/lib
   ```  
3. 